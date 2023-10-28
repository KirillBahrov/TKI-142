#include <stdio.h>
#include <math.h>
/**
* @brief возвращает результат функции а
* @param x заданная константа
* @param y заданная константа
* @return возвращает значение функции a
*/
float functionA(float x, float y);

/**
* @brief возвращает результат функции b
* @param x заданная константа
* @param y заданная константа
* @param z заданная константа
* @return возвращает значение функции b
*/
float functionB(float x, float y, float z);

/**
* @brief точка входа в программу
* @return возвращает 0, если функция сработала правильно, в противном случае 1
*/
int main() 
{
	float x = 1.825f, y = 18.225f, z = -3.298f;
	printf("x = %f\n",x);
	printf("y = %f\n",y);
	printf("z = %f\n",z);
	printf("a = %f\n", functionA(x, y));
	printf("b = %f", functionB(x, y, z));
	return 0;
}

float functionA(float x, float y)
{
	return((pow(x,(y/x))-pow((y/x),(1.0 / 3))));
}

float functionB(float x, float y, float z)
{
	return((y-x)+(((y-z)/y-x)/(3+((pow(z,2))/5))));
}