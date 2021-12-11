/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Kyle Bunn"; }
   virtual std::string getCipherName()  { return "Polybius Square Cipher"; }
   virtual std::string getEncryptAuth() { return "Kyle Bunn"; }
   virtual std::string getDecryptAuth() { return "Kyle Bunn"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
       std::string s;
       s += "GeeksforGeeks.com (2021), ";
       s += "\"Geeks for Geeks - Polybius Square Cipher\', \n   retrieved: 12/10/21 ";
       s += "https://www.geeksforgeeks.org/polybius-square-cipher/";
       return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The 'default' Polybius Square
      str = "\n *The Polybius Square*\n\n";
      str += "   1 2 3 4 5\n";
      str += " 1 A B C D E\n";
      str += " 2 F G H I K\n";
      str += " 3 L M N O P\n";
      str += " 4 Q R S T U\n";
      str += " 5 V W X Y Z\n\n";

      // The encryptCase pseudocode
      str += "encrypt(string)\n";
      str += "   int row, collumn\n";
      str += "   FOR each element of string assign a row and collumn converting each letter into a two digit pair \n";
      str += "   IF the character is a 'k' row -1 and collumn +1 \n";
      str += "   Else if the character is greater than j adjust for the combined 'i'/'j' square\n";
      str += "   RETURN cipherText\n\n";

      // The decryptCase pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   int row, collumn\n";
      str += "   FOR each element of string look at two a numbered pair and convert into letters \n";
      str += "   RETURN plainText\n\n";


      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string s = plainText;
      string cypherText;
      int row;
      int col;
      

      for (int i = 0; s[i]; i++) {

          // finding row of the table
          row = ceil((s[i] - 'a') / 5) + 1;

          // finding column of the table
          col = ((s[i] - 'a') % 5) + 1;

          // if character is 'k'
          if (s[i] == 'k') {
              row = row - 1;
              col = 5 - col + 1;
          }

          // if character is greater than 'j'
          else if (s[i] >= 'j') {
              if (col == 1) {
                  col = 6;
                  row = row - 1;
              }
              col = col - 1;
          }
           
          cypherText.push_back(row);
          cypherText.push_back(col);

          
      }
      



      return cypherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      
      string returnText;

      int row;
      int col;
      
      char poly[5][5] = {
          { 'a','b','c','d','e' },
          { 'f','g','h','i','k' },
          { 'l','m','n','o','p' },
          { 'q','r','s','t','u' },
          { 'v','w','x','y','z' }
      };


      for (int i = 0; plainText[i]; i++)
      {
          row = plainText[i];
          col = plainText[i + 1];

          returnText += poly[row][col];
      }


      return plainText;
   }
};

#endif // CIPHER04_H
