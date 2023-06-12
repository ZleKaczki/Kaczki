#pragma once

#include <fstream>
#include <regex>
#include <string>

using namespace std;

struct Token {
    string type;
    string value;
    int line;
    int column;
};

class Lexer {
public:
    Lexer(string filename);
    ~Lexer();
    Token next_token();

private:
    ifstream input;
    int line;
    int column;
};
