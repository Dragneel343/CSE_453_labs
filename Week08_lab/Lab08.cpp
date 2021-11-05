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

void integerVulnerability(unsigned short deposit);
void integerWorking();
void integerExploit();


int main()
{
   //arrayWorking();
   //arrayExploit();
   //pointerWorking();
   //pointerExploit();
   integerWorking();
   integerExploit();
   

  
  
 


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
 * 1. There must be a pointer used in the code. * 2. Through some vulnerability, there must be a way for user input to * overwrite the pointer. This typically happens through a stack buffer * vulnerability. * 3. After the pointer is overwritten, the pointer must be dereferenced.
 *************************************************************************/
void pointerVulnerability(long * array, int size)
//void pointerVulnerability(const char *input1)
{
   /*long buffer[1];   //cout << "Intput: " << endl;   const char * p1 = input1;   const char * p2 = "Rosebud";    // the top secret password   cin >> buffer[1];               // actually referencing the pointer 'p1'   cout << p1 << endl;             // now displaying different data                                   // than our safe string*/
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
 * 1. The attacker must exploit a vulnerability allowing unintended access to * the pointer. * 2. The attacker must be able to provide a new pointer referring to data * altering the normal flow of the program.
 **********************************************************************/
void pointerExploit()
{
   //4197490
   //pointerVulnerability("Safe\0");
   // an attacker’s array
   long array[3] = {1, 1, (long)"Dangerous"};
   // exploit it
   pointerVulnerability(array, 3);
}

//ARC INJECTION
/**********************************************************************
 *  ARC VULNERABILTY
 *  1. There must be a function pointer used in the code.2. Through some vulnerability, there must be a way for user input tooverwrite the function pointer. This typically happens through a stackbuffer vulnerability.3. After the memory is overwritten, the function pointer must bedereferenced.  
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
 * 1. The attacker must exploit a vulnerability allowing unintended access to * the function pointer. * 2. The attacker must have the address to another function which is to be * used to replace the existing function pointer.
 **********************************************************************/
void arcExploit()
{
   arcVulnerability(/* parameters with malicious data */);
}

//VTABLE SPRAYING
/**********************************************************************
 *  VTABLE VULNERABILTY
 *  1. The vulnerable class must be polymorphic. *  2. The class must have a buffer as a member variable. *  3. Through some vulnerability, there must be a way for user input to *  overwrite parts of the V-Table. *  4. After a virtual function pointer is overwritten, the virtual function must *  be called.
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
 * 1. Through some vulnerability, the V-Table pointer or a function pointer * within the V-Table must be overwritten. * 2. The attacker must have the address to another V-Table pointer or a * function pointer.
 *********************************************************************/
void vtableExploit()
{
   vtableVulnerability(/* parameters with malicious data */);
}

//STACK SMASHING
/**********************************************************************
 * STACK VULNERABILTY
 * 1. There must be a buffer (such as an array) on the stack. * 2. The buffer must be reachable from an external input. * 3. The mechanism to fill the buffer from the external input must not * correctly check for the buffer size. * 4. A buffer overrun (extend beyond the intended limits of the array) must * extend to the return address on the stack.
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
 * 1. The attacker must provide more data into the outwardly facing buffer * than the buffer is designed to hold. * 2. The attacker must know where the return address pointer resides on the * stack. This should be just beyond the end of the buffer. * 3. The attacker must insert machine language instructions in the buffer. * This may occur before, after, or even around the return address pointer. * The machine language could be already compiled code in the program. * 4. The attacker must overwrite the return address. The old value, directing * the flow of the program after the function is returned, must be changed * from the calling function to the provided machine language in step 3.
 **********************************************************************/
void Exploit()
{
   stackVulnerability(/* parameters with malicious data */);
}

//HEAP SPRAYING
/**********************************************************************
 * HEAP VULNERABILTY
 * 1. There must be two adjacent heap buffers. * 2. The first buffer must be reachable through external input. * 3. The mechanism to fill the buffer from the external input must not * correctly check for the buffer size. * 4. The second buffer must be released before the first. * 5. The first buffer must be overrun (extend beyond the intended limits of * the array).
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
 * 1. The attacker must provide more data into the outwardly facing heap * buffer than the buffer is designed to hold. * 2. The attacker must know the layout of the Memory Control Block (MCB) * (essentially a linked list) residing just after the buffer. * 3. The attacker must provide a new MCB containing both the location of * the memory overwrite and the new data to be overwritten.
 **********************************************************************/
void heapExploit()
{
   heapVulnerability(/* parameters with malicious data */);
}

//INTEGER OVERFLOW
/**********************************************************************
 * INTEGER VULNERABILTY
 * 1. There must be a security check represented by an expression. * 2. The expression must have the potential for overflow. * 3. At least one of the numbers used to compute the sentinel must be * reachable through external input. This sentinel is a variable used to make * the security decision from the first requirement.
 *********************************************************************/
void integerVulnerability(unsigned short deposit)
{
   short balance = 100;
   cout << "Current Balance: " << balance << endl;
   cout << "Enter the deposit ammount: " << endl;
   cout << deposit << endl;
   if (deposit > 0)
   {
      balance += deposit;
   }
   cout << "New balance: " << balance << endl;   
}

/***********************************************************************
 *  INTEGER WORKING
 *  Call integerVulnerability() in a way that does
 *  not yield unexpected behavior
 **********************************************************************/
void integerWorking()
{
   integerVulnerability(246);
}

/***********************************************************************
 * INTEGER EXPLOIT
 * 1. Provide input, either a buffer size or a single value, that is directly or * indirectly used in the vulnerable expression. * 2. The input must exceed the valid bounds of the data-type, resulting in an * overflow or underflow condition.
 **********************************************************************/
void integerExploit()
{
   integerVulnerability(-1);
}

//ANSI-UNICODE CONVERSION
/**********************************************************************
 * UNICODE VULNERABILTY
 * 1. There must be a buffer where the basetype is greater than one. * 2. Validation of the buffer must check the size of the buffer rather than the * number of elements in the buffer.
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
 * 1. The attacker must provide more than half as much data into the * outwardly facing buffer as it is designed to hold. * 2. From here, a variety of injection attacks are possible. The most likely * candidates are stack smashing or heap smashing. In the above example, * the third parameter of the copyUnicodeText() function is the number * of elements in the string (256 elements), not the size of the string (512 * bytes). The end result is a buffer overrun of 256 bytes.
 **********************************************************************/
void unicodeExploit()
{
   unicodeVulnerability(/* parameters with malicious data */);
}