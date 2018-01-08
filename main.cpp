#include <iostream>
#include "hdr/MemPool.h"
#include "hdr/FreeList.h"
#include "hdr/MemoryManager.h"


using namespace std;

int main() {

//    MemPool &mmpl = MemPool::getInstance();

//    mmpl.setPool(10);

//    mmpl.setPool(20);

//    FreeList list;
//    char *block16 = new char[16];
//    char *block32 = new char[32];
//    char *block2 = new char[2];
//    list.add(block16, 16);
//    list.add(block32, 32);
//    list.add(block2, 2);

    MemoryManager mngr(15);

    mngr.printCurrMemoryState();

    FreeNode *mem = mngr.getMemory(3);

    cout << "\n\nAfter alloc:\n" << endl;
    mngr.printCurrMemoryState();

    mngr.returnMemory(mem);


    cout << "\n\nAfter dealloc:\n" << endl;
    mngr.printCurrMemoryState();

//    mngr.printCurrMemoryStateShortly();

    cout << "\t\t\t\t\t\t\t\t\t\t\t\t------\t\t\tMain ended\t\t\t------" << endl;

    return 0;
}