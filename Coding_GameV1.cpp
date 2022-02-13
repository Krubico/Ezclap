#include<cmath>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<vector>
#include<string>
#include <ctime>
#include<windows.h>
#include<map>
#include<iterator>
#include<algorithm>
#include<sstream>
#include<mmsystem.h>
using namespace std;

/*
User Guide:
    Main Menu:
    1. Sign in - Log on to your player account
    2. Sign up - Create new account
    3. Admin Sign in - Access the adminisation page for teachers to access scores of students
    4. Exit Program - End Program

    Sign in:
        username: - Enter your username
        password: - Enter your password
    Sign up:
        username - Create your username
        password - Create your password

    Sign in & Sign up -> Game Menu
    Game Menu: 
        1. Normal Quiz - Start Teacher Assigned Quiz
        2. Timer Quiz - Start Timed Quiz
        Options: 
        3. Highscores -Display the leaderboard of scores
        4. Return to Main Menu
    
    Timer Quiz:
        1. Normal - Start teacher-assigned quiz
        2. Easy - Start simple mode practice quiz
        3. Hard - Start hard mode practice quiz
        4. Expert -Start expert mode practice quiz

    Highscores:  
        1. Normal - Display normal leaderboard
        2. Easy - Display simple mode leaderboard
        3. Hard - Display hard mode leaderboard
        4. Expert - Display expert mode leaderboard
    

    Admin Sign in:
        username: - Enter your admin username
        password: - Enter your admin password
    
    Admin Sign in -> Admin Menu
    Admin Menu:
        1. Search for player name - Search for a plPayer and display their teacher-assigned quiz score
        2. Filter player scores - Organise students score 
        3. Exit Program - End Program 
    
*/

int display_mainmenu(); 
void signin();
void signup();
void displaygameMenu();
void run(int a, char x);
int questionDisplay(int qnNo);
void timer_Quiz(int r );
void normal_Quiz();
int writescore(string filename, int points);
int admin_menu();
int admin_signin();
int playersearch();
void filter_byscore();
int findLastIndex(string& str, char x);
bool inRange(unsigned low, unsigned high, unsigned x);
int display_leaderboard(int a);
void ren(int a);
void sort_lb(map<string, int>& lb);
char selectdifficulty();
char highscoredifficulty();
char highscorechoice();



string current_username;

char selectdifficulty() {}
char highscoredifficulty() {}
char highscorechoice() {}


int main() {

    display_mainmenu();
    return 0;
}


int display_mainmenu() 
{
    int choice;
    cout << "----------------" << "\n" << "Greetings User!" << "\n" << "----------------" << endl;
    cout << "1. Sign in" << endl;
    cout << "2. Sign up" << endl;
    cout << "3. Admin Sign in" << endl;
    // cout << "5. Sort students' marks" << endl;
    cout << "4. Exit Program" << endl;
    cout << "Enter option here: ";
    cin >> choice;
    switch (choice) 
    {
    break; case 1: signin();
    break; case 2: signup();
    break; case 3: admin_signin();
    break; case 4: return 0;
    default:
    {
        cout << "Incorrect choice input, please try again" << endl; 
        display_mainmenu();
    } 
    }
    return 0;
}


int admin_menu() 
{
    system("CLS");
    int option;
    cout << "*********************************" << "\n" 
    << "* WELCOME TO STUDENT PROFILE ORGANISER *" 
    << "\n" << "*********************************" << endl;
    cout << "1. Search for player name" << endl;
    cout << "2. Filter player scores" << endl;
    cout << "3. Exit Program" << endl;
    cout << "Enter option here: ";
    cin >> option;

    switch (option) 
    {
        break; case 1: playersearch();
        break; case 2: filter_byscore();
        break; case 3: return 0;
    }
    return 0;
}
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
            data_password = user_creds_line.substr(user_creds_line.find(' ')+1);
            if ((stoi(data_username) == hash<std::string>{}(username)) && stoi(data_password) == hash<std::string>{}(password)) {authorised = true; break;}
            else {authorised = false; continue;}
        }
    } else cout << "creds file not found" << endl;
    if (authorised) 
    {
        cout << "Welcome back " << username << endl;
        current_username = username;
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
    creds_file.open("creds.txt", fstream::app);
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;
    if (username.find(' ') != -1 || password.find(' ') != -1) 
    {
        cout << "No Spaces are allowed in username or password" << endl;
        creds_file.close();
        signup();
    }
    if (creds_file.is_open())
    {
        if (username.find(' ')) {}
        creds_file << hash<std::string>{}(username) << " " << hash<std::string>{}(password) << endl;
    }
    cout << "Username and password saved!" << endl;
    authorised = true;
    
    if (authorised) 
    {
        cout << "Welcome  " << username << endl;
        current_username = username;
        displaygameMenu();
    }
    creds_file.close();
}

