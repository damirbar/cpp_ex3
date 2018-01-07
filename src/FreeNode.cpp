//
// Created by damir on 07-Jan-18.
//

#include <iostream>
#include "../hdr/FreeNode.h"


int FreeNode::id = 0;

FreeNode::FreeNode(char *block, size_t size)
        : _blockSize(size), _block(block), _id(id++), next(nullptr), prev(nullptr) {

//    std::cout << "Created the node " << _id << " of the size " << size << " at address ";// << addr << std::endl;
//    printf("%p", (void*)_block);
//    std::cout << std::endl;
}

size_t FreeNode::getBlockSize() const {
    return _blockSize;
}

FreeNode::~FreeNode() {
    std::cout << "Deleted the node " << _id << " of the size " << getBlockSize() << std::endl;
//      delete block;
}

char *FreeNode::getBlock() {
    return _block;
}





std::ostream &operator<<(std::ostream &os, FreeNode &node) {
    char *blk = node.getBlock();

    os << "[ID: " << node._id << ", Size: " << node.getBlockSize() << ", Memory At:";// << addr << "]";

    char str[16];

    sprintf(str, "%p]", (void*)blk);

    os << str;

    return os;
}