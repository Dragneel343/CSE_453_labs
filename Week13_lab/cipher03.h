/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H
#include <iostream>
#include <map>
using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Mark Calla"; }
   virtual std::string getCipherName()  { return "Baconian Cipher"; }
   virtual std::string getEncryptAuth() { return "Mark Calla"; }
   virtual std::string getDecryptAuth() { return "Mark Calla"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += " Aman Gondaliya, May 18, 2020, ";
      s += "\"BACON’s CIPHER\', \n";
      s += " https://medium.com/@amangondaliya555/bacons-cipher-1ac9790839e2";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str += "encrypt(plaintext,password)\n";
      str += "FOR i is all values in plainText\n";
      str += "IF A <= character >= Z";
      str += "cipherText += map.find(i)\n";
      str += "ELSE\n";
      str += "RETURN cipherText\n";

      // The decrypt pseudocode
      str += "decrypt(plaintext,password)\n";
      str += "FOR i is all values in cipher Text\n";
      str += "str1 = cipherText\n";
      str += "IF aaaaa <= str >= bbaab\n";
      str += "plainText += map.find(i)\n";
      str += "RETURN plainText\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText;
      // TODO - Add your code here
      for (int i = 0; i < plainText.length(); i++)
      {
          char character = toupper(plainText[i]);
          if (character >= 'A' && character <= 'Z')
          {
              cipherText += this->baconCode[character];
          }
          else if (character == 32)
          {
              cipherText += " ";
          }
      }

      //for (int i = 0; i < password.length(); i++)
      //{
        //  char character = toupper(password[i]);
          //if (character >= 'A' && character <= 'Z')
          //{
            //  cipherText += this->baconCode[character];
          //}
          //else if (character == 32)
          //{
            //  cipherText += " ";
          //}
      //}
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText;
      //TODO - Add your code here
      for (int i = 0; i < cipherText.length(); i = i + 5)
      {
          string str1 = cipherText;
          if (str1 <= "aaaaa" && str1 >= "bbaab") {
              plainText += this->reverseBaconCode[str1];
          }
      }
      return plainText;
   }


private:
    map<char, string> baconCode = {
        {'A', "aaaaa"},
        {'B', "aaaab"},
        {'C', "aaaba"},
        {'D', "aaabb"},
        {'E', "aabaa"},
        {'F', "aabab"},
        {'G', "aabba"},
        {'H', "aabbb"},
        {'I', "abaaa"},
        {'J', "abaab"},
        {'K', "ababa"},
        {'L', "ababb"},
        {'M', "abbaa"},
        {'N', "abbab"},
        {'O', "abbba"},
        {'P', "abbbb"},
        {'Q', "baaaa"},
        {'R', "baaab"},
        {'S', "baaba"},
        {'T', "baabb"},
        {'U', "babaa"},
        {'V', "babab"},
        {'W', "babba"},
        {'X', "babbb"},
        {'Y', "bbaaa"},
        {'Z', "bbaab"}
    };

    map<string, char> reverseBaconCode = {
        {"aaaaa", 'A'}, 
        {"aaaab", 'B'}, 
        {"aaaba", 'C'}, 
        {"aaabb", 'D'},
        {"aabaa", 'E'}, 
        {"aabab", 'F'}, 
        {"aabba", 'G'}, 
        {"aabbb", 'H'},
        {"abaaa", 'I'},
        {"abaab", 'J'}, 
        {"ababa", 'K'}, 
        {"ababb", 'L'},
        {"abbaa", 'M'}, 
        {"abbab", 'N'},
        {"abbba", 'O'}, 
        {"abbbb", 'P'},
        {"baaaa", 'Q'}, 
        {"baaab", 'R'}, 
        {"baaba", 'S'}, 
        {"baabb", 'T'},
        {"babaa", 'U'}, 
        {"babab", 'V'}, 
        {"babba", 'W'}, 
        {"babbb", 'X'},
        {"bbaaa", 'Y'}, 
        {"bbaab", 'Z'}
    };
};

#endif // CIPHER03_H
