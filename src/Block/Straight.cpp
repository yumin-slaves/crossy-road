#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../include/Straight.hpp"

Straight::Straight(float x, float y, bool isRight) 
    : Block(x,y,1.f,1.f,64.f, 
        isRight ? "/home/gangd0dan/crossy-road/resource/StraightR.png" : "/home/gangd0dan/crossy-road/resource/StraightL.png"), isRight(isRight) {
}

bool Straight::getIsRight() {
    return isRight;
}