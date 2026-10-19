#include <iostream>
using namespace std;

int square(int x) {
    return x * x;
}

int cube(int x) {
    return x * x * x;
}
void applyOperation(int* array, int size, int (*op)(int)) {
    for (int i = 0; i < size; i++) {
        array[i]= op(array[i]);
}

}
int main(){
    int size=3;
    int arr[size] = {10, 20, 30};


    applyOperation(arr, size, square);   
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
        } 
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    applyOperation(arr, size, cube); 

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
        } 
    return 0;
}