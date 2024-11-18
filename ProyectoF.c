#include <stdio.h>
#include <stdlib.h>

#define Pueblos 10
#define Bebidas 8

void Matriz_0(int arr[Pueblos][Bebidas]) 
    {
        for (int i = 0; i < Pueblos; i++) 
            {
                for (int j = 0; j < Bebidas; j++) 
                    {
                        arr[i][j] = 0;
                    }
            }
        printf("La matriz se inicializó correctamente.\n");
    }

void Datos_Bebidas_Pueblo(int arr[Pueblos][Bebidas]) 
    {
        int bebida, cantidad;
        for (int i = 0; i < Pueblos; i++) 
            {
                printf("Introduce las bebidas consumidas en el pueblo %d:\n", i);
                do 
                    {
                        printf("Número de la bebida (-1 para terminar): ");
                        scanf("%d", &bebida);
                        if (bebida == -1) 
                            {
                                break; 
                            }
                        if (bebida >= 0 && bebida < Bebidas) 
                            {
                                printf("Cantidad en litros: ");
                                scanf("%d", &cantidad);
                                arr[i][bebida] += cantidad;
                            } 
                        else 
                            {
                                printf("Número de bebida inválido. Intenta nuevamente.\n");
                            }
                    } 
                while (bebida != -1);
            }
    }

void Bebida_MasBebida(int arr[Pueblos][Bebidas])
  {
    	int total[Bebidas] = {0};
    	int max = 0, bebida = -1;
    
    	for (int j = 0; j < Bebidas; j++)
        	{
          		for (int i = 0; i < Pueblos; i++)
              		{
              			total[j] = total[j] + arr[i][j];
              		}
          		if (total[j] > max)
              		{
              			max = total[j];
              			bebida = j;
              		}
        	}
    	printf("La bebida %d es la mas consumida con %d litros.\n", bebida, max);
  }

void BebidaH_MasBebida(int arr[Pueblos][Bebidas]) 
    {
        int total[Bebidas] = {0};
        int max = 0, bebida = -1;
    
        for (int j = 0; j < Bebidas; j++) 
            {
                if (j != 1 && j != 6) 
                    {
                        for (int i = 0; i < Pueblos; i++) 
                            {
                                total[j] = total[j] + arr[i][j];
                            }
            
                        if (total[j] > max) 
                            {
                                max = total[j];
                                bebida = j;
                            }
                    }
            }
        printf("La bebida alcohólica número %d es la más consumida con %d litros.\n", bebida, max);
    }

void Pueblo_MasBebedor(int arr[Pueblos][Bebidas]) 
    {
        int total[Pueblos] = {0};  
        int max = 0, pueblo = -1;
    
        for (int i = 0; i < Pueblos; i++) 
            {
                for (int j = 0; j < Bebidas; j++) 
                    {
                        if (j != 1 && j != 6) 
                            {
                                total[i] = total[i] + arr[i][j];
                            }
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
    	int arr[Pueblos][Bebidas];
    
    	Matriz_0(arr);
    	Datos_Bebidas_Pueblo(arr);

    	Bebida_MasBebida(arr);
    	BebidaH_MasBebida(arr);
    	Pueblo_MasBebedor(arr);
    
    	return 0;
    }

