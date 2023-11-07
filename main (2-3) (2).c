#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief считывает и проверяет ввод переменной типа float
 * @return возвращает считанное значение
*/
float getNumber();

/**
* @brief определяет пройдет ли кирпич в отверстие
* @param x сторона кирпича
* @param y сторона кирпича
* @param z сторона кирпича
* @param r сторона прямоугольного отверстия
* @param s сторона прямоугольного отверстия
* @return возвращает результат проверки
*/
char brickPassage(float r, float s, float x, float y, float z);


/**
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
    printf("The sides of the brick are equal: ");
    float x = getNumber();
    float y = getNumber();
    float z = getNumber();
    printf("Dimensions of the rectangular hole: ");
    float r = getNumber();
    float s = getNumber();
    printf("%c", brickPassage(x,y,z,r,s));
    return 0;
}

float getNumber()
{
    float v;
    if (scanf("%f", &v) !=1 || v <= 0)
    {
        puts("Wrong value");
        abort();
    }
    return v;
}


char brickPassage(float r, float s, float x, float y, float z)
{
    if ( ( ( ( r >= x ) && ( ( s >= y ) ||( s >= z ) ) ) || ( ( r >= y ) && ( ( s >= x ) ||( s >= z ) ) ) || ( ( r >= z ) && ( ( s >= x ) ||( s >= y ) ) ) ) ==1){
        printf("A brick with such dimensions will pass through the hole");
    }
    else{
    printf("No it doesn't pass ");
    }

}

