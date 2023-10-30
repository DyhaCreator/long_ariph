#include <iostream>
#include "long_ariph/ubigint.h"
#define ll long long
#define ull unsigned long long
using namespace std;

struct x{
    int z;
    x(int z){
        this->z = z;
    }
};

int main() {
    ubigint a = ubigint(4294967295);
    ubigint b = ubigint(4294967297);
    ubigint c = ubigint(0);
    c = a + b;
    c.simplePrint();
    return 0;
}