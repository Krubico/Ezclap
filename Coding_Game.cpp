#include<cmath>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<string>
#include <ctime>
#include<windows.h>
using namespace std;


void display_mainmenu(); 
void signin();
void signup();
void display_leaderboard();
char displaygameMenu();
void run(int a, char x);
int question(int qnNo);
void timer_Quiz(int r );
void normal_Quiz(int x);
void Displayscores();

int main() {
    display_mainmenu();
    return 0;
}


//To Add More Dependcies
// Checking for appropriate username
void display_mainmenu() 
{
    int choice;
    cout << "------------" << "\n" 
    << "Greetings, user!" << "\n" 
    << "------------" << endl;
    cout << "Would you like to sign in or sign up?" << "\n" << "1 to sign in 2 to sign up" << "\n" << "Enter choice: ";
    cin >> choice;
    switch (choice) 
    {
    break; case 1: signin();
    break; case 2: signup();
    }
}


//     cout << "2. Search for player name" << endl;
//     cout << "3. Create/edit text file" << endl;
//     cout << "4. Filter scores" << endl;

// Creds file has to be in format line1: username password
void signin() 
{
    string username, password, data_username, data_password, user_creds_line;
    char isagrees;
    bool authorised;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ifstream creds_file;
    creds_file.open("creds.txt", fstream::out);
    if (creds_file.is_open())
    {
        while (getline(creds_file, user_creds_line)) {
            data_username = user_creds_line.substr(0, user_creds_line.find(' '));
            data_password = user_creds_line.substr((0, user_creds_line.find(' ')+1));
            if ((data_username == username) && data_password == password) {authorised = true; break;}
            else {authorised = false; continue;}
        }
    } else cout << "creds file not found" << endl;
    if (authorised) 
    {
        cout << "Welcome back " << username << endl;
        displaygameMenu();
    }
    else 
    {
        cout << "Incorrect username or password" << endl;
        cout << "Do you want to sign up for an account?(Y/N)" << endl;
        cin >> isagrees;
        switch (isagrees) 
        {
            break; case 'Y': signup();
            break; case 'N': signin();
        }
    }
    creds_file.close();
}

// Creds file has to be in format line1: username password
void signup()
{
    string username, password;
    ofstream creds_file;
    bool authorised;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;
    creds_file.open("creds.txt", fstream::app);
    if (creds_file.is_open())
    {
        if (username.find(' ')) {}
        creds_file << "\n" << username << " " << password << endl;
    }
    cout << "Username and password saved!" << endl;
    authorised = true;
    
    if (authorised) 
    {
        cout << "Welcome back " << username << endl;
        displaygameMenu();
    }
    creds_file.close();
}

// void search_name() {
//     string student_name;
//     auto student_info_line;
//     ifstream student_file;
//     student_file.open("");
//     cout << "Enter name of search for: ";
//     cin >> student_name;
//     if (student_file.isOpen())
//     {
//         while (getline(student_file, student_info_line)) 
//     {
//         student_info_list = student_info.erase(' ');
//         student_info_list.split(',');
//         if (student_info_list[0] == student_name) {break;}
//         else { continue }
//     }
//     }
//     student_file.close("");

// }

// void edit_file() {
//     char edit_choice;
//     string file_name;
//     cout << "Do you wish to create or edit a file?(c/e}: ";
//     cin >> edit_choice;
//     cout << "Enter the name of the file you want to edit (___.txt): " << endl;
//     switch (edit_choice) 
//     {
//         case e {edit(file_name);}
//         case c {create();}
//     }

// }

// void edit(string file_name) {
//     ofstream student_file;
//     int admin_num;
//     string student_name, chosen_module_code, new_student_score;
//     cout << "Enter number of students: ";
//     cin >> num_of_students;
//     student_file.open("");
//     if (student_file.isOpen()) 
//     {
//         while ()
//     }
//     for (i = 1; i <= num_of_students; i++) 
//     {
//         cout << "Adding new record:" << endl;
//         cout << "Enter Admission number: ";
//         cin >> admin_num;
//         cout << "Enter students' name: ";
//         cin << student_name;
//         cout << "Enter module code: "
//         cin << chosen_module_code;
//         cout << "Enter the score";
//         cin >> new_student_score;
//         // exit halfway code
//         if ()
//         cout << "Record Saved!" << endl;
//     }

