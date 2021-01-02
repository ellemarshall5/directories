/* Directories
 * Danielle Marshall
 * 10/15/2020
 *
 * This project was to use the knowledge we learned regarding different
 * string functions and reading from and writing to files.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <array>
#include "directories.h"
using namespace std;


int main() {
    string phone; //declare string
    string name; //declare string
    string email; //declare string
    string clubName; //declare string
    string userString; //declare string
    ifstream userFile; //declare ifstream object to open file

    cout << "Please enter the name of the file: " << endl; //ask for user input
    cin >> userString; //read user input

    userFile.open("../../" + userString);//open file provided user

    //error message if file fails to open
    if(userFile.fail()){
        cout << "Unable to open file. Shutting down...\n";
        return 1;
    }

    ofstream outFile("../../test.txt"); //create ofstream object to write new file

    getline(userFile, clubName); //read in and store club name from file
    outFile << "          " + clubName << endl; //write club name to file

    //reads in all data from user provided file, formats it properly and writes to a new file
    while(userFile >> phone) {
        userFile.ignore(); //ignores spaces from extraction operator
        getline(userFile, name);//reads and stores name
        userFile >> email;//rads and stores email
        //calls function to format data and write to file
        WriteFormatted(FixPhoneNumber(phone), FixName(name), FixEmail(email), outFile);
    }

    userFile.close();//closes file

    return 0;
}