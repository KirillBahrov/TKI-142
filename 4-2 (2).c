#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>

/**
 * @brief Функция присваивает целочисленное значение переменной
 * @return целочисленная цифра
*/
int get_int();

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
 * @brief Функция выделяет память под массив
 * @param length длина массива
 * @return array указатель на пустой массив
*/
int* get_array(const size_t length);

/**
 * @brief фукнция считает новую длину под масиив из пункта 2
 * @param array исходный массив
 * @param length длина исходного массива
 * @param k введенное число
*/
size_t new_length(int* array, size_t length, size_t const k);

/**
 * @brief Функция заполняет массив, элементы вводит пользователь
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void user_array(int* const array, const size_t length);

/**
 * @brief Функция заполняет массив рандомными числами в диапазоне [-15:15]
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void random_array(int* const array, const size_t length);

/**
 * @brief Функция, показывающая массив поэлементно
 * @param array ссылка на показываемый массив
 * @param length длина массива
*/
void show_array(const int* const array, const size_t length);

/**
 * @brief Заменяет предпоследний элемент массива на максимальный по модулю.
 * @param array ссылка на массив
 * @param length размер массива
 * @return new_array новый массив, соответствующий этим требованиям
*/
void first_task(int* control_array, const int* array, size_t length);

/**
 * @brief ЗАПОЛНЯЕТ массив по условию пункта 2
 * @param original_array исходный массив
 * @param array пустой новый массив с нужной размерностью
 * @param length длина исходного массива
 * @param number введенное число
*/
void second_task(int* original_array, int* array, size_t length, int number);

/**
 * @brief Функция проверяет на четность целое число
 * @param number число
 * @return 0 четный
 * @return 1 нечетный
*/
bool is_even(int number);

/**
 * @brief Заменяет в массиве элементы по соответствующим условиям
 * @param array ссылка на массив
 * @param length размерность массива
 * @return new_array новый массив, соответствующий этим требованиям
*/
void third_task(int* control_array, int* array, size_t length);

/**
 * @brief Функция, освобождающая массив
 * @param array указатель на массив
*/
void free_array(int** array);

int* second_task_1(int* array, size_t length, size_t k);

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
*/
int main()
{
    const int min_range = -15;
    const int max_range = 15;
    puts("insert a length of array\n");
    size_t length = get_size_t();
    puts("if you fill array by youself, press 1, if you fill array by random numbers, press 2\n");
    int choice = get_int();
    int* mas =  get_array(length);

    switch ((enum Choices)choice)
    {
    case random_choice:
        random_array(mas, length);
        break;
    case user_choice:
        user_array(mas, length);
        break;
    default:
        puts("Insert a valid choice!\n");
        return 1;
    }
    
    puts("Array\n");
    show_array(mas, length);

    int* task_1_array =  get_array(length);
    first_task(mas, task_1_array, length);
    puts("First task\n");
    show_array(task_1_array, length);
    free_array(&task_1_array);

    puts("Insert a K\n");
    int k = get_int();
    if (k < 0 || k > 10)
    {
        puts("Insert a valid number!\n");
        return 1;
    }
    
    int* task_2_1 =  get_array(new_length(mas, length, k));
    second_task(mas, task_2_1, length, k);
    puts("Second task\n");
    show_array(task_2_1, new_length(mas, length, k));
    free_array(&task_2_1);

    int* task_3_array =  get_array(length);
    third_task(mas, task_3_array, length);
    puts("Third task\n");
    show_array(task_3_array, length);
    free_array(&task_3_array);
    free_array(&mas);

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

int* get_mem_array(const size_t length)
{
    int* array = (int*)malloc(length * sizeof(int));
    if (NULL == array)
    {
        errno = ENOMEM;
        perror("Error: ");
        abort();
    }
    return array;
}

void user_array(int* const array, const size_t length)
{
    puts("Insert array elements:\n");

    for (size_t i = 0; i < length; i++)
    {
        array[i] = get_int();
    }
}

void random_array(int* const array, const size_t length, const int max, const int min)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = rand() % max + min;
    }
}

void show_array(const int* const array, const size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("Element[%ld]  %d\n", i, array[i]);
    }
}

void copy_array(int* const array_original, int* array_copy, const size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        array_copy[i] = array_original[i];
    }
}

int find_abs_max(int* const array, size_t length)
{
    int abs_max = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (abs(array[i]) > abs(array[abs_max]))
        {
            abs_max = i;
        }
    }
    return abs_max;
}

bool is_even(int number)
{
    return number % 2 == 0;
}

void first_task(int* control_array, const int* array, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (i == length - 2)
        {
            array[i] = control_array[find_abs_max(control_array, length)];
        }
        else
        {
            array[i] = control_array[i];
        }
    }
}

size_t new_length(int* array, size_t length, size_t const k)
{
    size_t new_leng = length;
    if (abs(array[length-1]) % 10 == k)
    {
        new_leng++;
    }
    
    if (abs(array[0]) % 10 == k)
    {
        new_leng++;
    }
    
    for (size_t i = 0; i < length - 1; i++)
    {
        if ((abs(array[i]) % 10 == k && abs(array[i+1]) % 10 != k) || (abs(array[i]) % 10 != k && abs(array[i+1]) % 10 == k))
        {
            new_leng++;
        }
    }

    return new_leng;
}


void second_task(int* original_array, int* array, size_t length, int number)
{
    size_t top = 0;
    if (abs(original_array[0]) % 10 == number)
    {
        array[top] = number;
        top++;
    }
    array[top] = original_array[0];
    top++;

    for (size_t i = 1; i < length; i++)
    {
        if ((abs(original_array[i-1]) % 10 == number && abs(original_array[i]) % 10 != number) || (abs(original_array[i-1]) % 10 != number && abs(original_array[i]) % 10 == number))
        {
            array[top] = number;
            top++;
        }
        array[top] = original_array[i];
        top++;
    }

    if (abs(original_array[length - 1]) % 10 == number)
    {
        array[top] = number;
        top++;
    }
}

void third_task(int* control_array, int* array, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (!is_even(i))
        {
            array[i] = i * pow(control_array[i], 2);
        }
        else
        {
            array[i] = control_array[i] / (i - 1);
        }
    }
}

void free_array(int** array)
{
    if (array != NULL)
    {
        free(array);
        array = NULL;
    }
}
