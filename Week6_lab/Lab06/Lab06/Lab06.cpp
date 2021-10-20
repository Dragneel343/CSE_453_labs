//SELECT userList
//   FROM passwordList 
//      WHERE name = 'userName' && 'password'

//SELECT authenticate FROM passwordList WHERE name = '$Username' and passwd = '$Password';
#include <string>
#include <iostream>
using namespace std;

string genQuery(string userName, string password);
void testValid();

int main()
{
   string userName;
   string password;
   cout << "Enter user name: " << std::endl;
   getline(cin, userName);
   cout << "Enter password: " << std::endl;
   getline(cin, password);
   testValid();

   return 0;
};

string genQuery(string userName, string password)
{
  string query = "SELECT authenticate\n \tFROM userList\n \t\tWHERE name='" + userName + "' and passwd='" + password + "';";

   

   return query;
};

void testValid()
{
   string userName = "aNerdin";
   string password = "1234";
   cout << genQuery(userName, password);
};