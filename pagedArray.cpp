//
// Created by jimena on 2/24/17.
//
#include "pagedArray.h"
#include <fstream>
#include <iostream>
using namespace std;


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

void pagedArray::setIDs() {
    for(int i=0; i<numFrames; i++){
        framesArr[i]->frameNumber=i+1;
    }
}

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

bool pagedArray::checkEmptyFrames(int pageToLook) {
    bool result = false;
    if(framesArr[0]->pageNumber != pageToLook && framesArr[1]->pageNumber != pageToLook
       && framesArr[2]->pageNumber != pageToLook && framesArr[3]->pageNumber != pageToLook
       && framesArr[4]->pageNumber != pageToLook && framesArr[5]->pageNumber != pageToLook){
        result= true;
    }
    return result;
}

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
        //revisa si esta vacio
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
