/* gcc --std=c89 -Wall -Werror pr2.c -o pr2.exe */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h> /*Библиотека для выделение памяти*/
int main(){
	int n, m, i, j, l;
	int **a; /*Укзатель на массив*/
	scanf("%d %d", &n, &m);
	/*Выделение памяти*/
	a = (int**)malloc(n*sizeof(int*));
	/*srand(time(NULL));*/ /*Для различных рандомных чисел*/
	/*Заполнение двумерного массива*/
	for (i = 0; i < n; i++){
		a[i] = (int*)malloc(m*sizeof(int));
		for (j = 0; j < m; j++)
			a[i][j] = rand()%100+1;
	}
	/*Вывод массива*/
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++)	
			printf("%d  ",  a[i][j]);
		printf("\n");
	}
	/*Разворачивание первой и последней строки*/
	for(j = 0; j<n; j+=(n-1))
		for(i = 0; i < (m/2); i++){
			l = a[j][i];
			a[j][i]=a[j][m-i-1];
			a[j][m-i-1]= l;
		}

	/*Первая меняется на последнюю и наоборот*/
	int *b;
	b = (int*)malloc(m*sizeof(int));
	b = a[0];
	a[0]=a[n-1];
	a[n-1]=b;

	/*Нахождение наименьшего элемента двумерного массива*/
	int nomberI = 0, nomberJ = 0, min = a[0][0]; 
	for (int i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (min > a[i][j]){
				min = a[i][j];
				nomberI = i;
				nomberJ = j;
			}

	/*Удаление строки*/
	for(i = nomberI; i < n - 1; i++){
		b = a[i];
		a[i] = a[i+1];
		a[i+1]=b;
	}
	free(a[n-1]);
	n--;

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++)	
			printf("%d  ",  a[i][j]);
		printf("\n");
	}

	return 0;

}