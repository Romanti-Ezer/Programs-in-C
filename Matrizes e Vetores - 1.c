#include <stdio.h>

float matriz[5][3];
int escolha = 1, i,j, qtdProd[4] = {0,0,0,0};
int maiorEstoque, menorQtdProd;

// ---------------------- FUNÇÕES --------------------------

void preencherDados()
{
	printf("Informe o preco do Produto 1: ");
	scanf("%f", &matriz[4][0]);
	printf("Informe o preco do Produto 2: ");
	scanf("%f", &matriz[4][1]);
	printf("Informe o preco do Produto 3: ");
	scanf("%f", &matriz[4][2]);
	
	system("cls");
	
	for (i = 0; i < 4; i++)
	{
		qtdProd[i] = 0;
		printf("--- Armazem %d ---\n",(i+1));
		for(j = 0; j < 3; j++)
		{
			printf("Quantidade do produto %d: ",(j+1));
			scanf("%f",&matriz[i][j]);
			printf("\n");
			
			qtdProd[i] += matriz[i][j];
		}
	}
	printf("\nFim do preenchimento.\n");
	system("pause");
}

int maiorQtdP2()
{
	for(i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			maiorEstoque = 0;
		}
		else if (matriz[i][1] > matriz[maiorEstoque][1])
		{
			maiorEstoque = i;
		}
	}
	
	return maiorEstoque+1;
}

int menorQtdProdArm()
{
	for (i = 0; i < 4; i++)
	{
		if(i == 0)
		{
			menorQtdProd = i;
		}
		else if (qtdProd[i] < qtdProd[menorQtdProd])
		{
			menorQtdProd = i;
		}
	}
	
	return menorQtdProd+1;
}

void qtdItens()
{
	printf("------ Quantidade de Produtos ------\n\n");
	printf("Armazem 1: %d\n", qtdProd[0]);
	printf("Armazem 2: %d\n", qtdProd[1]);
	printf("Armazem 3: %d\n", qtdProd[2]);
	printf("Armazem 4: %d\n\n", qtdProd[3]);
	system("pause");
}

float totalProdX(int produto)
{
	if ((produto >= 0) && (produto < 3))
	{
		float totalDeItens = 0;
		for (i = 0; i < 4; i++)
		{
			totalDeItens += matriz[i][produto];
		}
		return totalDeItens*matriz[4][produto];
	}
	else{
		printf("\nProduto invalido\n");
		return 0;
	}
	
}

float totalArmX(int armazem)
{
	if ((armazem >= 0) && (armazem < 4))
	{
		float totalDeItens = 0;
		for (i = 0; i < 3; i++)
		{
			totalDeItens += (matriz[armazem][i] * matriz[4][i]);
		}
		return totalDeItens;
	}
	else{
		printf("\nArmazem invalido\n");
		return 0;
	}
	
}

// -------------------- FIM FUNÇÕES ------------------------






// ----------------------  MAIN  ---------------------------
main()
{	
	while (escolha != 0)
	{
		system("cls");
		printf("------ Estoque de Produtos ------\n\n");
		printf("1 - Preencher dados do estoque\n");
		printf("2 - Mostrar quantidade de itens em cada armazem\n");
		printf("3 - Verificar qual armazem possui maior estoque do produto 2\n");
		printf("4 - Veriricar qual armazem possui a menor quantidade de produtos\n");
		printf("5 - Custo total de cada produto\n");
		printf("6 - Custo total de cada armazem\n");
		printf("0 - Sair\n\n");
		printf("R: ");
		scanf("%d",&escolha);
		
		system("cls");
		
		if (escolha == 1)
		{
			preencherDados();
		}
		else if (escolha == 2)
		{
			qtdItens();
		}
		else if (escolha == 3)
		{
			int maior = maiorQtdP2();
			printf("Armazem com maior estoque do Produto 2: %d\n\n", maior);
			system("pause");
		}
		else if (escolha == 4)
		{
			int menor = menorQtdProdArm();
			printf("Armzem com menor quantidade de produtos: %d\n\n", menor);
			system("pause");
		}
		
		else if (escolha == 5)
		{
			float totP1 = totalProdX(0);
			float totP2 = totalProdX(1);
			float totP3 = totalProdX(2);
			
			printf("Total de custo do Produto 1: R$ %.2f\n", totP1);
			printf("Total de custo do Produto 2: R$ %.2f\n", totP2);
			printf("Total de custo do Produto 3: R$ %.2f\n\n", totP3);
			
			system("pause");
		}
		else if (escolha == 6)
		{
			float totA1 = totalArmX(0);
			float totA2 = totalArmX(1);
			float totA3 = totalArmX(2);
			float totA4 = totalArmX(3);
			
			printf("Total de custo do Armazem 1: R$ %.2f\n", totA1);
			printf("Total de custo do Armazem 2: R$ %.2f\n", totA2);
			printf("Total de custo do Armazem 3: R$ %.2f\n", totA3);
			printf("Total de custo do Armazem 4: R$ %.2f\n\n", totA4);
			
			system("pause");
		}
	}
}
// https://github.com/Romanti-Ezer
