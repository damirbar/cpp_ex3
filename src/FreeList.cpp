//
// Created by damir on 06-Jan-18.
//

#include <iostream>
#include "../hdr/FreeList.h"


FreeList::FreeList()
        : _size(0), head(nullptr), tail(nullptr) {}

void FreeList::add(char *block, size_t size) {
//    if (!head) {
//        head = new FreeNode(block, size);
//        tail = head;
//    } else {
//        FreeNode *tmp = new FreeNode(block, size);
//        tail->next = tmp;
//        tail = tmp;
//    }
}

FreeList::~FreeList() {
    if (head) {
        while (head->next) {
            FreeNode *curr = head;
            head = head->next;
            delete curr;
        }
        delete head;
    }
}

size_t FreeList::size() const {
    return _size;
}

//  Like LinkedList's remove
char *FreeList::alloc() {
//    FreeNode *it = head;

    if (!head) {
        return nullptr;
    }
    FreeNode *ret = head;

    head = head->next;
//    char *blockRet = ret->getBlock();
//    delete ret;

//    return ret->getBlock();

//    while (it && !it->_free) {
//        it = it->next;
//    }
//    if (it) {
//        it->_free = false;
//        it->prev->next = it->next;
//        it->next->prev = it->prev;
//        return it->getBlock();
//    }
    return nullptr;
}

//void FreeList::dealloc(char *block) {
//    if (!head) {
//        head = new FreeNode(size);
//        tail = head;
//    } else {
//        FreeNode *tmp = new FreeNode(size);
//        tail->next = tmp;
//        tail = tmp;
//    }
//}

void FreeList::add(FreeNode *f) {
    if (!head) {
        head = tail = f;
    }
    tail->next = f;
    tail = f;
}

FreeNode *FreeList::allocNode() {
    if (!head) {
        return nullptr;
    }
    FreeNode *ret = head;

    head = head->next;
    return ret;
}

FreeNode *FreeList::getHead() {
    return head;
}

