#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "../include/Block.hpp"
#include "../include/Stone.hpp"
#include "../include/Ball.hpp"
#include "../include/Star.hpp"
#include "../include/Jump.hpp"
#include "../include/Map.hpp"

/**
 *  구현 고려해야하는 부분
 * 
 *  1. 스테이지마다 공의 위치 초기화
 *  2. 좌우 벽에 부딪혔을 때 좌우 이동 잠깐 동안 안 되게 하기   ==> 너무 딱따구리가 되어버림
 *  3. x 속도는 설정 함수가 있는데, y 속도 설정 함수는 리펙토링 귀찮아서 아직 구현 안 함
 *  4. 블록 삭제 구현
 *  5. 이미지 경로는 그냥 둬도 되는건가
 */

int main() {

    // 기본 요소
    sf::RenderWindow window;
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;
    int starCount = 0;
    Map map = Map(starCount);

    // 공 선언
    Ball ball = Ball(196.f, 512.f);

    float windowWidth = 2048.0, windowHeight = 1024.0;

    // 맵 생성
    std::vector<std::unique_ptr<Block>> blockList;
    blockList = map.createMap();

    // 배경 생성 => 칸 계산 좀 쉽게 하려고
    Block backGround = Block(0.f, 0.f, 32, 16, 128.f, "/home/gangd0dan/crossy-road/resource/BackGround.png");


    window.create(sf::VideoMode(2048, 1024), "Bounce Ball");

    while (window.isOpen()) {

        // 모든 별을 다 먹었을 시 화면 구현 필요
        // 현재는 단순히 게임을 강제 종료 하는 방법
        if (starCount == 0) {
            break;
        }

        // delta time으로 계산
        float dt = clock.restart().asSeconds();

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();   

        // 배경 그리기
        window.draw(backGround);

        // 블럭 그리기
        for (const auto& block : blockList) {
            if ((*block).isDraw) {
                window.draw(*block);
            }
        }

        if (ball.getIsStraight()) {
            ball.moveHorizontal(dt);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            ball.setIsVelocityX(-230.f);
            ball.moveHorizontal(dt);
            ball.setIsStraight(false);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            ball.setIsVelocityX(230.f);
            ball.moveHorizontal(dt);
            ball.setIsStraight(false);
        }

        // 공 그리기
        ball.updatePosition(dt, blockList, starCount);
        window.draw(ball);


        window.display();
    }

    return 0;

}