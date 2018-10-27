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
                     string name, lName;
                     int id, test1, test2, test3, test4, test5, test6, test7, test8, test9, test10;
                     string address;
                     double gpa;
                     
                     //struct students *next
              };
              //students *head;
             vector<students>sRec;
      public : 
             void addRecords();
             void displayRecords();
             void displaySearched(int);
             void sortVector();
             int binarySearch(int, int, int);
             
}; 

void StudentRecords :: addRecords()
{
     
    
    string nameFromFile, addressFromFile, lNameFromFile;
    int idFromFile, test1FromFile, test2FromFile, test3FromFile, test4FromFile, test5FromFile, test6FromFile, test7FromFile, test8FromFile, test9FromFile, test10FromFile;
    double gpaFromFile;
    fstream nameFile;
    
    nameFile.open("Project4.txt", ios::in);
    
     for (int i = 0; i < 20; i++)
    {
    
    
    getline (nameFile, nameFromFile);
    getline (nameFile, addressFromFile);
    
    nameFile >> idFromFile >> gpaFromFile >> test1FromFile >> test2FromFile >> test3FromFile >> test4FromFile >> test5FromFile >> test6FromFile >> test7FromFile >> test8FromFile >> test9FromFile >> test10FromFile;
    
    sRec.push_back(students());
     
     sRec[i].name = nameFromFile;
     sRec[i].id = idFromFile;
     sRec[i].address = addressFromFile;
     sRec[i].gpa = gpaFromFile;
     sRec[i].test1 = test1FromFile;
     sRec[i].test2 = test2FromFile;
     sRec[i].test3 = test3FromFile;
     sRec[i].test4 = test4FromFile;
     sRec[i].test5 = test5FromFile;
     sRec[i].test6 = test6FromFile;
     sRec[i].test7 = test7FromFile;
     sRec[i].test8 = test8FromFile;
     sRec[i].test9 = test9FromFile;
     sRec[i].test10 = test10FromFile;
     
     
     }
     
}

void StudentRecords :: displayRecords()
{
     for (int i = 0; i < 20; i++)
     {
     cout << "Name: " << sRec[i].name << endl;
     cout << "Id: " << sRec[i].id << endl;
     cout << "Address: " << sRec[i].address << endl;
     cout << "GPA: " << sRec[i].gpa << endl;
     cout << "Test 2: " << sRec[i].test1 << endl;
     cout << "Test 2: " << sRec[i].test2 << endl;
     cout << "Test 3: " << sRec[i].test3 << endl;
     cout << "Test 4: " << sRec[i].test4 << endl;
     cout << "Test 5: " << sRec[i].test5 << endl;
     cout << "Test 6: " << sRec[i].test6 << endl;
     cout << "Test 7: " << sRec[i].test7 << endl;
     cout << "Test 8: " << sRec[i].test8 << endl;
     cout << "Test 9: " << sRec[i].test9 << endl;
     cout << "Test 10: " << sRec[i].test10 << endl << endl;
     }
}

int StudentRecords :: binarySearch(int first, int last, int idSearch)
{
    int middle;
    
    if (first > last)
    {
             return -1;
    }
    middle = (first + last)/2;
    if (sRec[middle].id == idSearch)
    {
             return middle;
    }
    if (sRec[middle].id < idSearch)
    {
             return binarySearch(middle+1, last, idSearch);
    }
    else
    {
             return binarySearch(first, middle-1, idSearch);
    }
}
    
void StudentRecords :: displaySearched(int R)
{
     cout << "Name: " << sRec[R].name << endl;
     cout << "Id: " <<sRec[R].id << endl;
     cout << "Address: " << sRec[R].address << endl;
     cout << "GPA: " <<sRec[R].gpa << endl;
     cout << "Test 1: " << sRec[R].test1 << endl;
     cout << "Test 2: " << sRec[R].test2 << endl;
     cout << "Test 3: " << sRec[R].test3 << endl;
     cout << "Test 4: " << sRec[R].test4 << endl;
     cout << "Test 5: " << sRec[R].test5 << endl;
     cout << "Test 6: " << sRec[R].test6 << endl;
     cout << "Test 7: " << sRec[R].test7 << endl;
     cout << "Test 8: " << sRec[R].test8 << endl;
     cout << "Test 9: " << sRec[R].test9 << endl;
     cout << "Test 10: " << sRec[R].test10 << endl;     
     
}
    
