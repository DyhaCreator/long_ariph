#include <iostream>
#include "long_ariph/arrbigint.h"
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
    arrbigint a = arrbigint(2);
    arrbigint b = arrbigint(3);
    arrbigint c = arrbigint(0);
    c = a * b;
    c.simplePrint();
    return 0;
}