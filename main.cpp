#include <iostream>
#include <string>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <algorithm>


void AddList(LinkedList<char>& List, std::string input)
{
     for (int i = input.size()-1; i >=0; i--)
   {
      List.add(input[i]);
   }  // end for

}  // end ListTester

bool ifSubString(LinkedList<char>& List, std::string subString){

   std::string fromTheList = List.toString();

    return (fromTheList.find(subString) != std::string::npos);

}

void AppendList(LinkedList<char>& List, std::string input){

    List.clear();
   for (int i = input.size()-1; i >=0; i--)
   {
      List.add(input[i]);
   }

}


int main()
{
    std::string userString, newstring, subString;
    int choice;
    char charInput;
    LinkedList<char> listik;


   std::cout << "Welcome to the linkedList program\n" << std::endl;
   std::cout << "Please, enter the string before we start: ";
   getline(std::cin, userString);
   AddList(listik, userString);
   std::cout << "The string \"" << userString << "\" has been added to the linked list.\n" << std::endl;
   std::cout << "Menu: " << std::endl;
   std::cout << "1. Find the length of your input." << std::endl;
   std::cout << "2. Add a new string to the current string." << std::endl;
   std::cout << "3. Find the index of a character." << std::endl;
   std::cout << "4. Find matches in the string." << std::endl;
   std::cout << "5. Quit and sleep." << std::endl;
   std::cin >> choice;
   std::cin.ignore();
   while(choice!=5){
      switch(choice){
        case 1:
            std::cout << "The List " <<  listik.toString() << " contains " << listik.getCurrentSize() << " elements." << std::endl;
            std::cout << std::endl;
           break;
        case 2:
            std::cout << "Please type the string you'd like to append to the current list: ";
            getline(std::cin, newstring);
            AppendList(listik, (userString+newstring));
            std::cout << "The list now is \"" << listik.toString() << "\"." << std::endl; //AppendList function contains add method from linkedList
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Please type the character you'd like to have the index of: ";
            std::cin >> charInput;
            std::cout << "The index of \"" << charInput << "\" is " << listik.getFrequencyOf(charInput) << std::endl;
            std::cout << std::endl;
            break;
        case 4:
            std::cout << "Please type the string you'd like to find in the current list: ";
            getline(std::cin, subString);
            std::cout << "The string \"" << subString << "\" is";
            if (ifSubString(listik, subString)==false) std::cout << " not";
            std::cout << " found in \"" << listik.toString() << "\"." << std::endl;;
            std::cout << std::endl;
            break;
        case 5:
            listik.clear();
            exit(0);
            break;
   }
   std::cout << "\nMenu: " << std::endl;
   std::cout << "1. Find the length of your input." << std::endl;
   std::cout << "2. Add a new string to the current string." << std::endl;
   std::cout << "3. Find the index of a character." << std::endl;
   std::cout << "4. Find matches in the string." << std::endl;
   std::cout << "5. Quit and sleep." << std::endl;
   std::cout << std::endl;
   std::cin >> choice;
   std::cin.ignore();
   std::cout << std::endl;

   }

    return 0;
}  // end main


