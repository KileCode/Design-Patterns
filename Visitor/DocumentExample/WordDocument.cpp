#include "WordDocument.h"
#include "DocumentProcessor.h"

WordDocument::WordDocument(const std::string& c, bool tracked) 
    : content(c), hasTrackedChanges(tracked) {}

void WordDocument::accept(DocumentProcessor& processor) {
    processor.visit(this);
}

std::string WordDocument::getContent() const {
    return content;
}

std::string WordDocument::getFormat() const {
    return "Word";
}

bool WordDocument::getHasTrackedChanges() const {
    return hasTrackedChanges;
}