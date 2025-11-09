#include "WordCounter.h"
#include "PDFDocument.h"
#include "WordDocument.h"
#include "TextDocument.h"
#include <iostream>
#include <sstream>

WordCounter::WordCounter() : totalWords(0) {}

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

int WordCounter::getTotalWords() const {
    return totalWords;
}