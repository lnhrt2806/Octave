//
// Created by jimena on 2/17/17.
//

#ifndef OCTAVE_PAGEDARRAY_H
#define OCTAVE_PAGEDARRAY_H
#include <fstream>
#include <iostream>
using namespace std;



class pagedArray{
private:
    int* mainArray = new int[size];
    int frameSpace = 5;
    struct frame{
        int frameNumber;
        int pageNumber= -1;
        int loadedPageContent[5];

    }frame1, frame2, frame3, frame4;



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
    }
    void printArray(){
        for(int i = 0; i < size; i++){
            cout << "array[" << i << "] = " << mainArray[i] << "\n" << endl;
        }
    }
};

int& pagedArray::operator[](int x) {
    if(settingIndex >0) {
        settingIndex--;
        cout << settingIndex << "y" << size << endl;
        return mainArray[x];
    }
    else{
        int pageToLook = x/frameSpace;
        int posOnPageToLook = x%frameSpace;
        if(posOnPageToLook !=0)posOnPageToLook--;

        if(frame1.pageNumber != pageToLook && frame2.pageNumber != pageToLook
                && frame3.pageNumber != pageToLook && frame4.pageNumber != pageToLook){
            cout << "Page fault, uploading to RAM the needed page..."<<endl;
            ifstream openFile(file, ios::binary);
            if(frame1.pageNumber == -1){
                frame1.pageNumber = pageToLook;
                openFile.seekg(pageToLook*frameSpace*4);
                int v;
                int k=0;
                while( openFile.read( reinterpret_cast<char*>(&v), sizeof(v) ) && openFile.tellg() <= 4*frameSpace + pageToLook*frameSpace*4){
                    frame1.loadedPageContent[k] = v;
                    k++;
                }
                for(int w= 0; w<frameSpace; w++){
                    cout<<frame1.loadedPageContent[w]<<endl;
                }
                return frame1.loadedPageContent[posOnPageToLook];
            }
            else if(frame2.pageNumber == -1){
                frame2.pageNumber = pageToLook;
                openFile.seekg(pageToLook*frameSpace*4);
                int v;
                int k=0;
                while( openFile.read( reinterpret_cast<char*>(&v), sizeof(v) ) && openFile.tellg() <= 4*frameSpace + pageToLook*frameSpace*4){
                    frame2.loadedPageContent[k] = v;
                    k++;
                }
                for(int w= 0; w<frameSpace; w++){
                    cout<<frame2.loadedPageContent[w]<<endl;
                }
                return frame2.loadedPageContent[posOnPageToLook];
            }
            else if(frame3.pageNumber == -1){
                frame3.pageNumber = pageToLook;
                openFile.seekg(pageToLook*frameSpace*4);
                int v;
                int k=0;
                while( openFile.read( reinterpret_cast<char*>(&v), sizeof(v) ) && openFile.tellg() <= 4*frameSpace + pageToLook*frameSpace*4){
                    frame3.loadedPageContent[k] = v;
                    k++;
                }
                for(int w= 0; w<frameSpace; w++){
                    cout<<frame3.loadedPageContent[w]<<endl;
                }
                return frame3.loadedPageContent[posOnPageToLook];
            }
            else if(frame4.pageNumber == -1){
                frame4.pageNumber = pageToLook;
                openFile.seekg(pageToLook*frameSpace*4);
                int v;
                int k=0;
                while( openFile.read( reinterpret_cast<char*>(&v), sizeof(v) ) && openFile.tellg() <= 4*frameSpace + pageToLook*frameSpace*4){
                    frame4.loadedPageContent[k] = v;
                    k++;
                }
                for(int w= 0; w<frameSpace; w++){
                    cout<<frame4.loadedPageContent[w]<<endl;
                }
                return frame4.loadedPageContent[posOnPageToLook];
            }else{
                cout <<"no hay espacio en la RAM"<<endl;
                //SIGUE ESCRIBIR EL REEMPLAZO DE PAGINAS
            }
        }
        else if(pageToLook == frame1.pageNumber){
            for(int w= 0; w<frameSpace; w++){
                cout<<frame1.loadedPageContent[w]<<endl;
            }
            return frame1.loadedPageContent[posOnPageToLook];
        }
        else if(pageToLook == frame2.pageNumber){
            for(int w= 0; w<frameSpace; w++){
                cout<<frame2.loadedPageContent[w]<<endl;
            }
            return frame2.loadedPageContent[posOnPageToLook];
        }
        else if(pageToLook == frame3.pageNumber){
            for(int w= 0; w<frameSpace; w++){
                cout<<frame3.loadedPageContent[w]<<endl;
            }
            return frame3.loadedPageContent[posOnPageToLook];
        }
        else if(pageToLook == frame4.pageNumber){
            for(int w= 0; w<frameSpace; w++){
                cout<<frame4.loadedPageContent[w]<<endl;
            }
            return frame4.loadedPageContent[posOnPageToLook];
        }



        cout <<"pagina " << pageToLook << " posicion " << posOnPageToLook-1 <<endl;
    }

    }





#endif //OCTAVE_PAGEDARRAY_H