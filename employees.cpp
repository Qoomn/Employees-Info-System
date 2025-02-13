/*Group 4
Abdullah albashrawi 2220003601,
Odai Alharthi 2220004066,
Saif Nabeal Albouq 2200000340,
Abdulrahman Alotaibi 2220006233,
Ali Alkhars 2220002664,
Tameem aljaafari 2220002539,
Saeed jamaan alghamdi 2220000087,
*/

#include "FUN.cpp"
int main()
{
  int Size = 0;
  employe *employeMembers = nullptr;
  fstream outputFile("employe-Members.txt", ios::app);
  if (inputFile.is_open() == true)
  {
    There_data_file = true;
    string line;
    int count = 0;
    while (getline(inputFile, line))
    {
      count++;
    }
    Size = count;
    employeMembers = new employe[Size];
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    count = 0;
    while (getline(inputFile, line))
    {
      istringstream ss(line);
      string token;
      getline(ss, employeMembers[count].name, '|');
      ss >> ws;
      getline(ss, token, '|');
      ss >> ws;
      employeMembers[count].id = stoi(token);
      getline(ss, employeMembers[count].pos, '|');
      ss >> ws;
      getline(ss, token, '|');
      ss >> ws;
      employeMembers[count].age = stoi(token);
      getline(ss, token, '|');
      ss >> ws;
      employeMembers[count].salary = stof(token);
      ss >> ws;
      count++;
    }
    outputFile.close();
  }
  else
  {
    cout << "There is no data \nWe will do a new data for you\n " << endl
         << "Enter how many Employe members: ";
    cin >> Size;
    employe *employeMembers = new employe[Size];
    addEmploye(employeMembers, Size);
  }

  // Menu
  int choice;
  while (choice != 8)
  {
    cout << "\n--------MENU---------\n";
    cout << "1) Add new Employe member\n"; // overwrite
    cout << "2) Search for employe member\n";
    cout << "3) Update an existing Employe member\n"; // overwrite
    cout << "4) Delete a employe member\n";           // overwrite
    cout << "5) Sort employe members\n";              // overwrite
    cout << "6) Display All employe members' information\n";
    cout << "7) Upload and see the reports from update-report.txt\n";
    cout << "8) => Quit the app\n";
    cout << "-----------------\n\nEnter Menu Choice (1-8):";

    // Menu Choices
    cin >> choice;
    if (choice == 1)
      addEmploye(employeMembers, Size);
    else if (choice == 2)
    {
      int id;
      cout << "Enter employe's ID: ";
      cin >> id;
      input_check("the ID you entered is not number please try again\nEnter employe ID: ", id);
      searchEmploye(id, Size, employeMembers);
    }
    else if (choice == 3)
    {
      cout << "\n-------Employe members List-------\n";
      displayInfo(Size, employeMembers);
      int id;
      cout << "\nChoose Employe ID to Update it: ";
      cin.clear();
      cin.ignore();
      cin >> id;
      input_check("the ID you entered is not number please try again\nEnter Employe ID: ", id);
      cout << updateEmploye(id, Size, employeMembers);
    }
    else if (choice == 4)
      deleteEmploye(Size, employeMembers);
    else if (choice == 5)
    {
      cout << "\n--------Sort Employe Members---------\n";
      sortEmploye(Size, employeMembers);
    }
    else if (choice == 6)
      displayInfo(Size, employeMembers);
    else if (choice == 7)
      updateReport();
    else if (choice == 8)
      quitApp();
    else
      cout << "Error, enter a number between (1-8).";
  }
  return 0;
}