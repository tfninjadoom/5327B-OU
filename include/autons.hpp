#pragma once
/**
 * @file autons.hpp
 * @date 2023-10-11
 * 
 * @brief
 * !! PENDING !!
 */
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