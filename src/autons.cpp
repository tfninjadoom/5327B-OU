/**
 * @file autons.cpp
 * @date 2023-10-11
 * 
 * @brief
 * !! PENDING !!
 */
#include "master.h"

namespace Autonomous {

    // forward declaration of selection
    Select selection;

    //------AUTONOMOUS FUNCTIONS-------//

    void left() {
        return;
    }

    void right() {
        return;
    }


    //--------SKILLS FUNCTIONS--------//

    void skills1() {
        chassis.setPose(-54, -50, -108);
        //matchload
        pros::Task([=]{
            Wing::right(true);
            pros::delay(100);
            Wing::right(false);
        });
        Slapper::turnon(true);
        pros::delay(26000);
        Slapper::turnon(false);
        //go back
        chassis.moveTo(-61, -37, 180, 800, false, false, 40, 0.5);
        chassis.moveTo(-62, -24, 180, 1000, false, false, 40, 0.2);
        //go with bot to the other side and bash alley 2-3 times
        chassis.moveTo(-43, -64, 135, 800, false, true, 40, 0.4);
        chassis.moveTo(-15, -64, -90, 800, false, false, 40, 0.1);
        chassis.moveTo(34, -64, -90, 900, false, false, 40, 0.1);
        chassis.moveTo(40, -64, -135, 700, false, false, 40, 0.4);
        chassis.moveTo(64, -28, 180, 800, false, false, 40, 0.4);
        chassis.moveTo(40, -80, -135, 700, false, true, 40, 0.4);
        chassis.moveTo(62, -28, 180, 800, false, false, 40, 0.4);
        chassis.moveTo(48, -54, -135,600, false, true, 40, 0.7);
        chassis.moveTo(20, -40, -50, 1000, false, true, 40,0.3);
        chassis.turnTo(5,-57, 900, false, false, 70);
        Wing::left(true);
        Wing::right(true);
        chassis.moveTo(70, -25, -90, 1200, false, false, 40,0.7, 90);
        chassis.moveTo(20, -40, -150, 3000, true, true, 40,0.3);
        chassis.waitUntilDist(10);
        Wing::left(false);
        Wing::right(false);
        chassis.waitUntilDist(100000);
        chassis.moveTo(25, -20, 180, 3000, false, false, 40,0.6);
        chassis.turnTo(-50, 0, 600);
        Wing::left(true);
        Wing::right(true);
        chassis.moveTo(70, -20, -90, 900, false, false, 40, 0.1);
        chassis.moveTo(15,-7, 90, 900, true, true, 40, 0.1,80);
        chassis.waitUntilDist(10);
        Wing::left(false);
        Wing::right(false);
        chassis.waitUntilDist(100000);
        
        chassis.turnTo(0, 50, 700);
        chassis.moveTo(25, 48, -45, 800, false, true, 40, 0.2);
        Wing::left(true);
        Wing::right(true);
        chassis.moveTo(70, -25, -90, 1200, false, false, 40, 0.5);
        chassis.moveTo(50, 20, 115, 700, true, true, 40, 0.3);
        chassis.waitUntilDist(10);
        Wing::left(false);
        Wing::right(false);
        chassis.waitUntilDist(100000);
        chassis.moveTo(70, 45, 150, 1200, false, true, 40, 0.4, 90);
        chassis.turnTo(27, 60, 700, false, false);
        chassis.moveTo(68, 0, 0, 1200, false, false, 40, 0.6);
        chassis.moveTo(70, 45, -90, 900, true, true, 40, 0.4);
        chassis.moveTo(68, 0, 0, 1200, false, false, 40, 0.6);
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

} //namespace Autonomous