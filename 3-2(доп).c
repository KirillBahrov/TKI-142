#include <stdio.h>

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
    scanf("%d", &N);
    maxNumber(N);
    return 0;
}
double maxNumber(int N)
{
    double x, max;
    max = scanf("%lf", &x);
    for (int i = 1; i < N; i++)
    {
        printf("Enter value: ");
        scanf("%lf", &x);
        if (x > max) 
        {
            max = x;
        }
    }
    printf("Max element: %lf\n", max);
}
