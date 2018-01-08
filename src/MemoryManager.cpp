//
// Created by damir on 06-Jan-18.
//

#include <cmath>
#include "../hdr/MemoryManager.h"

MemoryManager::MemoryManager(size_t size)
        : map(new FreeList[11]), _mmpl(MemPool::getInstance()), _poolSize((size_t) pow(2, ceil(log(size) / log(2)))), _currAlloc(0) {
    _mmpl.setPool(size);
    init();
}

FreeNode *MemoryManager::getMemory(size_t size) {

    std::cout << "Got a memory request of size " << size << ", but will return memory of size "
              << (int) pow(2, ceil(log(size) / log(2))) << std::endl;

    FreeNode *ret;

    size = (size_t) pow(2, ceil(log(size) / log(2)));
    _currAlloc += size;

    int check = whichPowerOfTwo(size);
    if (check != -1) {

        int nextPow = (int) pow(2, ceil(log(size) / log(2)));

        for (int i = 0; i < 11; ++i) {

//            if (i != check) {
//                if (map[i].size() != 0) {
//                    for (int j = 0; j == 0 || j < nextPow; ++j) {
//                        std::cout << "Popping a block of size " << pow(2, i) << std::endl;
//                        delete map[i].allocNode();
//                        --counters[i];
//                    }
//                }
//                // TODO else
//            }

//            nextPow /= 2;

            while (counters[i] * pow(2, i) > _poolSize - _currAlloc) {
                std::cout << "Popping a block of size " << pow(2, i) << std::endl;
                if (i == check) {
                    ret = map[i].allocNode();
                } else {
                    delete map[i].allocNode();
                }
                --counters[i];

            }

        }
        std::cout << "Returning a block of size " << (int) pow(2, check) << std::endl;
//        --counters[check];
//        return map[check].allocNode();
        return ret;
    }

    return nullptr;
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
    std::cout << "Attempting to return a memory of size " << f->getBlockSize() << std::endl;
    int check = whichPowerOfTwo(f->getBlockSize());
    std::cout << "the power is:" << check << std::endl;
    if (check == -1) {
        std::cerr << "Error returning memory" << std::endl;
    } else {
        char *block = f->getBlock();
        size_t size = f->getBlockSize();
        _currAlloc -= f->getBlockSize();

        for (int i = 0; i < 11; ++i) {
            size_t counter = (size_t) pow(2, i);


            /* Other version: // doesn't work well
//            int j = counters[i];
//            counters[i] += size;
//            int index = 0;
//            while (j < counters[i]) {
//
//                char *filler = &block[index * counter];
//                map[i].add(new FreeNode(filler, counter));
//                j += counter;
//                ++index;
//
//                ++j;
//            }
//            size /= 2;

            */


            if (counter <= _poolSize) {

//                long j = 0, index = 0;
//
//                do {
//                    char *filler = &block[index * counter];
//                    map[i].add(new FreeNode(filler, counter));
//                    ++counters[i];
//
//                    j += counter;
//                    ++index;
//                } while (j < size);


//                for (long j = 0, index = 0; j < size; j += counter, ++index) {
//                    char *filler;
//                    if (counter > size) {
//
////                        if (map[i].size() * counter)
//
//                        filler = &block[(index * counter) - (counter - size)];
//                    } else {
//                        filler = &block[index * counter];
//                    }
//                    map[i].add(new FreeNode(filler, counter));
//                    ++counters[i];
//                }

//                long j = 0, index = 0;
//
//                if (i == 0) {
//                    char *filler = &block[index * counter];
//                    map[i].add(new FreeNode(filler, counter));
//                    ++counters[i];
//                }
//
//                while (j < size && i > 0 &&
//                       (counters[i - 1] * pow(2, i - 1) >= (counters[i] * pow(2, i) + pow(2, i)))) {
//                    char *filler;
//
//                    if (counter > size) {
//                        filler = &block[(index * counter) - (counter - size)];
//                    } else {
//                        filler = &block[index * counter];
//                    }
//                    map[i].add(new FreeNode(filler, counter));
//                    ++counters[i];
//
//                    j += counter, ++index;
//                }

                long j = 0, index = 0;

                while ( (counters[i] * pow(2, i)) + pow(2, i) <= _poolSize - _currAlloc ) {
                    char *filler;
                    std::cout << "Adding a bolock of size " << pow(2,i) << std::endl;
                    if (counter > size) {
                        std::cout << "counters[" << i << "]=\t\t" << counters[i] << std::endl;
                        filler = &block[(index * counter) - (counter - size)];
                    } else {
                        filler = &block[index * counter];
                    }
                    map[i].add(new FreeNode(filler, counter));
                    ++counters[i];

                    j += counter, ++index;
                }

            }
        }
    }
    delete f;
}

MemoryManager::~MemoryManager() {
    delete[] map;
}

void MemoryManager::printCurrMemoryState() {

    for (int i = 0; i < 11; ++i) {

        FreeNode *it = map[i].getHead();

        if (it) {
            std::cout << "Showing state for blocks of size " << pow(2, i) << ":" << std::endl;
            while (it != map[i].tail) {
                std::cout << *it << " <-- ";
                it = it->next;
            }
            if (it == map[i].tail) {
                std::cout << *it;
            }
            std::cout << "\n" << std::endl;
        }
    }
}

void MemoryManager::printCurrMemoryStateShortly() {
    for (int i = 0; i < 11; ++i) {
        std::cout << "There are " << counters[i] << " free blocks of size " << pow(2, i) << std::endl;
    }
}

void MemoryManager::init() {

    char *pool = _mmpl.getPool();
    size_t size = _poolSize;

    for (int i = 0; i < 11; ++i) {
        size_t counter = (size_t) pow(2, i);

        counters[i] = 0;
        if (counter <= size) {
            for (long j = 0, index = 0; j < size; j += counter, ++index) {

                char *filler = &pool[index * counter];
                map[i].add(new FreeNode(filler, counter));
                ++counters[i];
            }
        }
    }
}

