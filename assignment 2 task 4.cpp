#include <iostream>
#include <stdexcept>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    // Default Constructor
    Matrix() : rows(0), cols(0), data(nullptr) {}

    // Parameterized Constructor
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    // Deep Copy Constructor
    Matrix(const Matrix& m) : rows(m.rows), cols(m.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = m.data[i][j];
            }
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Overloading assignment operator '='
    Matrix& operator=(const Matrix& m) {
        if (this != &m) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
            rows = m.rows;
            cols = m.cols;
            data = new int*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    data[i][j] = m.data[i][j];
                }
            }
        }
        return *this;
    }

    // Overloading subscript operator '[]'
    int* operator[](int row) {
        if (row < 0 || row >= rows) {
            throw out_of_range("Row index out of range");
        }
        return data[row];
    }

    // Friend function for input using '>>' operator
    friend istream& operator>>(istream& is, Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                is >> m.data[i][j];
            }
        }
        return is;
    }

    // Friend function for output using '<<' operator
    friend ostream& operator<<(ostream& os, const Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                os << m.data[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    // Transpose function
    void transpose() {
        Matrix temp(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp.data[j][i] = data[i][j];
            }
        }
        *this = temp;
    }

    // Overloading '+' operator for matrix addition
    Matrix operator+(const Matrix& m) {
        if (rows != m.rows || cols != m.cols) {
            throw invalid_argument("Matrix dimensions do not match");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return result;
    }

    // Non-member function for overloading '*' operator for scalar multiplication
    friend Matrix operator*(const Matrix& m, int scalar) {
        Matrix result(m.rows, m.cols);
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.data[i][j] = m.data[i][j] * scalar;
            }
        }
        return result;
    }

    // Non-member function for overloading '-' operator for scalar subtraction
    friend Matrix operator-(int scalar, const Matrix& m) {
        Matrix result(m.rows, m.cols);
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.data[i][j] = scalar - m.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    Matrix m1(2, 2);
    Matrix m2(2, 2);

    cout << "Enter matrix 1:" << endl;
    cin >> m1;

    cout << "Enter matrix 2:" << endl;
    cin >> m2;

    cout << "Matrix 1:" << endl;
    cout << m1 << endl;

    cout << "Matrix 2:" << endl;
    cout << m2 << endl;

    Matrix m3 = m1 + m2;
    cout << "Matrix 1 + Matrix 2:" << endl;
    cout << m3 << endl;

    Matrix m4 = m1 * 2;
    cout << "Matrix 1 * 2:" << endl;
    cout << m4 << endl;

    Matrix m5 = 3 - m1;
    cout << "3 - Matrix 1:" << endl;
    cout << m5 << endl;

    m1.transpose();
    cout << "Matrix 1 transposed:" << endl;
    cout << m1 << endl;

    return 0;
}