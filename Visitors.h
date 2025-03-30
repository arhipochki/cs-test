#include <iostream>

class NonTerminal;
class Token;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(NonTerminal &nonTerminal) = 0;
    virtual void visit(Token &token) = 0;
};

class JsonTranslator : public Visitor {
public:
    JsonTranslator() = default;

    void visit(NonTerminal &nonTerminal) override
    {
        std::cout << "[JsonTranslator] Parsing NonTerminal\n";
    }

    void visit(Token &token) override
    {
        std::cout << "[JsonTranslator] Parsing Token\n";
    }
};

class XmlTranslator : public Visitor {
public:
    XmlTranslator() = default;

    void visit(NonTerminal &nonTerminal) override
    {
        std::cout << "[XmlTranslator] Parsing NonTerminal\n";
    }

    void visit(Token &token) override
    {
        std::cout << "[XmlTranslator] Parsing Token\n";
    }
};
