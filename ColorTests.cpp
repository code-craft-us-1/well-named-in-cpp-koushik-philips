#include "ColorPair.h"
#include "ColorUtility.h"
#include <set>
#include <sstream>

void testNumberToPair(int pairNumber, 
    TelCoColorCoder::MajorColor expectedMajor, 
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(TelCoColorCoder::MajorColor major,
                      TelCoColorCoder::MinorColor minor, int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void testPrintColorManual(int expectedNumRows)
{
    std::stringstream ss;
    TelCoColorCoder::PrintColorManual(ss);

    std::string strLine, strMajorColor, strMinorColor;
    int numCurrColorPair = 0, numPrevColorPair = 0, countRows = 0;
    std::set<std::string> setColorPair;
    std::set<int> setColorNumber;
    while (std::getline(ss, strLine, '\n'))
    {
        std::istringstream inputStream(strLine);
        inputStream >> strMajorColor >> strMinorColor >> numCurrColorPair;
        std::string colorPairStr = strMajorColor + " " + strMinorColor;
        numPrevColorPair = (numPrevColorPair < numCurrColorPair) ? numCurrColorPair : 0;
        setColorPair.insert(colorPairStr);
        setColorNumber.insert(numCurrColorPair);
        countRows++;
    }
    assert(countRows == expectedNumRows);
    std::cout << "Prints " << expectedNumRows << " rows" << std::endl;
    assert((setColorPair.size() == expectedNumRows) && (setColorNumber.size() == expectedNumRows));
    std::cout << "No Color-pair duplicates, No Color-numbering duplicates" << std::endl;
    assert(numPrevColorPair != 0);
    std::cout << "Colors printed in sequence" << std::endl;
}
