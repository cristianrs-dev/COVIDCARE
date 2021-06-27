#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

void imprimeTela_SISPEC(){
	printf("\t\t\t\t\t========================\n");
	printf("\t\t\t\t\t|       COVIDCARE      |\n");
	printf("\t\t\t\t\t========================\n");
}
void imprimeTela_MENU(){
	printf("========================================\n");
	printf("\n[1] CADASTRAR PACIENTE\n");
	printf("[2] CONSULTAR GRUPO DE RISCO\n");
	printf("[3] CONSULTAR REGISTRO\n");
	printf("[4] CADASTRAR NOVO USUÁRIO DO SISTEMA\n");
	printf("[5] SAIR DO SISTEMA \n");
	printf("========================================\n");
	printf("\nescolha uma opcao:");
}		
void imprimeTela_cadastroUsuario(){
	printf("==========================\n");
	printf("|  CADASTRO DE USUARIOS  |\n");
	printf("==========================\n");
}
void imprimeTela_cadastroPacientes(){
	printf("=========================\n");
	printf("| CADASTRO DE PACIENTES |\n");	
	printf("=========================\n");
}


struct ficha_paciente{
	char nome[50];
	int idade;
	char sexo[15];
	char cpf[12];
	char comorbidade[40];
	//data nascimento
	int dia,mes,ano;
	//endereco
	char rua[40];
	int numero;
	char bairro[20];
	char cidade[20];
	int cep;
};

