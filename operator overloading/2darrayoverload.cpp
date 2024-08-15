#include <iostream>
using namespace std;

class Matrix
{
private:
    int arr[2][2];

public:
    // Default constructor
    Matrix();

    // Parameterized constructor
    Matrix(int inputArr[2][2]);

    // Overloaded addition operator
    Matrix operator+(Matrix &obj);

    // Overloaded negation operator to calculate determinant
    int operator!();

    // Overloaded output stream operator
    friend ostream &operator<<(ostream &output, const Matrix &obj);

    // Overloaded input stream operator
    friend istream &operator>>(istream &input, Matrix &obj);
};

Matrix::Matrix()
{
    // Initialize array elements to 0
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr[i][j] = 0;
        }
    }
}

Matrix::Matrix(int inputArr[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr[i][j] = inputArr[i][j];
        }
    }
}

Matrix Matrix::operator+(Matrix &obj)
{
    Matrix temp;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            temp.arr[i][j] = arr[i][j] + obj.arr[i][j];
        }
    }
    return temp;
}

int Matrix::operator!()
{
    int determinant = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
    return determinant;
}

ostream &operator<<(ostream &output, const Matrix &obj)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            output << obj.arr[i][j] << ' ';
        }
        output << endl;
    }
    return output;
}

istream &operator>>(istream &input, Matrix &obj)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            input >> obj.arr[i][j];
        }
    }
    return input;
}

int main()
{
    Matrix mat1, mat2, mat3;
    cout << "Enter elements of first 2x2 matrix:" << endl;
    cin >> mat1;
    cout << "Enter elements of second 2x2 matrix:" << endl;
    cin >> mat2;

    mat3 = mat1 + mat2;

    cout << "Matrix 1:" << endl
         << mat1;
    cout << "Matrix 2:" << endl
         << mat2;
    cout << "Sum of Matrix 1 and Matrix 2:" << endl
         << mat3;
    cout << "Determinant of the sum matrix: " << !mat3 << endl;

    return 0;
}
