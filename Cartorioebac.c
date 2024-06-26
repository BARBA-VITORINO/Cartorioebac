#include <stdio.h> // biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> // biblioteca de aloca��o de texto pot regi�o
#include <string.h>// biblioteca responsavel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de variaveis/strings
	char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usu�rio
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
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:\t");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
    system("pause");
    
    
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio deletado do sistema!.\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n");  // inicio do menu
	    printf("Escolha a op��o desejada do Menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n");
	    printf("\t4 - Sair do Sistima\n\n");
	    printf("Op��o: "); //fim do menu
	
	    scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
	    system("cls"); // responsavel por limpar a tela 
	    
	    
	    switch(opcao) //inicio da sele��o do menu 
	    {
	    	case 1:
	    	registro(); // chamada de fun��es 
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");	
		}
	
	   
	
    }
}
