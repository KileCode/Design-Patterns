#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include "DocumentProcessor.h"

// ConcreteVisitor
class WordCounter : public DocumentProcessor {
private:
    int totalWords;
public:
    WordCounter();
    void visit(PDFDocument* doc) override;
    void visit(WordDocument* doc) override;
    void visit(TextDocument* doc) override;
    int getTotalWords() const;
};

#endif