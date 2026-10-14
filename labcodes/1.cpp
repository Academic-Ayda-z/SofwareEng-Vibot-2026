#include <iostream>
using namespace std;

void incByValue(int val, int offset) {
    val = val + offset;
}

void incByPointer(int* val, int offset) {
    *val = *val + offset;
}

void incByReference(int& val, int offset) {
    val = val + offset;
}

int main() {
    int a = 10;
    int b = 10;
    int c = 10;
    int offset = 1;

    // Pass by value
    incByValue(a, offset);

    // Pass by pointer
    incByPointer(&b, offset);

    // Pass by reference
    incByReference(c, offset);

    cout << "a (by value):     " << a << endl;
    cout << "b (by pointer):   " << b << endl;
    cout << "c (by reference): " << c << endl;

    return 0;
}
