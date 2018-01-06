#include <iostream>
#include "hdr/MemPool.h"


using namespace std;

int main() {

    MemPool &mmpl = MemPool::getInstance();

    mmpl.setPool(10);

    mmpl.setPool(20);

    return 0;
}