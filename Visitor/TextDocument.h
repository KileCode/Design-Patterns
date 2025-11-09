#ifndef TEXTDOCUMENT_H
#define TEXTDOCUMENT_H

#include "Document.h"
#include <string>

// ConcreteElement
class TextDocument : public Document {
private:
    std::string content;
    std::string encoding;
public:
    TextDocument(const std::string& c, const std::string& enc);
    void accept(DocumentProcessor& processor) override;
    std::string getContent() const override;
    std::string getFormat() const override;
    std::string getEncoding() const;
};

#endif