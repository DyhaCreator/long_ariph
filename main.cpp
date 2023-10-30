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
    ubigint a = ubigint(10);
    ubigint b = ubigint(12);
    ubigint c = ubigint(0);
    c = ubigint(3);
    c.simplePrint();
    return 0;
}