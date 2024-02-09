#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считывает и проверяет ввод переменной типа float
 * @return возвращает считанное значение
*/
float getNumber();

/**
* @brief вычисляет  площадь грани куба
* @param x грань куба
* @return возвращает результат вычисленной площади
*/
float faceArea(const float x);

/**
* @brief вычисляет площадь полной поверхности куба
* @param x грань куба
* @return возвращает результат вычисленной площади поверхности
*/
float totalSurfacearea(const float x);

/**
* @brief вычисляет объем куба
* @param x грань куба
* @return возвращает результат вычисленного объема
*/
float cubeVolume(const float x);

/**
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Enter the length of the edge of the cube: ");
    float x = getNumber();

    printf(" faceArea = %f\n", faceArea(x));
    printf(" totalSurfacearea = %f\n", totalSurfacearea(x));
    printf(" cubeVolume = %f\n", cubeVolume(x));

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


float faceArea(const float x)
{
    return(pow(x, 2));
}

float totalSurfacearea(const float x)
{
    return(6 * (pow(x, 2)));
}

float cubeVolume(const float x)
{
    return (pow(x, 3));
}