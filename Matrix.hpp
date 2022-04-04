#pragma once
#include <iostream>
#include <vector>

namespace zich
{
    class Matrix
    {
    private:
        int rows, columns;
        std::vector<std::vector<double>> matrix;

    public:
        Matrix(std::vector<double> vec, int rows, int columns);
        Matrix(const Matrix& other);
         ~Matrix();
        
        // addition
        friend Matrix operator+(const double& num, const Matrix& mat); // NUM + MAT
        Matrix operator+(const Matrix& mat); // MAT + MAT
        Matrix operator+(const double& num); // MAT + NUM
        Matrix& operator+=(const double& num); // MAT += NUM
        const Matrix operator++(int); // Postfix
        Matrix& operator++(); // Prefix
        Matrix operator+() const; // unary

        // substraction
        friend Matrix operator-(const double& num, const Matrix& mat); // NUM - MAT
        Matrix operator-(const Matrix& mat); // MAT - MAT
        Matrix operator-(const double& num); // MAT - NUM
        Matrix& operator-=(const double& num); // MAT -= NUM
        const Matrix operator--(int); // Postfix
        Matrix& operator--(); // Prefix
        Matrix operator-() const; // unary
        
        // multiplication
        friend Matrix operator*(const double& num, const Matrix& mat); // NUM * MAT
        Matrix operator*(const Matrix& mat); // MAT * MAT
        Matrix operator*(const double& num); // MAT * NUM
        Matrix& operator*=(const double& num); // MAT *= NUM
        
        // division
        friend Matrix operator/(const double& num, const Matrix& mat); // NUM / MAT
        Matrix operator/(const double& num); // MAT / NUM
        Matrix& operator/=(const double& num); // MAT /= NUM
        
        // compare
        bool operator==(const Matrix& mat) const;
        bool operator<=(const Matrix& mat) const;
        bool operator>=(const Matrix& mat) const;
        
        // extraction
        friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
    };
}