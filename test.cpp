#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class StudentRecords
{ 
      private : 
              struct students
              {
                     string name;
                     int id;
                     string address;
                     double gpa;
                     int test1;
                     int test2;
                     int test3;
                     int test4;
                     int test5;
                     int test6;
                     int test7;
                     int test8;
                     int test9;
                     int test10;
                     //struct students *next
              };
              //students *head;
             vector<students>sRec;
      public : 
             void addRecords();
             
}; 

void StudentRecords :: addRecords()
{
     
     infile.open("Project4.txt");

while(!infile.eof())

{

infile >> myWord;

tempStruct.inWord = myWord;

tempStruct.wordNumber = ++wCount;

myVector.push_back(tempStruct);

}

Read more: http://www.ehow.com/how_7168356_put-file-vector-structs-c__.html#ixzz2wMSug6AJ

     
}
int main()
{
    /*string input;
    fstream nameFile;
    
    nameFile.open("Project4.txt", ios::in);
    
    if(nameFile)
    {
    getline(nameFile, input);
    
    while (nameFile)
          {
               cout << input << endl;
               getline(nameFile, input);
          }
    nameFile.close();
    }
    else
    {
        cout << "ERROR" << endl;
    }*/
    system ("pause>nul");  
    return 0; 
}
