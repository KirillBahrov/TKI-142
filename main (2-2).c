#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>


/**
 * @brief считывает и проверяет ввод переменной типа float
 * @return возвращает считанное значение
*/
float getNumber();

/**
 * @brief решает функцию
 * @param x значение, которое вводит пользователь для расчета функции
 * @return выводит значение посчитанной функции
*/
float functionY(const float x);

int main()
{
    printf("Enter the X value ");
    float x = getNumber();
    printf("y = %f", functionY(x) );
    return 0;
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

float functionY(const float x)
{
    float a = 2, e = 2.71828;
    if ( 1 <= x + DBL_EPSILON <= 2)
    {
        return ( a * (pow(x, 2 * (log(x) ) ) ) );
    }
    else if (x + DBL_EPSILON < 1)
    {
        return 1;
    }
    else if (x + DBL_EPSILON > 2)
    {
        return (( exp (a * x) * cos(x) ));
    }
}
