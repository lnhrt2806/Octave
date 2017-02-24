//
// Created by jimena on 2/24/17.
//

#ifndef OCTAVE_FRAME_H
#define OCTAVE_FRAME_H
#include <iostream>

class frame{
public:
    int frameNumber;
    int pageNumber= -1;
    int* loadedPageContent = NULL;
    int numOfUseOfPage = 0;
    frame(){
    }
};

#endif //OCTAVE_FRAME_H