// }

// void sort_marks() {
//     //Come up with a better name than vec
//     string student_name, subject_code;
//     auto student_score_line;
//     ifstream student_file;
//     vector<int> vec;
//     cout << "Enter a subject code to sort the marks: ";
//     cin >> subject_code;
//     struct Predicate {
//         bool operator()(const A first, const A second) 
//         {
//             return first.num < second.num;
//         }
//     }
//     if student_file.isOpen() 
//     {
//         while (getline(student_file, student_score_line)) 
//         {
//             if (student_score_line[] == subject_code)
//             student_score = student_score_line[]
//         }
//     }
//     sort(vec.begin(), vec.end(), Predicate())
    

// }

// void exit() {
//     cout << "Shutting down" << endl;
// }

// void filter_display() {
//     int choice;
//     string module_code;
//     cout << "Filter a group of students based on " << endl;
//     cout << " 1. GPA" << "\n" << " 2. Modules" << endl;
//     cout << " Enter your choice: " << endl;
//     cin >> choice;
//     switch (choice) 
//     {
//         case 1 {filter_GPAs();}
//         case 2 {filter_modules();}
//     }
// }

char displaygameMenu()
{
    int b[4]={1, 2, 3, 4};
    int a;
    char y[3] = {'s', 'h', 'e'};
    char x;
    bool checkTwo = false;
    bool checkOne = false;
		 
    cout << setw(25) << "Select Your Game mode" << endl;
    cout << "------------------------------\n";
    cout << "1. Normal Quiz" << endl;
    cout << "2. Timer Quiz" << endl;// ans all qns correctly in 5 mins
    cout << "------------------------------\n";
    cout << setw(19) << "Options\n";
    cout << "------------------------------\n";
    cout << "3. Highscores" << endl;
    cout << "4. Return To Login" << endl;
    cin >> a;
    while (checkOne == false)
    {
         if (a == b[0]) check = true;
         else if (a == b[1]) checkOne = true;
         else if (a == b[2]) checkOne = true;
	 else if (a == b[3]) checkOne = true;
         else
         {
             cout << "invalid option. Please enter again.";
             cin >> a;
         }
    }	 
		 
    if(a == 2)
    {
        system("CLS");
        cout << "Pick Difficulty\n";
        cout << "s. simple\n";
        cout << "h. Hard\n";
        cout << "e. Expert\n";
        cin >> x;
        while (checkTwo == false)
        {
            if (x == y[0]) checkTwo = true;
            else if (x == y[1]) checkTwo = true;
            else if (x == y[2]) checkTwo = true;
            else
            {
                cout << "invalid option. Please enter again.";
                cin >> x;
            }
        }
	run(a, x);    
    }
    else run(a);
    return x;
}

void run(int a, char x)
{
    int r;
	
    if (a == 1)
    {
        
    }
    else if (a == 2)
    {
        if (x == 's') r = 10;
	else if (x == 'h') r = 15;
	else if (x == 'e') r = 20;
	timer_Quiz(r);
    }
    /*  system("CLS");
        cout << "Easy Mode. Are You Ready?" << endl;
	cout << "You have 5 minutes to answer 5 questions!"<<endl;
	system("pause");
        question_picker(x);
	
        system("CLS");
        cout << "Hard Mode. Are You Ready?" << endl;
	cout << "You have 5 minutes to answer 10 questions!"<<endl;
	system("pause");
        question_picker(x);
    else if (x == 3)
    {
        system("CLS");
        cout << "Expert Mode. Are You Ready?" << endl;
	cout << "You have 5 minutes to answer 15 questions!"<<endl;
	system("pause");
        question_picker(x);
    }*/
    else if (a == 3)
    {
        system("CLS");
        cout << "Highscore Menu!" << endl;
        display_leaderboard();
    }
    else if (a == 4)
    {
        system("CLS");
        cout << "Return To Lobby?" << endl;

    }
}


