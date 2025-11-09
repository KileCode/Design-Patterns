CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = main
OBJS = main.o PDFDocument.o WordDocument.o TextDocument.o SpellChecker.o WordCounter.o Exporter.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Document.h PDFDocument.h WordDocument.h TextDocument.h SpellChecker.h WordCounter.h Exporter.h
	$(CXX) $(CXXFLAGS) -c main.cpp

PDFDocument.o: PDFDocument.cpp PDFDocument.h Document.h DocumentProcessor.h
	$(CXX) $(CXXFLAGS) -c PDFDocument.cpp

WordDocument.o: WordDocument.cpp WordDocument.h Document.h DocumentProcessor.h
	$(CXX) $(CXXFLAGS) -c WordDocument.cpp

TextDocument.o: TextDocument.cpp TextDocument.h Document.h DocumentProcessor.h
	$(CXX) $(CXXFLAGS) -c TextDocument.cpp

SpellChecker.o: SpellChecker.cpp SpellChecker.h DocumentProcessor.h PDFDocument.h WordDocument.h TextDocument.h
	$(CXX) $(CXXFLAGS) -c SpellChecker.cpp

WordCounter.o: WordCounter.cpp WordCounter.h DocumentProcessor.h PDFDocument.h WordDocument.h TextDocument.h
	$(CXX) $(CXXFLAGS) -c WordCounter.cpp

Exporter.o: Exporter.cpp Exporter.h DocumentProcessor.h PDFDocument.h WordDocument.h TextDocument.h
	$(CXX) $(CXXFLAGS) -c Exporter.cpp

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)