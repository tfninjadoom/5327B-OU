#pragma once
#include "master.h"

namespace Autonomous {

    extern void left();
    extern void right();
    extern void skills();

    namespace Select {
        extern bool left;
        extern bool right;
        extern bool skills;
    } //namespace Select

} //namespace Autonomous