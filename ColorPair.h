#pragma once
#include "StdAfx.h"
#include "ColorEnums.h"

namespace TelCoColorCoder
{
    extern int numberOfMajorColors;
    extern int numberOfMinorColors;

    class ColorPair
    {
    private:
        MajorColor majorColor;
        MinorColor minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor);
        MajorColor getMajor();
        MinorColor getMinor();
        std::string ToString();
    };

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
}