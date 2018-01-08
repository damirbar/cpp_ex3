#include <iostream>
#include "hdr/MemPool.h"
#include "hdr/FreeList.h"
#include "hdr/MemoryManager.h"


using namespace std;


//static MemoryManager manager(16);

//void *operator new(size_t size, MemoryManager &m) {
//    cout << "Inside manager's new operator. Got a request for " << size << " bytes of memory" << endl;
//    return manager.getMemory(size)->getBlock();
//}
//
//void operator delete(void *memory) {
//    cout << "Inside delete" << endl;
//    ::delete memory;
//}

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
    FreeNode *mem1 = mngr.getMemory(3);
    FreeNode *mem2 = mngr.getMemory(3);
    FreeNode *mem3 = mngr.getMemory(5);

    cout << "\n\nAfter alloc:\n" << endl;
    mngr.printCurrMemoryState();

    cout << "\n\nUsed Memory:" << endl;
    mngr.printCurrAllocatedMemoryState();

    mngr.returnMemory(mem);
//    mngr.returnMemory(mem1);
    mngr.returnMemory(mem2);
    mngr.returnMemory(mem3);

    cout << "\n\nAfter dealloc:\n" << endl;
    mngr.printCurrMemoryState();

//    mngr.printCurrMemoryStateShortly();

//    char *ch = new(manager) char;
//
//    *ch = 'A';
//    cout << "ch = " << *ch << endl;
//
//    delete ch;
//
//    double *d = new(manager) double;
//
//    *d = 3;
//    cout << "d = " << *d << endl;

//    delete d;

    cout << "\t\t\t\t\t\t\t\t\t\t\t\t------\t\t\tMain ended\t\t\t------" << endl;

    return 0;
}