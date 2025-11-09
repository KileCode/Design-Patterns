#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

// Forward declaration
class DocumentProcessor;

// Element
class Document {
public:
    virtual ~Document() {}
    virtual void accept(DocumentProcessor& processor) = 0;
    virtual std::string getContent() const = 0;
    virtual std::string getFormat() const = 0;
};

#endif