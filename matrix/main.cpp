#include <iostream>

class matrix {
private:
    int** mat0;
public:
    int size = 2;
    int col0 = size, row0 = size;
    int** const& mat = mat0;
    matrix() {
        mat0 = new int* [size];
        for (int i = 0; i < size; ++i) mat0[i] = new int[size];
    }
    matrix(int size1)
    {
        if (size1 <= 0) {
            std::cerr << "negative or 0 size given, taking positive" << std::endl;
            size1 *= -1;
        }
        size = size1;
        col0 = size; row0 = size;
        mat0 = new int* [size];
        for (int i = 0; i < size; ++i) mat0[i] = new int[size];
    }
    matrix(int row, int column)
    {
        if (row <= 0 or column <= 0) {
            std::cerr << "negative or 0 size given, taking positive" << std::endl;
            if (row <= 0) row *= -1;
            if (column <= 0)column *= -1;
        }
        row0 = row; col0 = column;
        mat0 = new int* [row0];
        for (int i = 0; i < row0; ++i) mat0[i] = new int[col0];
    }

    void type_matrix()
    {
        for (int i = 0; i < row0; i++)
        {
            for (int j = 0; j < col0; j++)
                std::cout << mat0[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void init_matrix()
    {
        for (int i = 0; i < row0; ++i)
        {
            for (int j = 0; j < col0; ++j)
                mat[i][j] = rand() % 100;
        }
    }

    int diag_sum()
    {
        int sum = 0;
        for (int i = 0; i < row0; ++i)
        {
            for (int j = 0; j < i; ++j) sum += mat[i][j];
        }
        return sum;
    }
    ~matrix()
    {
        for (int i = 0; i < row0; ++i)
        {
            delete(mat0[i]); mat0[i] = nullptr;
        }
        delete(mat0); mat0 = nullptr;
    }
};

int main() {

    matrix alpha(-4, -2);
    alpha.init_matrix();
    alpha.type_matrix();
    std::cout << alpha.diag_sum();
    return 0;
}