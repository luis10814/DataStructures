#include <iostream>

using namespace std;

class tower
{
      public:
            void moveDiscs(int, char, char, char);
};
     void tower :: moveDiscs(int numOfDiscs, char pegA, char pegB, char tempPeg)
     {
          if (numOfDiscs > 0)
          {
                  moveDiscs(numOfDiscs - 1, pegA, tempPeg, pegB);
                  cout << "move disc " << numOfDiscs << " from peg " << pegA << " to peg " << pegB << endl;
                  moveDiscs(numOfDiscs - 1, tempPeg, pegB, pegA);
          }
          
     }
int main()
{
    tower hanoi;
    int discs;
    char command;
    string exceptionString = "No Negative Numbers";
    do
    {
           
    cout << "Enter The Number Of Discs.";
    cin >> discs;
    
     try
         {
                if (discs < 0)
                throw exceptionString;
         }
          catch (string exceptionString)
          {
               cout << exceptionString;
          }     
    
    cout << endl;
    
    hanoi.moveDiscs(discs, 'A', 'C', 'B');
    cout << endl << "Play Again? Y/N:";
    cin >> command;
    } while (command != 'y' || command != 'Y');
    
    system ("pause>nul");
    return 0;
}
