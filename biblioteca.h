#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define L 11 //numero LINHAS matriz
#define C 20 //numero COLUNAS matriz

char letrasDigitadas[27]={0};
char alfabeto[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'y', 'z'};
char alfabetoExibido[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'y', 'z'};
int  qtdLetrasDigitadas=0;
void jogarNovo();

void introducao() {
	
printf("...........##..#######...######....#######.......\n");                                           
printf("...........##.##.....##.##....##..##.....##......\n");                                        
printf("...........##.##.....##.##........##.....##......\n");                                        
printf("...........##.##.....##.##...####.##.....##......\n");     
printf(".....##....##.##.....##.##....##..##.....##......\n");  
printf(".....##....##.##.....##.##....##..##.....##......\n");
printf("......######...#######...######....#######.......\n");
printf(".................................................\n");
printf("................########.....###.................\n");
printf("................##.....##...##.##................\n");
printf("................##.....##..##...##...............\n");
printf("................##.....##.##.....##..............\n");
printf("................##.....##.#########..............\n");
printf("................##.....##.##.....##..............\n");
printf("................########..##.....##..............\n");
printf(".................................................\n");
printf(".########..#######..########...######.....###....\n");
printf(".##.......##.....##.##.....##.##....##...##.##...\n");
printf(".##.......##.....##.##.....##.##........##...##..\n");
printf(".######...##.....##.########..##.......##.....##.\n");
printf(".##.......##.....##.##...##...##.......#########.\n"); 
printf(".##.......##.....##.##....##..##....##.##.....##.\n");
printf(".##........#######..##.....##..######..##.....##.\n\n");                          

	
}

void menu() {
	
	int tema;
	void forca(char palavra[][C], int t);
	int escolherTema();

	char palavraAnimal[L][C] = {"cavalo", "gato", "girafa", "jacare", "leao", "tatu", "lebre", "pato", "tigre", "formiga"};
	char palavraPaises[L][C] = {"brasil", "alemanha", "inglaterra", "holanda", "italia", "franca", "espanha", "colombia", "peru", "argentina"};
	char palavraCores[L][C] = {"azul", "verde", "vermelho", "laranja", "amarelo", "preto", "branco", "rosa", "roxo", "cinza"};
	char palavraFrutas[L][C] = {"maca", "pera", "banana", "morango", "laranja", "kiwi", "ameixa", "acerola", "goiaba", "limao"};
	
	tema = escolherTema();
	
	if (tema == 5) {
		srand(time(NULL));
        /* variavel tema recebe valor aleatorio de 0 a 3 */
		tema = (rand() % 3) + 1;
	}
	switch(tema) {
	case 1:
		system("cls");
		printf("TEMA ANIMAL\n");
		forca(palavraAnimal, tema);
		break;
	case 2:
		system("cls");
		printf("TEMA PAISES\n");
		forca(palavraPaises, tema);
		break;
	case 3:
		system("cls");
		printf("TEMA CORES\n");
		forca(palavraCores, tema);
		break;
	case 4:
		system("cls");
		printf("TEMA FRUTAS\n");
		forca(palavraFrutas, tema);
		break;
	}
}

int escolherTema() {
	
	int t; //escolher tema
	
	printf("Escolha um tema a seguir:\n");
	printf("Digite [1] para tema ANIMAL\n");
	printf("Digite [2] para tema PAISES\n");
	printf("Digite [3] para tema CORES\n");
	printf("Digite [4] para tema FRUTAS\n");
	printf("Digite [5] para tema ALEATORIO\n");

	scanf("%d", &t);
	
	if(t >= 1 && t <= 5) {
		return t;
	} else {
		printf("TEMA INVALIDO\n");
		system("pause");
		system("cls");
		
	}
}

int validacao(char l) {
	int b=0,flag=0;

	if(qtdLetrasDigitadas == 0) {
		letrasDigitadas[qtdLetrasDigitadas] = l;
		qtdLetrasDigitadas++;
		flag = 1;
	} else if(b < qtdLetrasDigitadas) {
		for(b = 0; (b < qtdLetrasDigitadas) && (letrasDigitadas[b] != l); b++);
			if(b >= qtdLetrasDigitadas) {
				letrasDigitadas[qtdLetrasDigitadas] = l;
				qtdLetrasDigitadas++;
				flag = 1;
			}
	} else {
		flag = 0;
	}
	
	return flag;
}

void marcaAlfabeto(char letra) {
	
	int i, flag;
	
	flag = validacao(letra);
	
	if (flag == 1) {
		for(i = 0; alfabetoExibido[i] != '\0' ; i++) {
			if (letra == alfabetoExibido[i]) {
				alfabetoExibido[i] = '_';
			}
		}
		printf("%s \n", alfabetoExibido);
	} else
		printf("Letra ja digitada!\n");
}

