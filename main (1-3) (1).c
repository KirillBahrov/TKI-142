#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считывает и проверяет ввод переменной типа float
 * @return возвращает считанное значение
*/
float getNumber();

/**
* @brief вычисляет  силу тяжести мешка
* @param m масса  мешка с картошкой
* @return возвращает результат вычисленной силы тяжести
*/
float gravity(const float m);

/**
* @brief вычисляет вес мешка 
* @param m масса мешка с картошкой
* @return возвращает результат вычисленного веса
*/
float weight(const float m);


/**
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Bag weight in kg: ");
    float m = getNumber();

    printf(" gravity = %f\n", gravity(m));
    printf(" weight = %f\n", weight(m));

    return 0;
}

float getNumber()
{
    float m;
    if (scanf("%f", &m) !=1 || m <= 0)
    {
        puts("Wrong value");
        abort();
    }
    return m;
}


float gravity(const float m)
{
    return(m*9.81);
}

float weight(const float m)
{
    return(m*9.81);
}
