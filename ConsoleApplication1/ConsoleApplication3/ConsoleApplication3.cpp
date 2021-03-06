﻿// ConsoleApplication3.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include<stdio.h> 
#include <string>
#include <stdlib.h>
#include <cstdlib>		
#include <ctime>
using namespace std;


void imprime(int * X, int tam) {
	for (int i = 0; i < tam; ++i)
	{
		cout << "[" << X[i] << "]";
	}
	cout << "\n";
}
void intercala(int X[], int inicio, int fim, int meio) {
	int posLivre, inicio_vetor1, inicio_vetor2, i;
	int aux[10];
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1;
	posLivre = inicio;
	while (inicio_vetor1 <= meio && inicio_vetor2 <= fim) {
		if (X[inicio_vetor1] <= X[inicio_vetor2])
		{
			aux[posLivre] = X[inicio_vetor1];
			inicio_vetor1++;
		}
		else {
			aux[posLivre] = X[inicio_vetor2];
			inicio_vetor2++;
		}
		posLivre++;
	}
	 
	for (int i = inicio_vetor1; i <= meio; ++i)
	{
		aux[posLivre] = X[i];
		posLivre++;
	}
	  
	for (int i = inicio_vetor2; i <= fim; ++i)
	{
		aux[posLivre] = X[i];
		posLivre++;
	}
	  
	for (int i = inicio; i <= fim; ++i)
	{
		X[i] = aux[i];
	}
}
void merge(int X[], int inicio, int fim) {
	int meio;
	if (inicio < fim)
	{
		meio = (inicio + fim) / 2;
		merge(X, inicio, meio);
		merge(X, meio + 1, fim);
		intercala(X, inicio, fim, meio);
		imprime(X, 10);
	}
}
int main()
{
	int X[] = { 3,0,5,8,2,4,9,7,1,6 };
	merge(X, 0, 9);
	
	clock_t tempo;
	double tempo_decorrido = 0.0;
	tempo = clock();

	for (int cont = 0; cont < 1000000; cont++)


		tempo_decorrido = double(clock() - tempo) / CLOCKS_PER_SEC;

	cout << tempo_decorrido << " segundos" << endl;
	
	system("pause");
	return 0;
}


