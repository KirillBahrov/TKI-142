#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
@brief считает сумму всех четных чисел от 1 до 100
@return возвращает посчитанную сумму
*/
int sumEvenNumbers();

/**
@brief точка входа в программу
@return возвращает 0, если программа выполнена верно
*/
int main()
{
    int t = 0;
    for(int i = 0; i <= 100; i++){
        if(i % 2 == 0){
        t += i;
        }
    }
  printf("%d", t);
return 0;
}
