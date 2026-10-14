#include <iostream>
using namespace std;

int factorialForLoop(int n){
    int result=1;
    for(int i=1;i<n+1;i++){
        result*=i;
    }
    return result;
}

int factorialWhileLoop(int n){
    int result=1;
    int i=1;
    while(i<n+1){
        result*=i;
        i+=1;
    }
    return result;
}

int factorialDoWhileLoop(int n){
    int result=1;
    int i=1;
    do{
        result*=i;
        i++;
    }while(i<n+1);

    return result;
}


int main() {
    int n=4;
    cout << factorialForLoop(n) << endl;
    cout << factorialWhileLoop(n) << endl;
    cout << factorialDoWhileLoop(n) << endl;
    return 0;
}