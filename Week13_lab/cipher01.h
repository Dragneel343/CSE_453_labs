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
   virtual std::string getCipherName()  { return "Hill Cipher"; }
   virtual std::string getEncryptAuth() { return "Andrew Nerdin"; }
   virtual std::string getDecryptAuth() { return "Andrew Nerdin"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "EDUCBA.com (2020), ";
      s += "\"Network Secuirty Tutorial - Types of Cipher\', \n   retrieved: ";
      s += "https://www.educba.com/types-of-cipher/";
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
      str =  "insert the encryption pseudocode\n";

      // The decrypt pseudocode
      str += "insert the decryption pseudocode\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Encrypts the message
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      std::string cipherText = plainText;
      // TODO - Add your code here
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
      // TODO - Add your code here
      return plainText;
   }
private:
   /**********************************************************
    * GET KEY MATRIX
    * nerates the key matrix for the key string
    **********************************************************/
   void getKeyMatrix(string key, int keyMatrix[][3])
   {
      int k = 0;
      for (int i = 0; i < 3; i++)
      {
         for (int j = 0; j < 3; j++)
         {
               keyMatrix[i][j] = (key[k]) % 65;
               k++;
         }
      }
   }     
};

#endif // CIPHER01_H