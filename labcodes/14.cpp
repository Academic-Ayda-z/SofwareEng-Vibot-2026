
#include <iostream>
#include <vector>

// Exercise 1 - Version A: Raw pointers
int* copyGrowPointer(int* arr, int size) {

    int* arrGrow = new int[size * 2];

    for (int i = 0; i < size * 2; i++) {
        if (i >= size)
            arrGrow[i] = 0;
        else
            arrGrow[i] = arr[i];
    }

    delete[] arr;

    return arrGrow;
}

// Exercise 1 - Version B: Vector
std::vector<int> copyGrowVect(std::vector<int> vec) {

    int size = vec.size();

    vec.resize(2 * size, 0);

    return vec;
}

// Exercise 2 - Version A: Cleanup
void dynamic2DMatrixResizingPointerCleanup(
    double** matrix, int rows
) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

// Exercise 2 - Version A: Allocation
double** dynamic2DMatrixResizingPointer(
    int rows, int cols
) {
    double** arr = new double*[rows];

    // Allocation of columns for each row
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[cols]{};
    }

    // Initialize matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j + 1;
        }
    }

    return arr;
}

// Exercise 2 - Version B: Nested vectors
std::vector<std::vector<double>>
dynamic2DMatrixResizingVect(int rows, int cols) {

    std::vector<std::vector<double>> arr(
        rows, std::vector<double>(cols, 0.0)
    );

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j + 1;
        }
    }

    return arr;
}

int main() {

    // EXERCISE 1: RAW POINTERS
    int size = 3;
    int* arr = new int[size]{10, 20, 30};

    int* newArr = copyGrowPointer(arr, size);

    for (int i = 0; i < size * 2; i++) {
        std::cout << newArr[i] << " ";
    }

    std::cout << std::endl;

    delete[] newArr;

    // EXERCISE 1: VECTOR
    std::vector<int> vec = {10, 20, 30};

    std::vector<int> newVec = copyGrowVect(vec);

    for (int value : newVec) {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    // EXERCISE 2: RAW POINTERS
    int rows = 3;
    int cols = 4;

    double** matrix =
        dynamic2DMatrixResizingPointer(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    dynamic2DMatrixResizingPointerCleanup(matrix, rows);

    // EXERCISE 2: VECTOR
    std::vector<std::vector<double>> matrixVec =
        dynamic2DMatrixResizingVect(rows, cols);

    for (const std::vector<double>& row : matrixVec) {
        for (double value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
























