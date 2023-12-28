#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

/**
 * @brief Функция присваивает целочисленное значение переменной
 * @return целое число
*/
int get_int();

/**
 * @brief Функция, прерывающая программу из-за отсутствия памяти для массивов
*/
void array_null();

/**
 * @brief освобождает многомерный массив
 * @param array указатель на заполняемый массив
 * @param rows количество строк в массиве
*/
void free_array(int*** array, size_t rows);

/**
 * @brief Функция присваивает переменной целочисленное значение и проверяет его на положителность
 * @return number положительное число
*/
size_t get_size_t();

/**
 * @brief структура хранит константы, указывающие выбор пользователя заполнить массив
 * @brief user_choice хранит значение, вызывающее ввод массива вручную
 * @brief random_choice хранит значение, вызывающее ввод массива случайными числами
*/
enum Choices
{
    user_choice = 1,
    random_choice = 2,
};

/**
 * @brief Функция выделяет память под многомерный массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
 * @return array указатель на пустой многомерный массив
*/
int** get_mem_array(const size_t rows, const size_t cols);

/**
 * @brief Функция заполняет массив, элементы вводит пользователь
 * @param array указатель на заполняемый массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
*/
void user_array(int** const array, const size_t rows, const size_t cols);

/**
 * @brief Функция заполняет массив рандомными числами в диапазоне, указанный пользователем
 * @param array указатель на заполняемый массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
*/
void random_array(int** const array, const size_t rows, const size_t cols);

/**
 * @brief Функция, показывающая массив поэлементно
 * @param array ссылка на показываемый массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
*/
void show_array(const int** const array, const size_t rows, const size_t cols);

/**
 * @brief Заменяет отрицателный элемент каждого столбца нулем
 * @param array ссылка на массив
 * @param rows количество строк в массиве
 * @param cols количество столбцов в массиве
 * @return NULL отрицательных чисел нет
 * @return new_array новый массив, соответствующий этим требованиям
*/
int **first_task(int** array, size_t rows, size_t cols);

/**
 * @brief Функция удаляет из массива столбцы, содержащие элемент, кратный 5
 * @param array ссылка на массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
 * @return result_array новый массив, соответствующий этим требованиям
*/
int **second_task(int** const array, size_t rows, size_t cols);

/**
 * @brief Функция вычисляет размер столбцов в массиве, который соответствует условию 2-го пункта
 * @param array ссылка на массив
 * @param rows количество строк в массиве
 * @param cols  количество столбцов в массиве
 * @return new_columns количество столбцов нового массива
*/
size_t new_cols(const int** const array, size_t rows, size_t cols);

/**
 * @brief Вспомогательная функция для функции new_cols, предотвращает выход за диапазон переменной
 * @param number положительное число (или нуль)
*/
void check_range_size_t(size_t number);

/**
 * @brief выделяет память под линейный массив
 * @param length длина массива
 * @return array пустой массив
*/
int* get_mem_array_linear(const size_t length);

/**
 * @brief Функция заполняет вспомогательный массив ненужных столбцов
 * @param array многомерный массив
 * @param array_linear массив, который будет заполняться
 * @param rows количество строк в массиве
 * @param cols количество столбцов в массиве
*/
void fill_trash_columns(const int** const array, int* array_linear, size_t rows, size_t cols);

/**
 * @brief Функция, проверяющая, что есть ли число в массиве
 * @param array линейный массив
 * @param length длина массива
 * @param number проверяемое число
 * @return true есть число
 * @return false нет числа
*/
bool contains(const int* const array, const size_t length, const size_t number);

/**
 * @brief точка входа в программу
 * @return 0 программа исправна
 * @return 1 программа завершилась досрочно с ошибкой
*/
int main()
{
    puts("insert a rows\n");
    size_t n = get_size_t();
    puts("insert a columns\n");
    size_t m = get_size_t();
    printf("if you fill array by youself, press %d, if you fill array by random numbers, press %d\n", (enum Choices)(user_choice), (enum Choices)(random_choice));
    int choice = get_int();
    int** mas = get_mem_array(n, m);

    switch ((enum Choices)choice)
    {
        case random_choice:
            random_array(mas, n, m);
            break;
        case user_choice:
            user_array(mas, n, m);
            break;
        default:
            puts("Insert a valid choice!\n");
            return 1;
    }
    
    show_array(mas, n, m);
    int** first_array = first_task(mas, n, m);
    show_array(first_array, n, m);
    int** second_array = second_task(mas, n, m);
    if (NULL == second_array)
    {
        puts("Second task == NULL\n");
    }
    else
    {
        size_t new_columns = new_cols(mas, n, m);
        show_array(second_array, n, new_columns);
    }
    free_array(mas, n);
    free_array(first_array, n);
    free_array(second_array, n);
    return 0;
}

