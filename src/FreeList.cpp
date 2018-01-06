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

    bool _free;

    FreeNode *next;
    FreeNode *prev;

    explicit FreeNode(size_t size);

    ~FreeNode();

    size_t getBlockSize() const;

    char *getBlock();

};


int FreeList::FreeNode::id = 0;

FreeList::FreeNode::FreeNode(size_t size)
        : _blockSize(size), block(new char[size]), _id(id++), _free(true), next(nullptr), prev(nullptr) {
    std::cout << "Created the node " << _id << " of the size " << size << std::endl;
}

size_t FreeList::FreeNode::getBlockSize() const {
    return _blockSize;
}

FreeList::FreeNode::~FreeNode() {
    std::cout << "Deleted the node " << _id << " of the size " << getBlockSize() << std::endl;
    delete block;
}

char *FreeList::FreeNode::getBlock() {
    return block;
}

FreeList::FreeList()
        : _size(0), head(nullptr), tail(nullptr) {}

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

size_t FreeList::size() const {
    return _size;
}

char *FreeList::getFirstFree() {
    FreeNode *it = head;

    while (it && !it->_free) {
        it = it->next;
    }
    if (it) {
        it->_free = false;
        return it->getBlock();
    }
    return nullptr;
}

