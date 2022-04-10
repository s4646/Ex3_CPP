#pragma once
#include <iostream>
#include <vector>
#define EPSILON 0.00000000000001

namespace zich
{
    class Matrix
    {
    private:
        int rows, columns;
        std::vector<double> matrix;

    public:
        Matrix(std::vector<double> vec, int rows, int columns);
        Matrix(const Matrix& other);
        ~Matrix();
        
        // addition
        friend Matrix operator+(const double& num, const Matrix& mat); // NUM + MAT
        Matrix operator+(const double& num); // MAT + NUM
        Matrix& operator+=(const double& num); // MAT += num
        Matrix operator+(const Matrix& mat); // MAT + MAT
        Matrix& operator+=(const Matrix& mat); // MAT += MAT
        Matrix operator++(int); // Postfix
        Matrix& operator++(); // Prefix
        Matrix operator+() const; // unary

        // substraction
        friend Matrix operator-(const double& num, const Matrix& mat); // NUM - MAT
        Matrix operator-(const double& num); // MAT - NUM
        Matrix& operator-=(const double& num); // MAT -= num
        Matrix operator-(const Matrix& mat); // MAT - MAT
        Matrix& operator-=(const Matrix& mat); // MAT -= MAT
        Matrix operator--(int); // Postfix
        Matrix& operator--(); // Prefix
        Matrix operator-() const; // unary
        
        // multiplication
        friend Matrix operator*(const double& num, const Matrix& mat); // NUM * MAT
        Matrix operator*(const Matrix& mat); // MAT * MAT
        Matrix operator*(const double& num); // MAT * NUM
        Matrix& operator*=(const double& num); // MAT *= NUM
        Matrix& operator*=(const Matrix& mat); // MAT *= MAT
        
        // compare
        bool operator==(const Matrix& mat) const;
        bool operator<=(const Matrix& mat) const;
        bool operator<(const Matrix& mat) const;
        bool operator>=(const Matrix& mat) const;
        bool operator>(const Matrix& mat) const;
        bool operator!=(const Matrix& mat) const;
        
        // insertion & extraction
        friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
        friend std::istream& operator>>(std::istream& is, Matrix& mat);

        // utils
        friend double matSum(const Matrix& mat);
    };
}