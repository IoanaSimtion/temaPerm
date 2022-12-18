using namespace std;
#include <iostream>
#pragma once

//Se citește o multime cu n numere naturale. Afișați în ordine lexicografică toate 
//permutările mulțimii citite în care elementul minim nu își schimbă poziția.

unsigned v[20], n, nr[20], minim=INT_MAX, pozMin=0;

//todo functie ce determina elementul minim si poz acestuia

void elemMinim() {
	for (int i = 0; i < n; i++) {
		if (v[i] < minim) {
			minim = v[i];
			pozMin = i;
		}
	}
}

//todo afisare vector

void afisareVector() {
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
}

//todo backtracking permutari

void tipar() {
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << nr[i] << ' ';
	}
}

int valid(int k) {
	for (int i = 0; i < n; i++) {
		if (nr[i] == minim && i != pozMin) {
			return 0;
		}
	}

	for (int i = 0; i < k; i++) {
		if (nr[k] == nr[i]) {
			return 0;
		}
	}
	return 1;
}

int solutie(int k) {
	if (k == n - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void back(int k) {
	for (int i = 0; i < n; i++) {
		nr[k] = v[i];
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

			
void sol3161() {
	cout << "n=";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	//afisareVector();
	elemMinim();
	back(0);
	//cout << endl << "min=" << minim << "   poz=" << pozMin << endl;
}