/* 
Return to Game Menu
Points logged
*/
void timer_Quiz(int r)
{
	srand(time(NULL));
	const int maxTime = 300000;//5 minutes;
	int i = 0, qnNo;
	int counter[20] = { 0 };
	int points;
	int duration;
	
	double sum;
	bool found, finished = false;
	char decisions[2] = { 'v','x' }, decision;
	
	while (finished == false)
	{
		sum = 0;
		duration = 0;
		system("CLS");
		int startTime = clock();
		for (int j = 0; j < r; j++)
		{
			found = false;
			while (found == false)
			{
				qnNo = rand() % 20 + 1;
				for (int k = 1; k <= 20; k++)
				{
					if (qnNo == k && counter[k - 1] == 0)
					{
						cout << "Qn" << j + 1 << ")" << endl;
						i = question(qnNo);
						sum += i;
						counter[k - 1]++;
						found = true;
					}
				}
			}
		}
		int endTime = clock();

		duration = endTime - startTime;

		if (sum == r)
		{
			if ((duration > maxTime))
			{
				if (r == 5)points = 1;
				else if (r == 10)points = 2;
				else if (r == 15)points = 4;
				cout << "You took more than 5 minutes, That's too Long!\n";
				cout << "Total points: " << points << endl;
			}
			else if (duration > 240000 && duration <= maxTime)
			{
				if (r == 5)points = 2;
				else if (r == 10)points = 4;
				else if (r == 15)points = 8;
				cout << "You took 5 minutes or less, You need more Practice!\n";
				cout << "Total points: " << points << endl;
			}
			else if (duration > 180000 && duration <= 240000)
			{
				if (r == 5)points = 3;
				else if (r == 10)points = 6;
				else if (r == 15)points = 12;
				cout << "You took 4 minutes or less, Can be Better!\n";
				cout << "Total points: " << points << endl;
			}
			else if (duration > 120000 && duration <= 180000)
			{
				if (r == 5)points = 4;
				else if (r == 10)points = 8;
				else if (r == 15)points = 16;
				cout << "You took 3 minutes or less, Good Try!\n";
				cout << "Total points: " << points << endl;
			}
			else if (duration > 60000 && duration <= 120000)
			{
				if (r == 5)points = 5;
				else if (r == 10)points = 10;
				else if (r == 15)points = 20;
				cout << "You took 2 minutes or less, Excellent!\n";
				cout << "Total points: " << points << endl;
			}
			else if (duration <= 60000)
			{
				if (r == 5)points = 6;
				else if (r == 10)points = 12;
				else if (r == 15)points = 24;
				cout << "You took a minute or less, WOW!\n";
				cout << "Total points: " << points << endl;
			}
		}
		else
		{
			cout << "You did not get Everything Right!\n";
			cout << "Total points: " << 0 << endl;
		}
                
		cout << "If you would like to try again press v. However if you wish to end press x.";
		cin >> decision;
		
		Displayscores();
		
		if (decision == decisions[0]) finished = false;
		else if (decision == decisions[1])
		{
		     finished = true;
		     displaygameMenu();
		}
	}
}
	
	
void Displayscores()
{
	string username;
	fstream inFile;
	int points = 5;
	username = "Kai Heng";
	inFile.open("scores.txt", ios::app);
	if (inFile.is_open()) 
	{
		inFile << username << "	" << points << endl;
		inFile.close();
	}
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
    //Open scorers file (username  score)
    //Update file if user is new 
	return i;
}

// Write return to game menu
//Combine both scoresid and scores files
void display_leaderboard() {
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
	int id[30];

	ifstream finid;
	finid.open("scorerid.txt");
	while (!finid.eof()) {
		finid >> id[n];
		n++;
	}
	finid.close();
	// putting scores into an array
	int m = 0; // m is the score integer in the file
	int scores[30];

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
}
