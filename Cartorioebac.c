#include <stdio.h> // biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço de memória 
#include <locale.h> // biblioteca de alocação de texto pot região
#include <string.h>// biblioteca responsavel por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início criação de variaveis/strings
	char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a salvar uma string
	
	strcpy(arquivo,cpf); //responsavel por copiar os arquivos das strings
	 
	FILE *file;// cria o arquivo
	file = fopen(arquivo,"w");// cria o arquivo e o "w" aiginifica escrever 
	fprintf(file,cpf);// salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
    char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a escolher:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\t");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
    system("pause");
    
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário deletado do sistema!.\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n");  // inicio do menu
	    printf("Escolha a opção desejada do Menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n\n");
	    printf("Opção: "); //fim do menu
	
	    scanf("%d", &opcao); // armazenando a escolha do usuário
	
	    system("cls"); // responsavel por limpar a tela 
	    
	    
	    switch(opcao) //inicio da seleção do menu 
	    {
	    	case 1:
	    	registro(); // chamada de funções 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
		    system("pause");	
		}
	
	   
	
    }
}
