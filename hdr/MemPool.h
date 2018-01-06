//
// Created by damir on 06-Jan-18.
//

#ifndef CPP_EX3_MEMPOOL_H
#define CPP_EX3_MEMPOOL_H


#include <iostream>


/**
 *  Singleton class
 */
class MemPool {

    char *_pool;

    MemPool();

    MemPool(const MemPool &other) = delete;

    void operator=(const MemPool &other) = delete;

public:

    ~MemPool();

    static MemPool &getInstance();

    void setPool(int size);
};


#endif //CPP_EX3_MEMPOOL_H