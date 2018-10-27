#include <iostream> 
#include <string> 


using namespace std;


class infix 
{ 
      private : 
             char target[50], stack[50]; 
             char *PtrS, *PtrT; 
             int top; 
      public : 
             infix(); 
             void setexpression(char *str); 
             void push(char c); 
             char pop(); 
             void convert(); 
             int expressionOrder(char c); 
             void display(); 
}; 
                     
infix :: infix() 
{ 
      top = -1; 
      strcpy (target, ""); 
      strcpy (stack, ""); 
      PtrT = target ; 
      PtrS = ""; 
} 
                           
void infix :: setexpression(char *str) 
{ 
      PtrS = str; 
} 
                                
void infix :: push(char c) 
{ 
      if (top == 50) 
         cout << endl << "Stack is full" << endl; 
      else 
      { 
         top++; 
         stack[top] = c; 
      } 
} 
char infix :: pop() 
{ 
      if (top == -1) 
      { 
           
          return -1; 
      } 
      else 
      { 
          char item = stack[top]; 
          top--; 
          return item; 
       } 
}
 
void infix :: convert() 
{ 
           while (*PtrS) 
           { 
                  if (*PtrS == ' ' || *PtrS == '\t') 
                  { 
                      PtrS++; 
                      continue; 
                  } 
                  if (isdigit (*PtrS) || isalpha (*PtrS)) 
                  { 
                     while (isdigit (*PtrS) || isalpha (*PtrS)) 
                     { 
                           *PtrT = *PtrS; 
                           PtrS++; 
                           PtrT++; 
                     } 
                  } 
                  if (*PtrS == '(') 
                  { 
                     push (*PtrS); 
                     PtrS++ ; 
                  } 
                  char opr; 
                  if (*PtrS == '*' || *PtrS == '+' || *PtrS == '/' || *PtrS == '%' || *PtrS == '-' || *PtrS == '$') 
                  { 
                      if ( top != -1 ) 
                      { 
                          opr = pop(); 
                          while (expressionOrder (opr) >= expressionOrder (*PtrS)) 
                          { 
                          *PtrT = opr; 
                          PtrT++; 
                          opr = pop(); 
                      } 
                      push (opr) ; 
                      push (*PtrS); 
                  } 
                  else push (*PtrS); 
                      PtrS++; 
                  } 
                  if (*PtrS == ')') 
                  { 
                     opr = pop(); 
                     while ((opr) != '(') 
                     { 
                          *PtrT = opr; 
                          PtrT++; 
                          opr = pop(); 
                     } 
                     PtrS++; 
                  } 
           } 
           while (top != -1) 
           { 
                char opr = pop(); 
                *PtrT = opr; 
                PtrT++; 
           } 
           *PtrT = '\0'; 
} 

int infix :: expressionOrder(char c) 
{ 
    if (c == '$') 
    return 3; 
    if (c == '*' || c == '/' || c == '%') 
       return 2; 
    else 
    { 
         if (c == '+' || c == '-') 
            return 1; 
    else 
       return 0; 
    } 
} 
                                                                     
void infix :: display() 
{ 
     cout << target; 
} 
                                                                          
int main() 
{ 
    char expression[50]; 
    infix infixObj; 
    char command;
    
    cout << "**********************************************" << endl;
    cout << "Enter an infix expression: "; 
    cin.getline ( expression, 50 );   
    infixObj.setexpression ( expression ); 
    infixObj.convert( );   
    cout << endl << "The postfix expression is: "; 
    infixObj.display(); 
    cout << endl << "**********************************************" << endl;
    cout << endl << endl << "Press any key to exit";
    system ("pause>nul");
    return 0;
}
