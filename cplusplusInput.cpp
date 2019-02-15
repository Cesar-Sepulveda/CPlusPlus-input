#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct PERSON{
  char name[20];
  float balance;
};

void display(PERSON arr[], int n){
  cout << "Name" << "           " << "Balance" << endl;
  cout << "------------------------------" << endl;
  for(int i = 0; i < n; ++i){
    cout << arr[i].name << " " << arr[i].balance << endl;
  }

}

void findRichest(PERSON arr[], int n){
  char richest[20];
  for(int i = 0; i < n -1; ++i){
    if(arr[i].balance > arr[i+i].balance){
      strcpy(richest, arr[i].name);
    }else{ strcpy(richest, arr[i+1].name);}
  }
  cout << "The customer with the highest balance is ";
  cout << richest << endl;
}

void deposit(string name, PERSON arr[], int n){
  float add;
  int found;
  for(int i = 0; i < n; ++i){
    if(strcmp(name.c_str(), arr[i].name) == 0){
      cout << name << ", how much would you like to deposit? ";
      cin >> add;
      cout << endl;
      found = i;
    }
  }
  add += arr[found].balance;
  cout << "Now your balance is " << add << endl;
}

void readFile(string filename, PERSON arr[], int n){
  fstream myFile;
  myFile.open(filename);
  string str1;
  string str2;
  string sName;
  float pay;
  string space;

  for(int i = 0; i < n; ++i){
    myFile >> str1 >> str2;
    sName = str1 + " " + str2;
    strcpy(arr[n].name, sName.c_str());
    myFile >> pay;
    arr[n].balance = pay;
    getline(myFile, space);
  }
  myFile.close();
}

int numOfLines(string filename){
  int count = 0;
  string line;
  fstream myFile;
  myFile.open(filename);
  if(myFile.is_open()){
    while(!myFile.eof()){
      getline(myFile,line);
      ++count;
      }
    myFile.close();
  }
  return count;
}

void NewCopy(string filename, PERSON arr[], int n){
  fstream myFile;
  myFile.open(filename);
  for(int i = 0; i < n; ++i){
    myFile << arr[i].name << arr[i].balance << endl;
  }
  myFile.close();
}

int main(){
  int n;
  string filename;
  string name;
  cout << "Enter the filename: " << endl;
  cin >> filename;
  n = numOfLines(filename);

  PERSON arr[n];
  readFile("data.txt", arr, n);
  display(arr, n);
  findRichest(arr, n);
  cout << "Enter your full name to deposite money: ";
  cin >> name;
  cout << endl;

  NewCopy("data.txt", arr, n);

  return 0;
}
