//
// Created by damir on 06-Jan-18.
//

#ifndef CPP_EX3_FREELIST_H
#define CPP_EX3_FREELIST_H


#include <cstdlib>
#include "FreeNode.h"

//class FreeNode;

class FreeList {

    friend class MemoryManager;
//    class FreeNode;

    FreeNode *head;
    FreeNode *tail;

    size_t _size;
    size_t _numOfPairs;

    FreeNode *getHead();

public:

//    class FreeNode;

    FreeList();

    ~FreeList();

    size_t size() const;

    size_t pairs();

    void add(char *block, size_t size);

    void add(FreeNode *f);

    FreeNode *allocNode();

    char *alloc();

    FreeNode *removeNode(FreeNode *f);

    void addNode(FreeNode *f);

//    void dealloc(char *block);

    void updatePairs();

    char *getPairAt(char *string);

    bool getPairAt(char *block, FreeList *map, int i, size_t counter, FreeNode *f, size_t size,
                   FreeList *allocated, bool test);

    int whichPowerOfTwo(size_t n);

    void remove();

    char* removeNodeOfBlock(char *block);

    bool contains(char *string);

    void addBlock(char *block, size_t size);
};


#endif //CPP_EX3_FREELIST_H
