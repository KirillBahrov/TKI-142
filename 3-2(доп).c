#include <stdio.h>
#include <stdlib.h>

/**
 * @brief считывает и проверяет ввод переменной типа double
 * @return возвращает считанное значение
*/
double getNumber();
/**
@brief считает максимальное число из N введенных чисел
@return возвращает максимальное число из N введенных
*/
double maxNumber(int N);
/**
@brief точка входа в программу
@return возвращает 0, если программа выполнена верно
*/
int main()
{
    int N;
    printf("Enter N: ");
    getNumber(N);
    maxNumber(N);
    return 0;
}

double getNumber()
{
    double x;
    if (scanf("%lf", &x) !=1 || x <= 0)
    {
        puts("Wrong value");
        abort();
    }
    return x;
}
double maxNumber(int N)
{
    double x;
    double max = getNumber();
    for (int i = 1; i < N; i++)
    {
        printf("Enter value: ");
        x = getNumber();
        if (x > max) 
        {
            max = x;
        }
    }
    printf("Max element: %lf\n", max);
}
