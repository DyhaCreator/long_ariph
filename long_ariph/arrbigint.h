#pragma once
#include <iostream>
#define ll long long
#define ull unsigned long long
using namespace std;

struct arrbigint{
    unsigned int len = 4;
    unsigned int num[4] = {0};
    arrbigint(){}
    arrbigint(ull a){
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
    arrbigint min(arrbigint a, arrbigint b){
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }
    arrbigint max(arrbigint a, arrbigint b){
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
    bool operator==(arrbigint const &n){
        arrbigint a = *this;
        arrbigint b = n;
        for(int i = 0; i < len; i++) {
            if (a.num[i] != b.num[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(arrbigint const &n){
        arrbigint a = *this;
        arrbigint b = n;
        return !(a == b);
    }
    bool operator<(arrbigint const &n){
        arrbigint a = *this;
        arrbigint b = n;
        if (a == b) return false;
        for (int i = len - 1; i >= 0; i--) {
            if (a.num[i] > b.num[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator>(arrbigint const &n){
        arrbigint a = *this;
        arrbigint b = n;
        if (a == b) return false;
        for (int i = len - 1; i >= 0; i--) {
            if (a.num[i] < b.num[i]) {
                return false;
            }
        }
        return true;
    }
    arrbigint operator+(arrbigint const &n){
        arrbigint c = arrbigint(0);
        int carry = 0;
        for (int i = 0; i < len; i++) {
            ull d = (long long)this->num[i] + (long long)n.num[i] + (long long)carry;
            carry = 0;
            if (d > 4294967295) {
                carry = 1;
            }
            c.num[i] = d % 4294967296;

        }
        return c;
    }
    arrbigint operator-(arrbigint const &n){
        arrbigint a = arrbigint::min(*this, n);
        arrbigint b = n;
        arrbigint c = arrbigint(0);
        return c;
    }
    arrbigint mult_on_num(arrbigint a, int b) {
        arrbigint c = arrbigint(0);
        ll carry = 0;
        for (int i = 0; i < len; i++) {
            ull d = (unsigned long long)a.num[i] * (unsigned long long)b + carry;
            carry = 0;
            if (d > 4294967295) {
                carry = d / 4294967296;
            }
            c.num[i] = d % 4294967296;
        }
        return c;
    }
    arrbigint operator*(arrbigint const &n){
        arrbigint a = *this;
        arrbigint b = n;
        arrbigint c = arrbigint(0);

        for (int i = 0; i < len; i++) {
            c = c + mult_on_num(a, b.num[i]);
        }

        return c;
    }
    arrbigint pow(arrbigint a, arrbigint b) {
        arrbigint c = arrbigint(1);
        for (arrbigint i = arrbigint(0); i < b; i.inc()) {
            c = c * a;
        }
        return c;
    }
};