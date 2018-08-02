#include "biblioteca.h"

int main(int argc, char** argv) {
	char resposta;
	do {
		introducao();
		system("pause");
		system("cls");	
		menu();
		jogarNovo();
		printf("Deseja jogar de novo? [Digite [s] para SIM]: ");
		scanf("%c", &resposta);
		resposta = tolower(resposta); //converter letra maiuscula
		system("cls");
	} while (resposta == 's');
	return 0;
}
