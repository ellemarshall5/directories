#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

/*
 * The FixPhoneNumber function is passed the phone number from main and
 * then formats the phone number
 */

string FixPhoneNumber(string phone){
    string phoneFixed;//declares string

    //if statement to test phone number and send it to the proper statement
    if(phone.length() == 13) {
        phone.erase(0,1);//erases first char
        if (phone.find('-')) {
            //replaces - with .
            while (phone.find('-') != string::npos) {
                phoneFixed = phone.replace(phone.find("-"), 1, ".");
            }
        }
        if (phone.find(")")) {
            //replaces ) with .
            while (phone.find(")") != string::npos) {
                phoneFixed = phone.replace(phone.find(")"), 1, ".");
            }
        }
    }
    else if(phone.length() == 8  || phone.length() == 12){
        //keeps phone number the same
        if (phone.find('.')){
            phoneFixed = phone;
        }
        if (phone.find('-')) {
            //replaces - with .
            while (phone.find('-') != string::npos) {
                phoneFixed = phone.replace(phone.find("-"), 1, ".");
            }
        }
    }
    else if(phone.length() == 7){
        //inserts .
        phoneFixed = phone.insert(3, ".");
    }
    else if(phone.length() == 10){
        //inserts .
        phoneFixed = phone.insert(3, ".");
        phoneFixed = phone.insert(7, ".");
    }

    return phoneFixed; //returns the properly formatted phone number
}

/*
 * The FixName functions is passed a string and returns a string. This function
 * formats the name.
 */

string FixName(string name){

    string fixedName;//declares string
    string lastName;//declares string
    string firstName;//declares string

    //tests to see if name has a "," if it does switches which name comes first
    if (name.find(",") != string::npos) {
        int position = name.find(",");
        lastName = name.substr(0, position);//creates substring for last name
        firstName = name.substr(position + 2, name.length());//creates substring for first name
        fixedName = firstName + " " + lastName;//concatenates first and last name
    }
    else{
        fixedName = name;//nothing wrong with original name format, returns original
    }

    return fixedName;//returns properly formatted name
}

/*
 * The FixEmail function receives a string and returns a string. This function sets the email
 * address to the proper format
 */

string FixEmail(string email){

    string fixedEmail;//declares string

    //tests email for .com, if it's there returns original email
    if(email.find(".com") != string::npos){
        fixedEmail = email;
    }
    //tests email for .com, if it's not there adds it
    if(email.find(".com") == string::npos){
        fixedEmail = email + ".com";
    }
    //tests email for @, if not there adds the proper email handle
    if(email.find("@") == string::npos){
        fixedEmail = email + "@mail.weber.edu";
    }

    return fixedEmail;//returns properly formatted email
}

/*
 * The WriteFormatted function receives the properly formatted email, phone and name strings.
 * It then prints them to a new file with certain formatting
 */

void WriteFormatted(string phone, string name, string email, ostream& out){

    string name_to_print;//declares string

    //tests to name and if longer than 19 char shortens it to 16 and adds ...
    if(name.length() > 18){
        name_to_print = name.substr(0, 16) + "...";
    }
    else {
        name_to_print = name;
    }

    //writes to new file with a specific format
    out
        << right << setw(16) << phone << "  "
        << left << setw(19) << name_to_print << "  "
        << left << email << endl;
}
