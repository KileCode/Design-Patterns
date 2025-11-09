#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include "DocumentProcessor.h"

// ConcreteVisitor
class SpellChecker : public DocumentProcessor {
private:
    int errorCount;
public:
    SpellChecker();
    void visit(PDFDocument* doc) override;
    void visit(WordDocument* doc) override;
    void visit(TextDocument* doc) override;
    int getErrorCount() const;
};

#endif