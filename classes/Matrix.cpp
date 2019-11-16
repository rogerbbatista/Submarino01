#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <bits/stdc++.h>
#include "Matrix.h"

using namespace std;

Matrix::Matrix() {}

Matrix::Matrix(int shape0, int shape1)
{
    m = vector<vector<double>>(shape0, vector<double>(shape1));
    this->shape0 = shape0;
    this->shape1 = shape1;
}

Matrix::Matrix(vector<vector<double>> &other)
{
    this->m = other;
    this->shape0 = other.size();
    this->shape1 = other[0].size();
}

const Matrix Matrix::dot(const Matrix &other) const
{
    if (this->shape1 != other.shape0)
    {
        cerr << "(" << this->shape0 << "," << this->shape1 << ") x (";
        cerr << other.shape0 << "," << other.shape1 << ")\n";

        throw "Dimensões não compativeis";
    }

    auto result = vector<vector<double>>(this->shape0, vector<double>(other.shape1));

    for (int i = 0; i < this->shape0; i++)
    {
        for (int k = 0; k < other.shape0; k++)
        {
            for (int j = 0; j < other.shape1; j++)
            {
                result[i][j] += this->m[i][k] * other.m[k][j];
            }
        }
    }

    return result;
}

const Matrix Matrix::multiply(const Matrix &other) const
{
    if (this->shape0 != other.shape0 || this->shape1 != other.shape1)
    {
        cerr << "(" << this->shape0 << "," << this->shape1 << ") * (";
        cerr << other.shape0 << "," << other.shape1 << ")\n";

        throw "Dimensões não compativeis";
    }

    auto result = vector<vector<double>>(this->shape0, vector<double>(other.shape1));

    for (int i = 0; i < this->shape0; i++)
    {
        for (int j = 0; j < this->shape1; j++)
        {
            result[i][j] = this->m[i][j] * other.m[i][j];
        }
    }
    
    return result;
}

const Matrix Matrix::operator*(double value) const
{
    auto result = vector<vector<double>>(this->shape0, vector<double>(this->shape1));

    for (int i = 0; i < this->shape0; i++)
    {
        for (int j = 0; j < this->shape1; j++)
        {
            result[i][j] = this->m[i][j] * value;
        }
    }
    
    return result;
}

const Matrix Matrix::operator+(const Matrix &other) const
{
    if (this->shape0 != other.shape0 || this->shape1 != other.shape1)
    {
        cerr << "(" << this->shape0 << "," << this->shape1 << ") + (";
        cerr << other.shape0 << "," << other.shape1 << ")\n";

        throw "Dimensões não compativeis";
    }

    auto result = vector<vector<double>>(this->shape0, vector<double>(other.shape1));

    for (int i = 0; i < this->shape0; i++)
    {
        for (int j = 0; j < this->shape1; j++)
        {
            result[i][j] = this->m[i][j] + other.m[i][j];
        }
    }
    
    return result;
}

const Matrix Matrix::operator-(const Matrix &other) const
{
    if (this->shape0 != other.shape0 || this->shape1 != other.shape1)
    {
        cerr << "(" << this->shape0 << "," << this->shape1 << ") - (";
        cerr << other.shape0 << "," << other.shape1 << ")\n";

        throw "Dimensões não compativeis";
    }

    auto result = vector<vector<double>>(this->shape0, vector<double>(other.shape1));

    for (int i = 0; i < this->shape0; i++)
    {
        for (int j = 0; j < this->shape1; j++)
        {
            result[i][j] = this->m[i][j] - other.m[i][j];
        }
    }
    
    return result;
}

vector<double>& Matrix::operator[](int i)
{
    return this->m[i];
}

const vector<double>& Matrix::operator[](int i) const
{
    return this->m[i];
}

#endif //MATRIX_CPP