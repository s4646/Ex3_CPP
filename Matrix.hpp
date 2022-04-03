#include <vector>

namespace zich
{
    class Matrix
    {
    private:
        int rows, columns;
        std::vector<std::vector<double>> matrix;
    
    // ADD ++ AND -- PREFIX AND SUFFIX
    public:
        Matrix(std::vector<double> vec, int rows, int columns);
         ~Matrix();
        // addition
        Matrix operator+(const Matrix& mat); // MAT + MAT
        friend Matrix operator+(const double& num, const Matrix& mat); // NUM + MAT
        Matrix operator+(const double& num); // MAT + NUM
        Matrix& operator+=(const double& num); // MAT += NUM
        Matrix operator+() const; // unary
        // multiplication
        Matrix operator*(const Matrix& mat); // MAT * MAT
        friend Matrix operator*(const double& num, const Matrix& mat); // NUM * MAT
        Matrix operator*(const double& num); // MAT * NUM
        Matrix& operator*=(const double& num); // MAT *= NUM
        // substraction
        Matrix operator-(const Matrix& mat); // MAT - MAT
        friend Matrix operator-(const double& num, const Matrix& mat); // NUM - MAT
        Matrix operator-(const double& num); // MAT - NUM
        Matrix& operator-=(const double& num); // MAT -= NUM
        Matrix operator-() const; // unary
        // division
        Matrix operator/(const double& num); // MAT / NUM
        friend Matrix operator/(const double& num, const Matrix& mat); // NUM / MAT
        Matrix& operator/=(const double& num); // MAT /= NUM
        // input output
        friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
        friend std::istream& operator>>(std::istream& os, const Matrix& mat);
    };
}