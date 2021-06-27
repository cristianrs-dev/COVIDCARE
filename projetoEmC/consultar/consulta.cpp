#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct logar{
	char usuario[15];
	int senha;
};

int main(){
	FILE *arq;
	struct logar log[2];
	char nome[50],pesquisa[20],usuario[100],*name;
	int i,u,igual,senha,user,pass,senhaPesquisada,valida;
	printf("1-cadastrar: ");
	printf("2-validar: ");
	printf("3-exibir registro:");
	scanf("%d",&i);
	switch(i){
	case 1:
	arq=fopen("arq.txt","a");
	printf("digite login:");
	fflush(stdin);
	scanf("%s",&log[i].usuario);
	fprintf(arq,"%s ",log[i].usuario);
	printf("digite sua senha:");
	fflush(stdin);
	scanf("%d",&log[i].senha);
	fprintf(arq,"%d\n",log[i].senha);
	fclose(arq);
	break;
	case 2:
	printf("\n\nvalidar login:");
		fflush(stdin);
		scanf("%s",&pesquisa);
		
		printf("digite senha:");
		fflush(stdin);
		scanf("%d",&pass);
		
		arq=fopen("arq.txt","r");
		while(fscanf(arq,"%s %d",nome,&senha)!=EOF){
			if(strcmp(nome,pesquisa)==0)
				if(senha==pass)
				printf("registro encontrado:\n %s",nome);
			else
				printf("registro nao encontrado\n");
		}
		fclose(arq);
			break;
		case 3:
			printf("\n\ninforme nome:");
			fflush(stdin);
			scanf("%s",&pesquisa);
			arq=fopen("arq.txt","r");
		while(fscanf(arq,"%s %d",log[i].usuario,&log[i].senha)!=EOF){
			if(strcmp(log[i].usuario,pesquisa)==0)
				//if(log[i].senha==pass)
				printf("registro encontrado:\n usuario:%s\n senha:%d\n",log[i].usuario,log[i].senha);
			//else
			//	printf("registro nao encontrado\n");
			
		}
		fclose(arq);
			break;
			
}
}
