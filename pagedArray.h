//
// Created by jimena on 2/17/17.
//

#ifndef OCTAVE_PAGEDARRAY_H
#define OCTAVE_PAGEDARRAY_H
#include <fstream>
#include <iostream>
using namespace std;

const int numFrames = 6;

class frame{
public:
    int frameNumber;
    int pageNumber= -1;
    int* loadedPageContent = NULL;
    int numOfUseOfPage = 0;

    frame(){
    }
};



class pagedArray{
private:
    int* mainArray = NULL;
    int frameSpace = 256;
    frame* framesArr[numFrames];

public:
    char* file;
    int settingIndex;
    int size;
    int& operator[](int x);
    frame *frame1, *frame2, *frame3, *frame4, *frame5, *frame6;

    pagedArray(int x, char * fileName){
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

    void setIDs(){
        for(int i=0; i<numFrames; i++){
            framesArr[i]->frameNumber=i+1;
        }
    }
    int leastUsedPage(){
        int mayor = framesArr[0]->numOfUseOfPage;
        //determina el mayor
        for(int k = 0; k<numFrames; k++){
            if(framesArr[k]->numOfUseOfPage > mayor){
                mayor = framesArr[k]->numOfUseOfPage;
            }
        }
        //retorna la pagina que ha sido menos usada
        for(int k = 0; k<numFrames; k++){
            if(framesArr[k]->numOfUseOfPage == mayor){
                return framesArr[k]->pageNumber;
            }
        }
    }

    int replace(int pageNum, int newPageNum, int posToLook) {
        FILE *ff = fopen(file, "rb+");
        //ofstream binaryFile(file, ios::binary);
        //busca donde esta la pagina
        int numFrame = 0;
        for (int k = 0; k < numFrames; k++) {
            if (framesArr[k]->pageNumber == pageNum) {
                //escribe lo que contiene el frame en la posicion indicada

                fseek(ff, framesArr[k]->pageNumber * frameSpace * 4, SEEK_SET);
                if (framesArr[k]->pageNumber * frameSpace * 4 < 0 || framesArr[k]->pageNumber * frameSpace * 4 > size*4) {
                    cout << "abortar, posicion fuera de rango" << endl;
                    return 0;
                }
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

    void update(){
        FILE *ff = fopen(file, "rb+");
        for(int k =0; k<numFrames; k++){
            if(framesArr[k]->loadedPageContent != NULL) {
                fseek(ff, framesArr[k]->pageNumber * frameSpace * sizeof(int), SEEK_SET);
                if (ftell(ff) < 0) {
                    cout << "abortar, posicion negativa" << endl;
                    return;
                }
                fwrite(framesArr[k]->loadedPageContent, sizeof(int) * frameSpace, 1, ff);
            }
        }
        fclose(ff);

    }

};

int& pagedArray::operator[](int x) {
    if(x == -1){
        update();
        }
    else if(settingIndex >0) {
        settingIndex--;
        return mainArray[x];
    }
    else{
        int pageToLook = x/frameSpace;
        int posOnPageToLook = x%frameSpace;

    //revisa si ya esta cargada en algun frame
        for(int i=0; i< numFrames; i++){
         if(framesArr[i]->pageNumber == pageToLook){
             framesArr[i]->numOfUseOfPage++;
             return framesArr[i]->loadedPageContent[posOnPageToLook];
         }
        }

        //revisa si esta vacio
        if(framesArr[0]->pageNumber != pageToLook && framesArr[1]->pageNumber != pageToLook
           && framesArr[2]->pageNumber != pageToLook && framesArr[3]->pageNumber != pageToLook
           && framesArr[4]->pageNumber != pageToLook && framesArr[5]->pageNumber != pageToLook){

            FILE *ff = fopen(file, "rb+");


            //cout << "Page fault, uploading to RAM the needed page..."<<endl;

            //busca alguno que este vacio
            for(int i = 0; i<numFrames+1; i++){
                if(framesArr[i]->pageNumber == -1){
                    framesArr[i]->pageNumber = pageToLook;
                    fseek(ff, pageToLook*frameSpace* sizeof(int), SEEK_SET);

                    void* buffer = malloc(sizeof(int)*frameSpace);
                    int bytesRead = fread(buffer, sizeof(int)*frameSpace, 1, ff);

                    framesArr[i]->loadedPageContent = (int*) buffer;

                    fclose(ff);
                    return framesArr[i]->loadedPageContent[posOnPageToLook];
                }
            }
            //cout << "No hay espacio en la RAM, swap requerido" << endl;


            //reemplaza uno, escribe y carga otro
            //busca la pagina que mas ha sido usada
            int pageToReplace = leastUsedPage();
            int lookedFor = replace(pageToReplace, pageToLook, posOnPageToLook);
            return lookedFor;

    }

    }}





#endif //OCTAVE_PAGEDARRAY_H