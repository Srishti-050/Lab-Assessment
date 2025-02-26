#include <iostream>
using namespace std;

class Matrix {
private:
    int mat[2][2];

public:
    Matrix(int arr[2][2]) { 
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                mat[i][j] = arr[i][j]; 
    }

    Matrix add(const Matrix& other) {
        int result[2][2];
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                result[i][j] = mat[i][j] + other.mat[i][j];
        return Matrix(result);
    }

    Matrix subtract(const Matrix& other) {
        int result[2][2];
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                result[i][j] = mat[i][j] - other.mat[i][j];
        return Matrix(result);
    }

    Matrix multiply(const Matrix& other) {
        int result[2][2] = {0};  
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                for (int k = 0; k < 2; k++) 
                    result[i][j] += mat[i][k] * other.mat[k][j];
        return Matrix(result);
    }

    void display() {
        for (int i = 0; i < 2; i++, cout << endl) 
            for (int j = 0; j < 2; j++) 
                cout << mat[i][j] << " ";
    }
};

int main() {
    int sample1[2][2] = {{1, 2}, {3, 4}};
    int sample2[2][2] = {{5, 6}, {7, 8}};

    Matrix matrix1(sample1), matrix2(sample2);

    cout << "Matrix 1:\n"; matrix1.display();
    cout << "Matrix 2:\n"; matrix2.display();

    cout << "Addition:\n"; matrix1.add(matrix2).display();
    cout << "Subtraction:\n"; matrix1.subtract(matrix2).display();
    cout << "Multiplication:\n"; matrix1.multiply(matrix2).display();

    return 0;
}

