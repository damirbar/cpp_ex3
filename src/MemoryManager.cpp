//
// Created by damir on 06-Jan-18.
//

#include <cmath>
#include "../hdr/MemoryManager.h"

MemoryManager::MemoryManager(size_t size)
        : map(new FreeList[11]), _mmpl(MemPool::getInstance()) {}

char *MemoryManager::getMemory(size_t size) {

    char *ret;

    int check = whichPowerOfTwo(size);
    if (check != -1) {
        return map[check].getFirstFree();
    }
    return nullptr;

//    switch (size) {
//
//        case 1:
//
//            ret = map[0].getFirstFree();
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
        n /= 2;
    }
    if (n != 1) {
        return -1;
    }
    return counter;
}

