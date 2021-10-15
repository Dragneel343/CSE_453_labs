#include <string>
#include <iostream>
#include <filesystem>
#include <locale>

std::string getPath(std::string filename);

int main()
 {
   std::string path1 = "cd test";
   std::string path2 = "cd c:\\test";
   std::cout << std::filesystem::current_path() << std::endl;

   //std::cout << "Enter a file path: ";
   //std::getline(std::cin, path1);

   //std::cout << "Enter a second file path: ";
   //std::getline(std::cin, path2);
   
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
   std::string Path; 

   if (filename[4] != ':' )
   {      
      std::filesystem::path cwd = std::filesystem::current_path();
      std::string currentPath = cwd.string();
      
      std::locale loc;
      Path += std::tolower(currentPath[0], loc);
      Path += currentPath[1];
      Path += currentPath[2];      

      for (int i = 3; i < filename.length(); i++)
      {         
         Path += filename[i];
      }
   }

   else
   {
      for (int i = 3; i < filename.length(); i++)
      {
         Path += filename[i];
      }
   }

   return Path;
}