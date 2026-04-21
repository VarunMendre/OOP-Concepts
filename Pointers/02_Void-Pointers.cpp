#include <bits/stdc++.h>
using namespace std;

// void pointers : a void pointer is a special type of pointer that can point to any data type. It is also known as a generic pointer. A void pointer cannot be dereferenced directly, and it must be cast to the appropriate type before it can be used.

void printNum(int *num)
{
    cout << *num << endl;
}

void printChar(char *ch)
{
    cout << *ch << endl;
}

void print(void *ptr, char type)
{
    switch (type)
    {
    case 'i':
        // so here 1st: we cast the void pointer to an int pointer (int *)ptr
        // 2nd: we dereference it to get the value of the integer. *(int *)ptr
        cout << *(int *)ptr << endl;
        break;
    case 'c':
        // so here 1st: we cast the void pointer to a char pointer
        // 2nd: we dereference it to get the value of the character.
        cout << *(char *)ptr << endl;
        break;
    case 'f':
        // so here 1st: we cast the void pointer to a float pointer
        // 2nd: we dereference it to get the value of the float.
        cout << *(float *)ptr << endl;
        break;
    }
}

int main()
{
    int num = 5;
    char ch = 'a';
    float f = 3.14;

    printNum(&num);
    printChar(&ch);

    // but make sure to pass the correct type of pointer and type identifier to the print function
    // other wise it will lead to undefined behavior because the print function will try to interpret the data at the pointer as the wrong type, 
    // which can cause incorrect output or even a crash.
    print(&num, 'i');
    print(&ch, 'c');
    print(&f, 'f');
}