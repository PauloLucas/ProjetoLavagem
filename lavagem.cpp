#include<stdio.h>
#include<locale.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define DUCHAtp		 1
#define EXPRESSAtp	 2
#define GERALtp 	 3
#define GERAL_CERAtp 4

#define DUCHAvl 	 15.00
#define EXPRESSAvl 	 20.00
#define GERALvl 	 30.00
#define GERAL_CERAvl 40.00

typedef struct{
	char placa[8];
	bool situacao;
	char DateTime[18];
	char fucionario[30];
	int servicoTipo;
	float servivoValor;
	float valorAdicional;
	float desconto;
}lavagem;

main(){
	setlocale(LC_ALL,"");
	
	lavagem servLavagem[1000];
	int controlLavagem=0, busca,indice=0,indiceAux=0, ajuda=0;
	
	int contAberta=0;
	int contFechada=0;
	int contDucha=0;
	int contExpressa=0;
	int contGeral=0;
	int contGeralCera=0;
	float totalVlDucha=0;
	float totalVlExpressa=0;
	float totalVlGeral=0;
	float totalVlGeralCera=0;
	
	char SystemOn,upperPlaca[8],adi,pic,suj;
	
	while(SystemOn != 'S'){
		printf("\nSistema de lavagens Posto Tylaier - Espaço para registros %i",(1000-controlLavagem));
		printf("\n _MENU_____________________________________________\n|   1-Registro 					   |\n|   2-Busca 					   |\n|   3-Pagamento 				   |\n|   4-Excluir 					   |\n|   5-Menu					   |\n|__________________________________________________|\n\n");
		fflush(stdin);
		scanf("%c",&SystemOn);
		switch(SystemOn){
			case '1':
				if(controlLavagem<1001){

					printf("Informe a placa do veiculo:\n(apenas letras e numeros)\n\n");
					fflush(stdin);

					gets(upperPlaca);
						for(indice=0;indice<7;indice++){
							if(!isalnum(upperPlaca[indice])){//testa o digito
			  					printf("\nPlaca invalida! Tente novamente.\n");
			  					indice=8;
			  					break;
							}
							if(ispunct(upperPlaca[indice])){//testa se o digito é um caracter especial
			  					printf("\nPlaca invalida! Tente novamente.\n");
			  					indice=8;
			  					break;
							}
							if(isspace(upperPlaca[indice])){//testa se o digito é um espaço
								printf("\nPlaca invalida! Tente novamente.\n");
								indice=8;
								break;
							}
							if(isdigit(upperPlaca[indice])){//testa se são numeros nas posiçoes 0,1,2
								if(indice==0||indice==1||indice==2){
									printf("\nPlaca invalida! Tente novamente.\n");
									indice=8;
									break;
								}
							}
							if(isalpha(upperPlaca[indice])){//testa se são letras nas posiçoes 3,5,6
								if(indice==3||indice==5||indice==6){
									printf("\nPlaca invalida! Tente novamente.\n");
									indice=8;
									break;
								}else{
									upperPlaca[indice] = toupper(upperPlaca[indice]);//Coloca as letras em caixa alta
								}
							}
	     				}
	     				

						if(indice!=8){

							for(indice=0;indice<7;indice++){
								servLavagem[controlLavagem].placa[indice] = upperPlaca[indice];
							}
							
							_strtime(servLavagem[controlLavagem].DateTime);
							servLavagem[controlLavagem].situacao = false;
							servLavagem[controlLavagem].valorAdicional = 0.00;
							servLavagem[controlLavagem].desconto = 0.00;

							do{
								printf("\nInforme tipo do serviço:\n1-Ducha\n2-Expressa\n3-Geral\n4-Geral com cera\n");
								scanf("%i",&servLavagem[controlLavagem].servicoTipo);
								if(servLavagem[controlLavagem].servicoTipo<1||servLavagem[controlLavagem].servicoTipo>4){
					 				printf("\nOpção Invalida! Tente novamente.\n");
								}
							}while(servLavagem[controlLavagem].servicoTipo<1||servLavagem[controlLavagem].servicoTipo>4);

							switch(servLavagem[controlLavagem].servicoTipo){
								case 1:
									servLavagem[controlLavagem].servivoValor = DUCHAvl;
								break;
								case 2:
									servLavagem[controlLavagem].servivoValor = EXPRESSAvl;
								break;
								case 3:
									servLavagem[controlLavagem].servivoValor = GERALvl;
								break;
								case 4:
									servLavagem[controlLavagem].servivoValor = GERAL_CERAvl;
								break;
							}
							
		     				do{
								printf("\nAdicionar adicional? S/N\n");
								fflush(stdin);
								scanf("%c",&adi);
								adi = toupper(adi);
								if(adi!='S'&&adi!='N'){
									printf("\nOpção invalida!\n");
								}
							}while(adi!='S'&&adi!='N');
							if(adi=='S'){
								do{
								printf("\nAdicional utilitário? S/N\n");
								fflush(stdin);
								scanf("%c",&pic);
								pic = toupper(pic);
									if(pic!='S'&&pic!='N'){
										printf("\nOpção invalida!\n");
									}
								}while(pic!='S'&&pic!='N');
								if(pic=='S'){
									servLavagem[controlLavagem].valorAdicional = servLavagem[controlLavagem].valorAdicional + 10;
								}
								do{
								printf("\nAdicional sujeira pesada? S/N\n");
								fflush(stdin);
								scanf("%c",&suj);
								suj = toupper(suj);
									if(suj!='S'&&suj!='N'){
										printf("\nOpção invalida!\n");
									}
								}while(suj!='S'&&suj!='N');
								if(suj=='S'){
									servLavagem[controlLavagem].valorAdicional = servLavagem[controlLavagem].valorAdicional + 10;
								}
							}

							printf("\nServiço gravado com sucesso as %s.\n",servLavagem[controlLavagem].DateTime);
							controlLavagem++;
						}
						
				}else{
					printf("\nEspaço insuficiente em memória.\n");
				}
				system("pause");
				system("cls");
			break;
			case '2':
				//BUSCA
				if(controlLavagem>0){
					do{
						printf("\nInforme a opção de busca desejada:\n1-Busca por placa.\n2-Busca lavagens em aberto.\n\n");
						scanf("%i",&busca);
						if(busca<1 || busca>2){
							printf("\nOpção Invalida! Tente novamente.\n");
						}
					}while(busca<1 || busca>2);
					switch(busca){
						case 1:
							printf("Informe a placa do veiculo:\n(apenas letras e numeros)\n");
							fflush(stdin);

							gets(upperPlaca);
							for(indice=0;indice<7;indice++){
								if(!isalnum(upperPlaca[indice])){//testa o digito
				  					printf("\nPlaca invalida! Tente novamente.\n");
				  					indice=8;
				  					break;
								}
								if(ispunct(upperPlaca[indice])){//testa se o digito é um caracter especial
				  					printf("\nPlaca invalida! Tente novamente.\n");
				  					indice=8;
				  					break;
								}
								if(isspace(upperPlaca[indice])){//testa se o digito é um espaço
									printf("\nPlaca invalida! Tente novamente.\n");
									indice=8;
									break;
								}
								if(isdigit(upperPlaca[indice])){//testa se são numeros nas posiçoes 0,1,2
									if(indice==0||indice==1||indice==2){
										printf("\nPlaca invalida! Tente novamente.\n");
										indice=8;
										break;
									}
								}
								if(isalpha(upperPlaca[indice])){//testa se são letras nas posiçoes 3,5,6
									if(indice==3||indice==5||indice==6){
										printf("\nPlaca invalida! Tente novamente.\n");
										indice=8;
										break;
									}else{
										upperPlaca[indice] = toupper(upperPlaca[indice]);//Coloca as letras em caixa alta
									}
								}
							}
							if(indice<8){
								for(indice = 0;indice<=controlLavagem;indice++){
									if(!strcmp(servLavagem[indice].placa,upperPlaca)){//verifica a placa informada com as armazenadas na memoria.
										printf("\n\nPlaca pesquisada: %s\n",upperPlaca);
										printf("\n\nIndice: %i\n",indice);
										printf("\nPlaca: %s\n",servLavagem[indice].placa);
										printf("\nHora: %s\n",servLavagem[indice].DateTime);
										if(servLavagem[indice].situacao==false){
											printf("\nSituação: Em aberto.\n");
										}else{
											printf("\nSituação: Paga.\n");
										}
										switch(servLavagem[indice].servicoTipo){
											case 1:
												printf("\nServiço: Ducha\n");
											break;
											case 2:
												printf("\nServiço: Expressa\n");
											break;
											case 3:
												printf("\nServiço: Geral\n");
											break;
											case 4:
												printf("\nServiço: Geral com cera\n");
											break;
										}
										printf("\nAdicional: R$%.2f\n",servLavagem[indice].valorAdicional);
										printf("\nDesconto: R$%.2f\n",servLavagem[indice].desconto);

										printf("\nValor total: R$%.2f\n",(servLavagem[indice].servivoValor + servLavagem[indice].valorAdicional)-servLavagem[indice].desconto);
									}
								}
							}
						break;
						case 2:
							ajuda=0;
							for(indice = 0;indice<controlLavagem;indice++){
								if(servLavagem[indice].situacao==false){
									if(servLavagem[indice].servivoValor>0){
										printf("\nPlaca: %s\t",servLavagem[indice].placa);
										printf("Valor total: R$%.2f\n\n\n",(servLavagem[indice].servivoValor + servLavagem[indice].valorAdicional)-servLavagem[indice].desconto);
										ajuda = 1;
									}
								}
							}
							if(ajuda!=1){
								printf("\nNão existem registros a serem exibidos.\n");
							}
						break;
					}
				}else{
					printf("\nNão existem registros a serem exibidos.\n");
				}
				system("pause");
				system("cls");
			break;
			case '3':
				//PAGAMENTO
				if(controlLavagem>0){
					printf("Informe a placa do veiculo:\n(apenas letras e numeros)\n\n");
					fflush(stdin);

					gets(upperPlaca);
					for(indice=0;indice<7;indice++){
						if(!isalnum(upperPlaca[indice])){//testa o digito
		  					printf("\nPlaca invalida! Tente novamente.\n");
		  					indice=8;
		  					break;
						}
						if(ispunct(upperPlaca[indice])){//testa se o digito é um caracter especial
		  					printf("\nPlaca invalida! Tente novamente.\n");
		  					indice=8;
		  					break;
						}
						if(isspace(upperPlaca[indice])){//testa se o digito é um espaço
							printf("\nPlaca invalida! Tente novamente.\n");
							indice=8;
							break;
						}
						if(isdigit(upperPlaca[indice])){//testa se são numeros nas posiçoes 0,1,2
							if(indice==0||indice==1||indice==2){
								printf("\nPlaca invalida! Tente novamente.\n");
								indice=8;
								break;
							}
						}
						if(isalpha(upperPlaca[indice])){//testa se são letras nas posiçoes 3,5,6
							if(indice==3||indice==5||indice==6){
								printf("\nPlaca invalida! Tente novamente.\n");
								indice=8;
								break;
							}else{
								upperPlaca[indice] = toupper(upperPlaca[indice]);//Coloca as letras em caixa alta
							}
						}
					}
					if(indice<8){
						for(indice = 0;indice<=controlLavagem;indice++){
							if(!strcmp(servLavagem[indice].placa,upperPlaca)){
								if(servLavagem[indice].situacao==false){
									do{
										printf("\nRealizar desconto? S/N\n");
										fflush(stdin);
										scanf("%c",&adi);
										adi = toupper(adi);
										if(adi!='S'&&adi!='N'){
											printf("\nOpção invalida!\n");
										}
									}while(adi!='S'&&adi!='N');
									if(adi=='S'){
										do{
										printf("\nDesconto funcionário? S/N\n");
										fflush(stdin);
										scanf("%c",&pic);
										pic = toupper(pic);
											if(pic!='S'&&pic!='N'){
												printf("\nOpção invalida!\n");
											}
										}while(pic!='S'&&pic!='N');
										if(pic=='S'){
											printf("\nInforme o nome do funcionário:\n");
											fflush(stdin);
											gets(servLavagem[indice].fucionario);
											servLavagem[indice].desconto = servLavagem[indice].desconto + 15;
										}
										if(servLavagem[indice].desconto<15){
											do{
												printf("\nDesconto JetOil? S/N\n");
												fflush(stdin);
												scanf("%c",&suj);
												suj = toupper(suj);
													if(suj!='S'&&suj!='N'){
														printf("\nOpção invalida!\n");
													}
											}while(suj!='S'&&suj!='N');
											if(suj=='S'){
												servLavagem[indice].desconto = servLavagem[indice].desconto + 10;
											}
										}
									}
									printf("Total R$ %.2f",(servLavagem[indice].servivoValor+servLavagem[indice].valorAdicional)-servLavagem[indice].desconto);
									do{
										printf("\nRealizar pagemento? S/N\n");
										fflush(stdin);
										scanf("%c",&suj);
										suj = toupper(suj);
											if(suj!='S'&&suj!='N'){
												printf("\nOpção invalida!\n");
											}
									}while(suj!='S'&&suj!='N');
									if(suj=='S'){
										servLavagem[indice].situacao = true;
										printf("\nSituação : Pago\n");
									}else{
										servLavagem[indice].desconto = 0;
									}
								}else{
									printf("\nNão é possivel realizar pagemento em serviços já finalizados.\n");
								}
							}
						}
					}
				}else{
					printf("\nNão existem registros a serem exibidos.\n");
				}
				system("pause");
				system("cls");
			break;
			case '4':
				//EXCLUSÃO
				if(controlLavagem>0){
					printf("Informe a placa do veiculo a ser excluido:\n(apenas letras e numeros)\n\n");
					fflush(stdin);

					gets(upperPlaca);
					for(indice=0;indice<7;indice++){//valida a placa digito a digito
						if(!isalnum(upperPlaca[indice])){//testa o digito
		  					printf("\nPlaca invalida! Tente novamente.\n");
		  					indice=8;
		  					break;
						}
						if(ispunct(upperPlaca[indice])){//testa se o digito é um caracter especial
		  					printf("\nPlaca invalida! Tente novamente.\n");
		  					indice=8;
		  					break;
						}
						if(isspace(upperPlaca[indice])){//testa se o digito é um espaço
							printf("\nPlaca invalida! Tente novamente.\n");
							indice=8;
							break;
						}
						if(isdigit(upperPlaca[indice])){//testa se são numeros nas posiçoes 0,1,2
							if(indice==0||indice==1||indice==2){
								printf("\nPlaca invalida! Tente novamente.\n");
								indice=8;
								break;
							}
						}
						if(isalpha(upperPlaca[indice])){//testa se são letras nas posiçoes 3,5,6
							if(indice==3||indice==5||indice==6){
								printf("\nPlaca invalida! Tente novamente.\n");
								indice=8;
								break;
							}else{
								upperPlaca[indice] = toupper(upperPlaca[indice]);//Coloca as letras em caixa alta
							}
						}
					}

					if(indice!=8){
						for(indice = 0;indice<=controlLavagem;indice++){
							if(!strcmp(servLavagem[indice].placa,upperPlaca)){//verifica a placa informada com as armazenadas na memoria.
								if(servLavagem[indice].situacao==false){
									indiceAux = indice;
									controlLavagem--;
									do{
										servLavagem[indiceAux] = servLavagem[indiceAux+1];
										indiceAux++;
									}while(indiceAux<controlLavagem);
									printf("\nExclusão realizada com sucesso.\n");
									break;
								}else{
									printf("\nNão é possivel excluir serviços já finalizados.\n");
								}
							}
							if(indice==controlLavagem){
								printf("Placa não encontrada!\n");
							}
						}
						
					}
				}else{
					printf("\nNão existem registros a serem exibidos.\n");
				}
				system("pause");
				system("cls");
			break;
			case '5':
				//MENU
				/*RELATÓRIO
					  SAIR*/
				printf("\nSelecione a opção desejada\n");
				printf("\n1-Relatório de lavagens do dia %s\n2-Sair e encerrar o sistema\n",__DATE__);
				fflush(stdin);
				scanf("%c",&SystemOn);
				switch(SystemOn){
					case '1':
						totalVlDucha=0;
						totalVlExpressa=0;
						totalVlGeral=0;
						totalVlGeralCera=0;
						contAberta=0;
						contFechada=0;
						contDucha=0;
						contExpressa=0;
						contGeral=0;
						contGeralCera=0;
						if(controlLavagem>0){
							for(indice=0;indice<controlLavagem;indice++){
								switch(servLavagem[indice].servicoTipo){
									case 1:
										contDucha++;
										totalVlDucha = totalVlDucha+((servLavagem[indice].servivoValor + servLavagem[indice].valorAdicional)-servLavagem[indice].desconto);
									break;
									case 2:
										contExpressa++;
										totalVlExpressa = totalVlExpressa+((servLavagem[indice].servivoValor + servLavagem[indice].valorAdicional)-servLavagem[indice].desconto);
									break;
									case 3:
										contGeral++;
										totalVlGeral = totalVlGeral+((servLavagem[indice].servivoValor + servLavagem[indice].valorAdicional)-servLavagem[indice].desconto);
									break;
									case 4:
										contGeralCera++;
										totalVlGeralCera = totalVlGeralCera+((servLavagem[indice].servivoValor + servLavagem[indice].valorAdicional)-servLavagem[indice].desconto);
									break;
								}
								if(servLavagem[indice].situacao==true){
									contFechada++;
								}else{
									contAberta++;
								}
								
							}
							printf("\t________________________________________________________________\n");
							printf("\t|==>Relatório de lavagens do dia %s<==\t\t\t|\n",__DATE__);
							printf("\t|==>Total serviços aberto: %i - Total serviços concluidos: %i<==\t|\n",contAberta,contFechada);
							printf("\t|==>Total Duchas: %i - Total movimentado: %.2f<==\t\t|\n",contDucha,totalVlDucha);
							printf("\t|==>Total Expressas: %i - Total movimentado: %.2f<==\t\t|\n",contExpressa,totalVlExpressa);
							printf("\t|==>Total Geral: %i - Total movimentado: %.2f<==\t\t\t|\n",contGeral,totalVlGeral);
							printf("\t|==>Total Geral c/ cera: %i - Total movimentado: %.2f<==\t|\n",contGeralCera,totalVlGeralCera);
							printf("\t|==>Total: %.2f<==\t\t\t\t\t\t|\n",(totalVlDucha+totalVlExpressa+totalVlGeral+totalVlGeralCera));
							printf("\t________________________________________________________________\n");
							for(indice=0;indice<controlLavagem;indice++){
								printf("PLACA: %s  -  ",servLavagem[indice].placa);
								if(servLavagem[indice].situacao==true){
									printf("SITUAÇÃO: Pago  -  ");
								}else{
									printf("SITUAÇÃO: A pagar  -  ");
								}
								printf("HORÁRIO: %s  -  ",servLavagem[indice].DateTime);
								printf("VALOR: %.2f\n",(servLavagem[indice].servivoValor + servLavagem[indice].valorAdicional)-servLavagem[indice].desconto);
							}
							
						}else{
							printf("\nNão existem registros a serem exibidos.\n");
						}
						system("pause");
						system("cls");
					break;
					case '2':
						do{
							printf("\nDeseja realmente sair e encerrar o sistema? S/N\n");
							fflush(stdin);
							scanf("%c",&adi);
							adi = toupper(adi);
							if(adi!='S'&&adi!='N'){
								printf("\nOpção invalida!\n");
							}
						}while(adi!='S'&&adi!='N');
						if(adi=='S'){
							SystemOn='S';
						}
						system("pause");
						system("cls");
					break;
					default:
						SystemOn='x';
						printf("Opção Invalida!\nTente novamente...\n");
						system("pause");
						system("cls");
					break;
				}
			break;
			default:
				SystemOn='x';
				printf("Opção Invalida!\nTente novamente...\n");
				system("pause");
				system("cls");
			break;
		}
	}
}
