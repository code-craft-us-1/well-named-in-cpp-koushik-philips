#pragma once
#include "ColorPair.h"
#include <map>

namespace TelCoColorCoder
{
    using Map = std::map<int, std::string>;

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    Map GetColorManual();
    void PrintColorManual(Map colorManual);
}