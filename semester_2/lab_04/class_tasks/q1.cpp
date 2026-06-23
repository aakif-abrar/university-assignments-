#include<iostream>
#include<string>
using namespace std;
class Matrix
{
    private:
    int rows,cols;
    public:
    double** arr;
    Matrix(){
        rows=0;
        cols=0;
        arr=nullptr;
    } 
    Matrix(int r,int c):rows(r),cols(c){
        arr=new double*[rows];
        for(int i=0;i<rows;i++)
        arr[i]=new double[cols];
    }
    ~Matrix()
    {
        for(int i=0;i<rows;i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    Matrix(Matrix &mat2):rows(mat2.rows),cols(mat2.cols)
    {
        arr=new double*[rows];
        for(int i=0;i<rows;i++)
        {
            arr[i]=new double[cols];
            for(int j=0;j<cols;j++)
            {
                arr[i][j]=mat2.arr[i][j];
            }
        }
    }
    Matrix(Matrix &&mat3) noexcept : rows(mat3.rows), cols(mat3.cols), arr(mat3.arr)
    {
        mat3.rows=0;
        mat3.cols=0;
        mat3.arr=nullptr;
    }
    int GetRows()
    {
        return rows;
    }
    int GetCols()
    {
        return cols;
    }
    void fill(double value)
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                arr[i][j]=value;
            }
        }
    }
    Matrix transpose(){
        Matrix transpose(cols, rows);
    
        cout<<"Transpose of Matrix:\n";
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                transpose.arr[j][i] = arr[i][j];
            }
        }
        for(int i = 0; i < cols; i++)
        {
            for(int j = 0; j < rows; j++) 
            {
                cout << transpose.arr[i][j] << " ";
            }
            cout << endl;
        }
    
        return transpose;
    }
    double& at(int r,int c)
    {
        return arr[r][c];
    }
    void print()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    int rows,cols;
    cout<<"Enter number of rows of the matrix: ";
    cin>>rows;
    cout<<"Enter number of columns of the matrix: ";
    cin>>cols;
    Matrix mat1(rows,cols);
    double value;
    int j=0;
    for(int i=0;i<mat1.GetRows();i++)
    {
        for(int j=0;j<mat1.GetCols();j++)
        {
            cout << "Enter element(" << i << "," << j << "): ";
            cin >> value;
            mat1.at(i, j) = value;
        }
    }
    cout<<"Original Array: \n";
    mat1.print();
    mat1.transpose();
    Matrix mat2 = mat1;
    cout << "\nCopied Matrix (mat2):\n";
    for(int i=0;i<mat2.GetRows();i++)
    {
        for(int j=0;j<mat2.GetCols();j++)
        mat2.arr[i][j]*=i+j;
    }
    mat2.print();
    mat2.transpose();
    Matrix mat3 = move(mat1);
    for(int i=0;i<mat3.GetRows();i++)
    {
        for(int j=0;j<mat3.GetCols();j++)
        mat3.arr[i][j]+=i+j;
    }
    cout << "\nMoved Matrix (mat3):\n";
    mat3.print();
    mat3.transpose();
}
