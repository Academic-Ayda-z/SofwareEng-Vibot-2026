#include <iostream>
using namespace std;
#include <random>

/*sum of all integers between pointers begin (inclusive) and end (exclusive) using a pointer-
incrementing while loop (while (begin != end)).
2. Write a function void reverseArrayPtr(int* begin, int* end) that reverses an array in-
place using two pointers (front starting at the beginning, back starting at the end) moving
toward each ot#include <random>her until they meet.
3. In main(), test both functions on a statically allocated array of 6 integers. Note how this
pointer-range syntax ([begin, end)) directly mirrors modern C++ STL iterators!

*/

int randGen( int minVal, int maxVal){
    //generate random number
random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dist(minVal, maxVal);

    int number = dist(gen);
    return number;
}
void fillRandom(int* arr, int size, int minVal, int maxVal) {


while(size>0){
    
    *arr=randGen(minVal,maxVal);
    arr++;
    size--;
}


}

//llocating a heap array filled with factorials (0!, 1!, . . . , (n−1)!).

int recursiveFact(int n){
    if (n==0)
      return 0;
    if(n==1 )
        return 1; 
        
    return n*recursiveFact(n-1);
}

int* createFactorialArray(int n){
    
    int* heapArr=new int[n];
    n--;
    while (n>=0){
        heapArr[n]=recursiveFact(n);
        n--;
    }
    
    return heapArr;
}
int main(){
     int size=6;
     int arr[size];
     fillRandom(arr,size,5,30);
     for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    std::cout << '\n' << std::endl;
    int *heapFactArr = createFactorialArray(size);
    for (int i = 0; i < size; i++)
    {
        cout << heapFactArr[i] << " ";
    }
    
    return 0;
    
}





