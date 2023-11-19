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
@brief проверяет существует ли в функция в заданной точке
@param x - значение переменной x
@return возвращает true если функция существует
*/
bool existFunction(double x);

/**
@brief рассчитывает значение функции
@return возвращает посчитанное значение
*/
double getFunction();

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
    printf("Enter the step value: ");
    double stepValue = getNumber();
    double x = beginningX;
    while(fabs(DBL_EPSILON) >= x - finishX)
    {
        if (existFunction(x))
        {
            double y = getFunction();
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
 if (scanf("%lf", &entered_number) != 1 || (entered_number < 0)) 
 { 
  printf("Wrong value"); 
  abort(); 
 } 
 return entered_number; 
} 

bool existFunction(double x)
{
    return x > DBL_EPSILON;
}

double getFunction(double x)
{
    return( (0.29 * ( pow(x, 3))) + x - 1.2502 );
}



