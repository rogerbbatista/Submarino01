#ifndef MATRIX_H
#define MATRIX_H

#include <bits/stdc++.h>

using namespace std;

class Matrix
{
private:
    vector<vector<double>> m;

public:
    int shape0;
    int shape1;

    Matrix();

    Matrix(int shape0, int shape1);

    Matrix(vector<vector<double>> &other);

    const Matrix dot(const Matrix &other) const;

    const Matrix multiply(const Matrix &other) const;

    const Matrix operator*(double value) const;

    const Matrix operator+(const Matrix &other) const;

    const Matrix operator-(const Matrix &other) const;

    vector<double> &operator[](int i);

    const vector<double> &operator[](int i) const;

    friend ostream& operator<< (ostream &out, const Matrix& m);

    friend const Matrix operator*(double value, Matrix &m);

    const Matrix T();
};

#endif //MATRIX_H