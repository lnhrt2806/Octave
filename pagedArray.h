//
// Created by jimena on 2/17/17.
//

#ifndef OCTAVE_PAGEDARRAY_H
#define OCTAVE_PAGEDARRAY_H
#include <fstream>
#include <iostream>
using namespace std;


const int numFrames = 4;
class pagedArray{
private:
    int* mainArray = new int[size];
    int frameSpace = 5;

    struct frame{
        int frameNumber;
        int pageNumber= -1;
        int loadedPageContent[5];
        int numOfUseOfPage = 0;

    }frame1, frame2, frame3, frame4;
    frame framesArr[numFrames] = {frame1, frame2, frame3, frame4};
public:
    char* file;
    int settingIndex;
    int size;
    int& operator[](int x);
    pagedArray(int x, char * fileName){
        int mainArray[x];
        file = fileName;
        size = x;
        settingIndex = size;
        setIDs();
    }
    void printArray(){
        for(int i = 0; i < size; i++){
            cout << "array[" << i << "] = " << mainArray[i] << "\n" << endl;
        }
    }
    void setIDs(){
        for(int i=0; i<numFrames; i++){
            framesArr[i].frameNumber = i+1;
        }
    }
    int leastUsedPage(frame a[]){
        int menor = a[0].numOfUseOfPage;
        //determina el menor
        for(int k = 0; k<numFrames; k++){
            if(a[k].numOfUseOfPage < menor){
                menor = a[k].numOfUseOfPage;
                cout << "el menor uso es de "<< menor<<" de la pagina"<< a[k].pageNumber<< " en el frame" << a[k].frameNumber<<endl;
            }
        }
        //retorna la pagina que ha sido menos usada
        for(int k = 0; k<numFrames; k++){
            if(a[k].numOfUseOfPage == menor){
                cout << "el menor uso es de "<< menor<<" de la pagina"<< a[k].pageNumber<< " en el frame" << a[k].frameNumber<<endl;
                return a[k].pageNumber;
            }
        }
    }

    int replace(int pageNum, int newPageNum, int posToLook, frame a[]) {
        FILE *ff = fopen(file, "r+");

        //ofstream binaryFile(file, ios::binary);
        //busca donde esta la pagina
        int numFrame;
        for (int k = 0; k < numFrames; k++) {
            if (a[k].pageNumber == pageNum) {
                //escribe lo que contiene el frame en la posicion indicada
                /*binaryFile.seekp(pageNum * frameSpace * 4);
                cout << "pos" << binaryFile.tellp() << endl;
                for (int w = 0; w < frameSpace; w++) {
                    binaryFile.write(reinterpret_cast<const char *>(&a[k].loadedPageContent[w]),
                                     sizeof(a[k].loadedPageContent[w]));
                }*/
                fseek(ff, a[k].pageNumber * frameSpace * 4, SEEK_SET);
                if (a[k].pageNumber * frameSpace * 4 < 0) {
                    cout << "abortar, posicion negativa" << endl;
                    return 0;
                }
                for (int w = 0; w < frameSpace; w++) {
                    fwrite(&a[k].loadedPageContent[w], sizeof(a[k].loadedPageContent[w]), 1, ff);
                }
                //obtiene la pagina que se va a cargar y escribe su contenido en el frame

                ifstream infile(file, ios::binary);
                infile.seekg(newPageNum * frameSpace * 4);
                int v;
                int r = 0;
                while (infile.read(reinterpret_cast<char *>(&v), sizeof(v)) &&
                       infile.tellg() <= 4 * frameSpace + newPageNum * frameSpace * 4) {
                    a[k].loadedPageContent[r] = v;
                    r++;
                }

                // le reinicia el contador al frame de las veces que es accesada la pagina y le cambia el numero de pagina
                a[k].numOfUseOfPage = 0;
                a[k].pageNumber = newPageNum;
                cout << "ahora el frame " << a[k].frameNumber << "contiene la pagina" << a[k].pageNumber
                     << " con los elementos ";
                for (int f = 0; f < frameSpace; f++) {
                    cout << a[k].loadedPageContent[f] << ' ';
                    cout << endl;

                }

            }
            numFrame = k;

        }
        fclose(ff);
        return a[numFrame].loadedPageContent[posToLook];

    }
    void update(frame a[]) {
        /*for(int k =0; k<numFrames; k++){
            ofstream binaryFile(file, ios::binary);
            binaryFile.seekp(a[k].pageNumber * frameSpace * 4);
            cout << "pos" << binaryFile.tellp() <<a[k].pageNumber * frameSpace * 4<< endl;
            if(binaryFile.tellp()<0){
                cout <<"abortar, posicion negativa"<<endl;

                return;
            }
            for (int w = 0; w < frameSpace; w++) {
                binaryFile.write(reinterpret_cast<const char *>(&a[k].loadedPageContent[w]),
                                 sizeof(a[k].loadedPageContent[w]));
            }
        }*/

        FILE *ff = fopen(file, "r+");
        for (int k = 0; k < numFrames; k++) {
            fseek(ff, a[k].pageNumber * frameSpace * 4, SEEK_SET);
            if (a[k].pageNumber * frameSpace * 4 < 0) {
                cout << "abortar, posicion negativa" << endl;
                return;
            }
            for (int w = 0; w < frameSpace; w++) {
                fwrite(&a[k].loadedPageContent[w], sizeof(a[k].loadedPageContent[w]), 1, ff);
            }

        }
        fclose(ff);

    }
    void updateFile(frame a[]){
        for(int k =0; k<numFrames; k++){
            ofstream binaryFile(file, ios::binary);
            binaryFile.seekp(a[k].pageNumber * frameSpace * 4);
            cout << "pos" << binaryFile.tellp() << endl;
            for (int w = 0; w < frameSpace; w++) {
                binaryFile.write(reinterpret_cast<const char *>(&a[k].loadedPageContent[w]),
                                 sizeof(a[k].loadedPageContent[w]));
            }
        }
    }
    void updatePage(frame a[], int frameNumber, int pageNumber){
        ofstream binaryFile(file, ios::binary);
        binaryFile.seekp(pageNumber * frameSpace * 4);
        cout << "posicion a actualizar " << binaryFile.tellp() << endl;
        if(binaryFile.tellp()<0){
            cout <<"abortar, posicion negativa"<<endl;

            return;
        }

        for (int w = 0; w < frameSpace; w++) {
            binaryFile.write(reinterpret_cast<const char *>(&a[frameNumber-1].loadedPageContent[w]),
                             sizeof(a[frameNumber-1].loadedPageContent[w]));
        }cout <<endl;


    }

};

