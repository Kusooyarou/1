#include "matrix.h"
#include <iostream>

int main() {
    linalg::Matrix mat(2, 2);

    mat(0, 0) = 1.0;
    mat(0, 1) = 2.0;
    mat(1, 0) = 3.0;
    mat(1, 1) = 4.0;

    for (size_t i = 0; i < mat.rows(); ++i) {
        for (size_t j = 0; j < mat.columns(); ++j) {
            std::cout << mat(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
