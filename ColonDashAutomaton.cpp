#include "ColonDashAutomaton.h"

void ColonDashAutomaton::S0(const std::string& input) {
    if (input[index] == ':') {
        inputRead++; //size of the input (ex, comma would be 1, facts would be 5)
        index++; //(where in the string theyre at)
        S1(input);
    }
    else {
        Serr();
    }
}

void ColonDashAutomaton::S1(const std::string& input) {
    if (input[index] == '-') {
        inputRead++;
    }
    else {
        //could we set this to still inputRead++
        Serr();
    }
}