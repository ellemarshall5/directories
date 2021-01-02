//#ifndef DIRECTORIES_H
#define DIRECTORIES_H
#include <iostream>
#include <string>

std::string FixPhoneNumber(std::string phone);

std::string FixName(std::string name);

std::string FixEmail(std::string email);

void WriteFormatted(std::string phone, std::string name, std::string email, std::ostream& out);