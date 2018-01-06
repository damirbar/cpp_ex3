//
// Created by damir on 06-Jan-18.
//

#include "../hdr/MemoryManager.h"

MemoryManager::MemoryManager(size_t size)
        : _mmpl(MemPool::getInstance()) {}
