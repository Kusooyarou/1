#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

namespace linalg {

    class Matrix {
    private:
        double* m_ptr;      // ��������� �� ������������ ������
        size_t m_rows;      // ���������� �����
        size_t m_columns;   // ���������� ��������

    public:
        Matrix(); // ����������� �� ���������
        Matrix(size_t rows, size_t cols); // ����������� � �����������
        size_t rows() const; // ����� ��� ��������� ���������� �����
        size_t columns() const; // ����� ��� ��������� ���������� �������
        bool empty() const; // ����� ��� ��������, ����� �� �������
        void reshape(size_t new_rows, size_t new_cols); // ����� ��� ��������� ������� �������
        double& operator()(size_t row, size_t col); // ����� ��� ������� � �������� �������
        const double& operator()(size_t row, size_t col) const; // ����������� ����� ��� ������� � ��������
        ~Matrix(); // ����������
    };

} // namespace linalg

#endif // MATRIX_H
