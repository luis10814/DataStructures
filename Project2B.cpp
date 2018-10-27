# include <iostream>
#include <limits>

using namespace std;

class StudentRecords
{
      private:
              
              struct Students
              {
              string nameOne, addressOne;
              int idOne;
              double gpaOne;
              
              struct Students *nextOne;       
              };
              Students *head;
              
              
              struct StudentsStack
              {
              string name, address;
              int id;
              double gpa;
              
              struct StudentsStack *next;       
              };
              
              StudentsStack *top;
              
              
      public:
             
             StudentRecords()
             {
                top = NULL;
                head = NULL;
             }
             
             ~StudentRecords();
             
             void addStudent(string, string, int, double);
             void displayNonPopped() const;
             void displayLinkedList() const;
             void push();
             void pop(string &, string &, int &, double &);
             bool isEmpty() const;
};

StudentRecords ::~StudentRecords()
{
     StudentsStack *studentPtr;
     StudentsStack *nextStudent;
     Students *studentPtrOne;
     Students *nextStudentOne;
     
     studentPtr = top;
     
     while (studentPtr != NULL)
     {
           nextStudent = studentPtr->next;
           
           delete studentPtr;
           
           studentPtr = nextStudent;
     }
     
     studentPtrOne = head;
     
     while (studentPtrOne != NULL)
     {
           nextStudentOne = studentPtrOne->nextOne;
           
           delete studentPtrOne;
           
           studentPtrOne = nextStudentOne;
     }
}

void StudentRecords :: addStudent(string studentName, string studentAddress, int studentId, double studentGpa)
{
     Students *newStudentOne;
     Students *studentPtrOne;
     
     newStudentOne = new Students;
     newStudentOne->idOne = studentId;
     newStudentOne->nameOne = studentName;
     newStudentOne->addressOne = studentAddress;
     newStudentOne->gpaOne = studentGpa;
     newStudentOne->nextOne = NULL;
     
     if (!head)
     {
               head = newStudentOne;
     }
     
     else
     {
         studentPtrOne = head;
         
         while (studentPtrOne->nextOne)
               studentPtrOne = studentPtrOne->nextOne;
         
         studentPtrOne->nextOne = newStudentOne;
     }
}

void StudentRecords :: push()
{
     while (head != NULL)
     {
     
     StudentsStack *newStudent;
     newStudent = new StudentsStack;
     
     
     
     //while (head != NULL)
     //{
    
     newStudent->id = head->idOne;
     newStudent->name = head->nameOne;
     newStudent->address = head->addressOne;
     newStudent->gpa = head->gpaOne;
     
     
     
     
     
     
     
     if (isEmpty())
     {
           top = newStudent;
           
           newStudent->next = NULL;
          
           
     }
     else
     {
          
            
          newStudent->next = top;
          top = newStudent;
            
     }  
           
     head = head->nextOne;
    
    
    //cout << newStudent->name << endl;
    //cout << newStudent->id << endl;
    //cout << newStudent->address << endl;
    //cout << newStudent->gpa << endl;
    
}
    
     
}

void StudentRecords :: pop(string &inName, string &inAddress, int &inId, double &inGpa)
{
     
     StudentsStack *temp;
      if (isEmpty())
     {
           cout << "The Stack Is Empty." << endl;
           
     }
     else
     {
           inName = top->name;
           inAddress = top->address;
           inId = top->id;
           inGpa = top->gpa;
           temp = top->next;
           delete top;
           top = temp;
           
     }
}

bool StudentRecords :: isEmpty() const
{
     bool status;
     
     if (!top)
        status = true;
     else
         status = false;
     return status;
}

void StudentRecords :: displayLinkedList() const
{
     Students *studentPtrOne;
     
     studentPtrOne = head;
     
     while (studentPtrOne)
     {
           cout << "***************************************" << endl;
           cout << studentPtrOne->nameOne << endl;
           cout << studentPtrOne->idOne << endl;
           cout << studentPtrOne->addressOne << endl;
           cout << studentPtrOne->gpaOne << endl;
           cout << "***************************************" << endl;
           studentPtrOne = studentPtrOne->nextOne;
     }
    
}


void StudentRecords :: displayNonPopped() const
{
     StudentsStack *studentPtr;
     
     studentPtr = top;
     
     while (studentPtr)
     {
           cout << "***************************************" << endl;
           cout << studentPtr->name << endl;
           cout << studentPtr->id << endl;
           cout << studentPtr->address << endl;
           cout << studentPtr->gpa << endl;
           cout << "***************************************" << endl;
           studentPtr = studentPtr->next;
     }
    
}


