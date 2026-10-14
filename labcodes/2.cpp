#include <iostream>
using namespace std;

void minMaxRef(int a, int b, int& outMin, int& outMax){
    outMax=b;
    outMin=a;

    if (a>=b){
        outMax=a;
        outMin=b;
    }

}

void minMaxPtr(int a, int b, int* outMin, int* outMax){

    *outMax= b;
    *outMin= a;

    if (a>=b){
        *outMax=a;
        *outMin=b;
    }
}
std::pair<int, int> minMaxPair(int a, int b){

if (a>=b){
    return{b,a};
}
return{a,b};

}



int main() {
    int a = 2;
    int b = 3;

    // Test minMaxRef
    int minRef, maxRef;
    minMaxRef(a, b, minRef, maxRef);

    cout << "Reference version:" << endl;
    cout << "Min = " << minRef << endl;
    cout << "Max = " << maxRef << endl;


    // Test minMaxPtr
    int minPtr, maxPtr;
    minMaxPtr(a, b, &minPtr, &maxPtr);

    cout << "\nPointer version:" << endl;
    cout << "Min = " << minPtr << endl;
    cout << "Max = " << maxPtr << endl;


    // Test minMaxPair
    pair<int, int> result = minMaxPair(a, b);

    cout << "\nPair version:" << endl;
    cout << "Min = " << result.first << endl;
    cout << "Max = " << result.second << endl;

    return 0;
}
