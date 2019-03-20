#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct PERSON{
  char name[20];
  float balance;
};

//------------------------------------------------------------------------------
void display(PERSON *arr, int N){
  cout << fixed << setprecision(2);
  for(int i = 0; i < N; ++i){
    cout << arr[i].name << " " << arr[i].balance << endl;
  }
}

//------------------------------------------------------------------------------
void findRichest(PERSON *arr, int N){
  char richest[20];
  for(int i = 0; i < N -1; ++i){
    if(arr[i].balance > arr[i+1].balance){
      strcpy(richest, arr[i].name);
    }else{ strcpy(richest, arr[i+1].name);}
  }
  cout << "Highest balance: ";
  cout << richest << endl;
}

//------------------------------------------------------------------------------
void deposit(PERSON *arr, int N, string custName, float amount){
  float add = 0;
  int found = -1;
  for(int i = 0; i < N; ++i){
    if(strcmp(custName.c_str(), arr[i].name) == 0){
      found = i;
    }
  }
  if(found != -1){
    arr[found].balance = arr[found].balance + amount;
    cout << fixed << setprecision(2);
    cout << "New balance: " << arr[found].balance << endl;
  }else{
    cout << "Record not found" << endl;
  }
}

//------------------------------------------------------------------------------
PERSON *readData(int N){
  PERSON *arr = new PERSON[N];
  fstream myFile;
  myFile.open("data.txt");
  string str1;
  string str2;
  string sName;
  float pay;
  string space;

  for(int i = 0; i < N; ++i){
    myFile >> str1 >> str2;
    str1 = str1.substr(0,8);
    str2 = str2.substr(0,9);
    sName = str1 + " " + str2;
    strcpy(arr[i].name, sName.c_str());
    myFile >> arr[i].balance;
    getline(myFile, space);
  }
  myFile.close();
  return arr;
}

//------------------------------------------------------------------------------
int numOfLines(string filename){
  int count = 0;
  string line;
  fstream myFile;
  myFile.open(filename);
  while(getline(myFile, line)){
    ++count;
  }
  myFile.close();
  return count;
}

//------------------------------------------------------------------------------
void newCopy(string filename, PERSON *arr, int N){
  fstream myFile;
  myFile.open(filename);
  myFile << fixed << setprecision(2);
  for(int i = 0; i < N; ++i){
    myFile << arr[i].name << " " << arr[i].balance << endl;
  }
  cout << "File Updated..." << endl;
  myFile.close();
}

//------------------------------------------------------------------------------
  void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
  }

//------------------------------------------------------------------------------
int main(){
  int N = numOfLines("data.txt");
  PERSON *arr = readData(N);
  string fname;
  string lname;
  float amount;
  string custName;
  string buf;
  int choice;
  do{
    printmenu();
    cin >> choice;
    switch(choice){
      case 1:
        display(arr,N);// Act on display
        break;

      case 2:
        cout << "Enter name: ";
        cin >> fname >> lname;
        getline(cin, buf);
        custName = fname + " " + lname;
        cout << "Amount: ";
        cin >> amount;
        cout << endl;
        deposit(arr, N, custName, amount);// Act on deposit
        break;

      case 3:
        findRichest(arr,N);// Act highest balance
        break;

      case 4:
        newCopy("data.txt", arr, N);// Act on update records
        break;

      case 5:
        newCopy("data.txt", arr, N);// Must call update records here before exiting the program
        break;

      default:
        cout << "Invalid entry" << endl;
        break;
    }
    cout << endl;
  } while(choice != 5);
  delete arr;
  arr = nullptr;
  return 0;
}
