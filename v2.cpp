#include <iostream>
#include <conio.h>
#define nsamples 5
#define outputs 3
using namespace std;


string X[nsamples] = {
	"1100",
	"0011",
	"1101",
	"1000",
	"0111"
};

string Y[nsamples] = {
	"011",
	"000",
	"111",
	"010",
	"001"
};


string compute(string s) {
	s = s.substr(1) + (s[0] == s[1]? '0': '1');
	return s;
}

string norm2out(string s) {
	s = s.substr(s.length() - outputs);
	return s;
}

int sums = 0;
bool vr = false;

int main(int argc, char *argv[]) {
	while (!vr) {
		vr = true;
		for (int i = 0; i < nsamples; i++) {
			X[i] = compute(X[i]);
			
			if (Y[i] != norm2out(X[i])) {
				vr = false;
				break;
			}
		}
		
		sums ++;
		
		cout << "Iter " << sums << "\n";
	}
	
	cout << "\nModelo optimo en: " << sums << " iters\n";
	getch();
	
	return 0;
}
