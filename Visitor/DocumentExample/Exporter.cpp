#include "Exporter.h"
#include "PDFDocument.h"
#include "WordDocument.h"
#include "TextDocument.h"
#include <iostream>

Exporter::Exporter() : exportedData("") {}

void Exporter::visit(PDFDocument* doc) {
    std::cout << "Exporting PDF document..." << std::endl;
    exportedData = "[PDF Export]\n";
    exportedData += "Format: " + doc->getFormat() + "\n";
    exportedData += "Pages: " + std::to_string(doc->getPages()) + "\n";
    exportedData += "Content: " + doc->getContent() + "\n";
    std::cout << "  PDF exported successfully" << std::endl;
}

void Exporter::visit(WordDocument* doc) {
    std::cout << "Exporting Word document..." << std::endl;
    exportedData = "[Word Export]\n";
    exportedData += "Format: " + doc->getFormat() + "\n";
    exportedData += "Tracked Changes: " + std::string(doc->getHasTrackedChanges() ? "Yes" : "No") + "\n";
    exportedData += "Content: " + doc->getContent() + "\n";
    std::cout << "  Word document exported successfully" << std::endl;
}

void Exporter::visit(TextDocument* doc) {
    std::cout << "Exporting Text document..." << std::endl;
    exportedData = "[Text Export]\n";
    exportedData += "Format: " + doc->getFormat() + "\n";
    exportedData += "Encoding: " + doc->getEncoding() + "\n";
    exportedData += "Content: " + doc->getContent() + "\n";
    std::cout << "  Text document exported successfully" << std::endl;
}

std::string Exporter::getExportedData() const {
    return exportedData;
}