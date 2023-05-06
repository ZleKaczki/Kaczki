#include <iostream>
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
    Lexer(string filename) {
        input.open(filename);
        line = 1;
        column = 1;
    }

    ~Lexer() {
        input.close();
    }

    Token next_token() {
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
            } else if ( c == ',' || c == '.' || c == ';' || c == ':') {
                Token token;
                token.type = "Znak";
                token.value = c;
                column++;
                token.line = line;
                token.column = column - 1;
                return token;
            }
            else if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']') {
                Token token;
                token.type = "Nawias";
                token.value = c;
                column++;
                token.line = line;
                token.column = column - 1;
                return token;
            }
            else {
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

private:
    ifstream input;
    int line;
    int column;
};

int main() {
    cout<< "Analiza leksykalna linii z pliku example "<<endl;
    Lexer lexer("example.txt");
    Token token;
    do {
        token = lexer.next_token();
        cout << "Token: " << token.type << ", Jak wyglada: " << token.value << ", Linia: " << token.line << ", Kolumna: " << token.column << endl;
    } while (token.type != "Koniec");
    return 0;
}
