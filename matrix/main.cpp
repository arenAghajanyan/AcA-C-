#include <iostream>

class matrix {
private:

public:
    int** mat0;
    int size = 2;
    int col0 = size, row0 = size;
    matrix() {
        mat0 = new int* [size];
        for (int i = 0; i < size; ++i) mat0[i] = new int[size];
    }
    matrix(int size1)
    {
        if (size1 < 0) {
            std::cerr << "negative size given, taking positive" << std::endl;
            size1 *= -1;
        }
        size = size1;
        col0 = size; row0 = size;
        mat0 = new int* [size];
        for (int i = 0; i < size; ++i) mat0[i] = new int[size];
    }
    matrix(int row, int column)
    {
        if (row < 0 or column < 0) {
            std::cerr << "negative size given, taking positive" << std::endl;
            if (row < 0) row *= -1;
            if (column < 0)column *= -1;
        }
        row0 = row; col0 = column; size = 0;
        mat0 = new int* [row0];
        for (int i = 0; i < row0; ++i) mat0[i] = new int[col0];
    }

    matrix(const matrix& m1) {
        if (this != &m1)
        {
            size = m1.size; col0 = m1.col0;
            row0 = m1.row0;
            mat0 = new int* [row0];
            for (int i = 0; i < row0; ++i) mat0[i] = new int[col0];
            for (int i = 0; i < row0; ++i)
            {
                for (int j = 0; j < col0; ++j)
                    mat0[i][j] = m1.mat0[i][j];
            }
        }
    }

    void display_matrix()
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
            for (int j = 0; j < col0; ++j)  mat0[i][j] = rand() % 100;
    }

    int diag_sum()
    {
        int diagsum = 0;
        for (int i = 0; i < row0; ++i)
        {
            for (int j = 0; j < i; ++j) diagsum += mat0[i][j];
        }
        return diagsum;
    }

    void del_memory()
    {
        for (int i = 0; i < row0; ++i) delete(mat0[i]);
        delete(mat0);
    }

    matrix& operator = (const matrix& m1)
    {
        if (this != &m1)
        {
            del_memory();
            size = m1.size; col0 = m1.col0;
            row0 = m1.row0; mat0 = new int* [row0];
            for (int i = 0; i < row0; ++i) mat0[i] = new int[col0];
            for (int i = 0; i < row0; ++i)
                for (int j = 0; j < col0; ++j)
                    mat0[i][j] = m1.mat0[i][j];
        }
        return *this;
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

    matrix alpha(-4, -2), b(4, 2);
    alpha.init_matrix();
    alpha.display_matrix();
    std::cout << alpha.diag_sum() << std::endl;
    b = alpha;
    matrix c = b;
    b.display_matrix();
    c.display_matrix();
    return 0;
}
