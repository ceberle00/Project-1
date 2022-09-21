#ifndef UNDEFINEDAUTOMATON_H
#define UNDEFINEDAUTOMATON_H

#include "Automaton.h"

class UndefinedAutomaton : public Automaton
{
private:
    int commaCount = 0;
    void S1(const std::string& input) {
        if (input[index] == '|')
        {
            inputRead++;
            index++;
            S2(input);
        }
        else {
            Serr();
        }
    };
    void S2(const std::string& input) {
        if (input[index] == '|') 
        {
            inputRead++;
            index++;
            S3(input);
        }
        else if (input[index] != '\0')
        {
            //added, make sure it works
            if (input[index] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S2(input);
        }
        else {
            //do nothing, don't want to overload
        }
    };
    void S3(const std::string& input) {
        if (input[index] == '#') {
            Serr();
        }
        else if (input[index] != '\0')
        {
            if (input[index] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S2(input);
        }
        else {

        }
    }
    //start of unfinished quote
    //check at the end of newline for count, if even then it is complete, otherwise continue on
    void S4(const std::string& input) 
    {
        //splitting last undefined as 3 seperate
        if ((input[index] == '\n'))
        {
            if (commaCount % 2 == 0) 
            {
                Serr();
            }
            else {
                newLines++;
                inputRead++;
                index++;
                S4(input);
            }
            //doesn't increment newline, check back if thats still fine
            //S5(input);
        }
        else if (input[index] == '\0') 
        {
            if (commaCount % 2 == 0) {
                Serr();
            }
            else {
                //doing nothing, file ended, don't increase count or index
            }
        }
        else if (input[index] == '\'') 
        {
            commaCount++;
            if (commaCount % 2 == 0) {
                //maybe increment index??
                inputRead++;
                index++;
                S5(input);
            }
            else {
                inputRead++;
                index++;
                S4(input);
            }
        }
        else 
        {
            inputRead++;
            index++;
            S4(input);
        }
        
    }
    void S5(const std::string& input) 
    {
        if (input[index] == '\'') 
        {
            commaCount++;
            inputRead++;
            index++;
            S4(input);
        }
        else if ((input[index] == '\n') || (input[index] == '\0')) 
        {
            Serr();
        }
        else 
        {
            Serr();
        }
    }
public:
    UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {};  // Call the base constructor

    void S0(const std::string& input)
    {
        //undefined string has to have one quote followed by a newline
        //maybe make less complicated undefined file, 
        if (input[index] == '#') {
            inputRead++;
            index++;
            S1(input);
        }
        //see if quote finishes, help, go back to the count of the quotes, at the end of each newline see if even
        else if (input[index] == '\'')
        {
            commaCount = 1;
            inputRead++;
            index++;
            S4(input);
        }
        else {
            Serr();
        }
    };
};
#endif
