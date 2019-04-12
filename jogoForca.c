#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <gconio.h>

FILE* arquivo = NULL;
char palavras[20][50];

void setPalavras(){

	int t=0;
	for(int i=0; i<1; i++){
		printf("Cadastre uma palavra:\n");
		scanf(" %s", palavras[i]);
		if(strcmp(palavras[i], "") == 0)
			break;
		fwrite(palavras[t],sizeof(palavras[20]),1,arquivo);
		t++;
	}
	fclose(arquivo);
}
void lerPalavra(int optGrupo){
    char nome[20];
	int i=0;
	if(optGrupo == 6)
        optGrupo = 1+ rand()%5;
	switch(optGrupo)
	{
        case 1: arquivo = fopen("animais.txt","rb+");
                if (!arquivo)
                    arquivo = fopen("animais.txt","wb+");
                if (!arquivo){
                    printf("Programa não conseguiu abrir o arquivo!\n");
                    return;
                    }
                strcpy(nome,"animais.txt");
                break;

        case 2: arquivo = fopen("mse.txt","rb+");
                if (!arquivo)
                    arquivo = fopen("mse.txt","wb+");
                if (!arquivo){
                    printf("Programa não conseguiu abrir o arquivo!\n");
                    return;
                }
                strcpy(nome,"mse.txt");
                break;

        case 3: arquivo = fopen("paises.txt","rb+");
                if (!arquivo)
                    arquivo = fopen("paises.txt","wb+");
                if (!arquivo){
                    printf("Programa não conseguiu abrir o arquivo!\n");
                    return;
                }
                strcpy(nome,"paises.txt");
                break;
        case 4: arquivo = fopen("profissoes.txt","rb+");
                if (!arquivo)
                    arquivo = fopen("profissoes.txt","wb+");
                if (!arquivo){
                    printf("Programa não conseguiu abrir o arquivo!\n");
                    return;
                }
                strcpy(nome,"profissoes.txt");
                break;
        case 5: arquivo = fopen("timedefutebol.txt","rb+");
                if (!arquivo)
                    arquivo = fopen("timedefutebol.txt","wb+");
                if (!arquivo){
                    printf("Programa não conseguiu abrir o arquivo!\n");
                    return;
                }
                strcpy(nome,"timedefutebol.txt");
                break;
    }

	if(arquivo == NULL)
        {
		printf("Erro ao abrir o arquivo\n");
		printf("af\n");
		exit(0);
	}
	while(!feof(arquivo)){
		fread(palavras[i],sizeof(palavras[20]),1,arquivo);		//Realiza a cópia de uma estrutura em arquivo para uma estrutura em memória principal
		i++;
	}

}
void getGrupos(int optGrupos){
    if(optGrupos == 1)
        printf("ANIMAL");
    if(optGrupos == 2)
        printf("MINHA SOGRA É");
    if(optGrupos == 3)
        printf("PAÍS");
    if(optGrupos == 4)
        printf("PROFISSÃO");
    if(optGrupos == 5)
        printf("TIME DE FUTEBOL (BR)");
}


