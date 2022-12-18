using namespace std;
#include <iostream>
#pragma once

//Se citesc două numere naturale n și m. Afișați în ordine lexicografică toate submulțimile 
//cu m elemente ale mulțimii {1, 2, ..., n} în care nu există două elemente pare alăturate.

unsigned sir[20], n, m;

void tipar() {
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << sir[i] << ' ';
	}
}

int valid(int k) {
	for (int i = 0; i < k; i++) {
		if (sir[i] % 2 == 0 && sir[i + 1] % 2 == 0) {
			return 0;
		}
	}
	for (int i = 0; i < k; i++) {
		if (sir[k] == sir[i]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {
	if (k > m) {
		return 1;
	}
	else{
		return 0;
	}
}

void back(int k) {
	for (int i = 1; i <= n; i++) {
		sir[k] = i;
		if (valid(k)) {
			if (solutie(k)) {
				tipar();
			}
			else {
				back(k + 1);
			}
		}
	}
}

void sol3152() {
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	back(0);
}