#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Block.hpp"
#include "Stone.hpp"
#include "Ball.hpp"
#include "Star.hpp"
#include "Jump.hpp"
#include "Straight.hpp"
#include "Needle.hpp"

class Map {

    public : 
        Map(int& starCount);
        std::vector<std::unique_ptr<Block>> createMap();
    
    private :
        std::vector<std::unique_ptr<Block>> blockList;
        int& tempStarCount;

};

#endif