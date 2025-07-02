#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../include/Map.hpp"

Map::Map(int& starCount) : tempStarCount(starCount) {

}

std::vector<std::unique_ptr<Block>> Map::createMap() {

    blockList.push_back(std::make_unique<Stone>(0.f, 6.f, 1.f, 6.f, 64.f));
    blockList.push_back(std::make_unique<Stone>(0.f, 11.f, 5.f, 1.f, 64.f));
    blockList.push_back(std::make_unique<Stone>(6.f,11.f,3.f,1.f,64.f));

    blockList.push_back(std::make_unique<Stone>(12.f,7.f,3.f,1.f,64.f));
    blockList.push_back(std::make_unique<Stone>(16.f,7.f,3.f,1.f,64.f));

    blockList.push_back(std::make_unique<Stone>(20.f,11.f,2.f,1.f,64.f));
    blockList.push_back(std::make_unique<Stone>(24.f,3.f,3.f,1.f,64.f));
    
    blockList.push_back(std::make_unique<Needle>(4.f, 10.f, 1.f,1.f));
    blockList.push_back(std::make_unique<Needle>(20.f, 10.f, 2.f,1.f));

    blockList.push_back(std::make_unique<Jump>(1.f, 9.f));
    blockList.push_back(std::make_unique<Jump>(9.f,11.f));
    blockList.push_back(std::make_unique<Jump>(22.f,11.f));
    blockList.push_back(std::make_unique<Jump>(23.f,7.f));

    blockList.push_back(std::make_unique<Straight>(19.f , 7.f ,true));
    blockList.push_back(std::make_unique<Straight>(26.f , 8.f ,false));

    blockList.push_back(std::make_unique<Star>(0.f,5.f, tempStarCount));
    blockList.push_back(std::make_unique<Star>(6.f,10.f,tempStarCount));
    blockList.push_back(std::make_unique<Star>(14.f,6.f,tempStarCount));
    blockList.push_back(std::make_unique<Star>(15.f,5.f,tempStarCount));
    blockList.push_back(std::make_unique<Star>(16.f,6.f,tempStarCount));
    blockList.push_back(std::make_unique<Star>(26.f,2.f,tempStarCount));
    blockList.push_back(std::make_unique<Star>(12.f,8.f,tempStarCount));
    blockList.push_back(std::make_unique<Star>(13.f,8.f,tempStarCount));
    blockList.push_back(std::make_unique<Star>(14.f,8.f,tempStarCount));

    return std::move(blockList);
}