#include "Matrix.hpp"
#include <string>

using namespace std;

zich::Matrix::Matrix(vector<double> vec, int rows = 0, int columns = 0)
{
    this->rows = rows;
    this->columns = columns;
    this->matrix = vector<double>(vec);
}
zich::Matrix::Matrix(const Matrix& other)
{
    this->rows = other.rows;
    this->columns = other.columns;
    this->matrix = vector<double>(other.matrix);
}
zich::Matrix::~Matrix() {};

namespace zich
{
    // addition
    Matrix operator+(const double& num, const Matrix& mat) // NUM + MAT
    {
        Matrix newMat(mat.matrix, mat.rows, mat.columns);
        unsigned int size = newMat.matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) += num;
        }
        return newMat;
    }
    Matrix Matrix::operator+(const Matrix& mat) // MAT + MAT
    {
        Matrix newMat(this->matrix, this->rows, this->columns);
        unsigned int rowSize = newMat.matrix.size();
        newMat += mat;
        return newMat;
    }

    Matrix Matrix::operator+(const double& num) // MAT + NUM
    {
        Matrix newMat(this->matrix,this->rows,this->columns);
        unsigned int size = newMat.matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) += num;
        }
        return newMat;
    }
    Matrix& Matrix::operator+=(const Matrix& mat) // MAT += MAT
    {
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            this->matrix.at(i) += mat.matrix.at(i);
        }
        return *this;
    }
    Matrix& Matrix::operator+=(const double& num) // MAT += NUM
    {
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            this->matrix.at(i) += num;
        }
        return *this;
    }
    const Matrix Matrix::operator++(int)// Postfix
    {
        Matrix newMat(this->matrix, this->rows, this->columns);
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) += 1;
        }
        return newMat;
    }
    Matrix& Matrix::operator++() // Prefix
    {
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            this->matrix.at(i) += 1;
        }
        return *this;
    }
    Matrix Matrix::operator+() const // unary
    {
        Matrix newMat(this->matrix, this->rows, this->columns);
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) = +this->matrix.at(i);
        }
        return newMat;
    }

    // substraction
        Matrix operator-(const double& num, const Matrix& mat) // NUM - MAT
    {
        Matrix newMat(mat.matrix, mat.rows, mat.columns);
        unsigned int size = newMat.matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) -= num;
        }
        return newMat;
    }
    Matrix Matrix::operator-(const Matrix& mat) // MAT - MAT
    {
        Matrix newMat(this->matrix, this->rows, this->columns);
        unsigned int rowSize = newMat.matrix.size();
        newMat -= mat;
        return newMat;
    }

    Matrix Matrix::operator-(const double& num) // MAT - NUM
    {
        Matrix newMat(this->matrix,this->rows,this->columns);
        unsigned int size = newMat.matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) += num;
        }
        return newMat;
    }
    Matrix& Matrix::operator-=(const Matrix& mat) // MAT -= MAT
    {
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            this->matrix.at(i) -= mat.matrix.at(i);
        }
        return *this;
    }
    Matrix& Matrix::operator-=(const double& num) // MAT -= NUM
    {
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            this->matrix.at(i) -= num;
        }
        return *this;
    }
    const Matrix Matrix::operator--(int)// Postfix
    {
        Matrix newMat(this->matrix, this->rows, this->columns);
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) -= 1;
        }
        return newMat;
    }
    Matrix& Matrix::operator--() // Prefix
    {
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            this->matrix.at(i) -= 1;
        }
        return *this;
    }
    Matrix Matrix::operator-() const // unary
    {
        Matrix newMat(this->matrix, this->rows, this->columns);
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) = -this->matrix.at(i);
        }
        return newMat;
    }

    // multiplication
    Matrix operator*(const double& num, const Matrix& mat) // NUM * MAT
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
    Matrix operator/(const double& num, const Matrix& mat) // NUM / MAT
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

    // compare
    bool Matrix::operator==(const Matrix& mat) const
    {
        return true;
    }
    bool Matrix::operator<=(const Matrix& mat) const
    {
        return true;
    }
    bool Matrix::operator>=(const Matrix& mat) const
    {
        return true;
    }

    // input & output
    ostream& operator<<(ostream& os, const Matrix& mat)
    {
        for (size_t i = 0; i < mat.rows; i++)
        {
            os << '[';
            for (size_t j = 0; j < mat.columns; j++)
            {
                os << mat.matrix.at(i*(unsigned int)mat.columns+j);
                if(j != mat.columns-1)
                {
                    os << ' ';
                }
            }
            os << "]\n";
        }
            return os;
    }
}