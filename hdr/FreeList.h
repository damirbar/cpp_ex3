//
// Created by damir on 06-Jan-18.
//

#ifndef CPP_EX3_FREELIST_H
#define CPP_EX3_FREELIST_H


#include <cstdlib>

//class FreeNode;

class FreeList {

    class FreeNode;

    FreeNode *head;
    FreeNode *tail;

    size_t _size;

public:

//    class FreeNode;

    FreeList();

    ~FreeList();

    size_t size() const;

    void add(size_t size);

    char *getFirstFree();

};


#endif //CPP_EX3_FREELIST_H
