using namespace std;
#include <iostream>
#pragma once

//Se dă un număr natural n. Să se genereze toate numerele cu exact n cifre prime.

unsigned n, sir[20], cifr[20];

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << sir[i];
	}
}

int solutie(int k) {
	if (k == n -1) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	for (int i = 0; i < 4; i++) {
		sir[i] = cifr[i];
		if (solutie(k)) {
			tipar();
		}
		else {
			back(k + 1);
		}
	}
}

void sol1289() {
	cout << "n=";
	cin >> n;
	cifr[0] = 2;
	cifr[1] = 3;
	cifr[2] = 5;
	cifr[3] = 7;
	back(0);
}