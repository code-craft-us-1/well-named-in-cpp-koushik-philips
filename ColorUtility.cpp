#include "ColorUtility.h"
#include <iomanip>
namespace TelCoColorCoder
{
    extern int numberOfMajorColors;
    extern int numberOfMinorColors;

    ColorPair GetColorFromPairNumber(int pairNumber) 
    {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor =
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor)
    {
        return major * numberOfMinorColors + minor + 1;
    }
    
    // Original
    void PrintColorManual(std::ostream& out)
    {        
        std::cout << std::endl << "***** Color Manual *****" << std::endl;
        for (int ii = 1; ii <= TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors; ii++)
        {
            ColorPair clrPair = GetColorFromPairNumber(ii);
            out << std::setw(15) << clrPair.ToString() << std::setw(8) << ii << std::endl;
        }
        std::cout << std::endl;
    }
    
    // Overloaded
    void PrintColorManual(std::ostream& out, PrintOrder order)
    {
        std::cout << std::endl << "***** Color Manual *****" << std::endl;
        int startIndex = (order == PrintOrder::INCREASING) ? 1 : (TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors);
        int endIndex = (order == PrintOrder::INCREASING) ? (TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors + 1) : 0;
        while (startIndex != endIndex)
        {
            ColorPair clrPair = GetColorFromPairNumber(startIndex);
            out << std::setw(15) << clrPair.ToString() << std::setw(8) << startIndex << std::endl;
            startIndex = (order == PrintOrder::INCREASING) ? (startIndex + 1) : (startIndex - 1);
        }        
        std::cout << std::endl;
    }
}