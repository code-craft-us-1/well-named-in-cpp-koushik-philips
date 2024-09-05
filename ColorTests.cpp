#include "ColorPair.h"
#include "ColorUtility.h"
#include <set>

namespace TelCoColorCoder
{
    extern int numberOfMajorColors;
    extern int numberOfMinorColors;
}

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

void testColorManual(int expectedNumRows)
{
    auto colorManual = TelCoColorCoder::GetColorManual(); 
    assert(colorManual.size() == expectedNumRows); // color-Numbers are unique (no duplication)
    std::set<std::string> colors;
    for (const auto& item : colorManual)
    {
        colors.insert(item.second);
    }
    assert(colors.size() == expectedNumRows); // color-pairs are unique (no duplication)
    std::cout << "Expected Number of rows match " << std::endl;
    std::cout << "No duplication in either color-Numbers or color-pairs " << std::endl;
}

void testColorManualPrint()
{

}



