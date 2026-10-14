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
    
    return 0;
}
