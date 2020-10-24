/* 
Programa para calculo da m�dia de um determinado n�mero de alunos.
Instituto Federal de S�o Paulo � C�mpus S�o Paulo
An�lise e Desenvolvimento de Sistemas
PFDA1
Eric dos Santos Cabral 
Feito em 23/10/2020 
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define ALUNOS 3 //Define o n�mero de alunos a serem analizados

//Define uma estrutura de nome dados, para armazenamento de informa��es dos alunos
typedef struct
{
	char nome[50];
	float nota1, nota2, media;
} dados;

//corpo do programa

int main ()
{
	dados alunos[ALUNOS];
	
	setlocale (LC_ALL, "portuguese");
	
	for (int i = 0; i < ALUNOS; i++)
	{
		printf("Digite o nome do aluno n�mero %i: ", i+1);
		fflush(stdin);
		fgets(alunos[i].nome, 50, stdin);
		
		nota1: 
		printf ("Digite a primeira nota: ");
		scanf ("%f", &alunos[i].nota1);
		if (alunos[i].nota1 > 10)                                        //Checa se a nota do aluno est� dentro dos padr�es permitidos
		{
			printf ("ERRO! Notas aceitas somente de 1 a 10\n");
			goto nota1;
		}
		
		nota2:
		printf ("Digite a segunda nota: ");								//Checa se a nota do aluno est� dentro dos padr�es permitidos
		scanf ("%f", &alunos[i].nota2); 
		if (alunos[i].nota2 > 10)                                       
		{
			printf ("ERRO! Notas aceitas somente de 1 a 10\n");
			goto nota2;
		}
		
		alunos[i].media = (alunos[i].nota1 + alunos[i].nota2)/2;
		
		if (alunos[i].media < 6)
		{
			printf("M�dia = %.2f. Aluno reprovado!\n\n", alunos[i].media);
		}
		else if (alunos[i].media >= 6)
		{
			printf("M�dia = %.2f. Parab�ns! Aluno aprovado!\n\n", alunos[i].media);
		}
	}
	
	system ("cls");
	
	
	for (int i = 0; i < ALUNOS; i++)             ////Por fim, exibe as informa��es digitadas em lista
	{
		printf ("Nome do Aluno: %s", alunos[i].nome);
		printf ("M�dia = %.2f \n\n", alunos[i].media);
	}
	
	system ("pause");
	return 0;
}
