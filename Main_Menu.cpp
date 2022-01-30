#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
#include<fstream>
// #include <bits/stdc++.h>
using namespace std;

int main();
void signin();
void signup();
int findLastIndex(string& str, char x);


//To Add More Dependcies
int main() 
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
    return 0;
}

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
    if (authorised) {}
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
        creds_file << username << " " << password << endl;
    }
    cout << "Username and password saved!";
    authorised = true;
    
    if (authorised) 
    {
        cout << "Welcome back " << username;
    }
    creds_file.close();
}


// void main_menu() 
// {
//     int option;
//     cout << "********************" << "\n" 
//     << "* WELCOME TO STUDENT PROFILE ORGANISER *" 
//     << "\n" << "********************" << endl;
//     cout << "Sign in" << endl;
//     cout << "2. Search for player name" << endl;
//     cout << "3. Create/edit text file" << endl;
//     cout << "4. Filter GPA/Module scores" << endl;
//     // cout << "5. Sort students' marks" << endl;
//     cout << "6. Exit Program" << endl;
//     cout << "Enter option here";
//     cin >> option;
// }


// bool inRange(unsigned low, unsigned high, unsigned x)        
// {        
//  return (low <= x && x <= high);         
// }        

// // student_file has to be format line1: name admin_no [Code, marks, Code, marks ...] 
// void GPA_calculator() {
//     ifstream student_file;
//     string student_info;
//     list<string> student_info_list;
//     double student_GPA;
//     student_file.open("");
//     cout << fixed << setprecision();
//     cout << setw(set_width) << line3
//         << setw(set_width) << line3
//         << line3;
    
//     while (getline(student_file, student_info)) 
//     {
//         student_info_list = student_info.erase(' ');
//         student_info_list.split(',');
//         // Assuming all credit units are equal
//         // switch case for scoring
//         switch (student_score) {
//             if (inRange(90, 100, student_score);) {}
//             else if (inRange(80, 89, student_score);) {}
//             else if (inRange(70, 79, student_score);) {}
//             else if (inRange(60, 69, student_score);) {}
//             else if (inRange(0, 59, student_score);) {}
//         }
        
//         cout << setw(5) << student
//         << setw(5) << admin_no 
//         << setw(5) << admin_no
//         << setw(5) << admin_no
//         << setw(5) << admin_no
//         << setw(5) << admin_no
//         << setw(5) << admin_no
//         << endl;
//     }

//     student_file.close("");
    
// }


// // student_file has to be format line1: name admin_no [Code, Code, ...]
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
 
// void filter_GPAs() {
//     cout << setw(set_width) << line3
//     << setw(set_width) << line3
//     << line3;
// }

// void filter_modules() {
//     cout 
//     cout << setw(set_width) << line3
//     << setw(set_width) << line3
//     << line3;
// }

// int main() {
//     cout << left << fixed << setprecision();
//     first_menu();
//     switch (choice) {
//         break;case 1 {signin() if (authorised == true) {main_menu();}}
//         break;case 2 {signup(); main_menu();}
//     }
//     switch (option) 
//     {
//         break;case 1 {GPAcalculator();}
//         break;case 2 {search_name();}
//         break;case 3 {edit_file();}
//         break;case 4 {filter_scores();}
//         break;case 5 {sort_marks();}
//         break;case 6 {exit();}
//     }
    
// }

// main();
