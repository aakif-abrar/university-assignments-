#include <iostream>
#include <string>
using namespace std;
class Matrix
{
private:
    int rows, cols;
    int **arr;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        arr = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    int getRows()
    {
        return rows;
    }
    int getCols()
    {
        return cols;
    }
    void setElement(int i, int j, int val)
    {
        arr[i][j] = val;
    }
    void add(Matrix &m2)
    {
        if (rows != m2.rows || cols != m2.cols)
        {
            cout << "Sum cannot be done!" << endl;
            return;
        }
        else
        {
            cout << "Sum of two matrices is: " << endl;
            Matrix result(rows, cols);
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result.arr[i][j] = arr[i][j] + m2.arr[i][j];
                    cout << result.arr[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    void multiply(const Matrix &m2)
    {
        if (cols != m2.rows)
        {
            cout << "Matrices cannot be multiplied" << endl;
            return;
        }
        Matrix result(rows, m2.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m2.cols; j++)
            {
                result.arr[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    result.arr[i][j] += arr[i][k] * m2.arr[k][j];
                }
                cout<<result.arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    int r1,c1,val1;
    cout<<"Enter number of rows for Matrix 1: ";
    cin>>r1;
    cout<<"Enter number of cols for Matrix 1: ";
    cin>>c1;
    cout<<endl;
    Matrix m1(r1,c1);
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            cout<<"Element "<<"("<<i<<","<<j<<")"<<"(Matrix 1): ";
            cin>>val1;
            m1.setElement(i,j,val1);
        }
    }
    cout<<endl;

    int r2,c2,val2;
    cout<<"Enter number of rows for Matrix 2: ";
    cin>>r2;
    cout<<"Enter number of cols for Matrix 2: ";
    cin>>c2;
    cout<<endl;
    Matrix m2(r2,c2);
    for(int i=0;i<r2;i++)
    {
        for(int j=0;j<c2;j++)
        {
            cout<<"Element "<<"("<<i<<","<<j<<")"<<"(Matrix 2): ";
            cin>>val2;
            m2.setElement(i,j,val2);
        }
    }
    cout<<"Addition: "<<endl;
    m1.add(m2);
    cout<<endl;
    cout<<"Matrix1 X Matrix2: "<<endl;
    m1.multiply(m2);
    cout<<endl;
    cout<<"Matrix2 X Matrix1: "<<endl;
    m2.multiply(m1);
}
