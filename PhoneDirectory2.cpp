#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Phone {
  std::string name;
  std::string phone;

  Phone(std::string name, std::string phone) {
    this->name = name;
    this->phone = phone;
  }
};

std::vector<std::string> split(const std::string& str, const std::string& delim) {
  std::vector<std::string> tokens;
  size_t prev = 0, pos = 0;
  do
  {
      pos = str.find(delim, prev);
      if (pos == std::string::npos) pos = str.length();
      std::string token = str.substr(prev, pos-prev);
      if (!token.empty()) tokens.push_back(token);
      prev = pos + delim.length();
  }
  while (pos < str.length() && prev < str.length());
  return tokens;
}


int main() {
  std::string line;
  std::vector<Phone> phoneDirectory;
  std::ifstream myfile ("PhoneDirectory2.csv");
  if (myfile.is_open()) {
    while ( getline (myfile, line)) {
      std::vector<std::string> parts = split(line, ", ");
      Phone phone = Phone(parts[0], parts[1]);
      phoneDirectory.push_back(phone);
    }
    myfile.close();
  }
  else std::cout << "Unable to open file"; 


  int selectedOption;
  std::cout << "Phone Directory (version 2)\n1. Add an Entry\n2. List All Entries\nPlease select an option (or 0 to finish): ";
  std::cin >> selectedOption;

  if (selectedOption == 1) {
    if (phoneDirectory.size() >= 5) {
      std::cout << "Warning: Can't have more than 5 entries in Phone Directory" << std::endl;
    } else {
      std::string name;
      std::string number;
      
      std::cout << "Please input name: " << std::endl;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, name);
      
      std::cout << "Please input number: " << std::endl;
      std::getline(std::cin, number);
      
      phoneDirectory.push_back(Phone(name, number));

      std::ofstream outFile;
      outFile.open("PhoneDirectory2.csv", std::ios::trunc);
      for (auto user: phoneDirectory) {
        outFile << user.name << ", " << user.phone << std::endl;
      }
      outFile.close();
    }
  } else if (selectedOption == 2) {
    for (int i = 0; i < phoneDirectory.size(); i++) {
      std::cout << i << ". " << phoneDirectory.at(i).name << ", " << phoneDirectory.at(i).phone << std::endl;
    }
  } else if (selectedOption == 0) {
    std::cout << "Goodbye!" << std::endl;
  } else {
    std::cout << "Invalid input!" << std::endl;
  }


}