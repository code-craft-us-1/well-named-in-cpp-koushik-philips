#include "StdAfx.h"
#include "ColorPair.h"
#include "ColorUtility.h"

extern void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor);
extern void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber);
extern void testPrintColorManual(int expectedNumRows, TelCoColorCoder::PrintOrder order);

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    //TelCoColorCoder::PrintColorManual(std::cout);
    TelCoColorCoder::PrintColorManual(std::cout, TelCoColorCoder::INCREASING);
    testPrintColorManual(25, TelCoColorCoder::INCREASING);

    TelCoColorCoder::PrintColorManual(std::cout, TelCoColorCoder::DECREASING);
    testPrintColorManual(25, TelCoColorCoder::DECREASING);

    return 0;
}
