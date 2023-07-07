#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int columns;

public:
    Matrix(int rows, int columns) : rows(rows), columns(columns) {
        data.resize(rows, std::vector<int>(columns, 0));
    }

    void setData() {
        std::cout << "Enter matrix elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cin >> data[i][j];
            }
        }
    }

    void displayData() {
        std::cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            throw std::runtime_error("Matrix sizes are incompatible for addition.");
        }

        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (columns != other.rows) {
            throw std::runtime_error("Matrix sizes are incompatible for multiplication.");
        }

        Matrix result(rows, other.columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                for (int k = 0; k < columns; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result(columns, rows);
        for (int i = 0; i < columns; i++) {
            for (int j = 0; j < rows; j++) {
                result.data[i][j] = data[j][i];
            }
        }
        return result;
    }
};

int main() {
    int rows1, columns1;
    std::cout << "Enter the number of rows for matrix 1: ";
    std::cin >> rows1;
    std::cout << "Enter the number of columns for matrix 1: ";
    std::cin >> columns1;

    Matrix matrix1(rows1, columns1);
    matrix1.setData();

    int rows2, columns2;
    std::cout << "Enter the number of rows for matrix 2: ";
    std::cin >> rows2;
    std::cout << "Enter the number of columns for matrix 2: ";
    std::cin >> columns2;

    Matrix matrix2(rows2, columns2);
    matrix2.setData();

    try {
        Matrix sum = matrix1 + matrix2;
        std::cout << "Sum of the matrices:\n";
        sum.displayData();
    } catch (const std::runtime_error& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }

    try {
        Matrix product = matrix1 * matrix2;
        std::cout << "Product of the matrices:\n";
        product.displayData();
    } catch (const std::runtime_error& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }

    std::cout << "Transpose of matrix 1:\n";
    Matrix transpose = matrix1.transpose();
    transpose.displayData();

    return 0;
}
