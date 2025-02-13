#include "HeaderFile\Functions.h"
using namespace std;

void addEmploye(employe*&employeMembers, int &size)
{
  if(!There_data_file){ 
   for(int i = 0; i < size; i++){
        cout<<"\n\tEmployes #"<<i+1<<" DATA: "<<endl; 
        cout<<"Enter Employe's Name: ";
        cin.ignore();
        getline(cin,employeMembers[i].name);
        cout<<"Enter Employe's ID: ";
        cin>>employeMembers[i].id;
        input_check("the ID you entered is not number please try again\nEnter Employe's ID: ", employeMembers[i].id);
        cout<<"Enter Employe's Position: ";
        cin.ignore();
        getline(cin,employeMembers[i].pos);
        cout<<"Enter Employe's age: ";
        cin>>employeMembers[i].age;
        input_check("the age you entered is not number please try again\nEnter Employe's age: ", employeMembers[i].age);
        cout<<"Enter Employe's salary: ";
        cin>>employeMembers[i].salary;
        input_check("the salary you entered is not number please try again\nEnter Staff's salary: ", employeMembers[i].salary);
    }
    count_of_edit += 1;
    cout<<count_of_edit<<endl;
    updateOutPut(size, employeMembers, ios::app);
  }
  else 
  {
    size+=1;
    employe *temp = new employe[size];
    for(int i=0; i<(size-1); i++)
    {
      temp[i].name = employeMembers[i].name;
      temp[i].id = employeMembers[i].id;
      temp[i].pos = employeMembers[i].pos;
      temp[i].age = employeMembers[i].age;
      temp[i].salary = employeMembers[i].salary;
    }

    delete[] employeMembers;
    employeMembers = temp;  
    cout<<"Enter Employe's Name: ";
    cin.ignore();
    getline(cin,employeMembers[size-1].name);
    cout<<"Enter Employe's ID: ";
    cin>>employeMembers[size-1].id;
    input_check("the ID you entered is not number please try again\nEnter Employe's ID: ", employeMembers[size-1].id);
    cout<<"Enter Employe's Position: ";
    cin.ignore();
    getline(cin,employeMembers[size-1].pos);
    cout<<"Enter Employe's age: ";
    cin>>employeMembers[size-1].age;
    input_check("the age you entered is not number please try again\nEnter Employe's age: ", employeMembers[size-1].age);
    cout<<"Enter Staff's salary: ";
    cin>>employeMembers[size-1].salary;
    input_check("the salary you entered is not number please try again\nEnter Employe's salary: ", employeMembers[size-1].salary);
    count_of_edit += 1;
    updateOutPut(size, employeMembers, ios::out);
  }
}
void searchEmploye(int id,int size,employe *employeMembers)
{
  bool f = false; // f = f 
  for (int i = 0; i < size; i++)
  {
    if(id == employeMembers[i].id)
    {
      cout<<"Employe was found. His name is "<<employeMembers[i].name<<" and his Position is "<<employeMembers[i].pos<<" \n";
      f = true;
      return;
    }
  }

  if (!f)
    cout<<"Sorry, Employe was not found.\n";  
}

//Function to update Employe member Information using his ID. 
string updateEmploye(int id, int size, employe *&employeMembers){
  bool f = false;
  for(int i = 0; i < size; i++){
    if(id == employeMembers[i].id)
    {
      f = true;
      cout<<"Enter Employe's Name: ";
      cin.ignore();
      getline(cin,employeMembers[i].name);
      cout<<"Enter Employe ID: ";
      cin>>employeMembers[i].id;
      input_check("the ID you entered is not number please try again\nEnter Employe's ID: ", employeMembers[i].id);
      cout<<"Enter Staff's Position: ";
      cin.ignore();
      getline(cin,employeMembers[i].pos);
      cout<<"Enter Employe's age: ";
      cin>>employeMembers[i].age;
     input_check("the age you entered is not number please try again\nEnter Employe's age: ", employeMembers[i].age);
      cout<<"Enter Employe's salary: ";
      cin>>employeMembers[i].salary;
      input_check("the salary you entered is not number please try again\nEnter Employe's salary: ", employeMembers[i].salary);
      count_of_edit += 1;
      updateOutPut(size, employeMembers, ios::out);
      return "The data have been Updated successfully.\n";
    }
  }
  if(!f){
    return "Employe member not found.";
  }
}

