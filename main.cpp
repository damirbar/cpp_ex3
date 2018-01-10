#include <iostream>
#include "hdr/MemPool.h"
#include "hdr/FreeList.h"
#include "hdr/MemoryManager.h"


using namespace std;


//static MemoryManager manager(16);

//size_t size;
//bool valgrind;
//static MemoryManager manager(size, valgrind);

void *operator new(size_t size, MemoryManager &m) {
    cout << "Inside manager's new operator. Got a request for " << size << " bytes of memory" << endl;
    return m.getMemoryBlock(size);
}


void returnToManager(void *memory, size_t size, MemoryManager &m) {
    cout << "Inside delete" << endl;
    m.returnMemoryBlock((char*)memory, size);
}

bool valgrindFlag = true;

int main(int argc, char *argv[]) {

    size_t size = 0;
    bool valgrind = false;

    if (argc == 1) {
        cerr << "Need more arguments" << endl;
        return 1;
    }
    if (argc > 3) {
        cerr << "Too many arguments" << endl;
        return 1;
    }
    if (argc == 2) {
        size = static_cast<size_t>(stoll((string)argv[1]));
    }
    else if (argc == 3) {
        size = static_cast<size_t>(stoll((string)argv[1]));
        if ((string)argv[2] == "-valgrind") {
            valgrind = true;
        }
    }

    static MemoryManager manager(size, valgrind);

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




//    MemoryManager mngr(15);

//    mngr.printCurrMemoryState();
//
//    FreeNode *mem =  mngr.getMemory(3);
//    FreeNode *mem1 = mngr.getMemory(2);
//    FreeNode *mem2 = mngr.getMemory(3);
//    FreeNode *mem3 = mngr.getMemory(5);
//
//    cout << "\n\nAfter alloc:\n" << endl;
//    mngr.printCurrMemoryState();
//
//    cout << "\n\nUsed Memory:" << endl;
//    mngr.printCurrAllocatedMemoryState();
//
//    mngr.returnMemory(mem3);
//    cout << "\n\nAfter dealloc1:\n" << endl;
//    mngr.printCurrMemoryState();
//    mngr.returnMemory(mem2);
//    cout << "\n\nAfter dealloc2:\n" << endl;
//    mngr.printCurrMemoryState();
//    mngr.returnMemory(mem);
//    cout << "\n\nAfter dealloc3:\n" << endl;
//    mngr.printCurrMemoryState();
//    mngr.returnMemory(mem1);
//    cout << "\n\nAfter dealloc4:\n" << endl;
//    mngr.printCurrMemoryState();


//    cout << "PRINTING CURR MEMORY STATE:\n" << endl;
//    mngr.printCurrMemoryState();

//    int *a = (int*)mngr.getMemoryBlock(sizeof(int));
//    int *b = (int*)mngr.getMemoryBlock(sizeof(int));/
//    double *c = (double*)mngr.getMemoryBlock(8);
//    double *d = (double*)mngr.getMemoryBlock(8);

//    if (!a) {
//        cerr << "Error allocating memory for A" << endl;
////        exit(1);
//    }
//    if (!b) {
//        cerr << "Error allocating memory for B" << endl;
////        exit(1);
//    }
//    if (!c) {
//        cerr << "Error allocating memory for C" << endl;
////        exit(1);
//    }
//    if (!d) {
//        cerr << "Error allocating memory for D" << endl;
////        exit(1);
//    }
//    *d = 8;

//    cout << "*d = " << *d << endl;

//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl;

//
//    cout << "PRINTING CURR MEMORY STATE AFTER ALLOCATING:\n" << endl;
//    mngr.printCurrMemoryState();
//
//    mngr.returnMemoryBlock((char*)a, sizeof(*a));
//    mngr.returnMemoryBlock((char*)b, sizeof(*b));
//    mngr.returnMemoryBlock((char*)c, sizeof(*c));


//    cout << "PRINTING CURR MEMORY STATE AFTER DEALLOCATING:\n" << endl;
//    mngr.printCurrMemoryState();


    int *a = new(manager) int(6);

    returnToManager(a, sizeof(int), manager);

//    delete(a, (size_t)4);



    cout << "\t\t\t\t\t\t\t\t\t\t\t\t------\t\t\tMain ended\t\t\t------" << endl;

    return 0;
}