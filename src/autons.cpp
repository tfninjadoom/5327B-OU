/**
 * @file autons.cpp
 * @date 2023-10-11
 * 
 * @brief
 * !! PENDING !!
 */
#include "master.h"
#include <iostream>

namespace Autonomous {

    // forward declaration of selection
    Select selection;

    //------AUTONOMOUS FUNCTIONS-------//

    void close() {
        return;
    }

    void far() {
        return;
    }


    //--------SKILLS FUNCTIONS--------//

    void skills1() {
        return;
    }
    void skills2() {
        return;
    }
    void skills3() {
        return;
    }


    //---------SKILLS SELECTION--------//

    // call selected skills path
    void skills() { 
        if 
        (selection==Select::skills1) { skills1(); }
        else if 
        (selection==Select::skills2) { skills2(); }
        else if 
        (selection==Select::skills3) { skills3(); }
    }

    // Uses rotation to determine selected skills
    // {}
    // rotation method: 
    

} //namespace Autonomous