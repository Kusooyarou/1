#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

namespace linalg {

    class Matrix {
    private:
        double* m_ptr;      // Указатель на динамический массив
        size_t m_rows;      // Количество строк
        size_t m_columns;   // Количество столбцов

    public:
        Matrix(); // Конструктор по умолчанию
        Matrix(size_t rows, size_t cols); // Конструктор с параметрами
        size_t rows() const; // Метод для получения количества строк
        size_t columns() const; // Метод для получения количества колонок
        bool empty() const; // Метод для проверки, пуста ли матрица
        void reshape(size_t new_rows, size_t new_cols); // Метод для изменения размера матрицы
        double& operator()(size_t row, size_t col); // Метод для доступа к элементу матрицы
        const double& operator()(size_t row, size_t col) const; // Константный метод для доступа к элементу
        ~Matrix(); // Деструктор
    };

} // namespace linalg

#endif // MATRIX_H
