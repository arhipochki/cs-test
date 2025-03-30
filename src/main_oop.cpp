#include <iostream>
#include <vector>
#include <memory>

#include "Characters.h"

int main(void)
{
    std::vector<std::unique_ptr<LanguageCharacter>> characters;

    characters.emplace_back(std::make_unique<NonTerminal>());
    characters.emplace_back(std::make_unique<Token>());
    characters.emplace_back(std::make_unique<NonTerminal>());
    characters.emplace_back(std::make_unique<Token>());

    JsonTranslator jsonTranslator;
    XmlTranslator xmlTranslator;

    std::cout << "JsonTranslator result:\n";
    for (auto &ch : characters)
    {
        ch->accept(jsonTranslator);
    }

    std::cout << "XmlTranslator result:\n";
    for (auto &ch : characters)
    {
        ch->accept(xmlTranslator);
    }

    return 0;
}
