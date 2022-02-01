/*Elaborar um programa que auxilie no controle de uma fazenda de gado que possuí um 
total de 100 cabeças de gado. A base de dados é formada por um conjunto de
estruturas (registros) contendo os seguintes campos referente a cada cabeça de gado:
 código: código da cabeça de gado,
 leite: número de litros de leite produzido por semana,
 alim: quantidade de alimento ingerida por semana - em quilos,
 nasc: data de nascimento - mês e ano,
 abate: ‘N" (não) ou ‘S’ (sim).
O campo nasc. é do tipo struct data que por sua vez, possui dois campos:
o mês
o ano
Elaborar funções para:
a) Ler a base de dados (código, leite, alim, nasc.mês e nasc.ano), armazenado em um vetor 
de estruturas.
b) O sistema que deve preencher o campo abate, considerando que a cabeça de gado irá 
para o abate caso:
 tenha mais de 5 anos, ou;
produza menos de 40 litros de leite por semana, 
Crie o menu de opções para:
c) Retornar a quantidade total de leite produzida por semana na fazenda.
d) Retornar a quantidade total de alimento consumido por semana na fazenda.
e) Listar os animais que devem ir para o abate.
f) Salvar dados em arquivo e carregar dados
g) Sair do programa.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 100

typedef struct n 
{
	char mes[15];
	int ano;
}tnascimento;

//*****************************
	
	typedef struct
	{
		char codigo [15]; 
		char abate[1];
		float leite, alimentacao;
		struct n dataNasc;
	}tgado;
	
//**************************
	
int AnoAtual = 2022;
int quant= 0;

void salvarArquivo(tgado g[]) {
FILE*arq;
int i=0;
arq=fopen("Gado.txt","wb");
fwrite(&g[i],sizeof(tgado),quant,arq);
		printf("\n Os dados foram salvos om sucesso! \n");
		fclose(arq);
	}
//*****************************

void CarregarArquivo(tgado g[])	{	
FILE*arq;
arq=fopen("Gado.txt", "rb");
if(arq==NULL)
{
printf("\n Arquivo nao encontrado! \n");
return;
		}
while(fread(&g[quant],sizeof(tgado),1,arq)>0)
quant++;
printf("\n Dados foram carregados com sucesso! \n");
fclose(arq);
}

//*******************************
	void cadastrar(tgado g[]){
		
printf("\n ---- Cadastra de cabecas de gado---- \n");
printf("\n Codigo da cabeca de gado \n");
fflush(stdin);gets(g[quant].codigo);
printf("\n Litros de leite por semana: \n");
scanf("%f", &g[quant].leite);
printf("\n Quantidade de alimento consumido por semana: \n");
scanf("%f", &g[quant].alimentacao);
printf("\n Data de nascimeto");
printf("\n Mes (por extenso);");
fflush(stdin); gets(g[quant].dataNasc.mes);
printf("\n Ano(0000)");
scanf("%d", &g[quant]. dataNasc.ano);

//******************************
		
int idade = AnoAtual - g[quant]. dataNasc.ano;
		if (idade>5 || g[quant].leite <40){
			g[quant].abate[0]= 's';
		}
		else
		{
			g[quant].abate[0]= 'n';
		}
		printf("\n Abate: %s", g[quant].abate);
		quant++;
		
			}
		 float produT(tgado Gado[])
			 {
		int i;
		float Total=0;
		for(i=0; i<quant; i++)
			{
			 		Total+=Gado[i].leite;
				 }
		return Total;
			 	 
			 }
		float consumoT(tgado Gado[])
			{
		int i;
		float Total=0;
		for(i=0; i<quant;i++)
				{
		Total+= Gado[i].alimentacao;
				}
		return Total;
	
			}
//*************************************

void ListarAbates(tgado gado[])
{
int i, flag=0;
for(i=0; i<quant; i++)
{
if (strcmp (gado[i].abate,"s")==0)
{
flag=1;
printf("\n ----Gado %d---- \n",i+1);
printf("\n Codigo: %s \n",gado[i].codigo);
}
}
if (flag==0)
{
printf("\n Nao ha animais cadastrados para o abate!\n");
}
}

//*************************************
void mostrarCadastro(tgado Gado[]){
int i;
if(quant>0)
{
printf("\n ---- H %d cabaças de gado cadastrados ----\n", quant);
		
for(i=0; i<quant;i++)
{
printf("\n ---- Gado %d ----\n",i+1);
printf("\n Codigo: %s \n",Gado[i].codigo);
printf("\n Litros de leite por semana: %1.f\n", Gado[i].leite);
printf("\n Quantidade de alimento consumido por semana: %1.f\n",Gado[i].alimentacao);
printf("\n data e nascimento: %s %d\n", Gado[i].dataNasc.mes, Gado[i].dataNasc.ano);
}
} else
{
printf("\n Nenhum animal cadastrado!\n");
}	
}

//*************************************			

int menu ()
{
int op;
printf("\n ----- Controle de cabecas de gado ---- \n");
printf("\n 1- Inserir novo animal\n");
printf("\n 2- Animais cadastrados\n");
printf("\n 3- Leite produzido por semana\n");
printf("\n 4- Alimento consumido por semana\n");
printf("\n 5- Animais que devem ir para o abate\n");
printf("\n 6- Salvar em arquivo\n");
printf("\n 7- Carregar arquivo\n");
printf("\n 0- Sair\n");
scanf("%d", &op);	
			
return op;
}

//*********************************

main()
{
tgado g[MAX];
int op;
do {
op=menu();
switch(op)
    	{
        case 1: cadastrar(g);
		 
  break;
		 
		case 2: mostrarCadastro(g);
		  
  break;
		 
		case 3: produT (g);
		 
  break; 
		 
		case 4: consumoT (g);
		 
  break;
		 
		case 5: ListarAbates (g);
		 
  break;
		 
		case 6: salvarArquivo (g);
		 
  break;
		 
	    case 7: CarregarArquivo (g);
		 
  break;
		 
		case 0: printf("\n Sair");	
		 
  break;
		}
getch();
system("cls");

}
while(op!=0);
return 0;
		
					}			
				
				
