#include <iostream>
using namespace std;


/*sum of all integers between pointers begin (inclusive) and end (exclusive) using a pointer-
incrementing while loop (while (begin != end)).
2. Write a function void reverseArrayPtr(int* begin, int* end) that reverses an array in-
place using two pointers (front starting at the beginning, back starting at the end) moving
toward each other until they meet.
3. In main(), test both functions on a statically allocated array of 6 integers. Note how this
pointer-range syntax ([begin, end)) directly mirrors modern C++ STL iterators!

*/

int sumArrayPtr(const int* begin, const int* end) {
    
    int result=0;
    
    while (begin != end){
        result+=*begin;
        begin++;
    }
    return result;
}

void reverseArrayPtr(int* begin, int* end){
    if (begin == end)
        return;

    end--; 

    while (begin < end)
    {
        int temp = *begin;
        *begin = *end;
        *end = temp;

        begin++;
        end--;
    }
}

int main(){
    
    
    int arr[] = {10, 20, 30, 40, 50,60};
    int size=6;

    int result = sumArrayPtr(arr, arr + size);
    std::cout << result << std::endl;
    reverseArrayPtr(arr, arr+size);
    
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}





