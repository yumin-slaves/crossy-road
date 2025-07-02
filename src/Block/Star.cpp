#include <iostream>
#include <SFML/Graphics.hpp>

#include "../../include/Star.hpp"

Star::Star(float x, float y, int& starCount) 
    : Block(x,y, 1.f, 1.f,64.f,"/home/gangd0dan/crossy-road/resource/Star.png"){

    starCount++;
}