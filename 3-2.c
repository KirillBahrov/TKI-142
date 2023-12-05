#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <locale.h>

/**
* @brief проверяет на положительное число
* @remarks Экстренное завершение программы, в случае неправильного ввода
* @return  возвращает Количество членов последовательности
*/
int getCount();
/**
* @brief проверяет на функцию, считывающую точность вычисления суммы последовательности
* @remarks Экстренное завершение программы, в случае неправильного ввода
* @return возвращает точность вычисления суммы последовательности
*/
double getEpsilon();
/**
* @brief рассчитывает функцию сумму членов последовательности
* @param count - количество членов последовательности
* @return возвращает сумму последовательности
*/
double getCountSum(int count);
/**
* @brief рассчитывает сумму членов последовательности
* @param epsilon - точность вычисления суммы последовательности
* @return возвращает посчитанную сумму последовательности
*/
double getEpsilonSum(double epsilon);
/**
* @brief расчитывает рекурентный член последовательности
* @param k - номер члена последовательности
* @return возвращает значение рекурентного члена последовательности
*/
double getRecurrent(int k);
/**
*@brief Точка входа в программу
*@return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
    setlocale(LC_ALL, "RU");
    printf("Введите количество членов последовательности: ");
    int count = getCount();
    double countSum = getCountSum(count);
    printf("Суммы %d членов последовательности равны: %.20lf \n", count, countSum);
    printf("Введите точность вычисления суммы последовательности: ");
    double epsilon = getEpsilon();
    double epsilonSum = getEpsilonSum(epsilon);
    printf("Сумма последовательности с заданной точностью равна: %.20lf", epsilonSum);
    return EXIT_SUCCESS;
}

int getCount()
{
    int count;
    int result = scanf("%d", &count);
    if(result != 1 || result != 0)
    {
        errno = EIO;
        perror("Wrong value");
        abort;
    }
    return count;
}

double getEpsilon()
{
    double epsilon;
    int result = scanf("%lf", &epsilon);
    if(result !=1 || epsilon >= - DBL_EPSILON)
    {
        errno = EIO;
        perror("Wrong value");
        abort;
    }
    return epsilon;
}

double getCountSum(int count)
{
    double current = 1.0;
    double sum = current;
    for(int k = 0; k < count - 1; k++)
    {
        current *= getRecurrent(k);
        sum += current;
    }
    return sum;
}

double getEpsilonSum(double epsilon)
{
    double current = 1.0;
    double sum = 0;
    int k = 0;
    while (fabs(current) < epsilon + DBL_EPSILON)
    {
        current *= getRecurrent(k);
        sum += current;
        k++;
    }
    return sum;
}

double getRecurrent(int k)
{
    return((-1)/((k+2)*(k+1))); 
}
