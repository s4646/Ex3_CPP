#include "Matrix.hpp"
#include <stdexcept>

using namespace std;

zich::Matrix::Matrix(vector<double> vec, int rows = 0, int columns = 0)
{
    this->rows = rows;
    this->columns = columns;
    this->matrix = vector<double>(std::move(vec));
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
    Matrix Matrix::operator+(const double& num) // MAT + NUM
    {
        Matrix newMat(*this);
        unsigned int size = newMat.matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) += num;
        }
        return newMat;
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
    Matrix operator+(const double& num, const Matrix& mat) // NUM + MAT
    {
        Matrix newMat(mat);
        newMat + num;
        return newMat;
    }
    Matrix Matrix::operator+(const Matrix& mat) // MAT + MAT
    {
        if(this->rows!= mat.rows || this->columns !=mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }

        Matrix newMat(*this);
        newMat += mat;
        return newMat;
    }
    Matrix& Matrix::operator+=(const Matrix& mat) // MAT += MAT
    {
        if(this->rows!= mat.rows || this->columns !=mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }

        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            this->matrix.at(i) += mat.matrix.at(i);
        }
        return *this;
    }
    Matrix Matrix::operator++(int) // Postfix
    {
        Matrix temp = *this;
        ++*this;
        return temp;
    }
    Matrix& Matrix::operator++() // Prefix
    {
        *this += 1;
        return *this;
    }
    Matrix Matrix::operator+() const // unary
    {
        Matrix newMat(*this);
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) = +this->matrix.at(i);
        }
        return newMat;
    }

    // substraction
        Matrix Matrix::operator-(const double& num) // MAT - NUM
    {
        Matrix newMat(*this);
        unsigned int size = newMat.matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            newMat.matrix.at(i) -= num;
        }
        return newMat;
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
    Matrix operator-(const double& num, const Matrix& mat) // NUM - MAT
    {
        Matrix newMat(mat);
        -(newMat - num);
        return newMat;
    }
    Matrix Matrix::operator-(const Matrix& mat) // MAT - MAT
    {
        if(this->rows!= mat.rows || this->columns !=mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }

        Matrix newMat(*this);
        newMat -= mat;
        return newMat;
    }
    Matrix& Matrix::operator-=(const Matrix& mat) // MAT -= MAT
    {
        if(this->rows!= mat.rows || this->columns !=mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }

        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            this->matrix.at(i) -= mat.matrix.at(i);
        }
        return *this;
    }
    Matrix Matrix::operator--(int) // Postfix
    {
        Matrix temp = *this;
        --*this;
        return temp;
    }
    Matrix& Matrix::operator--() // Prefix
    {
        *this -= 1;
        return *this;
    }
    Matrix Matrix::operator-() const // unary
    {
        Matrix newMat(*this);
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            if (newMat.matrix.at(i) == 0)
            {
                continue;
            }
            newMat.matrix.at(i) = -this->matrix.at(i);
        }
        return newMat;
    }

    // multiplication
    Matrix operator*(const double& num, const Matrix& mat) // NUM * MAT
    {
        Matrix newMat(mat);
        newMat *= num;
        return newMat;
    }
    Matrix Matrix::operator*(const double& num) // MAT * NUM
    {
        Matrix newMat(*this);
        newMat *= num;
        return newMat;
    }
    Matrix Matrix::operator*(const Matrix& mat) // MAT * MAT
    {
        if(this->columns!= mat.rows)
        {
            throw runtime_error("Matrices don't have the same size");
        }
        vector<double> mul;
        double tempItem = 0;

        for (size_t i = 0; i < this->rows; i++)
        {
           
            for (size_t j = 0; j < mat.columns; j++)
            {
                tempItem = 0;
                for (size_t k = 0; k < mat.columns; k++)
                {
                   tempItem += this->matrix.at(i*(size_t)this->columns + k) * mat.matrix.at(k*(size_t)mat.rows + j);
                }
                mul.push_back(tempItem);
            }
        }  
        return Matrix(mul,this->rows, mat.columns);
    }
    Matrix& Matrix::operator*=(const Matrix& mat) // MAT * MAT
    {
        *this = *this * mat;
        return *this;
    }
    Matrix& Matrix::operator*=(const double& num) // MAT *= NUM
    {
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            this->matrix.at(i) *= num;
        }
        return *this;
    }

    // division
    Matrix operator/(const double& num, const Matrix& mat) // NUM / MAT
    {
        if (num == 0)
        {
            throw runtime_error("Cannot divide by 0");
        }
        return (1/num) * mat;
    }
    Matrix Matrix::operator/(const double& num) // MAT / NUM
    {
        if (num == 0)
        {
            throw runtime_error("Cannot divide by 0");
        }
        return *this * (1/num);
    }
    Matrix& Matrix::operator/=(const double& num) // MAT /= NUM
    {
        if (num == 0)
        {
            throw runtime_error("Cannot divide by 0");
        }
        return *this *= (1/num);
    }

    // compare
    bool Matrix::operator==(const Matrix& mat) const // MAT == MAT
    {
        if(this->rows!= mat.rows || this->columns!= mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            if(this->matrix.at(i) - mat.matrix.at(i) > EPSILON)
            {
                return false;
            }
        }
        return true;
    }
    bool Matrix::operator<=(const Matrix& mat) const // MAT <= MAT
    {
        if(this->rows!= mat.rows || this->columns!= mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }
        double sum1 = matSum(*this); double sum2 = matSum(mat);
        return sum1 < sum2;
    }
    bool Matrix::operator>=(const Matrix& mat) const // MAT >= MAT
    {
        if(this->rows!= mat.rows || this->columns!= mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }
        double sum1 = matSum(*this); double sum2 = matSum(mat);
        return sum1 > sum2;
    }
    bool Matrix::operator!=(const Matrix& mat) const // MAT != MAT
    {
        if(this->rows!= mat.rows || this->columns!= mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }
        return !(*this == mat);
    }
    bool Matrix::operator<(const Matrix& mat) const // MAT < MAT
    {
        if(this->rows!= mat.rows || this->columns!= mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }
        double sum1 = matSum(*this); double sum2 = matSum(mat);
        return sum1 < sum2;
    }
    bool Matrix::operator>(const Matrix& mat) const // MAT > MAT
    {
        if(this->rows!= mat.rows || this->columns!= mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }
        double sum1 = matSum(*this); double sum2 = matSum(mat);
        return sum1 > sum2;
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
    istream& operator>>(istream& is, Matrix& mat)
    {
        return is;   
    }

    // utils
    double matSum(const Matrix& mat)
    {
        unsigned int size = mat.matrix.size();
        double sum = 0;
        for (size_t i = 0; i < size; i++)
        {
            sum += mat.matrix.at(i);
        }
        return sum;
    }
}