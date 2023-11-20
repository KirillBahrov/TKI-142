#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <float.h>

/**
@brief считывает и проверияет ввод переменной
@return возвращает значение переменной
*/
double getNumber();

/**
@brief проверяет условие, чтобы начальное значение интервала было меньше конечного
@param beginningX - значение начала интервала
@param finishX - значение rjywf интервала
@return возвращает 1 если условие выполнено
*/
double checkingInterval(double beginningX, double finishX);

/**
@brief проверка значение на положительное число
@return возвращает значение переменной
*/
double isPositive();

/**
@brief проверяет существует ли в функция в заданной точке
@param x - значение переменной x
@return возвращает true если функция существует
*/
bool existFunction(double x);

/**
@brief рассчитывает значение функции
@param x - значение переменной x
@return возвращает посчитанное значение
*/
double getFunction(double x);

/**
@brief точка входа в программу
@return возвращает 0, если программа выполнена верно
*/
int main()
{
    printf("Enter the beginning of the interval: ");
    double beginningX = getNumber();
    printf("Enter the end of the interval: ");
    double finishX = getNumber();
    checkingInterval(beginningX, finishX);
    printf("Enter the step value: ");
    double stepValue = isPositive();
    double x = beginningX;
    while(fabs(DBL_EPSILON) >= x - finishX)
    {
        if (existFunction(x))
        {
            double y = getFunction(x);
            printf(" x = %lf", x);
            printf(" y = %lf\n", y);
        }
        else
        {
            printf("The function does not exist, when x = %lf\n", x);
        }
    x = x + stepValue;
    }
    return 0;
}

double getNumber() 
{ 
 double entered_number; 
 if (scanf("%lf", &entered_number) != 1 ) 
 { 
  printf("Wrong value"); 
  abort(); 
 } 
 return entered_number; 
} 

double checkingInterval(double beginningX, double finishX)
{
 if(beginningX > finishX)
 {
    printf("Does not satisfy the interval condition!");
    abort;
 }
 return 1;
}

double isPositive()
{
    double number;
    if (scanf("%lf", &number) != 1 || number <0)
    {
     printf("Wrong value"); 
     abort();
    }
    return number;
}

bool existFunction(double x)
{
    return x > - DBL_EPSILON;
}

double getFunction(double x)
{
    return( (0.29 * ( pow(x, 3))) + x - 1.2502 );
}



