#include "parser.h"
#include <iostream>

Parser::Parser(Lexer& lexer) : lexer(lexer) {}

void Parser::parse() {
    Token token;
    do {
        token = lexer.next_token();
        if (token.type == "Identyfikator") {
            cout << "Znaleziono identyfikator: " << token.value << endl;
        } else if (token.type == "Kaczka") {
            cout << "Znaleziono liczbe: " << token.value << endl;
        } else if (token.type == "Operator") {
            cout << "Znaleziono operator: " << token.value << endl;
        } else if (token.type == "Znak") {
            cout << "Znaleziono znak: " << token.value << endl;
        } else if (token.type == "Nawias") {
            cout << "Znaleziono nawias: " << token.value << endl;
        } else if (token.type == "Error") {
            cout << "Blad leksykalny: Nieznany znak '" << token.value << "' w linii: " << token.line << ", kolumna: " << token.column << endl;
        }
    } while (token.type != "Koniec");
}
