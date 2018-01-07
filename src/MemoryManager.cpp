//
// Created by damir on 06-Jan-18.
//

#include <cmath>
#include "../hdr/MemoryManager.h"

MemoryManager::MemoryManager(size_t size)
        : map(new FreeList[11]), _mmpl(MemPool::getInstance()), _poolSize(size) {
    _mmpl.setPool(size);
    init();
}

char *MemoryManager::getMemory(size_t size) {

    char *ret;

    int check = whichPowerOfTwo(size);
    if (check != -1) {
        return map[check].alloc(); // Wrong at this point.
    }
    return nullptr;

//    switch (size) {
//
//        case 1:
//
//            ret = map[0].alloc();
//
//            break;
//
//        case 2:
//            break;
//
//        case 4:
//            break;
//
//        case 8:
//            break;
//
//        case 16:
//            break;
//
//        case 32:
//            break;
//
//        case 64:
//            break;
//
//        case 128:
//            break;
//
//        case 256:
//            break;
//
//        case 512:
//            break;
//
//        default:
//            size_t nextPow = (size_t)pow(2, ceil(log(size)/log(2)));
//            if (nextPow != size) {
//                std::cerr << "Not a power of two! Returning nothing" << std::endl;
//                return nullptr;
//            }
//            else {
//
//            }
//            break;
//    }
//
//    return nullptr;
}

int MemoryManager::whichPowerOfTwo(size_t n) {
    int counter = 0;

    while (n % 2 == 0) {
        counter++;
        if (counter > 10)
            break;
        n /= 2;
    }
    if (n != 1 && n % 2 != 0) {
        return -1;
    }
    return counter;
}

void MemoryManager::returnMemory(FreeNode *f) {
    map[whichPowerOfTwo(f->getBlockSize())].add(f);
}

MemoryManager::~MemoryManager() {
//    for (int i = 0; i < 11; ++i) {
//        delete map[i];
//    }
//    delete[] map;
//    for (int i = 0; i < 11; ++i) {
//
//    }
}

void MemoryManager::printCurrMemoryState() {

    for (int i = 0; i < 11; ++i) {

        FreeNode *it = map[i].getHead();

        if (it) {
            std::cout << "Showing state for blocks of size " << pow(2, i) << ":" << std::endl;
            while (it != map[i].tail) {
                std::cout << *it << " --> ";
                it = it->next;
            }
            if (it == map[i].tail) {
                std::cout << *it;
            }
            std::cout << "\n" << std::endl;
        }
    }

}

void MemoryManager::init() {

    char *pool  = _mmpl.getPool();
    size_t size = _poolSize;

    for (int i = 0; i < 11; ++i) {
        size_t counter = (size_t)pow(2, i);

        if (counter <= size) {

            for (long j = 0, index = 0; j < size; j += counter, ++index) {

                char *filler = &pool[index * counter];
                map[i].add(new FreeNode(filler, counter));

            }
        }
    }


}

