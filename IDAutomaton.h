#ifndef IDAUTOMATON_H
#define IDAUTOMATON_H

#include "Automaton.h"

class IDAutomaton : public Automaton
{
private:
    //some issue with this, figure out why
    void S1(const std::string& input) {
        if (isalpha(input[index]) || (isdigit(input[index])))
        {
            inputRead++;
            index++;
            S1(input);
        }
        else if (isspace(input[index]))
        {
 
        }
        else if (!(isalpha(input[index])) && !(isdigit(input[index]))) 
        {
  
        }
        else {
            Serr();
        }
    };

public:
    IDAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input)
    {
        if (isalpha(input[index])) {
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
