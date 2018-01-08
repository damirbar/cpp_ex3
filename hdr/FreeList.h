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

    FreeNode *getHead();

public:

//    class FreeNode;

    FreeList();

    ~FreeList();

    size_t size() const;

    void add(char *block, size_t size);

    void add(FreeNode *f);

    FreeNode *allocNode();

    char *alloc();

    void removeCopyOfNode(FreeNode *f);

    void addCopyOfNode(FreeNode *f);

//    void dealloc(char *block);

};


#endif //CPP_EX3_FREELIST_H
