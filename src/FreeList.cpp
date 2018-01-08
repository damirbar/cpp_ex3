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
    return ret->getBlock();
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
    else {
        head->prev = f;
        f->next = head;
        head = f;
//        tail->next = f;
//        tail = f;
    }
    ++_size;
}

FreeNode *FreeList::allocNode() {
    if (!head) {
        return nullptr;
    }

    FreeNode *ret = head;

    if (_size == 1) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
    }
    --_size;
    return ret;
}

FreeNode *FreeList::getHead() {
    return head;
}

void FreeList::removeCopyOfNode(FreeNode *f) {
    FreeNode *node = head;
    if (! head) {
        return;
    }
    if (node->getBlock() == f->getBlock()) {
        std::cout << "Removed the head node with id = " << node->_id << std::endl;
        head = head->next;
//        node = node->next;
        --_size;
        return;
    }

    while (node->getBlock() != f->getBlock() && node->next != nullptr) {
        node = node->next;
    }
    if (node->getBlock() == f->getBlock()) {
        std::cout << "Removed the node with id = " << node->_id << std::endl;
        node->prev->next = node->next;
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        --_size;
    }
}

void FreeList::addCopyOfNode(FreeNode *f) {
    FreeNode *substitutor = new FreeNode(f->getBlock(), f->getBlockSize());
    if (!head) {
        head = tail = substitutor;
    }
    else {
        head->prev = substitutor;
        substitutor->next = head;
        head = substitutor;
//        tail->next = f;
//        tail = f;
    }
    ++_size;
}

