#pragma once
#include <iostream>
#define ll long long
#define ull unsigned long long
using namespace std;

struct ubigint{
    const int len = 4;
    unsigned int num[4] = {0};
    ubigint(){}
    ubigint(ull a){
        num[0] = a % 4294967296;
        a /= 4294967296;
        num[1] = a % 4294967296;
    }
    void simplePrint(){
        for (int i = 0; i < len; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
    }
    void inc(){
        num[0]++;
        for (int i = 0; i < len; i++) {
            if (num[i] == 0) {
                num[i + 1]++;
            } else {
                break;
            }
        }
    }
    bool operator==(ubigint const &n){
        ubigint a = *this;
        ubigint b = n;
        for(int i = 0; i < len; i++) {
            if (a.num[i] != b.num[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(ubigint const &n){
        ubigint a = *this;
        ubigint b = n;
        return !(a == b);
    }
    bool operator<(ubigint const &n){
        ubigint a = *this;
        ubigint b = n;
        if (a == b) return false;
        for (int i = len - 1; i >= 0; i--) {
            if (a.num[i] > b.num[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator>(ubigint const &n){
        ubigint a = *this;
        ubigint b = n;
        if (a == b) return false;
        for (int i = len - 1; i >= 0; i--) {
            if (a.num[i] < b.num[i]) {
                return false;
            }
        }
        return true;
    }
};