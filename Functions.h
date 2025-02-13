#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <limits> //to raise Error when user put invalid input
#include <fstream>
#include <string>
#include <ctime> //to get current time
#include <sstream>
#include <iostream>
using namespace std;

struct employe
{
  string name;
  int id;
  string pos;
  int age;
  float salary;
};

// global variables
bool There_data_file = false; // to see if there file txt from beggining or do a new one with size eneterd by user and so on.
int count_of_edit = 0;
fstream inputFile("employe-Members.txt", ios::in);
fstream updateFile("Update-Reports.txt", ios::app);
fstream info_reports("Update-Reports.txt", ios::in); //  to take the old number of edit and reports and show all reports

// Functions prototype
void input_check(const string prompt, float &input);
void input_check(const string prompt, int &input);
void addEmploye(employe *&employeMembers, int &size); // will update employe-Members.txt
void searchEmploye(int id, int size, employe *employeMembers);
string updateEmploye(int id, int size, employe *&employeMembers); // will update employe-Members.txt
void deleteEmploye(int &size, employe *&employeMembers);          // will update employe-Members.txt
void sortEmploye(int &size, employe *&employeMembers);            // will update employe-Members.txt
void displayInfo(int size, employe *employeMembers);
void updateReport();
void updateOutPut(int size, employe *employeMembers, ios_base::openmode mode);
void quitApp();

#endif
