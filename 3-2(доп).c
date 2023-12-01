#include <stdio.h>

/**
@brief считает максимальное число из N введенных чисел
@return возвращает максимальное число из N введенных
*/
double maxNumber();
/**
@brief точка входа в программу
@return возвращает 0, если программа выполнена верно
*/
int main()
{
    maxNumber();
    return 0;
}
double maxNumber()
{
    double x, max;
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        printf("Enter value: ");
        scanf("%lf", &x);
        if (i == 0 || x > max) max = x;
    }
    printf("Max element: %lf\n", max);
}
