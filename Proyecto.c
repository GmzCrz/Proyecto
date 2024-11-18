#include <stdio.h>
#include <stdlib.h>

#define PUEBLOS 10
#define BEBIDAS 8

void initialize_matrix(int arr[PUEBLOS][BEBIDAS]) 
{
    for (int i = 0; i < PUEBLOS; i++) 
    {
        for (int j = 0; j < BEBIDAS; j++) 
        {
            arr[i][j] = 0;
        }
    }
    printf("La matriz se inicializó correctamente.\n");
}

void fill_matrix(int arr[PUEBLOS][BEBIDAS]) 
{
    for (int i = 0; i < PUEBLOS; i++) 
    {
        int bebida, cantidad;
        printf("Introduce las bebidas consumidas en el pueblo %d (usa -1 para terminar):\n", i);
        while (1) 
        {
            printf("Bebida: ");
            scanf("%d", &bebida);
            if (bebida == -1) break;
            printf("Cantidad en litros: ");
            scanf("%d", &cantidad);
            if (bebida >= 0 && bebida < BEBIDAS) 
            {
                arr[i][bebida] += cantidad;
            } 
            else 
            {
                printf("Número de bebida inválido.\n");
            }
        }
    }
}

void find_most_consumed_drink(int arr[PUEBLOS][BEBIDAS]) 
{
    int total[BEBIDAS] = {0};
    int max = 0, bebida = -1;

    for (int j = 0; j < BEBIDAS; j++) 
    {
        for (int i = 0; i < PUEBLOS; i++) 
        {
            total[j] += arr[i][j];
        }
        if (total[j] > max) 
        {
            max = total[j];
            bebida = j;
        }
    }
    printf("La bebida %d es la más consumida con %d litros.\n", bebida, max);
}

void find_most_consumed_non_soda_drink(int arr[PUEBLOS][BEBIDAS]) 
{
    int total[BEBIDAS] = {0};
    int max = 0, bebida = -1;

    for (int j = 0; j < BEBIDAS; j++) 
    {
        if (j == 1 || j == 6) continue;
        for (int i = 0; i < PUEBLOS; i++) 
        {
            total[j] += arr[i][j];
        }
        if (total[j] > max) 
        {
            max = total[j];
            bebida = j;
        }
    }
    printf("La bebida no soda %d es la más consumida con %d litros.\n", bebida, max);
}

void find_most_alcohol_consuming_town(int arr[PUEBLOS][BEBIDAS]) 
{
    int total[PUEBLOS] = {0};
    int max = 0, pueblo = -1;

    for (int i = 0; i < PUEBLOS; i++) 
    {
        for (int j = 0; j < BEBIDAS; j++) 
        {
            if (j == 1 || j == 6) continue; 
            total[i] += arr[i][j];
        }
        if (total[i] > max) 
        {
            max = total[i];
            pueblo = i;
        }
    }
    printf("El pueblo %d consume más alcohol con %d litros.\n", pueblo, max);
}

int main() 
{
    int arr[PUEBLOS][BEBIDAS];

    initialize_matrix(arr);
    fill_matrix(arr);

    printf("\n");
    find_most_consumed_drink(arr);
    find_most_consumed_non_soda_drink(arr);
    find_most_alcohol_consuming_town(arr);

    return 0;
}
