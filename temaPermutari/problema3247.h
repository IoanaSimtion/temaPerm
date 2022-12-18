using namespace std;
#include <iostream>
#pragma once

//Se citește un număr natural n. Afișați în ordine lexicografică toate submulțimile 
//mulțimii {1, 2, ..., n} care sunt formate dintr-un număr impar de elemente.

unsigned sir[20], k, n;

void tipar() {
	cout << endl;
	for (int i = 0; i < k; i++) {
		cout << sir[i] << ' ';
	}
}

int valid(int k) {
	for (int i = 0; i < k; i++) {
		if (sir[k] == sir[i]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {
	if (k % 2 == 1 && k < n) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	unsigned val;
	for (val = 1; val <= n; val++) {
		sir[k] = val;
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

void sol3247() {
	cout << "n=";
	cin >> n;
	back(0);
}