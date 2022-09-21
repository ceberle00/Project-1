#ifndef LEFTAUTOMATON_H
#define LEFTAUTOMATON_H

#include "Automaton.h"

class LeftAutomaton : public Automaton
{
public:
    LeftAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input)
    {
        if (input[index] == '(') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    };
};

#endif