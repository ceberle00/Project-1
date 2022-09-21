#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

#include "Lexer.h"
#include "Automaton.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "PeriodAutomaton.h"
#include "CommaAutomaton.h"
#include "QuestionAutomanton.h"
#include "LeftAutomaton.h"
#include "RightAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "StringAutomaton.h"
#include "IDAutomaton.h"
#include "CommentAutomaton.h"
#include "UndefinedAutomaton.h"

using namespace std;

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for (unsigned int i = 0; i < tokens.size(); i++)
    {
        delete tokens.at(i);
    }
    for (unsigned int j = 0; j < automata.size(); j++)
    {
        delete automata.at(j);
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QuestionAutomaton());
    automata.push_back(new LeftAutomaton());
    automata.push_back(new RightAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new UndefinedAutomaton());
}

void Lexer::Run(std::string& input) 
{
    int lineNum = 1;
    //need to alter lineNum at some point, use that as opposed to the size
    while (input.size() > 0)
    {
        string testString = "";
        int maxRead = 0;
        Automaton* maxAutomaton = automata.at(0);
        //maybe test string, do each part individually, added +1, didn't do anything
        //added this, test
        while (isspace(input[0]))
        {
            if (input[0] == '\n')
            {
                lineNum++;
            }
            input = input.substr(1);
        }
        for (unsigned int i = 0; i < automata.size(); i++)
        {
            int inputRead = automata.at(i)->Start(input);
            if (inputRead > maxRead)
            {
                maxRead = inputRead;
                maxAutomaton = automata.at(i);
            }
        }
        //pushing data to string
        for (int k = 0; k < maxRead; k++)
        {
            testString.push_back(input[k]);
        }
        if (maxRead > 0)
        {
            //testing with lineNum instead, seems to work, add more classes to make sure
            //Token* newToken = maxAutomaton->CreateToken(testString, maxRead);
            Token* newToken = maxAutomaton->CreateToken(testString, lineNum);
            lineNum = lineNum + maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        else
        {
            //need to this doesn't count with space
            testString = input[0];
            if ((input[0] == '\n') || (input[0] == ' ') || input.empty())
            {
                break;
            }
            maxRead = 1;
            //Token* newToken = new Token(TokenType::UNDEFINED, testString, input.at(maxRead - 1));
            Token* newToken = new Token(TokenType::UNDEFINED, testString, lineNum);
            tokens.push_back(newToken);
        }
        if (!(input.empty())) 
        {
            input = input.substr(maxRead, input.size() - 1);
        }
    }
    int totalTokens = 0;
    for (unsigned int j = 0; j < tokens.size(); j++) 
    {
        Token* token = tokens.at(j);
        cout << token->MyToString() << endl;
        totalTokens++;
    }

    totalTokens = totalTokens + 1;
    //maybe need to do lineNum + 1?
    string help = "";
    Token* EOFToken = new Token(TokenType::EOFTOKEN, help, lineNum);
    cout << EOFToken->MyToString() << endl;;
    cout << "Total Tokens = " << totalTokens;
}
