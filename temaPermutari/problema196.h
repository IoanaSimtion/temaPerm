using namespace std;
#include <iostream>
#pragma once

//Se citesc două numere naturale nenule n și m. Să se afişeze, în ordine lexicografică,
//aranjamentele de câte m elemente ale mulţimii {1,2,..,n}.

unsigned sir[20], n, m;

void tipar() {
	cout << endl;
	for (int i = 0; i < m; i++) {
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
	if (k == m) {
		return 1;
	}
	return 0;
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

void sol196() {
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	back(0);
}