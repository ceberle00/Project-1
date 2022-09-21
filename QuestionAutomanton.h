#ifndef QUESTIONAUTOMATON_H
#define QUESTIONAUTOMATON_H

#include "Automaton.h"

class QuestionAutomaton : public Automaton
{
public:
    QuestionAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input) 
    {
        if (input[index] == '?') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    };
};

#endif // COLONAUTOMATON_H