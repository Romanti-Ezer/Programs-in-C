#include <stdio.h>
#include <stdlib.h>

main (){
	struct{
		int codigo;
		char nome[50];
		float salario;
	} funcionario;
	
	char numstr[8];
	char nome_func[50];
	int codigo_func;
	int opcao = 0, escolha = 0, resultado_busca = 0;
	FILE *fptr;
	int codigo = 1;
	
	while (opcao != 4){
		system("cls");
		printf("---------- Sistema de controle de funcionarios ----------\n");
		printf("[1] Cadastrar\n");
		printf("[2] Consultar\n");
		printf("[3] Exibir\n");
		printf("[4] Sair\n");
		printf("-----------------------------------------------------------\n");
		printf("R: ");
		
		scanf("%d", &opcao);
		fflush(stdin);
		
		if (opcao == 1){
			system("cls");
			
			// Pegando o código anteior e gerando um novo
			if ((fptr = fopen("funcionarios.txt", "rb")) != NULL){
				while (fread(&funcionario, sizeof(funcionario), 1, fptr) == 1) {
					codigo = funcionario.codigo + 1;
				}
			}
			
			fclose(fptr);
			// Fim
			
			if ((fptr = fopen("funcionarios.txt", "ab")) == NULL){
				printf("Nao foi possivel abrir o arquivo 'funcionarios.txt'");
				exit(1);
			}
			
			funcionario.codigo = codigo;
			printf("Codigo gerado: %d\n", codigo);
			
			printf("Digite o nome do funcionario: ");
			gets(funcionario.nome);
			
			printf("Digite o salario do funcionario: ");
			gets(numstr);
			
			funcionario.salario = atof(numstr);
			
			fwrite(&funcionario, sizeof(funcionario), 1, fptr);
			fclose(fptr);
			printf("\nFuncionario cadastrado com sucesso.\n");
			system("pause");
		}
		
		else if (opcao == 2){
			system("cls");
			resultado_busca = 0;
			if((fptr = fopen("funcionarios.txt", "rb")) == NULL){
				printf("Wasn't possible read file 'books.txt'");
				exit(1);
			}
			printf("------------ Escolha uma forma de pesquisa ---------------\n");
			printf("1 - Por nome\n");
			printf("2 - Por codigo\n");
			printf("R: ");
			scanf("%d",&escolha);
			
			if (escolha == 1){
				
				system("cls");
				printf("--------------- Pesquisando funcionario ---------------\n");
				printf("Digite o nome do funcionario\n");
				printf("R: ");
				fflush(stdin);
				gets(nome_func);
				
				while (fread(&funcionario, sizeof(funcionario), 1, fptr) == 1) {
					if (strcmp(funcionario.nome, nome_func) == 0){
						printf("\nCodigo: %d\n", funcionario.codigo);
						printf("\nNome: %s\n", funcionario.nome);
						printf("\nSalario: %.2f\n", funcionario.salario);
						printf("----------------------------------------------\n\n");
						resultado_busca++;
					}
				}
				
				printf("Pesquisa concluida.\n");
				printf("Resultados encontrados: %d\n",resultado_busca);
				system("pause");
				
				fclose(fptr);
			}
			else if (escolha == 2){
				system("cls");
				printf("--------------- Pesquisando funcionario ---------------\n");
				printf("Digite o codigo do funcionario\n");
				printf("R: ");
				scanf("%d",&codigo_func);
				
				while (fread(&funcionario, sizeof(funcionario), 1, fptr) == 1) {
					if (funcionario.codigo == codigo_func){
						printf("\nCodigo: %d\n", funcionario.codigo);
						printf("\nNome: %s\n", funcionario.nome);
						printf("\nSalario: %.2f\n", funcionario.salario);
						printf("----------------------------------------------\n\n");
						resultado_busca++;
					}
				}
				
				printf("Pesquisa concluida.\n");
				printf("Resultados encontrados: %d\n",resultado_busca);
				system("pause");
				
				fclose(fptr);
			}
			else{
				printf("\nOpcao invalida!\n");
				fclose(fptr);
				system("pause");
			}
		}
		
		else if (opcao == 3){
			if((fptr = fopen("funcionarios.txt", "rb")) == NULL){
				printf("Wasn't possible read file 'books.txt'");
				exit(1);
			}
			
			while (fread(&funcionario, sizeof(funcionario), 1, fptr) == 1) {
				printf("\nCodigo: %d\n", funcionario.codigo);
				printf("\nNome: %s\n", funcionario.nome);
				printf("\nSalario: %.2f\n", funcionario.salario);
				printf("----------------------------------------------\n\n");
			}
			
			system("pause");
			
			fclose(fptr);
		}
		
		else if (opcao == 4){
			exit(1);
		}
		
		else{
			printf("Opcao invalida!");
			system("pause");
		}
	}		
}
