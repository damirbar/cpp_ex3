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
    size_t _poolSize;

    int whichPowerOfTwo(size_t n);

public:

    explicit MemoryManager(size_t size);

    ~MemoryManager();

    char *getMemory(size_t size);

    void returnMemory(FreeNode *f);

    void printCurrMemoryState();

    void init();
};


#endif //CPP_EX3_MEMORYMANAGER_H
