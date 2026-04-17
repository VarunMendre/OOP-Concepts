#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    cout << &n << endl; // o/p : 0x38f7ff90c  , which is address of that variable

    int *ptr = &n;        // so ptr holds the address of n
    cout << ptr << endl;  // shows same address
    cout << *ptr << endl; // shows actual value, its called as dereference you're pointer

    *ptr = 10;

    // both will have same value because both are pointing to same memory location
    cout << "pointer: " << *ptr << endl;
    cout << "variable: " << n << endl;

    // note: pointer data type should be same as which is pointing to

    // This is wrong because ptr needs a memory location not a value
    // int* ptr2;
    // ptr2 = 7;

    // instead :

    int v;
    int *ptr2 = &v;
    *ptr2 = 7;

    cout << "v: " << v << endl;

    // Pointer's are mainly used to pass value by reference
    // also using with combination of Different DS also
    // also used in Dynamic memory allocation
    // Very useful in OOP in case of polymorphism & encapsulation
    // Smart pointer's
}