bool inRange(unsigned low, unsigned high, unsigned x)        
{        
 return (low <= x && x <= high);         
}

int playersearch() 
{
    string playername, leaderboard_line, data_username, data_score;
    ifstream leaderboard_file;
    bool found;
    int option;
    leaderboard_file.open("scores.txt");
    cout << "Enter in players name: ";
    cin >> playername;
    if (leaderboard_file.is_open()) 
    {
        while (getline(leaderboard_file, leaderboard_line)) {
            data_username = leaderboard_line.substr(0, leaderboard_line.find(' '));
            data_score = leaderboard_line.substr(leaderboard_line.find(' ')+1);
            // if ((stoi(data_username) == hash<std::string>{}(playername))) {found = true; break;}
            if (data_username == playername) {found = true; break;}
            else found = false;
        }
    } else {
        cout << "leaderboard file not found" << endl;
        playersearch();
        system("pause");
        return 0;
    }
    if (found) 
    {
        cout << "The student " << playername <<  " has gotten a high score of " << data_score << endl;
    } else cout << "The student you player you specified cannot be found " << endl;
    
        cout << "1. Enter another player name " << endl;
        cout << "2. Return to menu " << endl;
        cout << "Enter you choice: ";
        cin >> option;
        switch(option) 
        {
            break; case 1:
            {
                playersearch();
                system("pause");
                return 0;
            }
            break; case 2: 
            {
                admin_menu(); 
                system("pause");
                return 0;
            }
        }
    system("pause");
    return 0;
}

// void edit_leaderboard() 
// {
//     string playername;
//     ifstream leaderboard_file;
//     leaderboard_file.open(scores_file);
//     cout << "Enter in player name to edit: ";
//     cin >> playername;
//     if (leaderboard_file.is_open()) 
//     {
//         while (getline(leaderboard_file, leaderboard_line)) {
//             data_username = leaderboard_line.substr(0, leaderboard_line.find(' '));
//             data_score = leaderboard_line.substr(leaderboard_line.find(' ')+1);
//             if ((data_username == hash<std::string>{}(playername))) {found = true; break;}
//             else found = false;
//         }
//     } else {
//         cout << "leaderboard file not found" << endl;
//         edit_leaderboard()
//         system("pause");
//         return 0;
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
//         cout << "Enter Students' name: ";
//         cin << student_name;
//         cout << "Enter Admin Number: "
//         cin << chosen_module_code;
//         cout << "Enter the score";
//         cin >> new_student_score;
//         // exit halfway code
//         if (admin_num == '/') 
//         {
//             cout << "Record Saved!" << endl;
//             break;
//         }
//         cout << "Record Saved!" << endl;
//     }

// }