void deleteEmploye(int &size,employe*&employeMembers)
{
  int id;
  string confirm;
  bool f = false;
  displayInfo(size, employeMembers);
  cout<<"\nEnter Employe ID to Delete: ";
  cin>>id;
  while(!cin){
    cout<<"Error, please enter a valid integer input\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Enter Employe's ID: ";
    cin>>id;
  }
  for (int i = 0; i < size; i++)
  {
    if(id == employeMembers[i].id)
    {
      f = true;
      cout<<"Staff was found. His name is "<<employeMembers[i].name<<" and his Position is "<<employeMembers[i].pos<<" \n";
      cout<<"Are you sure you want to delete "<<employeMembers[i].name<<" (yes/no) ? ";
      cin>>confirm;
      if(confirm == "yes")
      {
        for(int j = i; j < size-1; j++)
        {
          employeMembers[j] = employeMembers[j+1];
        }
        --size;
        employe *temp = new employe[size];
        for(int i=0; i<size; i++)
        {
          temp[i].name = employeMembers[i].name;
          temp[i].id = employeMembers[i].id;
          temp[i].pos = employeMembers[i].pos;
          temp[i].age = employeMembers[i].age;
          temp[i].salary = employeMembers[i].salary;
        }

        delete[] employeMembers;
        employeMembers = temp;
        count_of_edit += 1;
        updateOutPut(size, employeMembers, ios::out);
        cout<<"Employe "<<employeMembers[i].name<<" deleted Successfully .\n";
      }
      else
      {
        cout<<"Delete Cancelled.\n";
        break;
      }
    }
  }
    if (!f)
      cout<<"Sorry, Employe was not found.\n"; 
}

void sortEmploye(int &size, employe *&employeMembers){
  for(int i = 0; i < size-1; i++){
    for (int j = 0; j < size-1; j++){
      if (employeMembers[j].name > employeMembers[j+1].name){
        employe temp = employeMembers[j];
        employeMembers[j] = employeMembers[j+1];
        employeMembers[j+1] = temp;
      }
    }
  }
  count_of_edit += 1;
  updateOutPut(size, employeMembers, ios::out);
  cout<<"Employe members After Sorting:";
  displayInfo(size, employeMembers);
}
void displayInfo(int size,  employe*employeMembers)
{
  for (int i = 0; i < size; i++)
    cout<<"\n\nEmploye#"<<i+1<<" Name: "<<employeMembers[i].name<<" | ID: "<<employeMembers[i].id<<" | Position: "<<employeMembers[i].pos<<" | Age: "<<employeMembers[i].age<<" | Salary: "<<employeMembers[i].salary<<"\n";
}

void updateReport()
{
  time_t tmNow=time(0);
  char *dt = ctime(&tmNow);
  if(updateFile.is_open())
  {
    updateFile <<"Number of changes made: "<< count_of_edit <<" | Date: "<<dt<<endl;
    cout<<"Number of changes made: "<< count_of_edit <<" | Date: "<<dt<<endl;
  }
  else
  {
    cout<<"Error, couldn't open txt File.\n";
  }
  count_of_edit = 0;
}

void updateOutPut(int size, employe*employeMembers, ios_base::openmode mode){
  fstream outputFile("employe-Members.txt", mode);
  if(outputFile.is_open())
  {
    for(int i = 0; i < size; i++)
    {
      outputFile<<employeMembers[i].name<<" | "<<employeMembers[i].id<<" | "<<employeMembers[i].pos<<" | "<<employeMembers[i].age<<" | "<<employeMembers[i].salary<<endl;
    }
    outputFile.close();
  }
  else
  {
    cout<<"File could not be opened for writing."<<endl;
  }
}
void input_check(const string prompt, int &input){
  while (!cin) {
    cout << prompt;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin >> input;
  }
}
void input_check(const string prompt, float &input){
  while (!cin) {
    cout << prompt;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin >> input;
  }
}
void quitApp()
{
  updateFile.close();
  inputFile.close();
  info_reports.close();
  cout<<"\n* * *Thanks for using the app* * *";
}
