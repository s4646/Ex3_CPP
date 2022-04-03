#include "Matrix.hpp"
#include <string>

using namespace std;
using namespace zich;

Matrix::Matrix(vector<double> vec, int rows = 0, int columns = 0)
{
    this->rows = rows;
    this->columns = columns;
    for (size_t i = 0; i < this->rows; i++)
    {
        vector<double> temp;
        for (size_t j = i*(size_t)this->columns; j < (i+1)*(size_t)this->columns; j++)
        {
            temp.push_back(vec.at(j));
        }
        this->matrix.push_back(temp);
    }
}
Matrix::Matrix(const Matrix& other)
{
    this->rows = other.rows;
    this->columns = other.columns;
    for (size_t i = 0; i < this->rows; i++)
    {
        vector<double> vec(other.matrix.at(i));
        this->matrix.push_back(vec);
    }
}
Matrix::~Matrix() {};

// addition
Matrix operator+(const double& num, const Matrix& mat) // NUM + MAT
{
    vector<double> temp;
    return Matrix{temp, 0, 0};
}
Matrix Matrix::operator+(const Matrix& mat) // MAT + MAT
{
    return *this;
}
Matrix Matrix::operator+(const double& num) // MAT + NUM
{
    return *this;
}
Matrix& Matrix::operator+=(const double& num) // MAT += NUM
{
    return *this;
}
Matrix Matrix::operator++(int) const// Postfix
{
    return *this;
}
Matrix& Matrix::operator++() // Prefix
{
    return *this;
}
Matrix Matrix::operator+() const // unary
{
    return *this;
}

// substraction
Matrix operator-(const double& num, const Matrix& mat) // NUM - MAT
{
    vector<double> temp;
    return Matrix{temp, 0, 0};
}
Matrix Matrix::operator-(const Matrix& mat) // MAT - MAT
{
    return *this;
}
Matrix Matrix::operator-(const double& num) // MAT - NUM
{
    return *this;
}
Matrix& Matrix::operator-=(const double& num) // MAT -= NUM
{
    return *this;
}
Matrix Matrix::operator--(int) const// Postfix
{
    return *this;
}
Matrix& Matrix::operator--() // Prefix
{
    return *this;
}
Matrix Matrix::operator-() const // unary
{
    return *this;
}

// multiplication
Matrix zich::operator*(const double& num, const Matrix& mat) // NUM * MAT
{
    vector<double> temp;
    return Matrix{temp, 0, 0};
} 
Matrix Matrix::operator*(const Matrix& mat) // MAT * MAT
{
    return *this;
}
Matrix Matrix::operator*(const double& num) // MAT * NUM
{
    return *this;
}
Matrix& Matrix::operator*=(const double& num) // MAT *= NUM
{
    return *this;
}

// division
Matrix zich::operator/(const double& num, const Matrix& mat) // NUM / MAT
{
    vector<double> temp;
    return Matrix{temp, 0, 0};
}
Matrix Matrix::operator/(const double& num) // MAT / NUM
{
    return *this;
}
Matrix& Matrix::operator/=(const double& num) // MAT /= NUM
{
    return *this;
}

// input & output
ostream& zich::operator<<(ostream& os, const Matrix& mat)
{
    string out;
    for (size_t i = 0; i < mat.rows; i++)
    {
        out += '[';
        for (size_t j = 0; j < mat.columns; j++)
        {
            out += mat.matrix.at(i).at(j) + ' ';
        }
        out += "]\n";
    }
    os << out << endl;
    return os;
}