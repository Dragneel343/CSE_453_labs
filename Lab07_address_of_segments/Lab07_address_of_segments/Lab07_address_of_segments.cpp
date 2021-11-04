/***********************************************************************
* Program:
*  Lab07
* Author:
*  CSE 453 Group 3
* Summary:
*  The goal of the program is to get the any memory address from the stack,
*  heap and code segment and display them.
************************************************************************/
#include<iostream>
using namespace std;

//var to get the address for the code segment
const int code = 15;

int main()
{
   //display code segment address
   cout << "Code: " << &code << endl;
   cout << endl;

   //var to get the address for the stack
   double stack = 10;
   //display stack address
   cout << "Stack: " << &stack << endl;
   cout << endl;
 
   //var to get the address for the heap
   char* heap = new char;
   *heap = 'A';
   //display heap address
   cout << "Heap: " << &heap << endl;

   return 0;
}