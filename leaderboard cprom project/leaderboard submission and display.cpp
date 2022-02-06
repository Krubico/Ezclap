#include<cmath>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
using namespace std;
bool cmp(pair<string, int>& c,
	pair<string, int>& d)
{
	return c.second > d.second;
}

int main() {
	ifstream lbfile;
	int a;
	char x = ' ';
	cin >> a;
	if (a == 1) {
		lbfile.open("normal.txt");
	}
	if (a == 2) {
		cin >> x;
		if (x == 's') {
			lbfile.open("simple timer.txt");
		}
		else if (x == 'h') {
			lbfile.open("hard timer.txt");
		}
		else if (x == 'e') {
			lbfile.open("expert timer.txt");
		}
	}
	string username;
	int score;
	void sort_lb(map<string, int>&lb);
	map<string, int> lb;
	if (lbfile.is_open()) {
		while (!lbfile.eof()) {
			lbfile >> username >> score;
			lb[username] = score;
		}
	}
	lbfile.close();
	sort_lb(lb);

	system("pause");
	return 0;
}

void sort_lb(map<string, int>& lb)
{

	// Declare vector of pairs
	vector<pair<string, int> > A;
	cout << left << fixed << setprecision(2);

	// Copy key-value pair from Map
	// to vector of pairs
	for (auto& it : lb) {
		A.push_back(it);
	}

	// Sort using comparator function
	sort(A.begin(), A.end(), cmp);

	A.resize(5);
	lb = map<string, int>(A.begin(), A.end());
	// Print the sorted value
	for (auto& it : A) {

		cout << setw(15) << it.first
			<< it.second << endl;
	}
}
