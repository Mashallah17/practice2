#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int n, m, i, j, l;
	int **a; 
	printf("Enter the size of the initial array\n");
	scanf("%d %d", &n, &m);
	a = (int**)malloc(n*sizeof(int*));
	srand(time(NULL));
	for (i = 0; i < n; i++){
		a[i] = (int*)malloc(m*sizeof(int));
		for (j = 0; j < m; j++)
			a[i][j] = rand()%10+1;
	}
	printf("Initial array:\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++)
			printf("%3.d  ",  a[i][j]);
		printf("\n");
	}
	printf("\n");
	for(j = 0; j<n; j+=(n-1))
		for(i = 0; i < (m/2); i++){
			l = a[j][i];
			a[j][i]=a[j][m-i-1];
			a[j][m-i-1]= l;
		}

	int *b;
	b = (int*)malloc(m*sizeof(int));
	b = a[0];
	a[0]=a[n-1];
	a[n-1]=b;
	
	printf("An array with mirrored and rearranged first and last lines:\n");
	/*Распечатка*/
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++)
			printf("%3.d  ",  a[i][j]);
		printf("\n");
	}
	printf("\n");



	int nomberI = 0, nomberJ = 0, min = a[0][0];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (min > a[i][j]){
				min = a[i][j];
				nomberI = i;
				nomberJ = j;
			}

	for(i = nomberI; i < n - 1; i++){
		b = a[i];
		a[i] = a[i+1];
		a[i+1]=b;
	}
	free(a[n-1]);
	n--;



	for (j = nomberJ; j < m-1; j++){
        for (i = 0; i < n; i++){
            a[i][j]=a[i][j+1];
        }
	}
	m--;

	printf("An array with a deleted column and row\n");

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++)
			printf("%3.d  ",  a[i][j]);
		printf("\n");
	}
	printf("\n");

	printf("Enter an array size %d x %d\n", m, n);
	int **d;
	d = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < m; i++){
        d[i] = (int*)malloc(n*sizeof(int));
        for(j = 0; j < n; j++)
            scanf("%d", &d[i][j]);
	}

    int **c;
    c = (int**)malloc(n*sizeof(int*));
	for(i = 0; i < n; i++){
		c[i] = (int*)malloc(n*sizeof(int));
    	for(j = 0; j < n; j++){
        	c[i][j] = 0;
        	for(l = 0; l < m; l++)
            	c[i][j] += a[i][l] * d[l][j];
    }
	}	

    printf("\nNew array:\n");
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
			printf("%3.d  ",  c[i][j]);
		printf("\n");
	}


    for (i = 0; i < n; i++){
        free(a[i]);
        free(d[i]);
        free(c[i]);
    }

	return 0;

}