int main(){
			setlocale(LC_ALL,"Portuguese");
			FILE *login, *cad_paciente, *gp_risco;
			struct ficha_paciente ficha_paciente[4];
			char usuario[20],pesquisaUsuario[20],pesquisaPaciente[50];
			int i,u,senha,pesquisaSenha,escolha,res;
		
			//efetuar login para entrar no sistema
			imprimeTela_SISPEC();
			printf("\n\t\t\t\t\tUSUÁRIO..: ");
			fflush(stdin);
			scanf("%s",&pesquisaUsuario);
			printf("\t\t\t\t\tSENHA..: ");
			fflush(stdin);
			scanf("%d",&pesquisaSenha);
				//validar login
				system("cls");
			login=fopen("login.txt","r");
					while(fscanf(login,"%s %d",usuario,&senha)!=EOF){
								if(strcmp(usuario,pesquisaUsuario)==0){
									if(senha==pesquisaSenha){
								do{
									system("cls");
									fflush(stdin);
									imprimeTela_MENU();
									scanf("%d",&escolha);
									system("cls");
									switch(escolha){
										case 1:
											do	{
													cad_paciente=fopen("cad_paciente.txt","a");
															if(cad_paciente!=NULL){
																	imprimeTela_cadastroPacientes();	
															}else{
																		printf("nao foi possivel abrir o cadastro\n");
															}
															//nome
															printf("\nNOME...........");
															fflush(stdin);
															//fgets(ficha_paciente[i].nome,50,stdin);
															scanf("%s",&ficha_paciente[i].nome);
															fprintf(cad_paciente,"%s ",ficha_paciente[i].nome);
															//sexo
															printf("SEXO [M]/[F]...........");
															fflush(stdin);
															scanf("%s",&ficha_paciente[i].sexo);
															fprintf(cad_paciente,"%s ",ficha_paciente[i].sexo);
															//idade
															printf("IDADE....:");
															fflush(stdin);
															scanf("%d",&ficha_paciente[i].idade);
															fprintf(cad_paciente,"%d ",ficha_paciente[i].idade);
															//data de nascimento
															printf("DATA DE NASCIMENTO (n/n/n)....:");
															fflush(stdin);
															scanf("%d/%d/%d",&ficha_paciente[i].dia,&ficha_paciente[i].mes,&ficha_paciente[i].ano);
															fprintf(cad_paciente,"%d/%d/%d ",ficha_paciente[i].dia,ficha_paciente[i].mes,ficha_paciente[i].ano);
															/*printf("dia.....");
															fflush(stdin);
															scanf("%d",&ficha_paciente[i].dia);
															fprintf(cad_paciente,"%d ",ficha_paciente[i].dia);
															printf("MÊS...........");
															fflush(stdin);
															scanf("%d",&ficha_paciente[i].mes);
															fprintf(cad_paciente,"%d ",ficha_paciente[i].mes);
															printf("ANO...........");
															fflush(stdin);
															scanf("%d",&ficha_paciente[i].ano);
															fprintf(cad_paciente,"%d ",ficha_paciente[i].ano);
															*/
															//cpf
															printf("CPF...........");
															fflush(stdin);
															scanf("%s",&ficha_paciente[i].cpf);
															fprintf(cad_paciente,"%s ",ficha_paciente[i].cpf);
															
															printf("ENDEREÇO\n");
															
															printf("RUA....:");
															fflush(stdin);
															scanf("%s",&ficha_paciente[i].rua);
															fprintf(cad_paciente,"%s ",ficha_paciente[i].rua);
															
															printf("NÚMERO DA CASA....:");
															fflush(stdin);
															scanf("%d",&ficha_paciente[i].numero);
															fprintf(cad_paciente,"%d ",ficha_paciente[i].numero);
															
															printf("BAIRRO...:");
															fflush(stdin);
															scanf("%s",&ficha_paciente[i].bairro);
															fprintf(cad_paciente,"%s ",ficha_paciente[i].bairro);
															
															printf("CIDADE....:");
															fflush(stdin);
															scanf("%s",&ficha_paciente[i].cidade);
															fprintf(cad_paciente,"%s ",ficha_paciente[i].cidade);
															
															printf("CEP....:");
															fflush(stdin);
															scanf("%d",&ficha_paciente[i].cep);
															fflush(stdin);
															fprintf(cad_paciente,"%d ",ficha_paciente[i].cep);
															
															printf("POSSUI ALGUMA COMORBIDADE....:");
															fflush(stdin);
															scanf("%s",&ficha_paciente[i].comorbidade);
															fprintf(cad_paciente,"%s\n",ficha_paciente[i].comorbidade);
															//verifica a idade e insere no grupo de risco
															if(ficha_paciente[i].idade>=60 || 2020-ficha_paciente[i].ano==60){
																gp_risco=fopen("gp_risco.txt","a");
														
																fprintf(gp_risco,"%s ",ficha_paciente[i].nome);
																fprintf(gp_risco,"%s ",ficha_paciente[i].sexo);
																fprintf(gp_risco,"%d ",ficha_paciente[i].idade);
																fprintf(gp_risco,"%d ",ficha_paciente[i].cep);
																fprintf(gp_risco,"%s \n",ficha_paciente[i].comorbidade);
																fclose(gp_risco);
															};
															i++;
															printf("deseja cadastrar outro paciente\n");
															printf("[1]-sim [2]-nao\n");
															fflush(stdin);
															scanf("%d",&res);
															system("cls");	
													}while(res!=2);	
													fclose(cad_paciente);
													
										break;
										case 2:
										//consultar grupo de risco
										do{
												printf("*************************************\n");
												printf("PESQUISAR PACIENTE NO GRUPO DE RISCO\n");
												printf("*************************************\n");
												printf("informe o nome do paciente:");
												fflush(stdin);
												scanf("%s",&pesquisaPaciente);
												gp_risco=fopen("gp_risco.txt","r");
													while(fscanf(gp_risco,"%s %s %d %d %s",&ficha_paciente[i].nome,&ficha_paciente[i].sexo,&ficha_paciente[i].idade,&ficha_paciente[i].cep,&ficha_paciente[i].comorbidade)!=EOF){
														if(strcmp(ficha_paciente[i].nome,pesquisaPaciente)==0){
															//nome,sexo,idade,cep,cormobidad
															printf("*********************");
															printf("\nregistro encontrado:\n");
															printf("*********************\n");
															printf("paciente:%s\n",ficha_paciente[i].nome);
															printf("sexo:%s\n",ficha_paciente[i].sexo);
															printf("idade:%d\n",ficha_paciente[i].idade);
															printf("cep:%d\n",ficha_paciente[i].cep);
															printf("doenças:%s\n",ficha_paciente[i].comorbidade);
															//system("pause");
														}
													}
												fclose(gp_risco);
											printf("realizar outra consulta:\n");
											printf("[1]-sim [2]-nao\n");
											fflush(stdin);
											scanf("%d",&res);
											system("cls");
										}while(res==1);
								
												
												break;
									case 3:
										//consultar registro
										break;	
									case 4:
										//casdastrar usuarios do sistema
												do{
													login=fopen("login.txt","a");
														if(login)
															imprimeTela_cadastroUsuario();
															printf("\ninforme um novo usuário:");
															fflush(stdin);
															scanf("%s",&usuario);
															fprintf(login,"\n%s ",usuario);
															printf("digite uma senha:");
															fflush(stdin);
															scanf("%d",&senha);
															fprintf(login,"%d",senha);
															printf("deseja cadastrar outro usuário\n");
															printf("[1]-sim [2]-nao\n");
															fflush(stdin);
															scanf("%d",&res);
															system("cls");
													}while(res==1);	
														fclose(login);
													
												break;
									case 5:
										break;	
										
									default:
										printf("OPÇÃO INVALIDA!\n");
											
									}
									}while(escolha!=5);
						}
								}else{
								
										//printf("usuario ou senha invalidos\n");
										system("cls");
				
								}
						
				}	
				fclose(login);
			return 0;
}


