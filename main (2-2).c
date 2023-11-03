#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считывает и проверяет ввод переменной типа float
 * @return возвращает считанное значение
*/
float getNumber();

/**
 * @brief решает функцию
 * @param a заданная константа
 * @param е заданная константа
 * @param x значение, которое вводит пользователь для расчета функции
 * @return выводит значение посчитанной функции
*/
float functionY(const float x, const int a, const float e);

int main()
{
    float a = 2, e = 2.71828;
    printf("Enter the X value ");
    float x = getNumber();
    printf("y = %f", functionY(x, a, e) );
    
    
}

float getNumber()
{
    float x;
    if (scanf("%f", &x) !=1 || x <= 0)
    {
        puts("Wrong value");
        abort();
    }
    return x;
}

float functionY(const float x, const int a, const float e)
{
    if ( 1 <= x <= 2)
    {
        return ( a * (pow(x, 2 * (log(x) ) ) ) );
    }
    else if (x < 1)
    {
        return 1;
    }
    else if (x > 2)
    {
        return (( exp (a * x) * cos(x) );
    }
}