void StudentRecords :: sortVector()
{
     bool swap;
     int tempId, tempTest1, tempTest2,tempTest3, tempTest4, tempTest5, tempTest6, tempTest7, tempTest8, tempTest9, tempTest10;
     string tempName, tempAddress;
     double tempGpa;
     
     
     do
     {
         swap = false;
         for (int count = 0; count < 19; count++)
         {
             if (sRec[count].id > sRec[count + 1].id)
             {
                   tempId = sRec[count].id;
                   tempName = sRec[count].name;
                   tempAddress = sRec[count].address;
                   tempGpa = sRec[count].gpa;
                   tempTest1 = sRec[count].test1;
                   tempTest2 = sRec[count].test2;
                   tempTest3 = sRec[count].test3;
                   tempTest4 = sRec[count].test4;
                   tempTest5 = sRec[count].test5;
                   tempTest6 = sRec[count].test6;
                   tempTest7 = sRec[count].test7;
                   tempTest8 = sRec[count].test8;
                   tempTest9 = sRec[count].test9;
                   tempTest10 = sRec[count].test10;
                   
                   sRec[count].id = sRec[count + 1].id;
                   sRec[count].name = sRec[count + 1].name;
                   sRec[count].address = sRec[count + 1].address;
                   sRec[count].gpa = sRec[count + 1].gpa;
                   sRec[count].test1 = sRec[count + 1].test1;
                   sRec[count].test2 = sRec[count + 1].test2;
                   sRec[count].test3 = sRec[count + 1].test3;
                   sRec[count].test4 = sRec[count + 1].test4;
                   sRec[count].test5 = sRec[count + 1].test5;
                   sRec[count].test6 = sRec[count + 1].test6;
                   sRec[count].test7 = sRec[count + 1].test7;
                   sRec[count].test8 = sRec[count + 1].test8;
                   sRec[count].test9 = sRec[count + 1].test9;
                   sRec[count].test10 = sRec[count + 1].test10;
                   
                   sRec[count + 1].id = tempId;
                   sRec[count + 1].name = tempName;
                   sRec[count + 1].address = tempAddress;
                   sRec[count + 1].gpa = tempGpa;
                   sRec[count + 1].test1 = tempTest1;
                   sRec[count + 1].test2 = tempTest2;
                   sRec[count + 1].test3 = tempTest3;
                   sRec[count + 1].test4 = tempTest4;
                   sRec[count + 1].test5 = tempTest5;
                   sRec[count + 1].test6 = tempTest6;
                   sRec[count + 1].test7 = tempTest7;
                   sRec[count + 1].test8 = tempTest8;
                   sRec[count + 1].test9 = tempTest9;
                   sRec[count + 1].test10 = tempTest10;
                   
                   swap = true;
             }
         }
     } while (swap);
     
}


int main()
{
    StudentRecords sRec;
    int command, searchFor, results;
    
    sRec.addRecords();
    
    do
    {
    
    cout << "********************************************" << endl;
    cout << "*       Enter 1 To Display Records         *" << endl;
    cout << "*       Enter 2 To Search Vector For Id    *" << endl;
    cout << "********************************************" << endl;
    
    
    cin >> command;
    
    if (command == 1)
    {
    sRec.displayRecords();
    }
    
    else if (command ==2)
    {
         sRec.sortVector();
         cout << "Enter The ID to Search for ";
         cin >> searchFor;
         cout << endl;
         sRec.binarySearch(0, 19, searchFor);
         
         results = sRec.binarySearch(0, 19, searchFor);
         
         if (results == -1)
            cout << "Id Does Not Exist In The Vector" << endl;
            
         else
         {
             sRec.displaySearched(results);
         }
         
    }
    cout << endl;
} while (command == 1 || command == 2);
    
    system ("pause>nul");  
    return 0; 
}