void boneco(int erro) {
	
		if (erro <= 0) {
			printf("  ______      \n");
			printf(" |/     |     \n");
			printf(" |      	  \n"); 
			printf(" |            \n");
			printf(" |            \n");
			printf(" |            \n");
			printf(" |            \n");
			printf("_|___         \n");
			printf("\n\n");
		} else if (erro == 1) {
			printf("  ______      \n");
			printf(" |/     |     \n");
			printf(" |      O	  \n"); 
			printf(" |            \n");
			printf(" |            \n");
			printf(" |            \n");
			printf(" |            \n");
			printf("_|___         \n");
		} else if (erro == 2) {
			printf("  ______      \n");
			printf(" |/     |     \n");
			printf(" |      O	  \n"); 
			printf(" |     /      \n");
			printf(" |            \n");
			printf(" |            \n");
			printf(" |            \n");
			printf("_|___         \n");
		} else if (erro == 3) {
			printf("  ______      \n");
			printf(" |/     |     \n");
			printf(" |      O	  \n"); 
			printf(" |     / \\   \n");
			printf(" |            \n");
			printf(" |            \n");
			printf(" |            \n");
			printf("_|___         \n");
		} else if (erro == 4) {
			printf("  ______      \n");
			printf(" |/     |     \n");
			printf(" |      O	  \n"); 
			printf(" |     /|\\   \n");
			printf(" |            \n");
			printf(" |            \n");
			printf(" |            \n");
			printf("_|___         \n");
		} else if (erro == 5) {
			printf("  ______      \n");
			printf(" |/     |     \n");
			printf(" |      O	  \n"); 
			printf(" |     /|\\   \n");
			printf(" |      |     \n");
			printf(" |            \n");
			printf(" |            \n");
			printf("_|___         \n");
		} else if (erro == 6) {
			printf("  ______      \n");
			printf(" |/     |     \n");
			printf(" |      O	  \n"); 
			printf(" |     /|\\   \n");
			printf(" |      |     \n");
			printf(" |     /      \n");
			printf(" |            \n");
			printf("_|___         \n");
		} else if (erro == 7) {
			printf("  ______      \n");
			printf(" |/     |     \n");
			printf(" |      O	  \n"); 
			printf(" |     /|\\   \n");
			printf(" |      |     \n");
			printf(" |     / \\   \n");
			printf(" |            \n");
			printf("_|___         \n");
		}
}

void forca(char palavra[][C], int t) {
	
	char forca[C] = {0};
    char letra;
    int i, j, tamanhoPalavra, h, certa = 0, cont = 0, erro = 0;
    
    //sorteia uma palavra aleatoria na matriz
    srand(time(NULL));
    i = rand()%9;
    //printf("%s\n", palavra[i]);
    
    //primeiro for descobre o tamanho da palavra o segundo procura o caractere na palavra
    for(h = 0 ; h < strlen(palavra[i]); h++) {
        forca[h] = '-';
        tamanhoPalavra = strlen(palavra[i]);
    }
    
	do {
        printf("digite uma letra: "); 
        fflush(stdin);
        scanf("%c", &letra);
        letra = tolower(letra); //converter letra maiuscula
        if(letra >= 97 && letra <= 122) {
	        certa = 0;
	        for(j = 0; palavra[i][j] != '\0' ; j++) {
	            if (palavra[i][j] == letra) {
	                forca[j] = letra;
	                if (forca[j] == letra){ 
	                	fflush(stdin);
	                	certa = 1;
	                	cont++;
	                }
				}
	        }
	        system("cls");
	        switch(t) {
	        	case 1:
	        		printf("TEMA ANIMAL\n");
	        		break;
	        	case 2:
	        		printf("TEMA PAISES\n");
	        		break;
	        	case 3:
	        		printf("TEMA CORES\n");
	        		break;
	        	case 4:
	        		printf("TEMA FRUTAS\n");
	        		break;
			}
	        if (certa == 1) {
	        	printf("Letra Certa!\n");
	        } else {
	        	printf("Letra Errada!\n");
	        	erro++;
			}
			marcaAlfabeto(letra); //chama funcao marcaAlfabeto passando letra como **
			boneco(erro); //chama variavel boneco
			printf("%s\n", forca);
	        //printf("Palavra certa %d", cont);
    } else {
    	printf("%c Nao e' uma letra valida\n", letra);
	}
	
    } while (erro <= 6 && (strcmp(forca, palavra[i]) != 0));
    system("cls");
    if(strcmp(forca, palavra[i]) == 0) // verificar ganhador
    	printf("VOCE VENCEU!\n");
    else
    	printf("VOCE PERDEU!\n");
    system("pause");
    system("cls");
}

void jogarNovo() {
	
	int i;
	
	fflush(stdin);
	qtdLetrasDigitadas = 0;
	
	for(i=0; i<27; i++) {
		letrasDigitadas[i] = 0;
	}
	
	for(i=0; i<27; i++){
		alfabetoExibido[i] = alfabeto[i];
		//printf("%s", alfabetoExibido);
	}  
}
