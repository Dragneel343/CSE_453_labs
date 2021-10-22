
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

//define test cases for authentication
#define chris "cBowen_005"
#define chrisPsswd "l337_p455w@rd"
#define andrew ""
#define andrewPsswd ""
#define mark ""
#define markPsswd ""
#define kyle ""
#define kylePsswd ""
//define test cases for vulnerabilities
//tautology attack
#define attTautology_1 "nothing' OR 'hacked'='hacked"
//UNION attack
#define attUnion1 "nothing' UNION SELECT authenticate FROM userList"
//Add State attack
#define attAddState1 "nothing'; INSERT INTO userList (name, passwd) VALUES 'hacker', '1337"
//Comment attack
#define attComment1 "hacker'\";--"

string genQuery(string userName, string password);
string genQueryWeak(string userName, string password);
string genQueryStrong(string userName, string password);
void testValid();
void testTauology();
void testUnion();
void testAddState();
void testComment();
void testWeak();
void testStrong();
int main()

{
   testValid();
   testTauology();
   testUnion();
   testAddState();
   testComment();
   testStrong();
   testWeak();

   return 0;
};

string genQuery(string userName, string password)
{
  string query = "SELECT authenticate\n \tFROM userList\n \tWHERE name='" + userName + "' and passwd='" + password + "';";   

   return query;
}
string genQueryWeak(string userName, string password)
{
   unordered_map <char, int> allowed;
   allowed[';'] = 1; allowed['-'] = 2; allowed['\''] = 3; allowed['\"'] = 4;

   string sanitizedUserName;
   string sanitizedPassword;

   for (int i = 0; i < userName.length(); i++)
   {
      string checkUser = to_string(userName[i]);

      unordered_map<char, int>::const_iterator check = allowed.find(userName[i]);

      if (check == allowed.end())
      {
        sanitizedUserName += userName[i];
      }
    
   }

   for (int i = 0; i < password.length(); i++)
   {
      string checkUser = to_string(password[i]);

      unordered_map<char, int>::const_iterator check = allowed.find(password[i]);

      if (check == allowed.end())
      {
         sanitizedPassword += password[i];
      }

   }
   return genQuery(sanitizedUserName, sanitizedPassword);
}

string genQueryStrong(string userName, string password)
{
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
  allowed['@'] = 64; allowed['#'] = 65; allowed['^'] = 66; allowed['_'] = 67;

  bool isCorrectUser = false;
  bool isCorrectPassword = false;
  string sanitizedUserName;
  string sanitizedPassword;
  string results = "";
  

  for (int i = 0; i < userName.length(); i++)
  {
     string checkUser = to_string(userName[i]);

     unordered_map<char, int>::const_iterator check = allowed.find(userName[i]);

     if (check != allowed.end())
     {
        sanitizedUserName += userName[i];
     }
    
  }

  for (int i = 0; i < password.length(); i++)
  {
     string checkUser = to_string(password[i]);

     unordered_map<char, int>::const_iterator check = allowed.find(password[i]);

     if (check != allowed.end())
     {
        sanitizedPassword += password[i];
     }
  }    
    
   return genQuery(sanitizedUserName, sanitizedPassword);
}


void testValid()
{
   cout << "-----Valid Test-----" << endl;
   cout << endl;
   cout << genQuery(chris, chrisPsswd) << endl;
   cout << endl;

}
void testTauology()
{
   cout << "-----Tautology Tests-----" << endl;   
   cout << endl;
   cout << genQuery(chris, attTautology_1) << endl;
   cout << endl;
}

void testUnion()
{
   cout << "-----Union Tests-----" << endl;
   cout << endl;
   cout << genQuery(chris, attUnion1) << endl;
   cout << endl;
}
void testAddState()
{
   cout << "-----Add Statement Tests-----" << endl;
   cout << endl;
   cout << genQuery(chris, attAddState1) << endl;
   cout << endl;
}
void testComment()
{
   cout << "-----Add comment Tests-----" << endl;
   cout << endl;
   cout << genQuery(attComment1, chrisPsswd) << endl;
   cout << endl;
}
void testWeak()
{
   cout << "t-----Testing Weak Mitigation-----" << endl;
   cout << "-----Valid Testing-----" << endl;
   cout << endl;
   cout << genQueryWeak(chris, chrisPsswd) << endl;
   cout << endl;
   cout << "-----Tautology Tests-----" << endl;
   cout << endl;
   cout << genQueryWeak(chris, attTautology_1) << endl;
   cout << endl;
   cout << "-----Union Tests-----" << endl;
   cout << endl;
   cout << genQueryWeak(chris, attUnion1) << endl;
   cout << endl;
   cout << "-----Add Statement Tests-----" << endl;
   cout << endl;
   cout << genQueryWeak(chris, attAddState1) << endl;
   cout << endl;
   cout << "-----Add comment Tests-----" << endl;
   cout << endl;
   cout << genQueryWeak(attComment1, chrisPsswd) << endl;
   cout << endl;

}
void testStrong()
{
   cout << "-----Testing Strong Mitigation-----" << endl;
   cout << "-----Valid Testing-----" << endl;
   cout << endl;
   cout << genQueryStrong(chris, chrisPsswd) << endl;
   cout << endl;
   cout << "-----Tautology Tests-----" << endl;
   cout << endl;
   cout << genQueryStrong(chris, attTautology_1) << endl;
   cout << endl;
   cout << "-----Union Tests-----" << endl;
   cout << endl;
   cout << genQueryStrong(chris, attUnion1) << endl;
   cout << endl;
   cout << "-----Add Statement Tests-----" << endl;
   cout << endl;
   cout << genQueryStrong(chris, attAddState1) << endl;
   cout << endl;
   cout << "-----Add comment Tests-----" << endl;
   cout << endl;
   cout << genQueryStrong(attComment1, chrisPsswd) << endl;
   cout << endl;
}
;