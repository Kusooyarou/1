#include "matrix.h"
#include <iostream>

namespace linalg {

    // ����������� �� ��������� � ������ ������ �������
    Matrix::Matrix() : m_ptr(nullptr), m_rows(0), m_columns(0) {}

    // ����������� � ����������� � ������ ������� ��������� �������
    Matrix::Matrix(const size_t rows, const size_t cols) : m_rows(rows), m_columns(cols) {
        m_ptr = new double[rows * cols](); // ������������� ������
    }

    // ����������
    Matrix::~Matrix() {
        delete[] m_ptr;
    }

    // ����� ��� ��������� ���������� �����
    size_t Matrix::rows() const {
        return m_rows;
    }

    // ����� ��� ��������� ���������� �������
    size_t Matrix::columns() const {
        return m_columns;
    }

    // ����� ��� ��������, ����� �� �������
    bool Matrix::empty() const {
        return m_rows == 0 || m_columns == 0;
    }

    // ����� ��� ��������� ������� �������
    void Matrix::reshape(size_t new_rows, size_t new_cols) {
        if (new_rows * new_cols != m_rows * m_columns) {
            throw std::invalid_argument("New shape must have the same number of elements.");
        }

        m_rows = new_rows;
        m_columns = new_cols;
    }

    // ����� ��� ������� � �������� �������
    double& Matrix::operator()(size_t row, size_t col) {
        if (row >= m_rows || col >= m_columns) {
            throw std::out_of_range("Matrix indices out of range.");
        }
        return m_ptr[row * m_columns + col];
    }

    // ����������� ����� ��� ������� � ��������
    const double& Matrix::operator()(size_t row, size_t col) const {
        if (row >= m_rows || col >= m_columns) {
            throw std::out_of_range("Matrix indices out of range.");
        }
        return m_ptr[row * m_columns + col];
    }

} // namespace linalg
