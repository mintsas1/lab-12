#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 5;

void fillMatrix(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }
}

void showMatrix(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int sumPositiveRowElements(int row[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (row[i] > 0) {
            sum += row[i];
        }
    }
    return sum;
}

void matrixToArray(int matrix[][SIZE], int array[], int size) {
    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            array[index++] = matrix[i][j];
        }
    }
}

int findMaxElement(int array[], int size) {
    int maxElement = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    return maxElement;
}

int main() {
    srand(time(nullptr));
    int matrix[SIZE][SIZE];
    fillMatrix(matrix);
    cout << "Matrix:" << endl;
    showMatrix(matrix);

    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (sumPositiveRowElements(matrix[i], SIZE) > 0) {
            sum += sumPositiveRowElements(matrix[i], SIZE);
        }
    }
    cout << "Sum of elements in rows with positive numbers: " << sum << endl;

    int array[SIZE * SIZE];
    matrixToArray(matrix, array, SIZE * SIZE);

    int maxElement = findMaxElement(array, SIZE * SIZE);
    cout << "The maximum element in a one-dimensional array: " << maxElement << endl;

    return 0;
}