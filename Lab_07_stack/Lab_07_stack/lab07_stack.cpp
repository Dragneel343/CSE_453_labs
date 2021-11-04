/***********************************************************************
* Program:
*  Lab07 Stack
* Author:
*  CSE 453 Group 3
* Summary:
*  A program that calls multiple functions then displays the contents of the stack.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
using namespace std;

void one(long number);
void two(long number);
void pass() { cout << "You pass :)\n"; }
void fail() { cout << "You've failed :(\n"; }
const char * passMessage = ":)";
const char * failMessage = ":(";

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{
   char text[8] = "*MAIN**";
   char *prtText = (char*)&text;
   
   long number = 123456;
   void(*pointerFunction)() = fail;
   const char * message = failMessage;

   // display the initial values of the local variables
   cout << "main() : " << (void *)main << endl;
   cout << "\ttext:             " << text << endl;
   cout << "\tnumber:           " << number << endl;
   cout << "\tmessage:          " << message << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   // call the other functions
   one(number + 111111);     // 234567

   // display the new values of the local variables
   cout << "main() - after\n";
   cout << "\ttext:             " << text << endl;
   cout << "\tnumber:           " << number << endl;
   cout << "\tmessage:          " << message << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   return 0;
}


/************************************************
 * CONVERT TO STRING
 * Convert the data from p into a human-readable string
 * by removing all the unprintable characters and replacing
 * them with a dot
 ***********************************************/
string displayCharArray(const char * p)
{
   string output;
   for (int i = 0; i < 8; i++)
      output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
   return output;
}

/**********************************************
 * ONE : The next item on the call stack
 **********************************************/
void one(long number)               // 234567
{
   char text[8] = "**ONE**";

   cout << "one() : " << (void *)one << endl;
   cout << "\tmessage: " << (void *)failMessage << endl;
   cout << "\tfail():  " << (void *)fail << endl;

   two(number + 111111);    // 345678
}

/**********************************************
 * TWO : The bottom of the call stack
 **********************************************/
void two(long number)              // 345678
{
   // start your display of the stack from this point
   long bow = number + 111111;     // 456789
   char text[8] = "**TWO**";
   long * pLong = NULL;
   char * pChar = NULL;

   // header for our table. Use these setw() offsets in your table
   cout << '[' << setw(2) << 'i' << ']'
      << setw(15) << "address"
      << setw(20) << "hexadecimal"
      << setw(20) << "decimal"
      << setw(18) << "characters"
      << endl;
   cout << "----+"
      << "---------------+"
      << "-------------------+"
      << "-------------------+"
      << "-----------------+\n";
   //place in the stack
   char * current;

   for (long i = 24; i >= -4; i--)   // You may need to change 24 to another number
   {
   ////////////////////////////////////////////////
   // Insert code here to display the callstack
   //go through stack 8 bytes at a time
   current = (char*)((char*)&bow + 8 * i);
   
   cout << '[' << setw(2) << i << ']'
      << setw(15) << (void*)current
      << setw(20) << hex << *(long*)current
      << setw(20) << dec << *(long*)current
      << setw(18) << displayCharArray(current) << endl;
   //
   ////////////////////////////////////////////////
   }

   ////////////////////////////////////////////////
   // Insert code here to change the variables in main()

   // change text in main() to "*main**"
   //contents of stack
   const char* search = (char*)&bow;
   //look for a string 
   while (string(search) != "*MAIN**")
   {
      //if not found look at next part
      search++;
   }
      char* changeText = (char*)search;
      changeText[0] = '*';
      changeText[1] = 'm';
      changeText[2] = 'a';
      changeText[3] = 'i';
      changeText[4] = 'n'; 
      changeText[5] = '*';
      changeText[6] = '*';

      //const char * message = failMessage;

    // change number in main() to 654321
      //contents of stack
      pLong = (long*)&bow;
      //look for int
      while (*pLong != 123456)
      { 
         //if not found look at next part        
         pLong++;         
      }      
      *pLong = 654321;

      //const char * message = failMessage;
      /*pLong = (long*)&bow;
      while (pLong != (long*)fail)
      {
         pLong++;
      }
      pLong = (long*)pass;*/


      // change number in main() to 654321

      // change pointerFunction in main() to point to pass

      // change message in main() to point to passMessage
      //(void *)fail = (void *)pass;
      //
      ////////////////////////////////////////////////
}