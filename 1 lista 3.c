/*Defina uma estrutura que ir� representar bandas de m�sica. Essa estrutura deve ter o 
nome da banda, que tipo de m�sica ela toca, o n�mero de integrantes e em que 
posi��o do ranking essa banda est� dentre as suas bandas favoritas.
a) Agora crie um vetor que � do tipo tBanda que possa receber dados de at� 10 bandas.
b) Fa�a um looping para preencher as bandas de seu vetor de bandas.
c) Ap�s criar e preencher, exiba todas as informa��es das bandas/estruturas.
d) Pe�a para o usu�rio um valor entre 1 e 10 que representa a posi��o do ranking essa 
banda est� dentre as suas bandas favoritas.
e) Salve todos os dados em um arquivo bin�rio ou texto.
f) Seu programa deve exibir informa��es das bandas cuja posi��o no seu ranking � a que 
foi solicitada pelo usu�rio
g) Crie uma fun��o em C que pe�a ao usu�rio um g�nero de m�sica e exiba as bandas 
com este genero de m�sica e seu ranking. Utilize a fun��o strcmp da biblioteca 
string.h voc� para comparar as strings que representam o genero de banda.
h) Crie uma fun��o que pe�a o nome de uma banda ao usu�rio e diga se ela est� entre 
suas bandas favoritas ou n�o. Bandas favoritas possuem ranking entre 1 e 3.
i) Crie uma op��o excluir uma banda, para isso voc� deve sobrepor a posi��o que quer 
excluir pelo �ltimo registro e decrementar a qtd.
j) Desafio: Crie uma op��o para alterar dados de um registro.
k) Agora organize tudo em uma aplica��o que exibe um menu as op��es de preencher as 
estruturas e todas as op��es das quest�es passadas mais a possibilidade do usu�rio 
carregar os dados j� gravados.*/

#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct banda{
	char nome[40];
	char genero[40];
	int integrantes;
	int ranking;
}tbanda;

int qtd=0; 

//*********************************
int addBanda(tbanda b[]){
if(qtd==MAX)
return 0;
printf("Dados para banda\n");
printf("Nome:");
fflush(stdin); 
gets(b[qtd].nome);
printf("Genero:");
fflush(stdin); 
gets(b[qtd].genero);
printf("Integrantes:");
scanf("%d",&b[qtd].integrantes);
printf("Ranking:");
scanf("%d",&b[qtd].ranking);
qtd++;
return 1;  
}
//*******************************

void mostraBandas(tbanda b[]){
int i;
printf("* Bandas cadastradas **\n");
for(i=0;i<qtd;i++){
printf("Banda %d\n",i+1);
printf("Nome:%s\n",b[i].nome);
printf("Genero:%s\n",b[i].genero);
printf("Integrantes:%d\n",b[i].integrantes);
printf("Ranking:%d\n",b[i].ranking);
printf("---------------------------------------\n");
	}
}
//********************************
void buscaBanda(tbanda b[], char nomeBusca[40]){
int i, existe=0;
char aux[40];	
for(i=0;i<qtd;i++){
strcpy(aux,b[i].nome); 
if(strcmp( strupr(aux)   ,  strupr(nomeBusca)    )==0){ 
printf("*** Banda *** %d\n",i+1);
printf("Nome:%s\n",b[i].nome);
printf("Genero:%s\n",b[i].genero);
printf("Integrantes:%d\n",b[i].integrantes);
printf("Ranking:%d\n",b[i].ranking);
printf("---------------------------------------\n");
existe = 1;
	  }
	}
	if(!existe) 
	   printf("Banda nao encontrada :(\n");   
}
//*******************************
void buscaGenero(tbanda b[], char generoBusca[40]){
int i, existe=0;
char aux[40];	
for(i=0;i<qtd;i++){
strcpy(aux,b[i].genero);
if(strcmp( strupr(aux)   ,  strupr(generoBusca)    )==0){ 
printf("\n *** Banda *** %d\n",i+1);
printf("Nome:%s\n",b[i].nome);
printf("Genero:%s\n",b[i].genero);
printf("Integrantes:%d\n",b[i].integrantes);
printf("Ranking:%d\n",b[i].ranking);
printf("---------------------------------------\n");
existe = 1;
	  }
	}
	if(!existe) 
printf("Genero nao encontrado :(\n");   
}
//*********************************
void alteraBanda(tbanda b[], char nomeBusca[40]){
int i, existe=0;
char aux[40];	
for(i=0;i<qtd;i++){
strcpy(aux,b[i].nome); 
if(strcmp( strupr(aux)   ,  strupr(nomeBusca)    )==0){
printf("Novos dados para banda %s\n",b[i].nome);
printf("Novo nome:");
fflush(stdin); 
gets(b[i].nome);
printf("Novo genero:");
fflush(stdin); 
gets(b[i].genero);
printf("Integrantes:");
scanf("%d",&b[i].integrantes);
printf("Ranking:");
scanf("%d",&b[i].ranking);
existe = 1;
	  }
	}
	if(!existe) 
printf("Banda nao encontrada :(\n");   
}
//************************************

