#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include<windows.h>
using namespace std;
int question(int qnNo);
int main()
{
	srand(time(NULL));
	int i = 0, qnNo;
	int counter[20] = { 0 };
	double sum = 0;
	bool found;
	
	
	for (int j = 0; j < 5; j++)
	{
		found = false;
		while (found == false)
		{
			qnNo = rand() % 20 + 1;
			for (int k = 1; k <= 20; k++)
			{
				if (qnNo == k && counter[k - 1] == 0)
				{
					cout << "Qn" << j+1 << ")" << endl;
					i = question(qnNo);
					sum += i;
					counter[k - 1]++;
					found = true;
				}
			}
		}
	}

	cout << "Total Score = " << sum << endl;
	system("pause");
	return 0;
}

int question(int qnNo)
{
	fstream inFile;
	string qn;
	char ans, cAns[20] = { 'b','d','b','a','c','a','a','c','b','d','c','c','b','b','c','b','b','b','c','a'};
	int i=1;
	
	if (qnNo == 1) inFile.open("Qn1.txt");
	else if (qnNo == 2) inFile.open("Qn2.txt");
	else if (qnNo == 3) inFile.open("Qn3.txt");
	else if (qnNo == 4) inFile.open("Qn4.txt");
	else if (qnNo == 5) inFile.open("Qn5.txt");
	else if (qnNo == 6) inFile.open("Qn6.txt");
	else if (qnNo == 7) inFile.open("Qn7.txt");
	else if (qnNo == 8) inFile.open("Qn8.txt");
	else if (qnNo == 9) inFile.open("Qn9.txt");
	else if (qnNo == 10) inFile.open("Qn10.txt");
	else if (qnNo == 11) inFile.open("Qn11.txt");
	else if (qnNo == 12) inFile.open("Qn12.txt");
	else if (qnNo == 13) inFile.open("Qn13.txt");
	else if (qnNo == 14) inFile.open("Qn14.txt");
	else if (qnNo == 15) inFile.open("Qn15.txt");
	else if (qnNo == 16) inFile.open("Qn16.txt");
	else if (qnNo == 17) inFile.open("Qn17.txt");
	else if (qnNo == 18) inFile.open("Qn18.txt");
	else if (qnNo == 19) inFile.open("Qn19.txt");
	else if (qnNo == 20) inFile.open("Qn20.txt");

	while (!inFile.eof())
	{

		getline(inFile, qn);
		cout << qn << endl;

	}
	cout << endl << "Ans: ";
	cin >> ans;
	if (ans == cAns[qnNo-1])
	{
		cout << "\nCorrect Answer!" << endl;
		system("pause");
		i=1;
	}
	else
	{
		cout << "\nSorry wrong Answer!" << endl;
		system("pause");
		i=-1;
	}
	inFile.close();
	
	system("CLS");
	return i;
}