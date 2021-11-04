/***********************************************************************
* Program:
*  Lab08 VULNERABILITIES & EXPLOITS
* Author:
*  CSE 453 Group 3
* Summary:
* 
************************************************************************/
#include <iostream>
#include <array>
using namespace std;
void pointerVulnerability(long * array, int size);
void pointerWorking();
void pointerExploit();

void arrayVulnerability(int input1, int input2);
void arrayWorking();
void arrayExploit();


int main()
{
   arrayWorking();
   arrayExploit();
   //pointerWorking();
   //pointerExploit();
   

  
  
 


   return 0;
}

// ARRAY INDEX
/************************************************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
************************************************************************/
//change to retuen a data type
void arrayVulnerability(int input1, int input2)
{
   
   int grade[] = {90, 70, 60};
  
   
   grade[input1] = input2;
   
   int count = 0;

   try {
      
      for (int grade : grade)
      {
         cout << "Element " << count << " : " << grade << endl;
         count++;
      }
   }
   catch (...) {
   
      cout << "Error " << endl;
   
   };
}

/***********************************************************************
 * ARRAY WORKING
 * Call arrayVulnerability() in a way that does
 * not yield unexpected behavior
 **********************************************************************/
void arrayWorking()
{
   cout << "Array Index without Exploit" << endl;
   arrayVulnerability(0, 70);
  
}

/***********************************************************************
 * ARRAY EXPLOIT
 * 1. The attacker provides an array index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the array at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 **********************************************************************/
void arrayExploit()
{
   cout << "Array Index with Exploit" << endl;
   arrayVulnerability(3, 100);
}

// POINTER SUBTERFUGE
/**********************************************************************
 * Pointer VULNERABILTY
 * 1. There must be a pointer used in the code.
 *************************************************************************/
void pointerVulnerability(long * array, int size)
//void pointerVulnerability(const char *input1)
{
   /*long buffer[1];
   long buffer[2]; 
   const char * message = "Safe";
   for (int i = 0; i < size; i++)
   {
      buffer[i] = array[i];
   }
   cout << "Message is: \"" << message << "\".\n";
}

/***********************************************************************
 * Pointer WORKING
 * Call pointerVulnerability() in a way that does
 * not yield unexpected behavior
 **********************************************************************/
void pointerWorking()
{
   long array[1] = { 1 };
   pointerVulnerability(array, 1);
}

/***********************************************************************
 * Pointer EXPLOIT
 * 1. The attacker must exploit a vulnerability allowing unintended access to
 **********************************************************************/
void pointerExploit()
{
   //4197490
   //pointerVulnerability("Safe\0");
   // an attacker�s array
   long array[3] = {1, 1, (long)"Dangerous"};
   // exploit it
   pointerVulnerability(array, 3);
}

//ARC INJECTION
/**********************************************************************
 *  ARC VULNERABILTY
 *  1. There must be a function pointer used in the code.
 *************************************************************************/
void arcVulnerability(/* feel free to add parameters */)
{
}

/***********************************************************************
 *  ARC WORKING
 *  Call arcVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void arcWorking()
{
   arcVulnerability(/* parameters with non-malicious data */);
}

/***********************************************************************
 * ARC EXPLOIT
 * 1. The attacker must exploit a vulnerability allowing unintended access to
 **********************************************************************/
void arcExploit()
{
   arcVulnerability(/* parameters with malicious data */);
}

//VTABLE SPRAYING
/**********************************************************************
 *  VTABLE VULNERABILTY
 *  1. The vulnerable class must be polymorphic.
 **********************************************************************/
void vtableVulnerability(/* feel free to add parameters */)
{
}

/***********************************************************************
 *  VTABLE WORKING
 *  Call vtableVulnerabilityy() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void vatableWorking()
{
   vtableVulnerability(/* parameters with non-malicious data */);
}

/***********************************************************************
 * VTABLE EXPLOIT
 * 1. Through some vulnerability, the V-Table pointer or a function pointer
 *********************************************************************/
void vtableExploit()
{
   vtableVulnerability(/* parameters with malicious data */);
}

//STACK SMASHING
/**********************************************************************
 * STACK VULNERABILTY
 * 1. There must be a buffer (such as an array) on the stack.
 *********************************************************************/
void stackVulnerability(/* feel free to add parameters */)
{
}

/***********************************************************************
 *  STACK WORKING
 *  Call stackVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void Working()
{
   stackVulnerability(/* parameters with non-malicious data */);
}

/***********************************************************************
 * STACK EXPLOIT
 * 1. The attacker must provide more data into the outwardly facing buffer
 **********************************************************************/
void Exploit()
{
   stackVulnerability(/* parameters with malicious data */);
}

//HEAP SPRAYING
/**********************************************************************
 * HEAP VULNERABILTY
 * 1. There must be two adjacent heap buffers.
 *************************************************************************/
void heapVulnerability(/* feel free to add parameters */)
{
}

/***********************************************************************
 *  HEAP WORKING
 *  Call heapVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void heapWorking()
{
   heapVulnerability(/* parameters with non-malicious data */);
}

/***********************************************************************
 * HEAP EXPLOIT
 * 1. The attacker must provide more data into the outwardly facing heap
 **********************************************************************/
void heapExploit()
{
   heapVulnerability(/* parameters with malicious data */);
}

//INTEGER OVERFLOW
/**********************************************************************
 * INTEGER VULNERABILTY
 * 1. There must be a security check represented by an expression.
 *********************************************************************/
void integerVulnerability(/* feel free to add parameters */)
{
   //cout 
}

/***********************************************************************
 *  INTEGER WORKING
 *  Call integerVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void integerWorking()
{
   integerVulnerability(/* parameters with non-malicious data */);
}

/***********************************************************************
 * INTEGER EXPLOIT
 * 1. Provide input, either a buffer size or a single value, that is directly or
 **********************************************************************/
void integerExploit()
{
   integerVulnerability(/* parameters with malicious data */);
}

//ANSI-UNICODE CONVERSION
/**********************************************************************
 * UNICODE VULNERABILTY
 * 1. There must be a buffer where the basetype is greater than one.
 *********************************************************************/
void unicodeVulnerability(/* feel free to add parameters */)
{
}

/***********************************************************************
 *  UNICODE WORKING
 *  Call unicodeVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void unicodeWorking()
{
   unicodeVulnerability(/* parameters with non-malicious data */);
}

/***********************************************************************
 * UNICODE EXPLOIT
 * 1. The attacker must provide more than half as much data into the
 **********************************************************************/
void unicodeExploit()
{
   unicodeVulnerability(/* parameters with malicious data */);
}