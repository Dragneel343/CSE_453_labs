
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

//define test cases for authentication
#define chris "cBowen_005"
#define chrisPsswd "l337_p455w@rd"
#define andrew "AndrewNer_2771"
#define andrewPsswd "d33r_Hun73r"
#define mark "MCV_6005"
#define markPsswd "v4r6?4y4"
#define kyle "kyl_Bun_1337"
#define kylePsswd "6r0up_06@c53_453"
//define test cases for vulnerabilities
//tautology attack
#define attTautology1 "nothing' OR 'hacked'='hacked"
//UNION attack
#define attUnion1 "nothing' UNION SELECT authenticate FROM userList;--"
//Add State attack
#define attAddState1 "nothing'; INSERT INTO userList (name, passwd) VALUES 'hacker', '1337"
//Comment attack
#define attComment1 "cBowen_005'\";--"

#define attTautology2 "nothing' OR name LIKE '%Andre%"
//UNION attack
#define attUnion2 "nothing' UNION SELECT NULL NULL NULL;--"
//Add State attack
#define attAddState2 "nothing'; DROP TABLE userList"
//Comment attack
#define attComment2 "AndrewNer_2771'\";--"

#define attTautology3 "nothing' OR 'a'='a"
//UNION attack
#define attUnion3 "nothing' UNION SELECT NULL NULL;--"
//Add State attack
#define attAddState3 "nothing'; UPDATE userList SET passwd = hacked WHERE name  = 'MCV_6005"
//Comment attack
#define attComment3 "MCV_6005'\";--"

#define attTautology4 "nothing' OR '2'='2"
//UNION attack
#define attUnion4 "nothing' UNION SELECT NULL;--"
//Add State attack
#define attAddState4 "nothing'; UPDATE userList SET passwd = hacked WHERE name  LIKE 'kyl"
//Comment attack
#define attComment4 "kyl_Bun_1337'\";--"


string genQuery(string userName, string password);
string genQueryWeak(string userName, string password);
string genQueryStrong(string userName, string password);
void testValid();
void testTautology();
void testUnion();
void testAddState();
void testComment();
void testWeak();
void testStrong();
int main()

{
   testValid();
   testTautology();
   testUnion();
   testAddState();
   testComment();
   testStrong();
   testWeak();

   return 0;
};

/***********************************************************************
*  genQuery
*  This functation is used to generate a SQL query used to authenticate  
*  a user. It dose this with a user name and password
************************************************************************/
string genQuery(string userName, string password)
{
  string query = "SELECT authenticate\n \tFROM userList\n \tWHERE name= '" + userName + "' and passwd='" + password + "';";   

   return query;
}

/***********************************************************************
*  genQueryWeak
*  This functation is used to generate a SQL query that is sanizitsed 
*  using weak mitagation. It dose this with a black list of chars
*  that are not allowed in the user name or password.
************************************************************************/
string genQueryWeak(string userName, string password)
{
   //black list
   unordered_map <char, int> blackList;
   blackList[';'] = 1; blackList['-'] = 2; blackList['\''] = 3; blackList['\"'] = 4;

   string sanitizedUserName;
   string sanitizedPassword;

   for (int i = 0; i < userName.length(); i++)
   {
      unordered_map<char, int>::const_iterator check = blackList.find(userName[i]);

      //Check to see if the char is not on the black list 
      if (check == blackList.end())
      {
        //if it is not add it 
        sanitizedUserName += userName[i];
      }
    
   }

   for (int i = 0; i < password.length(); i++)
   {
      unordered_map<char, int>::const_iterator check = blackList.find(password[i]);

      //Check to see if the char is not on the black list
      if (check == blackList.end())
      {
         //if it is not add it
         sanitizedPassword += password[i];
      }

   }
   return genQuery(sanitizedUserName, sanitizedPassword);
}

