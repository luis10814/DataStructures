
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
                     
                     
              };
              
             vector<students>sRec;
      public : 
             void addRecords();
             void displayRecords();
             void quickSortId(int, int);
             void quickSortGpa(int, int);
             int partitionId(int, int);
             int partitionGpa(int, int);
             void swap(students &, students &);
             
             
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

void StudentRecords :: quickSortId(int start, int end)
{
     int pivotPoint;
     
     if (start < end)
     {
          pivotPoint = partitionId(start, end);
          quickSortId(start, pivotPoint - 1);
          quickSortId(pivotPoint + 1, end);
     }
}

void StudentRecords :: quickSortGpa(int start, int end)
{
     int pivotPoint;
     
     if (start < end)
     {
          pivotPoint = partitionGpa(start, end);
          quickSortGpa(start, pivotPoint - 1);
          quickSortGpa(pivotPoint + 1, end);
     }
}

int StudentRecords :: partitionId(int start, int end)
{
    int pivotValue, pivotIndex, mid;
    
    mid = (start + end) / 2;
    swap(sRec[start], sRec[mid]);
    pivotIndex = start;
    pivotValue = sRec[start].id;
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (sRec[scan].id < pivotValue)
        {
             pivotIndex++;
             swap(sRec[pivotIndex], sRec[scan]);
        }
    }
    swap(sRec[start], sRec[pivotIndex]);
    return pivotIndex;
}

int StudentRecords :: partitionGpa(int start, int end)
{
    int pivotIndex, mid;
    double pivotValue;
    
    mid = (start + end) / 2;
    swap(sRec[start], sRec[mid]);
    pivotIndex = start;
    pivotValue = sRec[start].gpa;
    for (int scan = start + 1; scan <= end; scan++)
    {
        if (sRec[scan].gpa < pivotValue)
        {
             pivotIndex++;
             swap(sRec[pivotIndex], sRec[scan]);
        }
    }
    swap(sRec[start], sRec[pivotIndex]);
    return pivotIndex;
}

void StudentRecords :: swap(students &value1, students &value2)
{
     students temp = value1;
     
     value1 = value2;
     value2 = temp;
}




int main()
{
    StudentRecords sRec;
    int command, searchFor, results, sortCommand;
    
    sRec.addRecords();
    
    do
    {
    
    cout << "********************************************" << endl;
    cout << "*       Enter 1 To Display Records         *" << endl;
    cout << "*       Enter 2 To Sort Vector And Display    *" << endl;
    cout << "********************************************" << endl;
    
    
    cin >> command;
    
    if (command == 1)
    {
    sRec.displayRecords();
    }
    
    else if (command ==2)
    {
         cout << "Type 1 To Sort By Id Or Type 2 To Sort By GPA" << endl;
         cin >> sortCommand;
         
         if (sortCommand == 1)
         {
             sRec.quickSortId(0, 19);
             sRec.displayRecords();
         }
         
         else if (sortCommand == 2)
         {
             sRec.quickSortGpa(0, 19);
             sRec.displayRecords(); 
         }
              
              
         else
         {
             cout << "Invalid Command" << endl;
         }
              
         
         
    }
    cout << endl;
} while (command == 1 || command == 2);
    
    system ("pause>nul");  
    return 0; 
}
