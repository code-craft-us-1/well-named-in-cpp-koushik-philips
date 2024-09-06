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

void testPrintColorManual(int expectedNumRows, TelCoColorCoder::PrintOrder order)
{
    std::stringstream ss;
    TelCoColorCoder::PrintColorManual(ss,order);

    std::string strLine, strMajorColor, strMinorColor;
    int numCurrColorPair = 0, countRows = 0;
    int numPrevColorPair = (order == TelCoColorCoder::INCREASING) ? 0 : 100;
    std::set<std::string> setColorPair;
    std::set<int> setColorNumber;
    while (std::getline(ss, strLine, '\n'))
    {
        std::istringstream inputStream(strLine);
        inputStream >> strMajorColor >> strMinorColor >> numCurrColorPair;
        std::string colorPairStr = strMajorColor + " " + strMinorColor;
        numPrevColorPair = (order == TelCoColorCoder::INCREASING) ? ((numPrevColorPair < numCurrColorPair) ? numCurrColorPair : -1) : ((numPrevColorPair > numCurrColorPair) ? numCurrColorPair : -1); //-1 is error code
        setColorPair.insert(colorPairStr);
        setColorNumber.insert(numCurrColorPair);
        countRows++;
    }
    assert(countRows == expectedNumRows);   // Test for: Number of rows printed
    std::cout << "Prints " << expectedNumRows << " rows" << std::endl;
    assert((setColorPair.size() == expectedNumRows) && (setColorNumber.size() == expectedNumRows)); // Test for: Duplicates
    std::cout << "No Color-pair duplicates, No Color-numbering duplicates" << std::endl;
    assert(numPrevColorPair != -1);         // Test for: Print in sequence
    std::cout << "Colors printed in sequence" << std::endl;
}
