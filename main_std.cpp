#include <iostream>
#include <vector>
#include <variant>

#include "Characters.h"

int main(void)
{
    std::vector<std::variant<NonTerminal, Token>> characters;
    characters.emplace_back(NonTerminal{});
    characters.emplace_back(Token{});
    characters.emplace_back(NonTerminal{});
    characters.emplace_back(Token{});

    JsonTranslator jsonTranslator;
    XmlTranslator xmlTranslator;

    std::cout << "JsonTranslator result:\n";
    for (auto &ch : characters)
    {
        std::visit([&jsonTranslator](auto &elem) {
            elem.accept(jsonTranslator);
        }, ch);
    }

    std::cout << "XmlTranslator result:\n";
    for (auto &ch : characters)
    {
        std::visit([&xmlTranslator](auto &elem) {
            elem.accept(xmlTranslator);
        }, ch);
    }

    return 0;
}
