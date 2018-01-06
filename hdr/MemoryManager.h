//
// Created by damir on 06-Jan-18.
//

#ifndef CPP_EX3_MEMORYMANAGER_H
#define CPP_EX3_MEMORYMANAGER_H


#include <cstdlib>
#include "MemPool.h"
#include "FreeList.h"

class MemoryManager {

    FreeList *map;
    MemPool &_mmpl;

    int whichPowerOfTwo(size_t n);

public:

    explicit MemoryManager(size_t size);

    char *getMemory(size_t size);



};


#endif //CPP_EX3_MEMORYMANAGER_H
