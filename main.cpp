#include <iostream>
#include "long_ariph/ubigint.h"
#define ll long long
#define ull unsigned long long
using namespace std;

int main() {
    ubigint a = ubigint(2);
    ubigint b = ubigint(3);
    a.simplePrint();
    b.simplePrint();
    cout << (a > b) << endl;
    return 0;
}