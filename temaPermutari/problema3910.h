using namespace std;
#include <iostream>
#pragma once

//Se citesc trei numere naturale a b n. Să se afișeze, în ordine lexicografică, 
//șirurile cu n elemente distincte din mulțimea {a, a + 1, ..., b}.

unsigned a, b, n, sir[20];

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
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
	if (k >= n) {
		return 1;
	}
	return 0;
}

void back(int k) {
	for (int i = a; i <= b; i++) {
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



void sol3910() {
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "n=";
	cin >> n;
	back(0);
}
