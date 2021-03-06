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
    FreeList *allocated;
    MemPool &_mmpl;
    size_t _poolSize;
    size_t _currAlloc;

    int whichPowerOfTwo(size_t n);

    int counters[11];


public:

    explicit MemoryManager(size_t size);

    ~MemoryManager();

    FreeNode *getMemory(size_t size);

    void returnMemory(FreeNode *f);

    void printCurrMemoryState();

    void printCurrAllocatedMemoryState();

    void init();

    void printCurrMemoryStateShortly();
};


#endif //CPP_EX3_MEMORYMANAGER_H
