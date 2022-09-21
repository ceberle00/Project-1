#include "ColonAutomaton.h"

//feels like we don't need a colon automaton, just colon dash and add a case where the colon is there and not the dash

void ColonAutomaton::S0(const std::string& input) {
    if (input[index] == ':') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}