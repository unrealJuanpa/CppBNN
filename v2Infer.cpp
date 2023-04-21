#include <iostream>
#include <conio.h>
#define nsamples 5
#define outputs 3
#define niters 25836
using namespace std;


string X[nsamples] = {
	"1100",
	"0011",
	"1101",
	"1000",
	"0111"
};


string compute(string s) {
	s = s.substr(1) + (s[0] == s[1]? '0': '1');
	return s;
}

string norm2out(string s) {
	s = s.substr(s.length() - outputs);
	return s;
}


int main(int argc, char *argv[]) {
	cout << "Calculando " << niters << "...\n";
	
	for (int sd = 0; sd < niters; sd++) {
		for (int i = 0; i < nsamples; i++) {
			X[i] = compute(X[i]);
		}
	}
	
	for (int i = 0; i < nsamples; i++) {
		cout << norm2out(X[i]) << "\n";
	}
	
	getch();
	
	return 0;
}
