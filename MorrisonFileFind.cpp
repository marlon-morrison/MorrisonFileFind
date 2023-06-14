#include <iostream>
#include <fstream>
#include <cstdlib>
#include<stdio.h>

int main ()
{
    char filename[15];
    char C;
    int count = 0;
    std::string line;
    std::string srch;

    std::fstream userFile; 
    std::cout << "Enter the name of an existing file: ";
    std::cin >> filename;
    std::cout << "Enter a word in the existing file: ";
    std::cin >> srch;
    std::cout << "\nThe name of your file is: " << filename << ".\n";
    userFile.open(filename, std::fstream::in);
    if(!userFile)
    {
        std::cout << "\nfile open FAILED \n";
        return 0;
    } else {
        std::cout << "\nFile open SUSSESS\n";
    }
    std::cout<<"\nContent of "<<filename<<":-\n";
    while(getline(userFile, line)){
        if (line.find(srch) != std::string::npos){
            std::cout << "\nFound on this line: \n" << line << "\n";
            count++;
            if (count==15) {
                userFile.close();
                std::cout<<"\n";
                return 0;
            }
            
        } 
    }
    if(count < 15){
        std::cout << "No more lines of text.\n";
        std::cout << srch <<" showed up "<< count <<" times.\n";
    }
    userFile.close();
    std::cout<<"\n";
    return 0;
}