void filter_byscore() {
    int i, student_score;
    ifstream student_file;
    string student_username, rank, leaderboard_line;
    vector<string> perfect;
    vector<string> great;
    vector<string> passed;
    vector<string> failed;
    double student_GPA;
    student_file.open("scores.txt");
    cout << "Perfect" << setw(15) << "Great" << setw(15) << "Passed" << setw(15) <<  "Failed" << endl;
    while (getline(student_file, leaderboard_line)) 
    {
        student_username = leaderboard_line.substr(0, leaderboard_line.find(' '));
        student_score = stoi(leaderboard_line.substr((leaderboard_line.find(' ')+1)));
        // TODO: Student ranges to be determined
            if (student_score == 20) 
            {
                perfect.push_back(student_username);
                
            }
                
            else if (inRange(16, 19, student_score)) 
            {
                great.push_back(student_username);
                
            }
            else if (inRange(10, 15, student_score))
            {
                passed.push_back(student_username);
                
            }
            else if (inRange(0, 9, student_score))
            {
                failed.push_back(student_username);
                
            } 
        }
        int x = 15;
        for (int i = 0; i < 30; i++) 
        {
            if (i < perfect.size()) 
            {
                cout << perfect[i];
            }
            else x += 7;
            if (i < great.size()) 
            {
                cout << setw(x) << great[i]; 
                x = 15 - (great[i].length() - 5);
            }
            else x += 20;
            if (i < passed.size()) 
            {
                cout << setw(x) << passed[i]; 
                x = 15 - (passed[i].length() - 6);
            }
            else x += 21;
            if (i < failed.size()) 
            {
                cout << setw(x) << failed[i]; 
                x = 15 - (failed[i].length() - 6);
            }
            cout << endl;
            x = 15;
        }
        
    student_file.close();
}

int admin_signin()
{
    string username, password, data_username, data_password, user_creds_line;
    int choice;
    bool authorised;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ifstream admincreds_file;
    admincreds_file.open("admincreds.txt", fstream::out);
    if (admincreds_file.is_open())
    {
        while (getline(admincreds_file, user_creds_line)) {
            data_username = user_creds_line.substr(0, user_creds_line.find(' '));
            data_password = user_creds_line.substr((user_creds_line.find(' ')+1));
            if ((stoi(data_username) == hash<std::string>{}(username)) && stoi(data_password) == hash<std::string>{}(password)) {authorised = true; break;}
            else {authorised = false; continue;}
        }
    } else cout << "creds file not found" << endl;
    if (authorised) 
    {
        cout << "Welcome back " << username << endl;
        admin_menu();
    }
    else 
    {
        cout << "Incorrect username or password" << endl;
        cout << "Would you like to return back to menu or try again?" << endl;
        cout << "1. Return back to Menu " << endl;
        cout << "2. Try Again " << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            break; case 1: display_mainmenu(); return 0;
            break; case 2: admin_signin();
        }
    }
    admincreds_file.close();
    return 0;
}

void displaygameMenu()
{
    int b[4] = { 1, 2, 3, 4 };
    int a;
    char y[3] = { 's', 'h', 'e' };
    char x=' ';
    bool checkTwo = false;
    bool checkOne = false;

    system("CLS");
    cout << setw(25) << "Select Your Game mode" << endl;
    cout << "------------------------------\n";
    cout << "1. Normal Quiz" << endl;
    cout << "2. Timer Quiz" << endl;// ans all qns correctly in 5 mins
    cout << "------------------------------\n";
    cout << setw(19) << "Options\n";
    cout << "------------------------------\n";
    cout << "3. Highscores" << endl;
    cout << "4. Return To Login" << endl;
    cout << "------------------------------\n"<<endl;
    cout << "Ans: ";
    cin >> a;
    while (checkOne == false)
    {
        if (a == b[0]) checkOne = true;
        else if (a == b[1]) checkOne = true;
        else if (a == b[2]) checkOne = true;
        else if (a == b[3]) checkOne = true;
        else
        {
            cout << "Invalid option. Please enter again." << endl;
            cout << "Ans: ";
            cin >> a;
        }
    }
    if (a == 2)
    {
        system("CLS");
        cout << "------------------------------------------------------------\n";
        cout << setw(35) << "Pick Difficulty\n";
        cout << "------------------------------------------------------------\n";
        cout << "s. simple (Complete 10 Questions in 5 Minutes)\n";
        cout << "h. Hard (Complete 15 Questions in 5 Minutes)\n";
        cout << "e. Expert(Complete 20 Questions in 5 Minutes)\n";
        cout << "------------------------------------------------------------\n"<<endl;
        cout << "Ans: ";
        cin >> x;
        while (checkTwo == false)
        {
            if (x == y[0]) checkTwo = true;
            else if (x == y[1]) checkTwo = true;
            else if (x == y[2]) checkTwo = true;
            else
            {
                cout << "Invalid option. Please enter again." << endl;
                cout << "Ans: ";
                cin >> x;
            }
        }
    }

    run(a, x);
}

