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

    Map GetColorManual()
    {
        Map colorManual;
        for (int ii = 1; ii <= TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors; ii++)
        {
            ColorPair clrPair = GetColorFromPairNumber(ii);
            colorManual.emplace(std::make_pair(ii, clrPair.ToString()));
        }
        return colorManual;
    }

    void PrintColorManual(Map colorManual)
    {        
        std::cout << std::endl << "***** Color Manual *****" << std::endl;
        static int previous = 0;
        for (const auto& item : colorManual)
        {
            std::cout << std::setw(15) << item.second << std::setw(8) <<  item.first << std::endl;
        }
        std::cout << std::endl;
    }
}