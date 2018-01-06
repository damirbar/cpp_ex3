#include <iostream>
#include "hdr/MemPool.h"
#include "hdr/FreeList.h"


using namespace std;

int main() {

    MemPool &mmpl = MemPool::getInstance();

    mmpl.setPool(10);

//    mmpl.setPool(20);

    FreeList list;

    list.add(16);
    list.add(32);
    list.add(2);



    return 0;
}