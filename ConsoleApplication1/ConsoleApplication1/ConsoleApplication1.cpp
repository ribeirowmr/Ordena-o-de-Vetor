// ConsoleApplication.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>		
#include <ctime>		

using namespace std;

int bubble_sort()
{
	srand(time(NULL));
	const int TAMANHO = 100;
	int vetor[TAMANHO], troca;

	for (int indice = 0; indice < TAMANHO; indice++) {
		vetor[indice] = rand() % 100;
		cout << vetor[indice];
		cout << endl;

	}

	for (int indice = 0; indice < TAMANHO - 1; indice++) {

		for (int ind = indice + 1; ind < TAMANHO; ind++) {


			if (vetor[indice] > vetor[ind]) {
				troca = vetor[indice];
				vetor[indice] = vetor[ind];
				vetor[ind] = troca;
			}
		}
	}
	cout << endl;


	for (int indice = 0; indice < TAMANHO; indice++) {
		cout << "\n" << vetor[indice];
	}

	cout << endl;

	system("pause");

	return 0;
}


int main()
{
	clock_t tempo;
	double tempo_decorrido = 0.0;
	tempo = clock();

	for (int cont = 0; cont < 1000000; cont++)


		tempo_decorrido = double(clock() - tempo) / CLOCKS_PER_SEC;

	cout << tempo_decorrido << " segundos" << endl;
	bubble_sort();
	system("pause");
	return 0;
}
