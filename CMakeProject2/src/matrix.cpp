#include "matrix.h"
#include <iostream>

namespace linalg {

    // Конструктор по умолчанию — создаёт пустую матрицу
    Matrix::Matrix() : m_ptr(nullptr), m_rows(0), m_columns(0) {}

    // Конструктор с параметрами — создаёт матрицу заданного размера
    Matrix::Matrix(const size_t rows, const size_t cols) : m_rows(rows), m_columns(cols) {
        m_ptr = new double[rows * cols](); // Инициализация нулями
    }

    // Деструктор
    Matrix::~Matrix() {
        delete[] m_ptr;
    }

    // Метод для получения количества строк
    size_t Matrix::rows() const {
        return m_rows;
    }

    // Метод для получения количества колонок
    size_t Matrix::columns() const {
        return m_columns;
    }

    // Метод для проверки, пуста ли матрица
    bool Matrix::empty() const {
        return m_rows == 0 || m_columns == 0;
    }

    // Метод для изменения размера матрицы
    void Matrix::reshape(size_t new_rows, size_t new_cols) {
        if (new_rows * new_cols != m_rows * m_columns) {
            throw std::invalid_argument("New shape must have the same number of elements.");
        }

        m_rows = new_rows;
        m_columns = new_cols;
    }

    // Метод для доступа к элементу матрицы
    double& Matrix::operator()(size_t row, size_t col) {
        if (row >= m_rows || col >= m_columns) {
            throw std::out_of_range("Matrix indices out of range.");
        }
        return m_ptr[row * m_columns + col];
    }

    // Константный метод для доступа к элементу
    const double& Matrix::operator()(size_t row, size_t col) const {
        if (row >= m_rows || col >= m_columns) {
            throw std::out_of_range("Matrix indices out of range.");
        }
        return m_ptr[row * m_columns + col];
    }

} // namespace linalg