void run(int a, char x)
{
    int r, choice;

    if (a == 1)
    {
        normal_Quiz();
    }
    else if (a == 2)
    {
        if (x == 's') r = 10;
        else if (x == 'h') r = 15;
        else if (x == 'e') r = 20;
        timer_Quiz(r);
    }
    else if (a == 3)
    {
        system("CLS");
        cout << "Highscore Menu!" << endl;
        cout << "1. Normal " << endl;
        cout << "2. Easy " << endl;
        cout << "3. Hard " << endl;
        cout << "4. Expert " << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        display_leaderboard(choice);
    }
    else if (a == 4)
    {
        system("CLS");
        display_mainmenu();
    }
}

void normal_Quiz()
{
    int i = 0, qnNo;
    int counter[20] = { 0 };
    double sum;
    bool found, finished = false;
    char decisions[2] = { 'v','x' }, decision;
    string username;
    fstream scores_file;
    scores_file.open("scores.txt");
    while (finished == false)
    {
        sum = 0;
        system("CLS");
        for (int j = 0; j < 20; j++)
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
                        i = questionDisplay(qnNo);
                        sum += i;
                        counter[k - 1]++;
                        found = true;
                    }
                }
            }
        }

        bool check = false;
        while (check == false)
        {
            for (int u = 0; u <= 20; u++)
            {
                if (sum == u)
                {
                    cout << "You got " << sum << " out of 20 Correct.\n";
                    check = true;
                }
            }
        }
        if (sum >= 15 && sum <= 20) cout << "Well done!\n";
        else if (sum >= 10 && sum <= 14) cout << "Good Try.Can be better!\n";
        else if (sum >= 0 && sum <= 9) cout << "You need more Practice!\n";

        writescore("scores.txt", sum);

        cout << "If you would like to try again press v. However if you wish to end press x." << endl;
        cout << "Ans: ";
        cin >> decision;

        bool checkQ = false;
        while (checkQ == false)
        {
            if (decision == decisions[0]) checkQ = true;
            else if (decision == decisions[1]) checkQ = true;
            else
            {
                cout << "Invalid option!. Please enter again." << endl;
                cout << "Ans: ";
                cin >> decision;
            }
        }

        if (decision == decisions[0])
        {
            finished = false;
            normal_Quiz();
        }
        else if (decision == decisions[1])
        {
            finished = true;
            main();
        }
    }
}
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
        system("CLS");
        cout << "Game will start in 5 Seconds. Get Ready!\n" << endl;
        for (int sec = 5; sec > 0; sec--)
        {
            cout << setw(20) << sec;
            cout.flush();
            Sleep(1000);
            cout << '\r';
        }
        cout << setw(20) << "BEGIN!";
        Sleep(1000);
        system("CLS");
        sum = 0;
        duration = 0;
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
                        i = questionDisplay(qnNo);
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
                if (r == 10)points = 1;
                else if (r == 15)points = 2;
                else if (r == 20)points = 4;
                cout << "You took more than 5 minutes, That's too Long!\n";
                cout << "Total points: " << points << endl;
            }
            else if (duration > 240000 && duration <= maxTime)
            {
                if (r == 10)points = 2;
                else if (r == 15)points = 4;
                else if (r == 20)points = 8;
                cout << "You took 5 minutes or less, You need more Practice!\n";
                cout << "Total points: " << points << endl;
            }
            else if (duration > 180000 && duration <= 240000)
            {
                if (r == 10)points = 3;
                else if (r == 15)points = 6;
                else if (r == 20)points = 12;
                cout << "You took 4 minutes or less, Can be Better!\n";
                cout << "Total points: " << points << endl;
            }
            else if (duration > 120000 && duration <= 180000)
            {
                if (r == 10)points = 4;
                else if (r == 15)points = 8;
                else if (r == 20)points = 16;
                cout << "You took 3 minutes or less, Good Try!\n";
                cout << "Total points: " << points << endl;
            }
            else if (duration > 60000 && duration <= 120000)
            {
                if (r == 10)points = 5;
                else if (r == 15)points = 10;
                else if (r == 20)points = 20;
                cout << "You took 2 minutes or less, Excellent!\n";
                cout << "Total points: " << points << endl;
            }
            else if (duration <= 60000)
            {
                if (r == 10)points = 6;
                else if (r == 15)points = 12;
                else if (r == 20)points = 24;
                cout << "You took a minute or less, WOW!\n";
                cout << "Total points: " << points << endl;
            }
        }
        else
        {
            cout << "You did not get Everything Right!\n";
            cout << "Total points: " << 0 << endl;
        }

        if (r == 10) writescore("simpletimer.txt", points);
        else if(r==15) writescore("hardtimer.txt", points);
        else if(r==20) writescore("experttimer.txt", points);


        cout << "If you would like to try again press v. However if you wish to end press x." << endl;
        cout << "Ans: ";
        cin >> decision;

        bool check = false;
        while (check == false)
        {
            if (decision == decisions[0]) check = true;
            else if (decision == decisions[1]) check = true;
            else
            {
                cout << "Invalid option!. Please enter again." << endl;
                cout << "Ans: ";
                cin >> decision;
            }
        }

        if (decision == decisions[0])
        {
            timer_Quiz(r);
            finished = false;
        }
        else if (decision == decisions[1])
        {
            finished = true;
            main();
        }
    }
}


