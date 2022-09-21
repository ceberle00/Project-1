#ifndef COMMENTAUTOMATON_H
#define COMMENTAUTOMATON_H

#include "Automaton.h"
//changed string at 1-90 test 2, check back to amke sure the rest still work :)
class CommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input)
    {
        if (input[index] == '|')
        {
            inputRead++;
            index++;
            S3(input);
        }
        else if (!(input[index] == '\n') && !(input[index] == '\0'))
        {
            inputRead++;
            index++;
            S2(input);
        }
        else 
        {
            Serr();
        }
    };
    void S2(const std::string& input)
    {
        if (!(input[index] == '\n') && !(input[index] == '\0'))
        {
            inputRead++;
            index++;
            S2(input);
        }
        else {

        }
    };
    void S3(const std::string& input) 
    {
        if (input[index] == '|') 
        {
            inputRead++;
            index++;
            S4(input);
        }
        else if (!(input[index] == '\0')) 
        {
            if (input[index] == '\n') 
            {
                newLines++;
            }
            inputRead++;
            index++;
            S3(input);
        }
        else 
        {
            Serr();
        }
    }
    void S4(const std::string& input) 
    {
        if (input[index] == '#') 
        {
            inputRead++;
        }
        else if (!(input[index] == '\0'))
        {
            if (input[index] == '\n')
            {
                newLines++;
            }
            inputRead++;
            index++;
            S3(input);
        }
        else
        {
            Serr();
        }
    }

public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input)
    {
        if (input[index] == '#') {
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

