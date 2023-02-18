#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix
{
private:
    vector<vector<int>> vec;
    int num_rows;
    int num_cols;

public:
    Matrix()
    {
        num_rows = 0;
        num_cols = 0;
    };

    Matrix(int num_rows, int num_cols) { Reset(num_rows, num_cols); };

    void Reset(int num_rows, int num_cols)
    {
        if (num_rows < 0)
        {
            throw out_of_range("out_of_range");
        }
        if (num_cols < 0)
        {
            throw out_of_range("out_of_range");
        }
        if (num_rows == 0 || num_cols == 0)
        {
            num_rows = num_cols = 0;
        }

        this->num_cols = num_cols;
        this->num_rows = num_rows;

        vec.assign(num_rows, vector<int>(num_cols));
    }

    int At(int num_rows, int num_cols) const
    {
        if (num_rows >= vec.size() || num_cols >= vec[0].size() || num_rows < 0 || num_cols < 0)
        {
            throw out_of_range("Must be >=0");
        }
        return vec[num_rows][num_cols];
    }

    int& At(int num_rows, int num_cols)
    {
        if (num_rows >= vec.size() || num_cols >= vec[1].size() || num_rows < 0 || num_cols < 0)
        {
            throw out_of_range("Must be >=0");
        }
        return vec[num_rows][num_cols];
    }

    int GetNumRows() const { return num_rows; }

    int GetNumColumns() const { return num_cols; }

    friend istream& operator>>(istream& istr, Matrix& mat);
    friend ostream& operator<<(ostream& ostr, const Matrix& mat);
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.GetNumRows() != rhs.GetNumRows())
    {
        throw invalid_argument("invalid_argument");
    }

    if (lhs.GetNumColumns() != rhs.GetNumColumns())
    {
        throw invalid_argument("invalid_argument");
    }

    Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());

    for (int i = 0; i < lhs.GetNumRows(); i++)
    {
        for (int j = 0; j < lhs.GetNumColumns(); j++)
        {
            result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }

    return result;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.GetNumRows() != rhs.GetNumRows())
    {
        return false;
    }

    if (lhs.GetNumColumns() != rhs.GetNumColumns())
    {
        return false;
    }

    for (int row = 0; row < lhs.GetNumRows(); ++row)
    {
        for (int column = 0; column < lhs.GetNumColumns(); ++column)
        {
            if (lhs.At(row, column) != rhs.At(row, column))
            {
                return false;
            }
        }
    }

    return true;
}

istream& operator>>(istream& istr, Matrix& mat)
{
    int ROW, COL;
    istr >> ROW >> COL;

    mat.Reset(ROW, COL);

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            istr >> mat.At(i, j);
        }
    }

    return istr;
}

ostream& operator<<(ostream& ostr, const Matrix& mat)
{
    ostr << mat.GetNumRows() << " " << mat.GetNumColumns() << endl;
    for (int i = 0; i < mat.GetNumRows(); i++)
    {
        for (int j = 0; j < mat.GetNumColumns(); j++)
        {
            ostr << mat.At(i, j) << " ";
        }
        ostr << endl;
    }

    return ostr;
}

int main()
{
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;

    return 0;
}