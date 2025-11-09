#include "Document.h"
#include "PDFDocument.h"
#include "WordDocument.h"
#include "TextDocument.h"
#include "SpellChecker.h"
#include "WordCounter.h"
#include "Exporter.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "=== Document Processing System using Visitor Pattern ===" << std::endl;
    std::cout << std::endl;

    // Create various documents (ConcreteElements)
    PDFDocument pdf("This is a sample PDF document with some content to process.", 5);
    WordDocument word("Here is a Word document that may have tracked changes enabled.", true);
    TextDocument text("A simple text document with UTF-8 encoding for processing.", "UTF-8");

    // Store documents in a collection (ObjectStructure simulation)
    std::vector<Document*> documents;
    documents.push_back(&pdf);
    documents.push_back(&word);
    documents.push_back(&text);

    std::cout << "--- Running SpellChecker Visitor ---" << std::endl;
    SpellChecker spellChecker;
    for (Document* doc : documents) {
        doc->accept(spellChecker);
        std::cout << std::endl;
    }

    std::cout << "--- Running WordCounter Visitor ---" << std::endl;
    WordCounter wordCounter;
    for (Document* doc : documents) {
        doc->accept(wordCounter);
        std::cout << std::endl;
    }

    std::cout << "--- Running Exporter Visitor ---" << std::endl;
    Exporter exporter;
    for (Document* doc : documents) {
        doc->accept(exporter);
        std::cout << std::endl;
    }

    std::cout << "--- Demonstrating Double Dispatch ---" << std::endl;
    std::cout << "Calling pdf.accept(spellChecker):" << std::endl;
    std::cout << "  1. accept() is called on PDFDocument" << std::endl;
    std::cout << "  2. PDFDocument::accept() calls processor.visit(this)" << std::endl;
    std::cout << "  3. SpellChecker::visit(PDFDocument*) is executed" << std::endl;
    std::cout << "  4. visit() can call back to PDFDocument methods like getPages()" << std::endl;
    std::cout << std::endl;

    pdf.accept(spellChecker);

    std::cout << std::endl;
    std::cout << "=== Pattern Benefits Demonstrated ===" << std::endl;
    std::cout << "1. Easy to add new visitors (e.g., Formatter, Compressor)" << std::endl;
    std::cout << "2. No need to recompile Document classes when adding visitors" << std::endl;
    std::cout << "3. Related operations grouped in visitor classes (high cohesion)" << std::endl;
    std::cout << "4. Double dispatch ensures correct method based on both types" << std::endl;

    return 0;
}