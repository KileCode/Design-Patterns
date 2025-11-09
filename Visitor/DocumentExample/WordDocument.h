#ifndef WORDDOCUMENT_H
#define WORDDOCUMENT_H

#include "Document.h"
#include <string>

// ConcreteElement
class WordDocument : public Document {
private:
    std::string content;
    bool hasTrackedChanges;
public:
    WordDocument(const std::string& c, bool tracked);
    void accept(DocumentProcessor& processor) override;
    std::string getContent() const override;
    std::string getFormat() const override;
    bool getHasTrackedChanges() const;
};

#endif