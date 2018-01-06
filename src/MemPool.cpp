//
// Created by damir on 06-Jan-18.
//

#include "../hdr/MemPool.h"

MemPool::MemPool() : _pool(nullptr) {
    std::cout << "MemPool ctor called" << std::endl;
}

void MemPool::setPool(int size) {
    if (!_pool) {
        _pool = new char[size];
    }
    else {
        std::cerr << "Can't set the pool twice!" << std::endl;
    }
}

MemPool::~MemPool() {
    std::cout << "MemPool dtor called" << std::endl;
    if (_pool) {
        delete _pool;
        _pool = nullptr;
        std::cout << "Pool deleted" << std::endl;
    }
}

MemPool & MemPool::getInstance() {
    static MemPool instance;
    return instance;
}
