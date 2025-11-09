#include "DocumentProcessor.h"
#include <iostream>
#include <sstream>

// ConcreteElement accept() implementations
// These must be in the concrete classes despite appearing identical
// because 'this' has different static types in each case

void PDFDocument::accept(DocumentProcessor& processor) {
    processor.visit(this);
}

void WordDocument::accept(DocumentProcessor& processor) {
    processor.visit(this);
}

void TextDocument::accept(DocumentProcessor& processor) {
    processor.visit(this);
}

// SpellChecker implementations
void SpellChecker::visit(PDFDocument* doc) {
    std::cout << "Spell checking PDF document..." << std::endl;
    // Simulate spell checking
    errorCount = doc->getContent().length() / 50; // Simple simulation
    std::cout << "  Found " << errorCount << " spelling errors in PDF" << std::endl;
}

void SpellChecker::visit(WordDocument* doc) {
    std::cout << "Spell checking Word document..." << std::endl;
    if (doc->getHasTrackedChanges()) {
        std::cout << "  Warning: Document has tracked changes" << std::endl;
    }
    errorCount = doc->getContent().length() / 45;
    std::cout << "  Found " << errorCount << " spelling errors in Word doc" << std::endl;
}

void SpellChecker::visit(TextDocument* doc) {
    std::cout << "Spell checking Text document..." << std::endl;
    std::cout << "  Encoding: " << doc->getEncoding() << std::endl;
    errorCount = doc->getContent().length() / 40;
    std::cout << "  Found " << errorCount << " spelling errors in text file" << std::endl;
}

// WordCounter implementations
void WordCounter::visit(PDFDocument* doc) {
    std::cout << "Counting words in PDF document..." << std::endl;
    std::istringstream iss(doc->getContent());
    std::string word;
    int count = 0;
    while (iss >> word) count++;
    totalWords = count;
    std::cout << "  PDF has " << doc->getPages() << " pages" << std::endl;
    std::cout << "  Total words: " << totalWords << std::endl;
}

void WordCounter::visit(WordDocument* doc) {
    std::cout << "Counting words in Word document..." << std::endl;
    std::istringstream iss(doc->getContent());
    std::string word;
    int count = 0;
    while (iss >> word) count++;
    totalWords = count;
    std::cout << "  Total words: " << totalWords << std::endl;
}

void WordCounter::visit(TextDocument* doc) {
    std::cout << "Counting words in Text document..." << std::endl;
    std::istringstream iss(doc->getContent());
    std::string word;
    int count = 0;
    while (iss >> word) count++;
    totalWords = count;
    std::cout << "  Total words: " << totalWords << std::endl;
}

// Exporter implementations
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