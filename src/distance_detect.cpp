#include "master.h"


double getDistanceInInches() {
    double distanceInMM = distance.get();
    return distanceInMM / 25.4;
}

bool detect() {
    double distanceInInches = getDistanceInInches();
    
    if (distanceInInches <= 2.0){
        return false;
    }
    else{
        return true;
    }
}