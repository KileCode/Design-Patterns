#include "TextDocument.h"
#include "DocumentProcessor.h"

TextDocument::TextDocument(const std::string& c, const std::string& enc) 
    : content(c), encoding(enc) {}

void TextDocument::accept(DocumentProcessor& processor) {
    processor.visit(this);
}

std::string TextDocument::getContent() const {
    return content;
}

std::string TextDocument::getFormat() const {
    return "Text";
}

std::string TextDocument::getEncoding() const {
    return encoding;
}