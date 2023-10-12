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

    enum class Select {
	    left,
	    right,
	    skills1,
        skills2,
        skills3,
    }; //enum Select

    extern Select selection;

} //namespace Autonomous