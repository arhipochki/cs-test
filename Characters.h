#include "Visitors.h"

class LanguageCharacter {
public:
    virtual ~LanguageCharacter() = default;
    virtual void accept(Visitor &visitor) = 0; 
};

class NonTerminal : public LanguageCharacter {
public:
    void accept(Visitor &visitor) override
    {
        visitor.visit(*this);
    }
};

class Token : public LanguageCharacter {
public:
    void accept(Visitor &visitor) override
    {
        visitor.visit(*this);
    }
};
