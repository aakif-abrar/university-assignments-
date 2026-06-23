#include <iostream>
#include <vector>
using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimensions do not match.";
    }
};

template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int rows, cols;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data.resize(r, vector<T>(c));
    }

    T& at(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw out_of_range("Index out of bounds");
        return data[i][j];
    }

    Matrix operator+(const Matrix& m) {
        if (rows != m.rows || cols != m.cols)
            throw DimensionMismatchException();

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& m) {
        if (cols != m.rows)
            throw DimensionMismatchException();

        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < m.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
        return result;
    }

    void print() {
        for (auto& row : data) {
            for (auto& val : row)
                cout << val << " ";
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A.at(0, 0) = 1; A.at(0, 1) = 2;
        A.at(1, 0) = 3; A.at(1, 1) = 4;

        B.at(0, 0) = 5; B.at(0, 1) = 6;
        B.at(1, 0) = 7; B.at(1, 1) = 8;

        Matrix<int> sum = A + B;
        Matrix<int> product = A * B;

        cout << "Matrix A + B:\n";
        sum.print();

        cout << "Matrix A * B:\n";
        product.print();

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
