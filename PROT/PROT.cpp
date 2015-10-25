#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void BuildMap(unordered_map<string, string>* codons) {
	ifstream f;
	f.open("codons.txt");
	string s;
	while (getline(f, s)) {
		istringstream ss(s);
		string k, c;
		while (ss >> k >> c) {
			(*codons)[k] = c;
		}
	}
}

// prints to command line translated protein from amino acid string
int main() {
	unordered_map<string, string> codons;
	BuildMap(&codons);

	ifstream f("input.txt");

	string s, t;
	getline(f, s);

	for (int c = 0; c < s.length(); c+=3) {
		t = s.substr(c, 3);
		if (codons[t] == "Stop") {
			cout << endl;
		}
		else {
			cout << codons[t];
		}
	}
	return 0;
}