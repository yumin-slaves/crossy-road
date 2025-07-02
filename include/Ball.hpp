#ifndef BALL_HPP
#define BALL_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Block.hpp"

class Ball : public sf::Drawable, public sf::Transformable{

    public:

        Ball(float x, float y);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void updatePosition(float dt, std::vector<std::unique_ptr<Block>>& blockList, int& starCount);
        void moveHorizontal(float dt);
        
        bool getIsStraight();
        void setIsStraight(bool isStraight);
        void setIsVelocityX(float velocityX);
        
    private:
        sf::Vector2f position;
        sf::Vector2f startingPosition;
        sf::Vector2f gravity;
        sf::Vector2f velocity;

        sf::CircleShape ball;

        bool isStraight;

};

#endif