void getForca(int contErros)
{
    if(contErros==0)
    {
        printf("\n==============================================================\n");
		printf("\t----\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("==============================================================\n");
    }
    if(contErros==1)
    {
        printf("\n==============================================================\n");
		printf("\t----\n");
		printf("\t|  0\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("==============================================================\n");
    }
    if(contErros==2)
    {
        printf("\n==============================================================\n");
		printf("\t----\n");
		printf("\t|  0\n");
		printf("\t| /| \n");
		printf("\t|\n");
		printf("\t|\n");
		printf("==============================================================\n");
    }
     if(contErros==3)
    {
        printf("\n==============================================================\n");
		printf("\t----\n");
		printf("\t|  0\n");
		printf("\t| /|\\\n");
		printf("\t|\n");
		printf("\t|\n");
		printf("==============================================================\n");
    }
     if(contErros==4)
    {
        printf("\n==============================================================\n");
		printf("\t----\n");
		printf("\t|  0\n");
		printf("\t| /|\\\n");
		printf("\t| _|\n");
		printf("\t|\n");
		printf("==============================================================\n");
    }
    if(contErros==5)
    {
        printf("\n==============================================================\n");
		printf("\t----\n");
		printf("\t|  0\n");
		printf("\t| /|\\\n");
		printf("\t| _|_\n");
		printf("\t|\n");
		printf("==============================================================\n");
    }
}
void jogo(){
	srand(time(NULL));
	int optGrupo;
    printf("ESCOLHA UM GRUPO DE PALAVRAS\n1- Animais\n2- Minha Sogra É\n3- Países\n4- Profissões\n5- Times de Futebol(BR)\n6- RANDOM\n0- Voltar ao Menu Principal:\n");
    scanf(" %d",&optGrupo);
    system("clear");
    if(optGrupo == 0)
        return;
    if(optGrupo == 6)
        optGrupo = 1+rand()%5;
    lerPalavra(optGrupo);

	int tamanho_palavra;
	int sortPalavra;
	char palavra_selecionada[20];
	char caracter;
	sortPalavra = rand()%10;								//Sorteia palavra
	tamanho_palavra = strlen(palavras[sortPalavra]);		//Recebe o tamanho da palavra
	strcpy(palavra_selecionada, palavras[sortPalavra]);

	int vAux[tamanho_palavra];
	for(int i=0;i<tamanho_palavra;i++)
            vAux[i] = 0;

	/*printf("\t------\n");
	printf("\t|\n");
	printf("\t|\t\t\t\tDICA:");
	getGrupos(optGrupo);
	printf("\t|\n");
	printf("\t|\n");

	printf("\t|\t");*/
	int contErros = 0;
	system("clear");
	printf("A dica é : ");
	getGrupos(optGrupo);
	getForca(contErros);
	printf("\n\t");
	for(int i=0; i<tamanho_palavra; i++)
		printf("_ ");
	
    int contAcertos = 0;
    
    int achou = 0;
    int ok = 1;
    char letras[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int letrasAux[26];
    for(int i=0;i<26;i++)
        letrasAux[i] = 0;

	printf("\n\n\t");

	do{
		printf("\n\nDigite uma letra: ");
		scanf(" %c", &caracter);
		system("clear");
		achou = 0;

//		printf("Palavra Sorteada: %s\nTamanho: %d Letras\n", palavra_selecionada, tamanho_palavra);
		system("clear");
		printf("**A dica é : ");
		getGrupos(optGrupo);
		getForca(contErros);	//Desenha forca
		printf("\n\t");
		
		for(int i=0; i<tamanho_palavra; i++){
			
			if(caracter == palavra_selecionada[i]){
				
				vAux[i] = 1;
				contAcertos++;
				achou = 1;
            }
			
			if (!vAux[i]){
				
                printf("_ ");
            }
            else{
				
                printf("%c ", palavra_selecionada[i]);           
			}
            
            for(int j=0;j<tamanho_palavra;j++){
				
                if(vAux[j]==0)
                {
                    ok = 0;
                    break;
                }
                if(j==(tamanho_palavra-1) )
                    ok = 1;
            }

            if(ok)
            {
                system("clear");
                printf("\n\nPARABÉNS! Você ganhou! \\o/ \n");
                printf("A palavra era : '%s'\n\nPress Enter para continuar...",palavra_selecionada);
                setbuf(stdin, NULL);
                getchar();
                system("clear");
                return;
            }
        }
        if(!achou)
        {
            for(int i=0;i<26;i++)
            {
                if(caracter == letras[i])
                    letrasAux[i] = 1;
            }
            contErros++;
            
            system("clear");
            
            printf("--A dica é : ");
			getGrupos(optGrupo);
			getForca(contErros);
            
            system("clear");
            
			printf("--A dica é : ");
			getGrupos(optGrupo);
			getForca(contErros);
		
        if(contErros>0)
        {
            printf("\nLETRAS que NÃO são: ");
            for(int i=0;i<26;i++)
            {
                if(letrasAux[i] == 1)
                    printf("%c ",letras[i]);
            }
        }
        
        printf("\n\t");
        for(int i=0; i<tamanho_palavra; i++){
			if (!vAux[i]){
					
					printf("_ ");
				}
				else{
					
					printf("%c ", palavra_selecionada[i]);           
				}
		}
        }
        
        if(contErros == 5)
        {
            printf("\n\nDEAD!\nA palavra era ' %s ' \n\nPress Enter para continuar...",palavra_selecionada);
				setbuf(stdin, NULL);
				getchar();
				system("clear");
                return;
        }
     
	}while(1);
}
void menuCadastro()
{
    int opt;
    do{
        printf("CADASTRO DE PALAVRAS\n1- Animais\n2- Minha Sogra É\n3- Países\n4- Profissões\n5- Times de Futebol(BR)\n0- Voltar ao Menu Principal:\n");
        scanf(" %d",&opt);
        switch(opt)
        {
            case 1: arquivo = fopen("animais.txt","rb+");
                    if (!arquivo)
                        arquivo = fopen("animais.txt","wb+");
                    if (!arquivo){
                        printf("Programa não conseguiu abrir o arquivo!\n");
                        return;
                    }
                    if(arquivo)
                        setPalavras();
                    break;
            case 2: arquivo = fopen("mse.txt","rb+");
                    if (!arquivo)
                        arquivo = fopen("mse.txt","wb+");
                    if (!arquivo){
                        printf("Programa não conseguiu abrir o arquivo!\n");
                        return;
                    }
                    if(arquivo)
                        setPalavras();
                    break;
            case 3: arquivo = fopen("paises.txt","rb+");
                    if (!arquivo)
                        arquivo = fopen("paises.txt","wb+");
                    if (!arquivo){
                        printf("Programa não conseguiu abrir o arquivo!\n");
                        return;
                    }
                    if(arquivo)
                        setPalavras();
                    break;
            case 4: arquivo = fopen("profissoes.txt","rb+");
                    if (!arquivo)
                        arquivo = fopen("profissoes.txt","wb+");
                    if (!arquivo){
                        printf("Programa não conseguiu abrir o arquivo!\n");
                        return;
                    }
                    if(arquivo)
                        setPalavras();
                    break;
            case 5: arquivo = fopen("timedefutebol.txt","rb+");
                    if (!arquivo)
                        arquivo = fopen("paises.txt","wb+");
                    if (!arquivo){
                        printf("Programa não conseguiu abrir o arquivo!\n");
                        return;
                    }
                    if(arquivo)
                        setPalavras();
                    break;
            case 0: break;
            default: printf("Opção inválida!!\n");
                    break;
        }
        
    }while(opt!=0);
    
    system("clear");

}

void menu(){
	int opc;

	do{
		printf("\n=================================================================\n");
		printf("|\t\t\tJOGO DA FORCA\t\t\t\t|\n");
		printf("=================================================================\n");
		printf("|\t----\t\t\t\t\t\t\t|\n");
		printf("|\t|  0\tDesenvolvido por Denilson Melo e Lucas Pimenta  |\n");
		printf("|\t| /|\\\tBacharelado em Sistemas de Informação\t\t|\n");
		printf("|\t| _|_\tEstrutura de Dados I\t\t\t\t|\n");
		printf("|\t|\t\t\t\t\t\t\t|\n");
		printf("=================================================================\n");
		printf("| 1-- JOGAR\t\t\t\t\t\t\t|\n| 2-- CADASTRAR PALAVRAS\t\t\t\t\t|\n| 0-- SAIR\t\t\t\t\t\t\t|\n");
		printf("=================================================================\n");
		printf("| DIGITE A OPÇÃO QUE DESEJA: ");
		scanf(" %d", &opc);
		system("clear");

		switch(opc){
			case 1: jogo();
				//	setbuf(stdin, NULL);
				//	getchar();
					break;
            case 2: menuCadastro();
                    break;

			case 0: printf("\nObrigado, Volte Sempre!\n");
					getchar();
					fclose(arquivo);
					exit(0);

			default: printf("Opção Inválida\n");
					 setbuf(stdin, NULL);
					 getchar();
					 break;
		}
	//	system("clear");

	}while(1);
}
int main()
{
	menu();
	return 0;
}

