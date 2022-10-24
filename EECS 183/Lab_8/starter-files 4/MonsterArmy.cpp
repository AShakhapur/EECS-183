/**
 * MonsterArmy.cpp
 *
 * Abhay Shakhapur
 * abhaysh
 *
 * EECS 183: Lab 10 - Exam 2 Review
 *
 * NOTE: You WILL submit this file to the autograder
 */

#include "Monster.h"
#include "MonsterArmy.h"
#include <iostream>
#include <string>
using namespace std;

MonsterArmy::MonsterArmy() {
    currentSize = 0;
}

bool MonsterArmy::spawnMonster(string type, int points) {

    Monster soldier;
    
    soldier.setData(type, points);
    
    if (!type.empty() && points >= 0){
        if (MAX_ARMY_SIZE>currentSize){
            army[currentSize] = soldier;
            currentSize++;
            return true;
        }
    }

	return false;
}


int MonsterArmy::pointsByType(string type) {
    int total;
    if (!type.empty()){
        for (int i = 0; i<currentSize; i++){
            if (army[i].getType() == type){
                total = total + army[i].getHitPoints();
            }
        }
    }
    
    return total;
}

