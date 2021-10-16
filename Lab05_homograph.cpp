/***********************************************************************
* Program:   
*  Lab05
* Author:
*  CSE 453 Group 3
* Summary:
*  This program detect a homograph attack on the windows file system.
*  It dose this by asking the user for the directory of a file, just
*  like typing it in the command promt. It then compares the to paths
*  to see if they are a homograpgh or not a homograph.
*  !!!This program uses C++ 17!!!
************************************************************************/
#include <string>
#include <iostream>
#include <filesystem>
#include <locale>

std::string canonicalization(std::string filename);

int main()
 {
   std::string path1 = "";
   std::string path2 = "";
   std::string canonPath1 = "";
   std::string canonPath2 = "";
   
   //asking for the first path
   std::cout << "Enter a file path: ";
   std::getline(std::cin, path1);   
   
   //asking for the second path
   std::cout << "Enter a second file path: ";
   std::getline(std::cin, path2);  

   //cannicalization of the paths
   canonPath1 = canonicalization(path1);
   canonPath2 = canonicalization(path2);

   //display original path and conaonicalized path
   std::cout << path1 << "----" << canonPath1 << std::endl;
   std::cout << path2 << "----" << canonPath2 << std::endl;

   //compares the two paths   
   if (canonPath1 == canonPath2)
   {
      std::cout << "Homograph!" << std::endl;
   }
   else
   {
      std::cout << "Not A Homograph!" << std::endl;
   }
   return 0;
}
/***********************************************************************
*Function
*  Take a sting entered in like a command promt command to access a file
*  and changes it in to a string of a file path. Then out puts the results
*  
************************************************************************/
std::string canonicalization(std::string inputFilePath)
{
   std::string path;
   std::string filePath;
   //changes to lower case
   for (int i = 0; i < inputFilePath.length(); i++)
   {
      std::locale loc;
      filePath += std::tolower(inputFilePath[i], loc);      
   }

   //Command cd [drive letter]:\filepath\filename.file
   if (filePath[4] == ':')
   {
      //add the drive letter
      path += filePath[3];
      //add the ':'
      path += ':';
      //add the'\'
      path += '\\';
      
      //gets the rest of the path
      for (int i = 6; i < filePath.length(); i++)
      {
         path += filePath[i];         
      }
   }
 
   //Command cd filepath\filename.file
   else if (filePath[3] != ':')   
   {
      //get the current working directory
      std::filesystem::path cwd = std::filesystem::current_path();
      std::string currentPath = cwd.string();
      std::locale loc;
      
      //add the current working directory 
      for (int i = 0; i < currentPath.length(); i++)
      {
         //makes sure the are all in the same case
         path += std::tolower(currentPath[i], loc);
      }
      path += '\\';
      //adds the next directory and file
      for (int i = 3; i < filePath.length(); i++)
      {
         path += filePath[i];
      }

   } 

   return path;
}