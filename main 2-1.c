#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считывает и проверяет ввод переменной типа float
 * @return возвращает считанное значение
*/
float getNumber();

/**
 * @brief вычисляет выбранную пользователем величину
 * @param x выбранная формула
 * @param a длина катета a
 * @param b длина катета b
 * @return возвращает посчитанную величину
*/
float formulaSelection(int x, float a, float b);

enum Values
{
    perimetrTriangle = 1,
    areaTriangle = 2,
};

/**
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("Enter the length of the catheter a: \n");
    float a = getNumber();
    printf("Enter the length of the catheter b: \n");
    float b = getNumber();
    printf("Please write down what you want to find: the perimeter of the triangle or the area\n");
    printf("If you want to find the perimeter of the triangle press 1: \n");
    printf("If you want to find the area of the triangle press 2: \n");
    int x = getNumber();
    formulaSelection(x, a, b);
    return 0;
}

float getNumber()
{
    float x;
    if (scanf("%f", &x) !=1 || x <= 0)
    {
        puts("Wrong value\n");
        abort();
    }
    return x;
}

float formulaSelection(int x, float a, float b){
    enum Values perimetr = perimetrTriangle, area = areaTriangle;
    if(x == perimetr){
            float c = pow( (pow(a, 2) + pow(b, 2) ), 0.5 );
            float x = (a + b + c );
            printf("The perimeter of the triangle is equal to: %f\n", x);
        }
        else if(x == area){
            float c = pow( (pow(a, 2) + pow(b, 2) ), 0.5 );
            float p = (a + b + c)/2;
            float s = ( pow( p * (p-a) * (p-b) * (p-c), 0.5 ) );
            printf("The area of the triangle is equal to: %f\n", s);
        }

}


