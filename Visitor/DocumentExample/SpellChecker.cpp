#include "SpellChecker.h"
#include "PDFDocument.h"
#include "WordDocument.h"
#include "TextDocument.h"
#include <iostream>

SpellChecker::SpellChecker() : errorCount(0) {}

void SpellChecker::visit(PDFDocument* doc) {
    std::cout << "Spell checking PDF document..." << std::endl;
    errorCount = doc->getContent().length() / 50;
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

int SpellChecker::getErrorCount() const {
    return errorCount;
}