/***********************************************************************
*  genQueryStrong
*  This functation is used to generate a SQL query that is sanizitsed
*  using strong mitagation. It dose this with an allowed list of chars
*  that are allowed in the user name and password.
************************************************************************/
string genQueryStrong(string userName, string password)
{
  //allowed list
  unordered_map <char, int> allowed;
  allowed['a'] = 1; allowed['b'] = 2; allowed['c'] = 3; allowed['d'] = 4; allowed['e'] = 5; allowed['f'] = 6; allowed['g'] = 7;
  allowed['h'] = 8; allowed['i'] = 9; allowed['j'] = 10; allowed['k'] = 11; allowed['l'] = 12; allowed['m'] = 13; allowed['n'] = 14;
  allowed['o'] = 15; allowed['p'] = 16; allowed['q'] = 17; allowed['r'] = 18; allowed['s'] = 19; allowed['t'] = 20; allowed['u'] = 21;
  allowed['v'] = 22; allowed['w'] = 23; allowed['x'] = 24; allowed['y'] = 25; allowed['z'] = 26; allowed['A'] = 27; allowed['B'] = 28;
  allowed['C'] = 29; allowed['D'] = 30; allowed['E'] = 31; allowed['F'] = 32; allowed['G'] = 33; allowed['H'] = 34; allowed['I'] = 35;
  allowed['J'] = 36; allowed['K'] = 37; allowed['L'] = 38; allowed['M'] = 39; allowed['N'] = 40; allowed['O'] = 41; allowed['P'] = 42;
  allowed['Q'] = 43; allowed['R'] = 44; allowed['S'] = 45; allowed['T'] = 46; allowed['U'] = 47; allowed['V'] = 48; allowed['W'] = 49;
  allowed['X'] = 50; allowed['Y'] = 51; allowed['Z'] = 52; allowed['0'] = 53; allowed['1'] = 54; allowed['2'] = 55; allowed['3'] = 56;
  allowed['4'] = 57; allowed['5'] = 58; allowed['6'] = 59; allowed['7'] = 60; allowed['8'] = 61; allowed['9'] = 62; allowed['*'] = 63;
  allowed['@'] = 64; allowed['#'] = 65; allowed['^'] = 66; allowed['_'] = 67; allowed['?'] = 68;

  string sanitizedUserName;
  string sanitizedPassword;

  for (int i = 0; i < userName.length(); i++)
  {     
     unordered_map<char, int>::const_iterator check = allowed.find(userName[i]);

     //Check to see if the char is not on the allowed list
     if (check != allowed.end())
     {
        //if is is add it
        sanitizedUserName += userName[i];
     }    
  }

  for (int i = 0; i < password.length(); i++)
  {
     unordered_map<char, int>::const_iterator check = allowed.find(password[i]);

     //Check to see if the char is not on the allowed list
     if (check != allowed.end())
     {
        //if is is add it
        sanitizedPassword += password[i];
     }
  }      
   return genQuery(sanitizedUserName, sanitizedPassword);
}

/***********************************************************************
*  testValid 
*  A set of tests to prove that genQuery outputs a vaild SQL query.
************************************************************************/
void testValid()
{
   cout << "-----Valid Test-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQuery(chris, chrisPsswd) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << endl;
   cout << genQuery(andrew, andrewPsswd) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << endl;
   cout << genQuery(mark, markPsswd) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << endl;
   cout << genQuery(kyle,kylePsswd) << endl;
   cout << endl;
}

/***********************************************************************
*  testTauolog
*  A set of tests to show that genQuery is vulnerable to an auolog attack.
************************************************************************/
void testTautology()
{
   cout << "-----Tautology Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQuery(chris, attTautology1) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQuery(andrew, attTautology2) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQuery(mark, attTautology3) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQuery(kyle, attTautology4) << endl;
   cout << endl;
}

/***********************************************************************
*  testUnion
*  A set of tests to show that genQuery is vulnerable to an UNION attack.
************************************************************************/
void testUnion()
{
   cout << "-----Union Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << genQuery(chris, attUnion1) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQuery(andrew, attUnion2) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQuery(mark, attUnion3) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQuery(kyle, attUnion4) << endl;
   cout << endl;
}

