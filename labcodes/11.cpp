#include <iostream>
using namespace std;
#include <random>

// Write void transposeFlatMatrix(const double* src, double* dst, int rows, int cols) for 1D heap allocations.


void transposeFlatMatrix(const double* src, double* dst, int rows, int cols){
     for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
             dst[j * rows + i] = src[i * cols + j];
        }
    }
}
double* genMatrix(int rows, int cols)
{
    double* matrix = new double[rows * cols];

    int value = 1;

    for (int i = 0; i < rows * cols; i++)
    {
        matrix[i] = value++;
    }

    return matrix;
}
void printFlatMatrix(const double* mat, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i * cols + j] << "\t";
        }
        cout << endl;
    }
}
int main(){
   int rows = 3;
    int cols = 4;

    // Create the original matrix
    double* matrix = genMatrix(rows, cols);

    cout << "Original matrix:" << endl;
    printFlatMatrix(matrix, rows, cols);

    // Create space for the transposed matrix
    double* transposed = new double[rows * cols];

    transposeFlatMatrix(matrix, transposed, rows, cols);

    cout << "\nTransposed matrix:" << endl;
    printFlatMatrix(transposed, cols, rows);

    // Free heap memory
    delete[] matrix;
    delete[] transposed;

    return 0;
    
}





