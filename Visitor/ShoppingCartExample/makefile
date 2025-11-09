CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = main
OBJS = main.o Electronics.o Clothing.o Groceries.o TaxCalculator.o DiscountApplier.o ShippingCalculator.o ShoppingCart.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Product.h Electronics.h Clothing.h Groceries.h TaxCalculator.h DiscountApplier.h ShippingCalculator.h ShoppingCart.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ShoppingCart.o: ShoppingCart.cpp ShoppingCart.h Product.h PricingCalculator.h
	$(CXX) $(CXXFLAGS) -c ShoppingCart.cpp

Electronics.o: Electronics.cpp Electronics.h Product.h PricingCalculator.h
	$(CXX) $(CXXFLAGS) -c Electronics.cpp

Clothing.o: Clothing.cpp Clothing.h Product.h PricingCalculator.h
	$(CXX) $(CXXFLAGS) -c Clothing.cpp

Groceries.o: Groceries.cpp Groceries.h Product.h PricingCalculator.h
	$(CXX) $(CXXFLAGS) -c Groceries.cpp

TaxCalculator.o: TaxCalculator.cpp TaxCalculator.h PricingCalculator.h Electronics.h Clothing.h Groceries.h
	$(CXX) $(CXXFLAGS) -c TaxCalculator.cpp

DiscountApplier.o: DiscountApplier.cpp DiscountApplier.h PricingCalculator.h Electronics.h Clothing.h Groceries.h
	$(CXX) $(CXXFLAGS) -c DiscountApplier.cpp

ShippingCalculator.o: ShippingCalculator.cpp ShippingCalculator.h PricingCalculator.h Electronics.h Clothing.h Groceries.h
	$(CXX) $(CXXFLAGS) -c ShippingCalculator.cpp

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)