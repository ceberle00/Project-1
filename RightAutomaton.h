#ifndef RIGHTAUTOMATON_H
#define RIGHTAUTOMATON_H

#include "Automaton.h"

class RightAutomaton : public Automaton
{
public:
    RightAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input)
    {
        if (input[index] == ')') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    };
};

#endif
