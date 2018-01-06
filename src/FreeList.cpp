//
// Created by damir on 06-Jan-18.
//

#include <iostream>
#include "../hdr/FreeList.h"

class FreeList::FreeNode {


    size_t _blockSize;
    char *block;

public:

    static int id;
    const int _id;

    FreeNode *next;
    FreeNode *prev;

    explicit FreeNode(size_t size);

    ~FreeNode();

    size_t getBlockSize() const;

};


int FreeList::FreeNode::id = 0;

FreeList::FreeNode::FreeNode(size_t size)
        : _blockSize(size), block(new char[size]), _id(id++), next(nullptr), prev(nullptr) {
    std::cout << "Created the node " << _id << " of the size " << size << std::endl;
}

size_t FreeList::FreeNode::getBlockSize() const {
    return _blockSize;
}

FreeList::FreeNode::~FreeNode() {
    std::cout << "Deleted the node " << _id << " of the size " << getBlockSize() << std::endl;
    delete block;
}

FreeList::FreeList() {
    head = tail = nullptr;
}

void FreeList::add(size_t size) {
    if (!head) {
        head = new FreeNode(size);
        tail = head;
    } else {
        FreeNode *tmp = new FreeNode(size);
        tail->next = tmp;
        tail = tmp;
    }
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
