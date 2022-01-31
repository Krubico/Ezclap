#include<cmath>
#include<fstream>
#include<iomanip>
#include<iostream>
using namespace std;
int main() {
	// storing id and scores into text file
	ofstream foutid;
	foutid.open("scorerid.txt", fstream::app);
	if (foutid.is_open()) {
        foutid << endl << 2;
	}
	foutid.close();

    ofstream fouts;
    fouts.open("scores.txt", fstream::app);
    if (fouts.is_open()) {
        fouts << endl << 15;
    }
    fouts.close();
	// putting id into an array
	int n = 0; // n is the id integer in the file
	int id[100000];

	ifstream finid;
	finid.open("scorerid.txt");
	while (!finid.eof()) {
		finid >> id[n];
		n++;
	}
	finid.close();
	// putting scores into an array
	int m = 0; // m is the score integer in the file
	int scores[100000];

	fstream fins;
	fins.open("scores.txt");
	while (!fins.eof()) {
		fins >> scores[m];
		m++;
	}
	fins.close();
	// size of array
	int size = sizeof(id) / sizeof(id[0]);
	int largest;
	cout << left << fixed;
	cout << setw(20) << "Position" << setw(20) << "ID" << "Top scores\n";
	for (int a = 1; a <= 5; a++) {
		//storing first array element as largest value
		int x = 0;
		largest = scores[0];
		for (int i = 0; i < size; i++) {
			if (largest < scores[i]) {
				largest = scores[i];
				x = i;
			}
		}
		cout << setw(20) << a << setw(20) << id[x] << largest << endl;
		std::copy(id + (x + 1), id + (size - 1), id + x);
		std::copy(scores + (x + 1), scores + (size - 1), scores + x);
	}

	system("pause");
	return 0;
}