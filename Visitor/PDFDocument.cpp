#include "PDFDocument.h"
#include "DocumentProcessor.h"

PDFDocument::PDFDocument(const std::string& c, int p) : content(c), pages(p) {}

void PDFDocument::accept(DocumentProcessor& processor) {
    processor.visit(this);
}

std::string PDFDocument::getContent() const {
    return content;
}

std::string PDFDocument::getFormat() const {
    return "PDF";
}

int PDFDocument::getPages() const {
    return pages;
}