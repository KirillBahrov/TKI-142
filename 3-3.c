#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>

/**
* @brief Считывает и проверяет ввод переменной
* @return Возвращает считанное значение
*/
double getNumber();
/**
* @brief Проверяет, чтобы шаг был положительным
* @return Возвращает 1, если условие верное
*/
double checkStep(double xStep);
/**
@brief Проверяет условие, чтобы начальное значение интервала было меньше конечного
@param xBegin - значение начала интервала
@param xEnd - значение конца интервала
@return Возвращает 1, если условие выполнено
*/
double checkInterval(double xBegin, double xEnd);
/**
* @brief Рассчитывает заданную функцию в данной точке
* @param x - аргумент функции
* @return Возвращает значение функции в данной точке
*/
double calculation(double x);
/**
* @brief Рассчитывает сумму функционального ряда
* @param x - аргумент функции
* @return Возвращает сумму функционального ряда
*/
double sumFunction(double x);
/**
* @brief точка входа в программу
* @return Возвращает 0, если программа работает верно
*/
int main()
{
printf_s("Enter the beginning value: \n");
double xBegin = getNumber();
printf_s("Enter the end value: \n");
double xEnd = getNumber();
printf_s("Enter the step value: \n");
double xStep = getNumber();
checkStep(xStep);
checkInterval(xBegin, xEnd);
while (xBegin < xEnd + xStep) //
{
printf_s("X: %lf Y: %lf Sum(x): %lf\n", xBegin, calculation(xBegin), sumFunction(xBegin));
xBegin = xBegin + xStep;
}
return 0;
}

double getNumber()
{
double entered_number;
if (scanf_s("%lf", &entered_number) != 1)
{
errno = EIO;
perror("Wrong value");
abort();
}
return entered_number;
}

double checkStep(double xStep)
{
if (xStep <= DBL_EPSILON) //
{
errno = EIO;
perror("Wrong value");
abort();
}
return 1;
}

double checkInterval(double xBegin, double xEnd)
{
if (xBegin - xEnd > -DBL_EPSILON) //
{
printf("Does not satisfy the interval condition!");
abort();
}
return 1;
}


double calculation(double x)
{
return (sin(x)); 
}

double sumFunction(double x)
{
const double e = pow(10, -4); // точность
double n = 0;  
double current_x = 1.0; //
double sum = x;
while (calculation(x) - sum > e - DBL_EPSILON) //
{
current_x *= (((pow(x, 2)) * (((-2) * n) - 1)) / ((2 * n) + 3));
sum += current_x;
n = n + 1;
}
return sum;
}
