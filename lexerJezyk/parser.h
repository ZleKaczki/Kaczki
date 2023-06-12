#pragma once

#include "lexer.h"

class Parser {
public:
    Parser(Lexer& lexer);
    void parse();

private:
    Lexer& lexer;
};
