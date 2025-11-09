#ifndef PDFDOCUMENT_H
#define PDFDOCUMENT_H

#include "Document.h"
#include <string>

// ConcreteElement
class PDFDocument : public Document {
private:
    std::string content;
    int pages;
public:
    PDFDocument(const std::string& c, int p);
    void accept(DocumentProcessor& processor) override;
    std::string getContent() const override;
    std::string getFormat() const override;
    int getPages() const;
};

#endif