#include <iostream>
#include "long_ariph/ubigint.h"
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
    ubigint a = ubigint(3);
    ubigint b = ubigint(3);
    ubigint c = ubigint(0);
    c = c.pow(ubigint(2), c.pow(ubigint(3), c.pow(ubigint(3), ubigint(2))));
    c.simplePrint();
    return 0;
}