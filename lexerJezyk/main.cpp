#include "lexer.h"
#include "parser.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Analiza leksykalna i skladniowa linii z pliku example" << endl;
    Lexer lexer("example.txt");
    Parser parser(lexer);
    parser.parse();
    return 0;
}
