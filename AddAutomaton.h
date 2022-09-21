#ifndef ADDAUTOMATON_H
#define ADDAUTOMATON_H

#include "Automaton.h"

class AddAutomaton : public Automaton
{
public:
    AddAutomaton() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input)
    {
        if (input[index] == '+') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    };
};

#endif
