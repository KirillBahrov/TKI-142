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
int* get_mem_array(const size_t length);

/**
 * @brief фукнция считает новую длину под масиив из пункта 2
 * @param array исходный массив
 * @param length длина исходного массива
 * @param k введенное число
*/
size_t new_length(int* array, size_t length, int const k);

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

/*

*/
int amount_k(int* array, size_t length, size_t k);

int* second_task_1(int* array, size_t length, size_t k, int amount);

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

    int* task_1_array = get_mem_array(length);
    copy_array(mas, task_1_array, length);
    int* task_1_array_1 = first_task(task_1_array, length);
    show_array(task_1_array_1, length);
    free_array(task_1_array);
    free_array(task_1_array_1);

    puts("Insert a K\n");
    int k = get_int();
    if (k < 0 || k > 10)
    {
        puts("Insert a valid number!\n");
        return 1;
    }
    int* task_2_1 = second_task_1(mas, length, k, amount_k(mas, length, k));
    show_array(task_2_1, length + amount_k(mas, length, k));
    free_array(task_2_1);

    int* task_3_array = get_mem_array(length);
    copy_array(mas, task_3_array, length);
    task_3_array = third_task(task_3_array, length);
    free_array(task_3_array);
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
            if (abs(array[i]) > abs(abs_max))
            {
                abs_max = array[i];
            }
    }
    return abs_max;
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
    array[-2] = find_abs_max(array, length);
    return array;
}

size_t new_length(int* array, size_t length, int const k)
{
    size_t new_leng = length;
    if (array[length-1] % 10 == k)
    {
        new_leng++;
    }
    
    else if (array[0] % 10 == k)
    {
        new_leng++;
    }
    
    for (size_t i = 0; i < length - 1; i++)
    {
        if ((array[i] % 10 == k && array[i+1] % 10 != k) || (array[i] % 10 != k && array[i+1] % 10 == k))
        {
            new_leng++;
        }
    }

    return new_leng;
}

int amount_k(int* array, size_t length, size_t k)
{
    int amount = 0;
    for (size_t i = 0; i < length; i++)
    {
        if(abs(array[i]) % 10 == k)
        {
            ++amount;
            printf("%d", amount);
        }
    }
    return amount+1;
}

int* second_task_1(int* array, size_t length, size_t k, int amount)
{
    int* mass = get_mem_array(length+amount);
    size_t i = 0;
    size_t j = 0;
    while (j < (length+amount), i < length)
    {
        if(abs(array[i]) % 10 == k)
        {
            mass[j] = k;
            mass[j+1] = array[i];
            mass[j+2] = k;
            i++;
            j = j + 3;
        }
        else
        {
            mass[j] = array[i];
            i++;
            j++;
        }
    }
    return mass;
}

int* third_task(int* const array, size_t length)
{
    int* new_array = get_mem_array(length);
    copy_array(array, new_array, length);
    for (size_t i = 0; i < length; i++)
    {
        if (is_even(new_array[i]) == 0)
        {
            array[i] = i * (new_array[i] * new_array[i]);
        }
        else
        {
            array[i] = new_array[i] / (i-1); 
        }
    }
    free_array(new_array);
    return array;
}

void free_array(int* array)
{
    if (array != NULL)
    {
        free(array);
        array = NULL;
    } 
}


