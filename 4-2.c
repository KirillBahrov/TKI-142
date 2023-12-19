#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <math.h>

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
int* get_mem_array(const int length);

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
 * @brief Функция копирующая элементы одного массива в другой
 * @param array_original исходный массив
 * @param array_copy пустой массив
 * @param length длина массива
*/
void copy_array(int* const array_original, int* array_copy, const size_t length);


/**
 * @brief Заменяет предпоследний элемент массива на максимальный по модулю.
 * @param array ссылка на массив
 * @param length размер массива
 * @return new_array новый массив, соответствующий этим требованиям
*/
int *first_task(int* array, size_t length);

/**
 * @brief Функция проверяет на четность целое число
 * @param number число
 * @return 0 четный
 * @return 1 нечетный
*/
int is_even(int number);

/**
 * @brief Заменяет в массиве элементы по соответствующим условиям
 * @param array ссылка на массив
 * @param length размерность массива
 * @return new_array новый массив, соответствующий этим требованиям
*/
int* third_task(int* const array, size_t length);

/**
 * @brief Функция, освобождающая массив
 * @param array указатель на массив
*/
void free_array(int* array);

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
*/
int main()
{
    puts("insert a length of array\n");
    size_t length = get_size_t();
    puts("if you fill array by youself, press 1, if you fill array by random numbers, press 2\n");
    int choice = get_int();
    int* mas = get_mem_array(length);

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

    int* new_array = get_mem_array(length);
    copy_array(*array, *new_array, length);
    show_array(first_task(mas, length), length);
    int* new_array = get_mem_array(length);
    copy_array(*array, *new_array, length);
    show_array(third_task(mas, length), length);
    free_array(mas);
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

int* get_mem_array(const int length)
{
    int* array = malloc(length * sizeof(int));
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

void random_array(int* const array, const size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = rand() % 15 - 15;
    }
}

void show_array(const int* const array, const size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("Element[%d]  %d\n", i, array[i]);
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
    int index = 0;
    for (size_t i = 0; i < length; i++)
    {
            if (abs(array[index]) < abs(array[i]))
            {
                index = i;
            }
    }
    return index;
}

int is_even(int number)
{
    if (number % 2 == 0)
    {
        return 0;
    }
    return 1;
}

int *first_task(int* array, size_t length)
{
    new_array[-2] = new_array[find_abs_max(*array, length)];
    return new_array;
}

int* third_task(int* const array, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        if (is_even(array[i]) == 0)
        {
            new_array[i] = i * (array[i] * array[i]);
        }
        else
        {
            new_array[i] = array[i] / (i-1); 
        }
    }
    return new_array;
}

void free_array(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}
