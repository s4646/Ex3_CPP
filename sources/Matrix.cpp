#include "Matrix.hpp"
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

vector<string> parser(string input, const string& delimiter);
bool validate(const string& str);

zich::Matrix::Matrix(vector<double> vec, int rows = 0, int columns = 0)
{
    if(vec.size() != rows*columns || rows<0 || columns<0)
    {
        throw invalid_argument("Invalid input");
    }
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
    // ADDITION
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

    // SUBSTRACTION 
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

    // MULTIPLICATION
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
                for (size_t k = 0; k < this->columns; k++)
                {
                    tempItem += this->matrix.at(i*(size_t)this->columns + k) * mat.matrix.at(k*(size_t)mat.columns + j);
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

    // COMPARE
    bool Matrix::operator==(const Matrix& mat) const // MAT == MAT
    {
        if(this->rows!= mat.rows || this->columns!= mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }
        unsigned int size = this->matrix.size();
        for (size_t i = 0; i < size; i++)
        {
            if(abs(this->matrix.at(i) - mat.matrix.at(i)) > EPSILON)
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
        return sum1 <= sum2;
    }

    bool Matrix::operator>=(const Matrix& mat) const // MAT >= MAT
    {
        if(this->rows!= mat.rows || this->columns!= mat.columns)
        {
            throw runtime_error("Matrices don't have the same size");
        }
        double sum1 = matSum(*this); double sum2 = matSum(mat);
        return sum1 >= sum2;
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

    // INPUT & OUTPUT
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
            os << (i!=(mat.rows-1) ? "]\n" : "]");
        }
            return os;
    }

    istream& operator>>(istream& is, Matrix& mat)
    {
        int rows = 0; int columns = 0;
        string input;
        getline(is, input);
        vector<double> matrix;
        // parse input into rows
        vector<string> splits = parser(input, ", ");
        rows = splits.size();
        for (size_t i = 0; i < splits.size(); i++)
        {
            // check for extra chars that are not numbers (except ' ')
            if(!validate(splits.at(i)))
            {
                throw invalid_argument("Invalid input");
            }
            // parse rows into numbers
            vector<string> temParse = parser(splits.at(i).substr(1,splits.at(i).size()-1)," ");
            columns = temParse.size();
            for (size_t j = 0; j < temParse.size(); j++)
            {
                if(temParse.at(j).empty())
                {
                    continue;
                }
                // convert string to double. stod throws exception if string is still illegal
                matrix.push_back(stod(temParse.at(j)));
            }
        }
        mat = Matrix(matrix, rows, columns);
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

vector<string> parser(string input, const string& delimiter)
{
    size_t pos = 0;
    std::string token;
    vector<string> splits;
    while ((pos = input.find(delimiter)) != std::string::npos)
    {
        token = input.substr(0, pos);
        splits.push_back(token);
        input.erase(0, pos + delimiter.size());
    }
    splits.push_back(input);
    return splits;
}

bool validate(const string& str)
{
    int leftMargains = 0; int rightMargains = 0; int commas = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if(str.at(i) == '[')
        {
            ++leftMargains;
        }
        if(str.at(i) == ']')
        {
            ++rightMargains;
        }
        if(str.at(i) == ',')
        {
            ++commas;
        }
    }
    return leftMargains == 1 && rightMargains == 1 && commas == 0;
}