int main()
{
    struct StudentsOne
              {
              
              int idOne;
              string nameOne, addressOne;
              double gpaOne;
                    
              };
    
    int newStudentsId, catchId;
    string catchName, catchAddress;
    double catchGpa;
    char command;
    StudentRecords sRecords;
    StudentsOne defaultRecords[20];
    
    defaultRecords[0].idOne = 559119;
    defaultRecords[0].nameOne = "Luis Pena";
    defaultRecords[0].addressOne = "162 Stony Creek Dr";
    defaultRecords[0].gpaOne = 3.14;
    defaultRecords[1].idOne = 785463;
    defaultRecords[1].nameOne = "Spike Speigal";
    defaultRecords[1].addressOne = "999 Space Ln";
    defaultRecords[1].gpaOne = 2.10;
    defaultRecords[2].idOne = 354789;
    defaultRecords[2].nameOne = "Faye Valentine";
    defaultRecords[2].addressOne = "186 Rainbow Ln";
    defaultRecords[2].gpaOne = 1.50;
    defaultRecords[3].idOne = 864125;
    defaultRecords[3].nameOne = "Jet Black";
    defaultRecords[3].addressOne = "123 Made Up Rd";
    defaultRecords[3].gpaOne = 4.0;
    defaultRecords[4].idOne = 254786;
    defaultRecords[4].nameOne = "Cloud Strife";
    defaultRecords[4].addressOne = "777 Mako Blvd";
    defaultRecords[4].gpaOne = 2.88;
    defaultRecords[5].idOne = 222214;
    defaultRecords[5].nameOne = "Tifa Lockheart";
    defaultRecords[5].addressOne = "33 Memory Ln";
    defaultRecords[5].gpaOne = 3.99;
    defaultRecords[6].idOne = 111186;
    defaultRecords[6].nameOne = "Vincent Valentine";
    defaultRecords[6].addressOne = "777 Chaos Rd";
    defaultRecords[6].gpaOne = 1.0;
    defaultRecords[7].idOne = 369874;
    defaultRecords[7].nameOne = "Aerith Gainsborough";
    defaultRecords[7].addressOne = "777 Holy Dr";
    defaultRecords[7].gpaOne = 2.99;
    defaultRecords[8].idOne = 556633;
    defaultRecords[8].nameOne = "Barret Wallace";
    defaultRecords[8].addressOne = "951 sector Dr";
    defaultRecords[8].gpaOne = 3.12;
    defaultRecords[9].idOne = 775541;
    defaultRecords[9].nameOne = "Marlene Wallace";
    defaultRecords[9].addressOne = "951 Sector Dr";
    defaultRecords[9].gpaOne = 4.0;
    defaultRecords[10].idOne = 221133;
    defaultRecords[10].nameOne = "Cid Highwind";
    defaultRecords[10].addressOne = "645 Rocket St";
    defaultRecords[10].gpaOne = 1.96;
    defaultRecords[11].idOne = 778855;
    defaultRecords[11].nameOne = "Yuffie Kasaragi";
    defaultRecords[11].addressOne = "28 Ninja St";
    defaultRecords[11].gpaOne = 3.75;
    defaultRecords[12].idOne = 997700;
    defaultRecords[12].nameOne = "Rufus Shinra";
    defaultRecords[12].addressOne = "357 Shinra Dr";
    defaultRecords[12].gpaOne = 3.02;
    defaultRecords[13].idOne = 431122;
    defaultRecords[13].nameOne = "Jose Rodriguez";
    defaultRecords[13].addressOne = "531 ridge Rd";
    defaultRecords[13].gpaOne = 3.66;
    defaultRecords[14].idOne = 465213;
    defaultRecords[14].nameOne = "Chris Godwin";
    defaultRecords[14].addressOne = "312 Thousand Oak Dr";
    defaultRecords[14].gpaOne = 2.89;
    defaultRecords[15].idOne = 754632;
    defaultRecords[15].nameOne = "Yvette Lopez";
    defaultRecords[15].addressOne = "312 Wild Turkey Rd";
    defaultRecords[15].gpaOne = 1.40;
    defaultRecords[16].idOne = 123654;
    defaultRecords[16].nameOne = "Karleigh Ford";
    defaultRecords[16].addressOne = "485 braunfels Ln";
    defaultRecords[16].gpaOne = 3.50;
    defaultRecords[17].idOne = 789645;
    defaultRecords[17].nameOne = "Ashley Lopez";
    defaultRecords[17].addressOne = "623 Phlugerville Way";
    defaultRecords[17].gpaOne = 2.50;
    defaultRecords[18].idOne = 174582;
    defaultRecords[18].nameOne = "Clarissa Esparza";
    defaultRecords[18].addressOne = "28 Lufkin Dr";
    defaultRecords[18].gpaOne = 3.02;
    defaultRecords[19].idOne = 693174;
    defaultRecords[19].nameOne = "Steven Ledisma";
    defaultRecords[19].addressOne = "289 Round Rock Rd";
    defaultRecords[19].gpaOne = 3.14;
    
    
    for (int i = 0; i < 20; i++)
    {
    sRecords.addStudent(defaultRecords[i].nameOne, defaultRecords[i].addressOne, defaultRecords[i].idOne, 
    defaultRecords[i].gpaOne);
    }
    
    
    
    
    do
    {
                                  
         cout << "                     *******************************" << endl;
         cout << "                     *   1 To Display The Linked List   *" << endl;
         cout << "                     *   2 To Display 5 Poped Records   *" << endl;
         cout << "                     *   3 To Display the Records In the Dynamic Stack       *" << endl;
         cout << "                     *******************************" << endl;
    
    
    
         cout << "Enter Command: ";
         cin >> command;
         cout << endl;
    
         if (command == '1')
         {
              sRecords.displayLinkedList();
         }
         
         else if (command == '2')
         {
            for (int i = 5; i > 0; i--)
              {
              cout << "************************************************" << endl;
              sRecords.pop(catchName, catchAddress, catchId, catchGpa);
              cout << catchName << endl;
              cout << catchId << endl;
              cout << catchAddress << endl;
              cout << catchGpa << endl;
              cout << "************************************************" << endl << endl;
              }    
         }
         
         else if (command == '3')
         {
              
              sRecords.push();
              
              sRecords.displayNonPopped();
         }
    
         
         
    } while (command != 'Q' && command != 'q');
    
    cout << "Press Any Key To Exit";
    system ("pause>nul");
    return 0;   
}
