#include <stdio.h>
// Revisão para a prova

main () {
	int vet_a[5];
	int maior_a;
	
	
	int vet_b[10];
	int menor_b;
	
	int mult_ab;
	
	int vet_c[5][4];
	int vet_result[5][4];
	
	int soma_linha_par[4] = {0,0,0,0};
	int entre_10_20[4] = {0,0,0,0};
	int i, j;
	
	// Entrar com Vetor A com 5 posições numéricas	
	for(i = 0; i<5; i++)
	{
		printf("Insira o valor do vetor A na posicao %d\n", i);
		scanf("%d", &vet_a[i]);
		
		// Encontrar o maior elemento do Vetor A
		if (i == 0)
		{
			maior_a = vet_a[i];
		}
		else
		{
			if (vet_a[i] > maior_a)
			{
				maior_a = vet_a[i];
			}
		}
	}
	
	printf("\nMaior valor do vetor A: %d\n", maior_a);
	system("pause");
	system("cls");
	
	// Entrar com o segundo vetor B contendo 10 posições
	for(i = 0; i<10; i++)
	{
		printf("Insira o valor do vetor B na posicao %d\n", i);
		scanf("%d", &vet_b[i]);
		
		// Encontrar o menor elemento do Vetor B
		if (i == 0)
		{
			menor_b = vet_b[i];
		}
		else
		{
			if (vet_b[i] < menor_b)
			{
				menor_b = vet_b[i];
			}
		}
	}
	
	printf("\nMenor valor do vetor B: %d\n", menor_b);
	system("pause");
	
	system("cls");
	
	// Obter o resultado multiplicando o maior e o menor elemento
	mult_ab = maior_a*menor_b;
	printf("Resultado da multiplicacao de %d por %d (maior x menor): %d\n", maior_a, menor_b, mult_ab);
	system("pause");
	
	system("cls");
	
	for(i = 0; i<4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			printf("Insira o valor da linha: %d e coluna %d\n", i, j);	
			scanf("%d", &vet_c[i][j]);
		}
		
	}
	
	system("cls");
	
	printf("Matriz A\n\n");
	for(i = 0; i<4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if (vet_c[i][j] < 10)
			{
				printf("[00%d] ", vet_c[i][j]);
			}
			else if (vet_c[i][j] < 100)
			{
				printf("[0%d] ", vet_c[i][j]);
			}
			else
			{
				printf("[%d] ", vet_c[i][j]);
			}
		}
		printf("\n\n");
	}
	
	system("pause");
	system("cls");
	
	for(i = 0; i<4; i++)
	{
		for(j = 0; j <3; j++)
		{
			vet_result[i][j] = vet_c[i][j] + mult_ab;
		}
	}
	
	// Somar o valor multiplicado na matriz, gerando uma matriz resultante
	printf("Matriz Resultante\n\n");
	for(i = 0; i<4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if (vet_result[i][j] < 0)
			{
				printf("[%d] ", vet_result[i][j]);
			}
			else if (vet_result[i][j] < 10)
			{
				printf("[00%d] ", vet_result[i][j]);
			}
			else if (vet_c[i][j] < 100)
			{
				printf("[0%d] ", vet_result[i][j]);
			}
			else
			{
				printf("[%d] ", vet_result[i][j]);
			}
		}
		printf("\n\n");
	}
	
	system("pause");
	system("cls");
	
	// Somar as linhas pares, e armazenar em um vetors
	for (i = 0; i < 4; i = i + 2)
	{
		for (j = 0; j < 3; j++)
		{
			soma_linha_par[i] += vet_result[i][j];
		}
		printf("Soma da linha %d: %d\n", i, soma_linha_par[i]);
	}
	
	system("pause");
	system("cls");
	
	// Quantificar por colunas os valores entre 10 e 20 e armazenar em outro vetor
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 4; i++){
			
			if ((vet_result[i][j] < 21) && (vet_result[i][j] > 9))
			{
				entre_10_20[j]++;
			}
		}
		printf("Numero entre 10 e 20 da coluna %d: %d\n\n", j, entre_10_20[j]);
	}
}

// https://github.com/Romanti-Ezer
