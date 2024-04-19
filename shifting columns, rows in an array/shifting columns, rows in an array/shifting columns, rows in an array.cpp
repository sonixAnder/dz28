#include <iostream>
#include <vector>
using namespace std;

// Функция для циклического сдвига строк или столбцов матрицы
void cyclicShift(vector<vector<int>>& matrix, int shiftCount, bool shiftRows, bool shiftRight)
{
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    if (shiftRows)
    {
        // Сдвиг строк
        shiftCount %= numRows; // Нормализация количества сдвигов
        if (shiftCount > 0)
        {
            reverse(matrix.begin(), matrix.end()); // Разворот всего вектора строк
            reverse(matrix.begin(), matrix.begin() + shiftCount); // Разворот первых shiftCount строк
            reverse(matrix.begin() + shiftCount, matrix.end()); // Разворот оставшихся строк
        }
    }
    else
    {
        // Сдвиг столбцов
        shiftCount %= numCols; // Нормализация количества сдвигов
        for (auto& row : matrix)
        {
            if (shiftRight)
            {
                rotate(row.rbegin(), row.rbegin() + shiftCount, row.rend()); // Сдвиг вправо
            }
            else
            {
                rotate(row.begin(), row.begin() + shiftCount, row.end()); // Сдвиг влево
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int M, N;
    cout << "Введите количество строк (M): ";
    cin >> M;
    cout << "Введите количество столбцов (N): ";
    cin >> N;

    vector<vector<int>> matrix(M, vector<int>(N));

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    int shiftCount, direction;
    bool shiftRows;
    cout << "Введите количество сдвигов: ";
    cin >> shiftCount;
    cout << "Сдвигать строки (1) или столбцы (0)? ";
    cin >> shiftRows;
    cout << "Сдвигать вправо (1) или влево (0)? ";
    cin >> direction;

    cyclicShift(matrix, shiftCount, shiftRows, direction);

    cout << "Результат:" << endl;
    for (const auto& row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
