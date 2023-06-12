#include "lexer.h"
#include <iostream>


using namespace std;

Lexer::Lexer(string filename) {
    input.open(filename);
    line = 1;
    column = 1;
}

Lexer::~Lexer() {
    input.close();
}

Token Lexer::next_token() {
    char c;
    while (input.get(c)) {
        if (c == ' ' || c == '\t') {
            column++;
        } else if (c == '\n') {
            line++;
            column = 1;
        } else if (isalpha(c)) {
            Token token;
            token.type = "Identyfikator";
            token.value = c;
            while (input.get(c)) {
                if (isalnum(c) || c == '_') {
                    token.value += c;
                    column++;
                } else {
                    input.putback(c);
                    break;
                }
            }
            token.line = line;
            token.column = column - token.value.size() + 1;
            return token;
        } else if (isdigit(c)) {
            Token token;
            token.type = "Kaczka";
            token.value = c;
            while (input.get(c)) {
                if (isdigit(c) || c == '.') {
                    token.value += c;
                    column++;
                } else {
                    input.putback(c);
                    break;
                }
            }
            token.line = line;
            token.column = column - token.value.size() + 1;
            return token;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>') {
            Token token;
            token.type = "Operator";
            token.value = c;
            column++;
            token.line = line;
            token.column = column - 1;
            return token;
        } else if (c == ',' || c == '.' || c == ';' || c == ':') {
            Token token;
            token.type = "Znak";
            token.value = c;
            column++;
            token.line = line;
            token.column = column - 1;
            return token;
        } else if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
            Token token;
            token.type = "Nawias";
            token.value = c;
            column++;
            token.line = line;
            token.column = column - 1;
            return token;
        } else {
            Token token;
            token.type = "Error";
            token.value = c;
            token.line = line;
            token.column = column;
            column++;
            return token;
        }
    }
    Token token;
    token.type = "Koniec";
    token.value = "";
    token.line = line;
    token.column = column;
    return token;
}
