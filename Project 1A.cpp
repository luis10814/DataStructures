#include <iostream>
#include <limits>

using namespace std;

class StudentRecords
{
      private:
              
              struct Students
              {
              string name, address;
              int id, value;
              double gpa;
              
              struct Students *next;       
              };
              
              Students *head;
              
      public:
             
             StudentRecords()
             {
                head = NULL;
             }
             
             ~StudentRecords();
             
            
             void addStudent(int, string, string, double);
             void insertStudent(int, string, string, double);
             void deleteStudent(int);
             void displayRecords() const;
};

StudentRecords ::~StudentRecords()
{
     Students *studentPtr;
     Students *nextStudent;
     
     studentPtr = head;
     
     while (studentPtr != NULL)
     {
           nextStudent = studentPtr->next;
           
           delete studentPtr;
           
           studentPtr = nextStudent;
           
     }
}



void StudentRecords :: addStudent(int studentId, string studentName, string studentAddress, double studentGpa)
{
     Students *newStudent;
     Students *studentPtr;
     
     newStudent = new Students;
     newStudent->id = studentId;
     newStudent->name = studentName;
     newStudent->address = studentAddress;
     newStudent->gpa = studentGpa;
     newStudent->next = NULL;
     
     if (!head)
     {
               head = newStudent;
     }
     
     else
     {
         studentPtr = head;
         
         while (studentPtr->next)
               studentPtr = studentPtr->next;
         
         studentPtr->next = newStudent;
     }
}

void StudentRecords :: insertStudent(int studentId, string studentName, string studentAddress, double studentGpa)
{
     Students *newStudent;
     Students *studentPtr;
     Students *previousStudent = NULL;
     Students *temphead = head;
     
     newStudent = new Students;
     newStudent->id = studentId;
     newStudent->name = studentName;
     newStudent->address = studentAddress;
     newStudent->gpa = studentGpa;
     newStudent->next = NULL;
     
	
	 int tempid;
	 string tempname;
	 string tempaddress;
	 double tempgpa;
	 int counter = 0;
     
     while (temphead)
	 {
		temphead = temphead->next;
		counter++;
	 }
	 temphead = head;
	
	 for (int j=0; j<counter; j++)
	 {
		while (temphead->next)  
		{
			if (temphead->id > temphead->next->id)
			{
				
				tempid = temphead->id;
				temphead->id = temphead->next->id;
				temphead->next->id = tempid;

				tempname = temphead->name;
				temphead->name = temphead->next->name;
				temphead->next->name = tempname;
				
				tempaddress = temphead->address;
				temphead->address = temphead->next->address;
				temphead->next->address = tempaddress;
				
				tempgpa = temphead->gpa;
				temphead->gpa = temphead->next->gpa;
				temphead->next->gpa = tempgpa;
				
				
				temphead = temphead->next;
			}
			else 
				temphead = temphead->next;
		}	
		temphead = head;
	 }
    
    
     
     if (!head)
     {
               head = newStudent;
               newStudent->next = NULL;
     }
     else
     {
         studentPtr = head;
         previousStudent = NULL;
         
         while (studentPtr != NULL && studentPtr->id < studentId)
         {
               previousStudent = studentPtr;
               studentPtr = studentPtr->next;
         }
         if (previousStudent == NULL)
         {
               head = newStudent;
               newStudent->next = studentPtr;
         }
         else
         {
               previousStudent->next = newStudent;
               newStudent->next = studentPtr;
         }
     }
}

void StudentRecords :: deleteStudent(int studentId)
{
     Students *studentPtr;
     Students *previousStudent;
     
     if (!head)
        return;
        
     if (head->id == studentId)
     {
        studentPtr = head->next;
        delete head;
        head = studentPtr;
     }
     else
     {
         studentPtr = head;
         
         while (studentPtr != NULL && studentPtr->id != studentId)
         {
               previousStudent = studentPtr;
               studentPtr = studentPtr->next;
         }
         
         if (studentPtr)
         {
               previousStudent->next = studentPtr->next;
               delete studentPtr;
         }
     }
}

void StudentRecords :: displayRecords() const
{
     Students *studentPtr;
     
     studentPtr = head;
     
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
    
    int newStudentsId, num, num2;
    char command;
    char newStudentsName[20];
    char newStudentsAddress[40];
    double newStudentsGpa;
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
    sRecords.addStudent(defaultRecords[i].idOne, defaultRecords[i].nameOne, 
    defaultRecords[i].addressOne, defaultRecords[i].gpaOne);
    }
    
    
    
    do
    {
                                  
         cout << "                     *******************************" << endl;
         cout << "                     *   1 To Append New Student   *" << endl;
         cout << "                     *   2 To Insert New Student   *" << endl;
         cout << "                     *   3 To Delete Student       *" << endl;
         cout << "                     *   4 To Display Records      *" << endl;
         cout << "                     *******************************" << endl;
    
    
    
         cout << "Enter Command: ";
         cin >> command;
         cout << endl;
    
         if (command == '1')
         {
               cout << "Enter New Students Name: " << endl;
               cin.ignore( numeric_limits<streamsize>::max(), '\n');
               cin.getline(newStudentsName, 20);
               
               cout << "Enter New Students ID: " << endl;
               cin >>  newStudentsId;
               
               cout << "Enter New Students Address: " << endl;
               cin.ignore( numeric_limits<streamsize>::max(), '\n');
               cin.getline(newStudentsAddress, 40);
               
               cout << "Enter New Students GPA: " << endl;
               cin >> newStudentsGpa;
               
               while (newStudentsGpa < 0 || newStudentsGpa > 4)
               {
                    cout << "GPA Is Out Of Range. Enter New GPA: " << endl;
                    cin >> newStudentsGpa;                  
               }
               
               cout << endl;
               
               sRecords.addStudent(newStudentsId, newStudentsName, 
               newStudentsAddress, newStudentsGpa );
         }
         
         else if (command == '2')
         {
               cout << "Enter New Students Name: " << endl;
               cin.ignore( numeric_limits<streamsize>::max(), '\n');
               cin.getline(newStudentsName, 20);
               
               cout << "Enter New Students ID: " << endl;
               cin >>  newStudentsId;
               
               cout << "Enter New Students Address: " << endl;
               cin.ignore( numeric_limits<streamsize>::max(), '\n');
               cin.getline(newStudentsAddress, 40);
               
               cout << "Enter New Students GPA: " << endl;
               cin >> newStudentsGpa;
               
               while (newStudentsGpa < 0 || newStudentsGpa > 4)
               {
                    cout << "GPA Is Out Of Range. Enter New GPA: " << endl;
                    cin >> newStudentsGpa;                  
               }
               cout << endl;
               
               sRecords.insertStudent(newStudentsId, newStudentsName, 
               newStudentsAddress, newStudentsGpa);
               
               cout << "New Student Inserted" << endl;
         }
         
         else if (command == '3')
         {
               cout << "Enter The ID Of The Student You Wish To Delete: ";
               cin >> newStudentsId;
               sRecords.deleteStudent(newStudentsId);
               cout << "Student Id " << newStudentsId << " Has Been Deledted" ;
               cout << endl;
         }
    
         else if (command == '4')
         {
               sRecords.displayRecords();
         }
         
        
         
         
    } while (command != 'Q' && command != 'q');
    
    cout << "Press Any Key To Exit";
    system ("pause>nul");
    return 0;   
}
