#include <iostream>
#include <ctime>
#include "long_ariph/arrbigint.h"
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
    arrbigint a = arrbigint(4294967296);
    arrbigint b = arrbigint(4294967296);
    arrbigint c = arrbigint(0);
    
    clock_t tStart = clock();
    c = a * b;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    a.simplePrint();
    b.simplePrint();
    c.simplePrint();
    return 0;
}