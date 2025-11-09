#ifndef EXPORTER_H
#define EXPORTER_H

#include "DocumentProcessor.h"
#include <string>

// ConcreteVisitor
class Exporter : public DocumentProcessor {
private:
    std::string exportedData;
public:
    Exporter();
    void visit(PDFDocument* doc) override;
    void visit(WordDocument* doc) override;
    void visit(TextDocument* doc) override;
    std::string getExportedData() const;
};

#endif