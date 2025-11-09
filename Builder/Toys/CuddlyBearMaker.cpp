#include "CuddlyBearMaker.h"

CuddlyBearMaker::CuddlyBearMaker() {
    // Product instantiated on construction
    bear = new CuddlyBear();
}

CuddlyBearMaker::~CuddlyBearMaker() {
    delete bear;
}

void CuddlyBearMaker::selectBody() {
    bear->setPart("Body", "Soft brown fur");
}

void CuddlyBearMaker::stuff() {
    bear->setPart("Stuffing", "Premium cotton");
}

void CuddlyBearMaker::insertHeart() {
    bear->setPart("Heart", "Red satin heart");
}

void CuddlyBearMaker::addVoice() {
    bear->setPart("Voice", "Squeaker");
}

void CuddlyBearMaker::setName(std::string name) {
    bear->setPart("Name", name);
}

CuddlyBear* CuddlyBearMaker::getBear() {
    return bear;
}