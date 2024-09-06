#pragma once
#include "ColorPair.h"

namespace TelCoColorCoder
{
    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    void PrintColorManual(std::ostream& out);
}