/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

#include<iostream>
using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Andrew Nerdin"; }
   virtual std::string getCipherName()  { return "Vigenère Cipher"; }
   virtual std::string getEncryptAuth() { return "Andrew Nerdin"; }
   virtual std::string getDecryptAuth() { return "Andrew Nerdin"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "GeeksforGeeks.com (2020), ";
      s += "\"Vigenère Cipher\', \n   retrieved: ";
      s += "https://www.geeksforgeeks.org/vigenere-cipher/?ref=lbp";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "    cipherText <- plainText\n";
      str += "    FOR i is less than the size of plainText\n";
      str += "    x <- (plainText[i] + password[i]) %26\n";
      str += "    x += A\n";
      str += "    cipherText PUSHBACK\n";
      str += "    RETURN cipherText\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "    plainText <- cipherText\n";
      str += "    FOR i is less than the size of cipherText\n";
      str += "    x <- (cipherText[i] + password[i]) %26\n";
      str += "    x += A\n";
      str += "    plainText PUSHBACK\n";
      str += "    RETURN plainText";

      // The generate key pseudocode
      str += "generateKey(plainText, password)\n";
      str += "    x <- size of plainText\n";
      str += "    FOR i <- 0\n";
      str += "    IF x == i\n";
      str += "       i = 0\n";
      str += "    IF size of password EQUAL to size of plainText\n";
      str += "       break\n";
      str += "    password PUSHBACK\n";
      str += "    RETURN password\n";

      return str;
   }

   /**********************************************************
    * GENERATE KEY
    * This function generates the key in
    * a cyclic manner until it's length isn't
    * equal to the length of original text
    **********************************************************/
   string generateKey(const std::string & plainText, 
                      string password)
   {
      int x = plainText.size();
   
      for (int i = 0; ; i++)
      {
         if (x == i)
               i = 0;
         if (password.size() == plainText.size())
               break;
         password.push_back(password[i]);
      }
      return password;
   }

   /**********************************************************
    * ENCRYPT
    * Encrypts the message
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      string cipherText = plainText;
 
      for (int i = 0; i < plainText.size(); i++)
      {
         // converting in range 0-25
         char x = (plainText[i] + password[i]) %26;
   
         // convert into alphabets(ASCII)
         x += 'A';
   
         cipherText.push_back(x);
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * Decrypts the message
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      std::string plainText = cipherText;

      for (int i = 0 ; i < cipherText.size(); i++)
    {
        // converting in range 0-25
        char x = (cipherText[i] - password[i] + 26) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
        plainText.push_back(x);
    }
      return plainText;
   } 
};

#endif // CIPHER01_H