void removeBanda(tbanda b[], char nomeBusca[40]){
int i, existe=0;
char aux[40];	
for(i=0;i<qtd;i++){
strcpy(aux,b[i].nome); 
if(strcmp( strupr(aux)   ,  strupr(nomeBusca)    )==0){ 
qtd--;
existe = 1;
	  }
	}
if(!existe)
printf("Banda nao encontrada :(\n");  
	else
printf("Banda removida com sucesso!\n");    
}
//**************************
void salvarBandas(tbanda b[]){
int i;
FILE *arq;
arq = fopen("bandas.txt","w"); 
fprintf(arq,"%d\n",qtd); 
for(i=0;i<qtd;i++){
fprintf(arq,"%s\n",b[i].nome);
fprintf(arq,"%s\n",b[i].genero);
fprintf(arq,"%d\n",b[i].integrantes);
fprintf(arq,"%d\n",b[i].ranking);
	}
	printf("Dados salvos com sucesso :)\n");
	fclose(arq);
}
//************************
void carregaBandas(tbanda b[]){
FILE *arq;
int i;
arq = fopen("bandas.txt","r"); 
if(arq==NULL){
printf("Arquivo nao foi encontrado :(\n");
return;
	}
fscanf(arq,"%d",&qtd);
printf("Carregando dados");
for(i=0;i<qtd;i++){
fscanf(arq,"%s",&b[i].nome);
fscanf(arq,"%s",&b[i].genero);
fscanf(arq,"%d",&b[i].integrantes);
fscanf(arq,"%d",&b[i].ranking);
printf("...");
_sleep(500);
	}
fclose(arq);
system("cls"); 
}
//*************************
int menu(){
int op;
printf("* Sistema de Cadastro de Bandas Rock4U *\n");
printf("1- Adiciona Banda\n");
printf("2- Mostra Bandas\n");
printf("3- Busca Banda\n");
printf("4- Remove Banda\n");
printf("5- Altera Banda\n");
printf("6- Busca por Genero\n");
printf("0- Sair\n");
scanf("%d",&op);
return op;
}
//**************************
int main(){
tbanda b[MAX];
char busca[40];
int op;
carregaBandas(b);
do{
op = menu();
switch(op){
	case 1: if(addBanda(b)==1)
			printf("Banda adicionada :)\n");
			 		else
			printf("Limite de bandas atingido :(\n");
break;
	case 2: mostraBandas(b);
	
break;
	case 3: printf("Nome da banda para buscar:");
			fflush(stdin); gets(busca);
			buscaBanda(b,busca);
					
break;
	case 4: printf("Nome da banda para remover:");
			fflush(stdin); gets(busca);
			removeBanda(b,busca);
					
break;

	case 5: printf("Nome da banda para alterar:");
			fflush(stdin); gets(busca);
			alteraBanda(b,busca);
			
break;	
	case 6: printf("Genero da banda para buscar:");
			fflush(stdin); gets(busca);
			buscaGenero(b,busca);
			

break;				
		
	case 0: salvarBandas(b);
			printf("Saindo... \n");
			
				break;
			default: printf("Opcao invalida\n");			 	
		}
		getch(); 
		system("cls");
	}while(op!=0);	

	return 0;
}
