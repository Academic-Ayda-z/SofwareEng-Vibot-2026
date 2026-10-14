#include <iostream>

// Naive Swap (By Value)
void swapValuesFail(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // The swaps happen only to local copies. Once the function ends, these changes are lost.
}


//Standard Swap (By Reference vs By Pointer): Implement working versions:
void swapRef(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}
void swapPtr(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Advanced Swap (Swapping Memory Addresses)  Given two heap pointers int* p1 = new int(10); and int* p2 = new int(20);:
void swapPointers (int ** a , int ** b ){
    int* temp = *a;
    *a = *b;
    *b = temp;

}
void swapPointersRef (int *& a , int *& b ){
    int* temp = &*a;
    a = &* b;
    b = temp;
}
int main() {
    int x = 5;
    int y = 10;
    
    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
    
    swapValuesFail(x, y);
    
    std::cout << "After swapValuesFail swap: x = " << x << ", y = " << y << "\n";
    x = 5;
    y = 10;



     std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
    
    swapRef(x, y);
    
    std::cout << "After swapRef swap: x = " << x << ", y = " << y << "\n";
    x = 5;
    y = 10;


     std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
    
    swapPtr(&x, &y);
    
    std::cout << "After swapPtr swap: x = " << x << ", y = " << y << "\n";
    

    int* p1 = new int(10);
    int* p2 = new int(20);
    std::cout << "Before swap: x = " << *p1 << ", y = " << *p2 << "\n";
    swapPointers(& p1,& p2);
    
    std::cout << "After swapPointers swap: x = " << *p1 << ", y = " << *p2 << "\n";
    
    std::cout << "Before swap: x = " << *p1 << ", y = " << *p2 << "\n";
    swapPointersRef(p1,p2);
    
    std::cout << "After swapPointersRef swap: x = " << *p1 << ", y = " << *p2 << "\n";
    

    return 0;
}