int& pagedArray::operator[](int x) {
    if(x == -1){
        update(framesArr);
        terminate();
        }
    else if(settingIndex >0) {
        settingIndex--;
        return mainArray[x];
    }
    else{
        int pageToLook = x/frameSpace;
        int posOnPageToLook = x%frameSpace;
        //if(posOnPageToLook !=0)posOnPageToLook--;
        cout <<"posicion en la pagina" << posOnPageToLook<<endl;
    //revisa si ya esta cargada en algun frame
        for(int i=0; i< numFrames; i++){
         if(framesArr[i].pageNumber == pageToLook){
             cout<<"La pagina "<< framesArr[i].pageNumber << " ya esta cargada en el frame: " << framesArr[i].frameNumber<<endl;
             for(int w= 0; w<frameSpace; w++){
                 cout << framesArr[i].loadedPageContent[w]<< ' ';
             }
             framesArr[i].numOfUseOfPage++;
             cout <<"La pagina " << framesArr[i].pageNumber << " ha sido llamada " << framesArr[i].numOfUseOfPage <<" veces";
             cout<<endl;

             cout << "valor buscado " << framesArr[i].loadedPageContent[posOnPageToLook]<<endl;
             return framesArr[i].loadedPageContent[posOnPageToLook];
         }
        }
        if(frame1.pageNumber != pageToLook && frame2.pageNumber != pageToLook
                && frame3.pageNumber != pageToLook && frame4.pageNumber != pageToLook){

            cout << "Page fault, uploading to RAM the needed page..."<<endl;
            ifstream openFile(file, ios::binary);
            cout <<"tamano del archivo" << openFile.tellg()<<endl;
            //busca alguno que este vacio
            for(int i = 0; i<numFrames+1; i++){
                cout <<i<<endl;
                if(framesArr[i].pageNumber == -1){
                    framesArr[i].pageNumber = pageToLook;
                    openFile.seekg(pageToLook*frameSpace*4);
                    cout <<"posicion del archivo" << openFile.tellg()<<endl;
                    int v;
                    int k=0;
                    while( openFile.read( reinterpret_cast<char*>(&v), sizeof(v) ) && openFile.tellg() <= 4*frameSpace + pageToLook*frameSpace*4){
                        framesArr[i].loadedPageContent[k] = v;
                        k++;
                    }
                    cout<< "El frame numero " << framesArr[i].frameNumber << " contiene la pagina numero " << framesArr[i].pageNumber<<endl;
                    for(int w= 0; w<frameSpace; w++){
                          cout <<framesArr[i].loadedPageContent[w]<< ' ';
                    }cout<<endl;
                    for(int k = 0; k<numFrames; k++) {
                        cout << "frame" << framesArr[k].frameNumber<<"pagina" << framesArr[k].pageNumber<<' ';
                    }cout<<endl;
                    cout << "valor buscado " << framesArr[i].loadedPageContent[posOnPageToLook]<<endl;
                    return framesArr[i].loadedPageContent[posOnPageToLook];
                }
            }
            cout << "no hay espacio en la RAM" << endl;

            for(int k = 0; k<numFrames; k++) {
                cout << "frame" << framesArr[k].frameNumber<<"pagina" << framesArr[k].pageNumber<<' ';
            }cout<<endl;
            //reemplaza uno, escribe y carga otro

            //busca la pagina que mas ha sido usada
            int pageToReplace = leastUsedPage(framesArr);
            cout <<"page to replace" <<pageToReplace<<endl;
            int lookedFor = replace(pageToReplace, pageToLook, posOnPageToLook, framesArr);
            return lookedFor;

    }

    }}





#endif //OCTAVE_PAGEDARRAY_H