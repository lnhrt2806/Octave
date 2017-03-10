//
// Created by jimena on 2/24/17.
//
#include "pagedArray.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
 * Constructor of the pagedArray class, it creates the six frames with space for 256 numbers
 * @param x
 * @param fileName
 */
pagedArray::pagedArray(int x, const char *fileName) {
    frame1 = new frame();
    frame2 = new frame();
    frame3 = new frame();
    frame4 = new frame();
    frame5 = new frame();
    frame6 = new frame();

    framesArr[0] = frame1;
    framesArr[1] = frame2;
    framesArr[2] = frame3;
    framesArr[3] = frame4;
    framesArr[4] = frame5;
    framesArr[5] = frame6;

    file = fileName;
    size = x;
    mainArray = new int[size];
    settingIndex = size;

    setIDs();
}
/**
 * Assigns an ID number to each frame
 */
void pagedArray::setIDs() {
    for(int i=0; i<numFrames; i++){
        framesArr[i]->frameNumber=i+1;
    }
}
/**
 * Function that checks which page is the most used
 * @return the most used page
 */
int pagedArray::mostUsedPage() {
    int mayor = framesArr[0]->numOfUseOfPage;
    //determina el mayor
    for(int k = 0; k<numFrames; k++){
        if(framesArr[k]->numOfUseOfPage > mayor){
            mayor = framesArr[k]->numOfUseOfPage;
        }
    }
    //retorna la pagina que ha sido mas usada
    for(int k = 0; k<numFrames; k++){
        if(framesArr[k]->numOfUseOfPage == mayor){
            return framesArr[k]->pageNumber;
        }
    }
}
/**
 * Function that will write the content in RAM to the file, and upload the new content needed in the empty frame
 * @param pageNum number of page that will be overwritten
 * @param newPageNum number of page that will be uploaded to RAM
 * @param posToLook number of the position in the page of the element that is being looked for
 * @return the number on the specified position
 */
int pagedArray::replace(int pageNum, int newPageNum, int posToLook) {
    FILE *ff = fopen(file, "rb+");
    //busca donde esta la pagina
    int numFrame = 0;
    for (int k = 0; k < numFrames; k++) {
        if (framesArr[k]->pageNumber == pageNum) {
            //escribe lo que contiene el frame en la posicion indicada
            fseek(ff, framesArr[k]->pageNumber * frameSpace * 4, SEEK_SET);
            fwrite(framesArr[k]->loadedPageContent, sizeof(framesArr[k]->loadedPageContent[0])*frameSpace, 1, ff);

            //obtiene la pagina que se va a cargar y escribe su contenido en el frame
            fseek(ff, newPageNum*sizeof(int)*frameSpace, SEEK_SET);
            void* buffer = malloc(sizeof(int)*frameSpace);
            int bytesRead = fread(buffer, sizeof(int)*frameSpace, 1, ff);
            framesArr[k]->loadedPageContent = (int*) buffer;

            // le reinicia el contador al frame de las veces que es accesada la pagina y le cambia el numero de pagina
            framesArr[k]->numOfUseOfPage = 0;
            framesArr[k]->pageNumber = newPageNum;
            numFrame = k;
        }
    }
    fclose(ff);
    int buscado = framesArr[numFrame]->loadedPageContent[posToLook];
    return buscado;
}
/**
 * Function that overwrites the complete result file, once it has finished the sorting
 */
void pagedArray::update() {
    //Escribe todo lo que esta cargado en la RAM
    FILE *ff = fopen(file, "rb+");
    for(int k =0; k<numFrames; k++){
        if(framesArr[k]->loadedPageContent != NULL) {
            fseek(ff, framesArr[k]->pageNumber * frameSpace * sizeof(int), SEEK_SET);
            fwrite(framesArr[k]->loadedPageContent, sizeof(int) * frameSpace, 1, ff);
        }
    }
    fclose(ff);
}
/**
 * Function that checks if there is an empty frame
 * @param pageToLook number of page that will be compared with the one of the frame
 * @return whether there is an empty frame or not
 */
bool pagedArray::checkEmptyFrames(int pageToLook) {
    bool result = false;
    if(framesArr[0]->pageNumber != pageToLook && framesArr[1]->pageNumber != pageToLook
       && framesArr[2]->pageNumber != pageToLook && framesArr[3]->pageNumber != pageToLook
       && framesArr[4]->pageNumber != pageToLook && framesArr[5]->pageNumber != pageToLook){
        result= true;
    }
    return result;
}
/**
 * Function that uploads data in an empty frame
 * @param i position in the frames array of the empty frame
 * @param pageToLook page that will be uploaded in the frame
 * @param posOnPageToLook position on the page that is being looked for
 * @return the number in the specified position
 */
int pagedArray::writeEmptyFrame(int i, int pageToLook, int posOnPageToLook) {
    FILE *ff = fopen(file, "rb+");
    framesArr[i]->pageNumber = pageToLook;
    fseek(ff, pageToLook*frameSpace* sizeof(int), SEEK_SET);
    void* buffer = malloc(sizeof(int)*frameSpace);
    int bytesRead = fread(buffer, sizeof(int)*frameSpace, 1, ff);
    framesArr[i]->loadedPageContent = (int*) buffer;
    fclose(ff);
    return framesArr[i]->loadedPageContent[posOnPageToLook];
}
/**
 * Operator overloading that is in charge of pagination, it looks for the page on RAM and if is not uploaded it goes
 * to disk to get it.
 * @param x position on the main array that is needed
 * @return the number in the specified position
 */
int& pagedArray::operator[](int x) {
    if (x == -1) {
        update();
    } else if (settingIndex > 0) {
        settingIndex--;
        return mainArray[x];
    } else {
        int pageToLook = x / frameSpace;
        int posOnPageToLook = x % frameSpace;
        //revisa si ya esta cargada en algun frame
        for (int i = 0; i < numFrames; i++) {
            if (framesArr[i]->pageNumber == pageToLook) {
                framesArr[i]->numOfUseOfPage++;
                return framesArr[i]->loadedPageContent[posOnPageToLook];
            }
        }
        if (checkEmptyFrames(pageToLook)) {
            cout << "Page fault, uploading to RAM the needed page..." << endl;
            //busca alguno que este vacio
            for (int i = 0; i < numFrames + 1; i++) {
                if (framesArr[i]->pageNumber == -1) {
                    int result = writeEmptyFrame(i, pageToLook, posOnPageToLook);
                    return result;
                }
            }
            cout << "No hay espacio en la RAM, swap requerido" << endl;
            int pageToReplace = mostUsedPage();
            int lookedFor = replace(pageToReplace, pageToLook, posOnPageToLook);
            return lookedFor;
        }
    }
}
