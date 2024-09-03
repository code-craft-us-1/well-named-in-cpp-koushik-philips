#include "ColorPair.h"

namespace TelCoColorCoder
{
    const char* MajorColorNames[] = {
       "White", "Red", "Black", "Yellow", "Violet"
    };

    const char* MinorColorNames[] = {
      "Blue", "Orange", "Green", "Brown", "Slate"
    };

    const int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    ColorPair::ColorPair(MajorColor major, MinorColor minor) :
                         majorColor(major), minorColor(minor)
    {}
    MajorColor ColorPair::getMajor() 
    {
        return majorColor;
    }
    MinorColor ColorPair::getMinor() 
    {
        return minorColor;
    }
    std::string ColorPair::ToString()
    {
        std::string colorPairStr = MajorColorNames[majorColor];
        colorPairStr += " ";
        colorPairStr += MinorColorNames[minorColor];
        return colorPairStr;
    }
    
    ColorPair GetColorFromPairNumber(int pairNumber) {
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

    void PrintColorManual()
    {
        std::cout << std::endl << "***** Color Manual *****" << std::endl;
        for (int ii = 1; ii <= numberOfMajorColors * numberOfMinorColors; ii++)
        {
            ColorPair clrPair = GetColorFromPairNumber(ii);
            std::cout.width(15);
            std::cout << clrPair.ToString();
            std::cout.width(8);
            std::cout << ii << std::endl;
        }
    }
}