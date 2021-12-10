/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include "cipher02.h"
#include <map>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "pseudocode author"; }
   virtual std::string getCipherName()  { return "Keyword Cipher"; }
   virtual std::string getEncryptAuth() { return "Chris Bowen"; }
   virtual std::string getDecryptAuth() { return "Chris Bowen"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Cryptology by Discovery: An Introduction to Conjecture and Proof, ";
      s += "\"2.9 Keyword Columnar Ciphers\', \n   retrieved: ";
      s += "https://facweb1.redlands.edu/fac/Tamara_Veenstra/cryptobook/keyword.html";
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
      str =  "encrypt(plaintext, password)\n";
      str += " newAlphabet <- cipherAlphabet(password)\n";
      str += "    For i all values of plainText\n";
      str += "       if plainText[i] >= ! and plainText[i] <= ~\n";
      str += "          pos = plainText[i] - 33\n";
      str += "          cipherText += newAlphabet[pos]\n";
      str += "       Else\n";
      str += "          cipherText += plainText[i]\n";
      str += " RETURN cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(plaintext, password)\n";
      str += " newAlphabet <- cipherAlphabet(password)\n";
      str += " string alphabet = all the char that are used for this alphabet\n";
      str += " map <char,int> alpha\n";
      str += "    FOR i all the values of newAlphabet\n";
      str += "       alpha[newAlphabet[i]] = i\n";
      str += "    For i all values of cipherText\n";
      str += "       if cipherText[i] >= ! and cipherText[i] <= ~\n";
      str += "          pos = alpha[cipherText][i]]\n";
      str += "          plainText += alphabet[pos]\n";
      str += "       Else\n";
      str += "          plainText += cipherTextText[i]\n";
      str += " RETURN plainText\n\n";

      //The cipherAlphabet pseudocode
      str += "cipherAlphabet(keyword)\n";
      str += " bool arr[94] = {0}\n";
      str += " FOR i all the values of keyword\n";
      str += "    IF keyword[i] >= '!' and keyword[i] <= '~'\n";
      str += "       IF arr[keyword[i]- 33] >= 0\n";
      str += "          cipherAlphabet += keyword[i]\n";
      str += " FOR i up to 94";
      str += "    IF arr[i] == 0\n";
      str += "       arr[i] = 1\n";
      str += "       cipherAlphabet =+ char i + 33\n";
      str += " RETURN cipherAlphabet\n\n";



      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";
      std::string newAlphabet = cipherAlphabet(password);

      for (int i = 0; i < plainText.size(); i++)
      {
         if (plainText[i] >= '!' && plainText[i] <= '~')
         {
            int pos = plainText[i] - 33;
            cipherText += newAlphabet[pos];
         }
         else
         {
            cipherText += plainText[i];
         }
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = "";

      std::string newAlphabet = cipherAlphabet(password);

      std::string alphabet = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

      map <char, int> alpha;
      for (int i = 0; i < newAlphabet.size(); i++)
      {
         alpha[newAlphabet[i]] = i;
      }

      // This loop deciphered the message.
      // Spaces, special characters and numbers remain same.
      for (int i = 0; i < cipherText.size(); i++)
      {
         if (cipherText[i] >= '!' && cipherText[i] <= '~')
         {
            int pos = alpha[cipherText[i]];
            plainText += alphabet[pos];
         }
         else
         {
            plainText += cipherText[i];
         }
      }
      return plainText;
   }

   /**********************************************************
    * CIPHERALPHABET
    * Description: Creat an alphabet starting with the keyword
    **********************************************************/
   virtual std::string cipherAlphabet(const std::string keyword)
   {
      //alphabet made from the keyword
      std::string cipherAlphabet = "";

      //Array to represent the char that have been added to alphabet
      bool arr[94] = { 0 };

      //insert the keyword at the begining of the cipher alphabet
      for (int i = 0; i < keyword.size(); i++)
      {
         if (keyword[i] >= '!' && keyword[i] <= '~')
         {
            //check to see if character is already in
            if (arr[keyword[i] - 33] >= 0)
            {
               cipherAlphabet += keyword[i];
               arr[keyword[i] - 33] = 1;
            }
         }
      }     
      //put the remain characters in
      for (int i = 0; i < 94; i++)
      {
         if (arr[i] == 0)
         {
            arr[i] = 1;
            cipherAlphabet += char(i + 33);
         }
      }
      return cipherAlphabet;
   }
};

#endif // CIPHER02_H