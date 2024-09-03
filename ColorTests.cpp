#include "ColorPair.h"

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void testPrintColorManual()
{
    std::cout << std::endl << "***** Color Manual *****" << std::endl;
    for (int ii = 1; ii <= TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors; ii++)
    {
        TelCoColorCoder::ColorPair clrPair = TelCoColorCoder::GetColorFromPairNumber(ii);
        std::cout.width(15);
        std::cout << clrPair.ToString();
        std::cout.width(8);
        std::cout << ii << std::endl;
    }
}

