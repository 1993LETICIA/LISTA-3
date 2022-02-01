//Faça um programa que:
//a) Crie e leia um vetor com dados de n livros: título (30 letras), autor(15 letras) ano e prateleira.
//b) Procure um livro por título, perguntando ao usuário qual título deseja buscar, apresente o nome e em qual prateleira o mesmo se encontra.
//c) Mostre os dados de todos os livros cadastrados.
//d) Leia um ano e apresente todos os livros cadastrados.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
	char titulo[30], autor[20];
	int ano,prat;
}tlivro;
int n=0;
//*************************************

void InserirLivro(tlivro l[])
{
if(n==MAX)
{ printf("\n Sistema sem espaço!\n");
return;
}
printf("\n*** CADASTRO DE LIVROS*** \n");
printf("\n Digite o título do livro: ");
fflush(stdin);
gets(l[n].titulo);
printf("\n Digite o autor do livro: ");
fflush(stdin);
gets(l[n].autor);
printf("\n Digite o ano do livro: ");
scanf("%d",&l[n].ano);
printf("\n Digite a prateleira em que se encontra: ");
scanf("%d",&l[n].prat);
fflus(stdin);

n++;
}

//*******************************

void mostrarlivros(tlivro l[])
{
int i;

for (i=0; i<n; i++)
{
printf("\n Livro cadastrado %d: ",i+1);
printf("\n Titulo: %s ",l[i].titulo);
printf("\n Autor: %s",l[i].autor);
printf("\n Ano de publicação: %d",l[i].ano);
printf("\n Prateleira: %d ",l[i].prat);

}
}

//*********************************

void BuscarNome( tlivro l[], char NomeB[]){
int i;
int existe=0;
	
for(i=0;i<n;i++)
{
if(strcmp(l[i].titulo,NomeB)==0){
printf("\n Livro cadastrado %d: ",i+1);
printf("\n Titulo: %s ",l[i].titulo);
printf("\n Autor: %s",l[i].autor);
printf("\n Ano de publicação: %d",l[i].ano);
printf("\n Prateleira: %d ",l[i].prat);
existe=1;
fflush(stdin);
}
}

if (existe==0){
printf("\n Este titulo não se encontra cadastrado nesse sistema!\n");
}
}

//************************************

void buscarAno( tlivro l[], int ano){
int i;
int existe=0;
for( i=0;i<n;i++){
if(ano< l[i].ano){
printf("\n Livro cadastrado %d: ",i+1);
printf("\n Titulo: %s ",l[i].titulo);
printf("\n Autor: %s",l[i].autor);
printf("\n Ano de publicação: %d",l[i].ano);
printf("\n Prateleira: %d ",l[i].prat);
existe=1;
fflush(stdin);
}
}
if (existe==0){
printf("\n não consta nenhum livro mais novo que este em nosso sistema!\n");
}
}

//***********************************

int menu ()
{
int op;
printf("\n *** SISTEMA DE CADASTRAMENTO DE LIVROS ***");
printf("\n 1- Inserir");
printf("\n 2- Mostrar");
printf("\n 3- Buscar por nome");
printf("\n 4- Buscar por ano");
printf("\n 0- Sair");
scanf("%d",&op);
return op;
}

//*********************************

int main (){
	tlivro livro[MAX];
char NomeB[30];
int op;
int ano;
do{
op = menu();
switch(op)
{
	case 1: InserirLivro(livro);
	fflush(stdin);
	
break;
	
	case 2: mostrarlivros(livro);
	fflush(stdin);
	
break;

    case 3: printf("\n Digite um nome para busca:");
    fflush(stdin);
    gets(NomeB);
    BuscarNome(livro,NomeB);
    
break;

    case 4: printf("\n Digite um ano para busca: ");
      fflush(stdin);
      scanf("%d",&ano);
      buscarAno(livro,ano);
      
break;

    case 0: printf("\n Sair do Sistema!");
    
}

printf("\n Pressione qualquer tecla do teclado para sair!\n");
getch();
system("cls");

}
while (op!=0);

}