/***********************************************************************
*  testAddState
*  A set of tests to show that genQuery is vulnerable to an Add statement attack.
************************************************************************/
void testAddState()
{
   cout << "-----Add Statement Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << genQuery(chris, attAddState1) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQuery(andrew, attAddState2) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQuery(mark, attAddState3) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQuery(kyle, attAddState4) << endl;
   cout << endl;
}

/***********************************************************************
*  testComment
*  A set of tests to show that genQuery is vulnerable to an comment attack.
************************************************************************/
void testComment()
{
   cout << "-----Add comment Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << genQuery(attComment1, chrisPsswd) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQuery(attComment2, andrewPsswd) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQuery(attComment3, markPsswd) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQuery(attComment4, kylePsswd) << endl;
   cout << endl;
}

/***********************************************************************
*  TestWeak
*  A set of tests to show that genQueryWeak sanitizes user input.
************************************************************************/
void testWeak()
{
   cout << "t-----Testing Weak Mitigation-----" << endl;
   cout << "-----Valid Testing-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryWeak(chris, chrisPsswd) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << endl;
   cout << genQueryWeak(andrew, andrewPsswd) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << endl;
   cout << genQueryWeak(mark, markPsswd) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << endl;
   cout << genQueryWeak(kyle, kylePsswd) << endl;
   cout << endl;

   cout << "-----Tautology Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryWeak(chris, attTautology1) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQueryWeak(andrew, attTautology2) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQueryWeak(mark, attTautology3) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQueryWeak(kyle, attTautology4) << endl;
   cout << endl;
 
   cout << "-----Union Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryWeak(chris, attUnion1) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQueryWeak(andrew, attUnion2) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQueryWeak(mark, attUnion3) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQueryWeak(kyle, attUnion4) << endl;
   cout << endl;

   cout << "-----Add Statement Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryWeak(chris, attAddState1) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQueryWeak(andrew, attAddState2) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQueryWeak(mark, attAddState3) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQueryWeak(kyle, attAddState4) << endl;
   cout << endl;

   cout << "-----Add comment Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryWeak(attComment1, chrisPsswd) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQueryWeak(attComment2, andrewPsswd) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQueryWeak(attComment3, markPsswd) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQueryWeak(attComment4, kylePsswd) << endl;
   cout << endl;
}

/***********************************************************************
*  testStrong
* A set of tests to show that genQueryWeak sanitizes user input.
************************************************************************/
void testStrong()
{
   cout << "t-----Testing Strong Mitigation-----" << endl;
   cout << "-----Valid Testing-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryStrong(chris, chrisPsswd) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << endl;
   cout << genQueryStrong(andrew, andrewPsswd) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << endl;
   cout << genQueryStrong(mark, markPsswd) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << endl;
   cout << genQueryStrong(kyle, kylePsswd) << endl;
   cout << endl;

   cout << "-----Tautology Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryStrong(chris, attTautology1) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQueryStrong(andrew, attTautology2) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQueryStrong(mark, attTautology3) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQueryStrong(kyle, attTautology4) << endl;
   cout << endl;

   cout << "-----Union Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryStrong(chris, attUnion1) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQueryStrong(andrew, attUnion2) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQueryStrong(mark, attUnion3) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQueryStrong(kyle, attUnion4) << endl;
   cout << endl;

   cout << "-----Add Statement Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryStrong(chris, attAddState1) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQueryStrong(andrew, attAddState2) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQueryStrong(mark, attAddState3) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQueryStrong(kyle, attAddState4) << endl;
   cout << endl;

   cout << "-----Add comment Tests-----" << endl;
   cout << "*****Test 1*****" << endl;
   cout << endl;
   cout << genQueryStrong(attComment1, chrisPsswd) << endl;
   cout << endl;
   cout << "*****Test 2*****" << endl;
   cout << genQueryStrong(attComment2, andrewPsswd) << endl;
   cout << endl;
   cout << "*****Test 3*****" << endl;
   cout << genQueryStrong(attComment3, markPsswd) << endl;
   cout << endl;
   cout << "*****Test 4*****" << endl;
   cout << genQueryStrong(attComment4, kylePsswd) << endl;
   cout << endl;
}
;