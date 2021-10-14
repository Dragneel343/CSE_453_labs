#include <string>
#include <iostream>

std::string getPath(std::string filename);

int main()
 {
   std::string path1 = "cd test";
   std::string path2 = "cd c:/test";

   std::cout << "Enter a file path: ";
   std::getline(std::cin, path1);

   std::cout << "Enter a second file path: ";
   std::getline(std::cin, path2);
   
   std::cout << path1 << " --- " << getPath(path1) << std::endl;
   std::cout << path2 << " --- " << getPath(path2) << std::endl;
   
   if (getPath(path1) == getPath(path2))
   {
      std::cout << "Homograph!" << std::endl;
   }
   else
   {
      std::cout << "Not A Homograph!" << std::endl;
   }

   return 0;
}

std::string getPath(std::string filename)
{
   std::string tempPath;
   if (filename[4] == ':')
   {
      //tempPath = "c:";
      for (int i = 3; i < filename.length(); i++)
      {         
         tempPath += filename[i];
      }
   }
   else
   {
      tempPath = "c:/";
      for (int i = 3; i < filename.length(); i++)
      {
         tempPath += filename[i];
      }
   }

   return tempPath;
}