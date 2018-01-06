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

public:

    FreeList();

    ~FreeList();

    void add(size_t size);

};


#endif //CPP_EX3_FREELIST_H
