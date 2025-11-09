#ifndef DOCUMENTPROCESSOR_H
#define DOCUMENTPROCESSOR_H

// Forward declarations
class PDFDocument;
class WordDocument;
class TextDocument;

// Visitor
class DocumentProcessor {
public:
    virtual ~DocumentProcessor() {}
    virtual void visit(PDFDocument* doc) = 0;
    virtual void visit(WordDocument* doc) = 0;
    virtual void visit(TextDocument* doc) = 0;
};

#endif