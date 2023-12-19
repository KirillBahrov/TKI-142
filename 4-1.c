#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <stdbool.h>

/**
 * @brief Функция досрочно завершает программу под предлогом исчерпания ОЗУ под динамический массив
 */
void array_null();

/**
 * @brief Функция присваивает целочисленное значение переменной
 * @return целочисленное число
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
 * @return указатель на пустой массив
*/
int* get_array(size_t length);

/**
 * @brief Функция, показывающая массив поэлементно
 * @param array ссылка на показываемый массив
 * @param length длина массива
*/
void show_array(const int* const array, const size_t length);

/**
 * @brief Функция проверяет на четность целое число
 * @param number число
 * @return 0 четный
 * @return 1 нечетный
*/
bool is_even(int number);


/**
 * @brief Функция заполняет массив, элементы вводит пользователь
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void user_array(int* array, const size_t length);

/**
 * @brief Функция заполняет массив рандомными числами в диапазоне [-100:200]
 * @param array указатель на заполняемый массив
 * @param length длина массива
*/
void random_array(int* array, const size_t length);

/**
 * @brief Находит произведение элементов, имеющих четное значение
 * @param array указатель на массив
 * @param length размерность массива
 * @return результат
*/
int first_task(int* const array, size_t length);

/**
 * @brief Заменяет элементы массива с нечетными номерами на квадраты их номеров.
 * @param array указатель на массив
 * @param length размерность массива
 * @return new_array новый массив,удовлетворяющим данным требованиям
 */
int *second_task(int* const array, const size_t length);

/**
 * @brief Определяет, есть ли в данном массиве положительные элементы, делящиеся на заданное число k с остатком 2.
 * @param array указатель на массив
 * @param length размерность массива
 * @param number заданное число
 * @return true есть такие элементы
 * @return false нет таких элементов
*/
bool third_task(int* const array, const size_t length, const int number);

/**
 * @brief Функция, освобождающая массив
 * @param array указатель на массив
*/
void free_array(int* array);

/**
 * @brief Точка входа в программу
 * @return 0 Программа исправна
 * @return 1 Программа досрочно закрылась с ошибкой
*/
int main()
{
    const int min_range = -15;
    const int max_range = 15;
    puts("insert a length of array\n");
    size_t length = get_size_t(); // size t 
    puts("if you fill array by youself, press 1, if you fill array by random numbers, press 2\n");
    int choice = get_int();
    int* mas = get_array(length);
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
    
    
    printf("First task: %d\n", first_task(mas, length));
    puts("Second task:\n");
    show_array(second_task(mas, length), length);
    puts("insert a integer number\n");
    int number = get_int();
    if (third_task(mas, length, number))
    {
        puts("Third task: True\n");
    }
    else
    {
        puts("Third task: False\n");
    }
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

int* get_array(size_t length)
{
    int* array = (int*)malloc(length * sizeof(int));
    if (NULL == array)
    {
        array_null();
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

void random_array(int* const array, const size_t length, const int q, const int r)
{
    for (size_t i = 0; i < length; i++)
    {
        array[i] = rand() % q + r;
    }
}

int first_task(int* const array, size_t length)
{
    int result = 1;
    for (size_t i = 0; i < length; i++)
    {
        if (is_even(array[i]) == 0)
        {
            result *= array[i];
        }
    }
    return result;
}

void show_array(const int* const array, const size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("Array[%su]  %su\n", i, array[i]);
    }
}

int *second_task(int* const array, const size_t length)
{
    int* new_array = get_array(length);
    for (size_t i = 0; i < length; i++)
    {
        if (is_even(i))
        {
            new_array[i] = i * i;
        }
        else
        {
            new_array[i] = array[i];
        }
    }
    return new_array;
}

bool third_task(int* const array, const size_t length, const int number)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] % number == 2)
        {
            return true;
        }
    }
    return false;
}

bool is_even(int number)
{
    if (number % 2 == 0)
    {
        return 0;
    }
    return 1;
}

void free_array(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}
