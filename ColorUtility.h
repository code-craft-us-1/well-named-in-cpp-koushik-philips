#pragma once
#include "ColorPair.h"

namespace TelCoColorCoder
{
    enum PrintOrder {INCREASING, DECREASING};
    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    void PrintColorManual(std::ostream& out);
    void PrintColorManual(std::ostream& out, PrintOrder order);
}