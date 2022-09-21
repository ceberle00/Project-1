#include "Lexer.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    //ifstream inputFileName(argv[1]);
    //input 5, does spacing matter?? otherwise correct 1-70
    ifstream inputFileName("C:\\Users\\camil\\Downloads\\Lab1PassOffCases_spring2021\\Lab1PassOffCases\\1-70\\input1.txt");
    string tempLine = "";
    if (inputFileName.is_open())
    {
        string testString = "";
        while (getline(inputFileName, tempLine)) 
        {
            testString.append(tempLine);
            testString.append("\n");
        }
        lexer->Run(testString);
    }
    
    

    delete lexer;

    return 0;
}