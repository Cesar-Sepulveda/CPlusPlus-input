#include <iostream>
#include <fstream>
#include <string>
#include <cstrings>
using namespace std;

struct PERSON{
  char name[20];
  float balance;
};

void display(PERSON arr[], int n){

}

void findRichest(PERSON arr[], int n){

}

void deposit(PERSON arr[], int n){

}

int readFile(string fileName){
  int num;
  string str1;
  string str2;
  string line;
  float value;
  ifstream inData;
  inData.open(fileName);
  inData >> str1;
  while (inData)
    {
      inData >> str1;
      inData >> value;
      getline (inData, line);
      inData >> str1;
      ++num;
    }
  return num;
}

int main(){
  int count;
  count = readFile("data.txt");
  PERSON personArray[count];
  cout << count;

  return 0;
}
