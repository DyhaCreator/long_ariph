#pragma once
#include <iostream>
#define ll long long
#define ull unsigned long long
using namespace std;

struct ubigint{
    unsigned int len = 4;
    unsigned int num[4] = {0};
    ubigint(){}
    ubigint(ull a){
        num[0] = a % 4294967296;
        a /= 4294967296;
        num[1] = a % 4294967296;
    }
    // aux func ---
    void simplePrint(){
        for (int i = 0; i < len; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
    }
    ubigint min(ubigint a, ubigint b){
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }
    ubigint max(ubigint a, ubigint b){
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
    // just a func ---
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
    ubigint operator+(ubigint const &n){
        ubigint a = *this;
        ubigint b = n;
        ubigint c = ubigint(0);

        int carry = 0;
        for (int i = 0; i < len; i++) {
            ull d = (long long)a.num[i] + (long long)b.num[i] + (long long)carry;
            carry = 0;
            if (d > 4294967295) {
                carry = 1;
            }
            c.num[i] = d % 4294967296;

        }
        return c;
    }
    ubigint operator-(ubigint const &n){
        ubigint a = ubigint::min(*this, n);
        ubigint b = n;
        ubigint c = ubigint(0);

        

        return c;
    }
    ubigint operator*(ubigint const &n){
        ubigint a = ubigint::max(*this, n);
        ubigint b = ubigint::min(*this, n);
        ubigint c = ubigint(0);

        for (ubigint i = ubigint(0); i < b; i.inc()) {
            c = c + a;
        }

        return c;
    }
};