int get_int()
{
    int number;
    if (scanf("%d", &number) != 1)
    {
        puts("Inserted a wrong value\n");
        abort();
    }
    return number;
}

size_t get_size_t()
{
    int number = get_int();
    if (number <= 0)
    {
        errno = ERANGE;
        perror("Error: \n");
        abort();
    }
    return (size_t)number;
}

int** get_mem_array(const size_t rows, const size_t cols)
{
    int** array = (int**)malloc(rows * sizeof(int*));
    if (NULL == array)
    {
        array_null();
    }
    for (size_t i = 0; i < rows; i++)
    {
        array[i] = (int*)malloc(cols * sizeof(int));
        if (NULL == array[i])
        {
            array_null();
        }
    }
    return array;
}

void user_array(int** const array, const size_t rows, const size_t cols)
{
    puts("Insert array elements:\n");

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            array[i][j] = get_int();
        }
    }
}

void random_array(int** const array, const size_t rows, const size_t cols)
{
    puts("Enter a minimal number in range\n");
    int minimum = get_int();
    puts("Enter a maximum number in range\n");
    int maximum = get_int();
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            array[i][j] = rand() % maximum - minimum;
        }
    }
}

void show_array(const int** const array, const size_t rows, const size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            printf(" %d ", array[i][j]);
        }
        printf("\n");
    }
    puts("\n");
}


int **first_task(int** array, size_t rows, size_t cols)
{
    int** new_array = get_mem_array(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (array[i][j] < 0)
            {
                new_array[i][j] = 0;
            }
            else
            {
                new_array[i][j] = array[i][j];
            }
        }
    }
    return new_array;
}

void check_range_size_t(size_t number)
{
    if (number == 0)
    {
        errno = ERANGE;
        perror("Error: ");
        abort();
    }
}

size_t new_cols(const int** const array, size_t rows, size_t cols)
{
    size_t new_columns = cols;
    for (size_t i = 0; i < cols; i++)
    {
        if (array[rows-1][i] > array[-1][i])
        {
            new_columns--;
        }
    }
    return new_columns;
}

int* get_mem_array_linear(const size_t length)
{
    int* array = (int*)malloc(length * sizeof(int));
    if (NULL == array)
    {
        array_null();
    }
    return array;
}

void fill_trash_columns(const int** const array, int* array_linear, size_t rows, size_t cols)
{
    size_t top = 0;
    for (size_t i = 0; i < cols; i++)
    {
        if (array[0][i] > array[rows-1][i])
        {
            array_linear[top] = i;
            top++;
        }
    }
}

bool contains(const int* const array, const size_t length, const size_t number)
{
    for (size_t i = 0; i < length; i++)
    {
        if (number == array[i])
        {
            return true;
        }
    }
    return false;
}

int **second_task(int** const array, size_t rows, size_t cols)
{
    size_t new_columns = new_cols(array, rows, cols);
    if (new_columns == 0)
    {
        return NULL;
    }
    int** new_array = get_mem_array(rows, new_columns);
    int* trash_columns = get_mem_array_linear(cols - new_columns);
    fill_trash_columns(array, trash_columns, rows, cols);
    size_t row_top = 0, col_top = 0;
    int flag = 0;
    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            if (!contains(trash_columns, (cols - new_columns), i))
            {
                new_array[i][col_top] = array[j][i];
                col_top++;
            }
        }
    }

    if (NULL != trash_columns)
    {
        free(trash_columns);
    }
    return new_array;
}

void free_array(int*** array, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(&array[i]);
        &array[i] = NULL;
    }
    if (NULL != array)
    {
        free(&array);
        &array = NULL;
    }
}

void array_null()
{
    errno = ENOMEM;
    perror("Error: ");
    abort();
}
