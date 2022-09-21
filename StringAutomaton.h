#ifndef STRINGAUTOMATON_H
#define STRINGAUTOMATON_H

#include "Automaton.h"

class StringAutomaton : public Automaton
{
private:
    //could cut this down to just two extra functions
    void S1(const std::string& input) {
        if (input[index] == '\'')
        {
            inputRead++;
            index++;
            S2(input);
        }
        else if (input[index] != '\0')
        {
            if (input[index] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S1(input);
        }
        else 
        {
            Serr();
        }
    };
    void S2(const std::string& input) 
    {
        if (input[index] == '\'') {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            //maybe not needed?? 
        }
    }

public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input)
    {
        if (input[index] == '\'') {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    };
};

#endif
