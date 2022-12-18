using namespace std;
#include <iostream>
#pragma once

//Să se genereze în ordine lexicografică elementele produsului cartezian A1×A2×⋯×An.

unsigned n, s[20], a[20];

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i] << ' ';
	}
}

int solutie(int k) {
	if (k > n - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	for (int i = 0; i < a[k]; i++) {
		s[k] = i;
		if (solutie(k)) {
			cout << "da";
			tipar();
		}
		else {
			back(k + 1);
		}
	}
}

void sol1278() {
	cout << "n=";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	back(0);
}