int questionDisplay(int qnNo)
{
    fstream inFile;
    string qn;
    char ans, cAns[20] = { 'b','d','b','a','c','a','a','c','b','d','c','c','b','b','c','b','b','b','c','a' };
    int i = 1;
    bool check = false;

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
    while (check == false)
    {
        if (ans == 'a') check = true;
        else if (ans == 'b') check = true;
        else if (ans == 'c') check = true;
        else if (ans == 'd') check = true;
        else
        {
            cout << "Invalid option!. Please enter again." << endl;
            cout << "Ans: ";
            cin >> ans;

        }
    }
    if (ans == cAns[qnNo - 1])
    {
	system("color 02");    
        cout << "\nCorrect Answer!" << endl;
        system("pause");
	system("color 07");
        i = 1;
    }
    else
    {
	system("color 04");    
        cout << "\nSorry wrong Answer!" << endl;
        system("pause");
	system("color 07");
        i = 0;
    }
    inFile.close();

    system("CLS");
    return i;
}




bool cmp(pair<string, int>& c, pair<string, int>& d)
{
	return c.second > d.second;
}

int display_leaderboard(int a) {
	ifstream lbfile;
	char choice;
	if (a == 1) {
		lbfile.open("scores.txt");
	}
	else if (a == 2) {
		lbfile.open("simpletimer.txt");
	}
	else if (a == 3) {
		lbfile.open("hardtimer.txt");
		}
	else if (a == 4) {
		lbfile.open("experttimer.txt");
	}
    cout << "Hall Of Fame (NORMAL)" << endl;
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
    cout << endl;
    cout << "Would you like to return to Game Menu? (Y/N) ";
    cin >> choice;
    if (choice == 'Y')
    {
        displaygameMenu();
        return 0;
    }
	system("pause");
	return 0;
}

void sort_lb(map<string, int>& lb)
{
	// Declare vector of pairs
	vector<pair<string, int> > A;

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

int writescore(string filename, int points)
{
	string line, data_username, data_score, points_string;
	ifstream inFile;
    ofstream inFile1;
    int score;
    map<string, int> lb;
	inFile.open(filename, ios::app);
	if (inFile.is_open()) 
	{
        while (getline(inFile, line))
        {
            data_username = line.substr(0, line.find(' '));
            data_score = line.substr(line.find(' ')+1);
            score = stoi(data_score);
            if (current_username == data_username)
            {
                if (points > score) 
                {
                    lb[data_username] = points;
                } else lb[data_username] = score;
            } else lb[data_username] = score;
        }
        inFile.close();
    }
    inFile1.open("scores.txt", ios::out);

    for (auto const& x: lb ) 
    {
        inFile1 << x.first << ' ' << x.second << endl;
    }
    inFile1.close();
    return 0;
}


