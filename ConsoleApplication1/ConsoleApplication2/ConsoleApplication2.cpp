
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>		
#include <ctime>
using namespace std;


int shellSort(int arr[], int n)
{
	
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		
		for (int i = gap; i < n; i += 1)
		{
		int temp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n)
{
	for (int i = 0; i<n; i++)
		cout << arr[i] << " ";
}

int main()
{
	srand(time(NULL));
	const int TAMANHO = 1000;
	int arr[TAMANHO] , i;
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int indice = 0; indice < TAMANHO; indice++) {
		arr[indice] = rand() % 1001;
		cout << arr[indice];
		cout << endl;

	}

	cout << "Array antes de classificar : \n";
	printArray(arr, n);

	shellSort(arr, n);

	cout << "\nArray após a classificação: \n";
	printArray(arr, n);

	clock_t tempo;
	double tempo_decorrido = 0.0;
	tempo = clock();

	for (int cont = 0; cont < 1000000; cont++)


		tempo_decorrido = double(clock() - tempo) / CLOCKS_PER_SEC;

	cout << tempo_decorrido << " segundos" << endl;
	
	system("pause");

	return 0;
}
