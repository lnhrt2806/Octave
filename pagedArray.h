//
// Created by jimena on 2/17/17.
//

#ifndef OCTAVE_PAGEDARRAY_H
#define OCTAVE_PAGEDARRAY_H
#include <fstream>
#include <iostream>

using namespace std;

const int numFrames = 6;

class pagedArray{
private:
    int* mainArray = NULL;
    int frameSpace = 256;
    frame* framesArr[numFrames];

public:
    char* file;
    int settingIndex;
    int size;
    pagedArray(int x, char * filename);
    int& operator[](int x);
    int mostUsedPage();
    int replace(int pageNum, int newPageNum, int posToLook);
    int writeEmptyFrame(int i, int pageToLook, int posOnPageToLook);
    bool checkEmptyFrames(int pageToLook);
    void setIDs();
    void update();
    frame *frame1, *frame2, *frame3, *frame4, *frame5, *frame6;
};

class frame{
public:
    int frameNumber;
    int pageNumber= -1;
    int* loadedPageContent = NULL;
    int numOfUseOfPage = 0;
    frame(){
    }
};





#endif //OCTAVE_PAGEDARRAY_H