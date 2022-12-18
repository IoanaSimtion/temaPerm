using namespace std;
#include <iostream>
#pragma once

//Se citesc un număr natural n având cifrele diferite două câte două și o cifră c. 
//Afișați în ordine crescătoare numerele formate din c cifre distincte care se pot obține din cifrele lui n.

unsigned v[20], n, dim = 0, nr[20], c, flag[10];

//todo functie ce memoreaza cifrele unui nr intr-un vector

void memorareCifre() {
	while (n) {
		v[dim] = n % 10;
		dim++;
		n /= 10;
	}
}

//todo functie ce afiseaza un vector

void afisareVector() {
	for (int i = 0; i < dim; i++) {
		cout << v[i] << ' ';
	}
}

//todo functie ce sorteaza cresc un vector

void sortCresc() {
	bool flag = 0;
	do {
		flag = 1;
		for (int i = 0; i < dim - 1; i++) {
			if (v[i] > v[i + 1]) {
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				flag = 0;
			}
		}
	} while (flag == 0);
}

//todo backtracking permutari

void numar() {
	n = 0;
	for (int i = 0; i < c; i++) {
		n = n * 10 + nr[i] % 10;
	}
	cout << n << endl;
}

int valid(int k) {
	for (int i = 0; i < k; i++) {
		if (nr[k] == nr[i]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {
	if (k == dim - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	for (int i = 0; i < dim; i++) {
		nr[k] = v[i];
		if (valid(k)) {
			if (solutie(k)) {
				numar();
			}
			else {
				back(k + 1);
			}
		}
	}
}

void sol3158() {
	cout << "n=";
	cin >> n;
	cout << "c=";
	cin >> c;
	memorareCifre();
	sortCresc();
	//afisareVector();
	back(0);
}