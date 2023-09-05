//
// Created by gwdin on 12/5/2021.
//

#ifndef SFML_TEMPLATE_PLAYER_H
#define SFML_TEMPLATE_PLAYER_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;

using namespace sf;

class Player {
public:
    /** @brief creates a default constructor
   * @desc get xDir and yDir via this parameter as well sets the size, position, and color of the paddle
   */
    Player();
    /** @brief vairable name for the Rectangle/player
   * @desc will just return a shape from private that gives access to RectangleShape
    * @return the varible used to give access to the Rectangle
   */
    RectangleShape getShape();
    /** @brief the movement inputed by the player
   * @desc will grab the param from the letter pressed by the player a move them accordingly
   * @param LHS direction the ball is going
   * @param RHS speed of the ball
    * @return the new positsion of the paddle
   */
    void movement(char direction, float speed);
    /** @brief grabbing x coord
   * @desc will get the x coord of the paddle to be used for collision of the ball in the ball class
    * @return the current x value of the paddle
   */
    float positionx();
    /** @brief grabbing y coord
   * @desc will get the y coord of the paddle to be used for collision of the ball in the ball class
    * @return the current y value of the paddle
   */
    float positiony();


private:
    RectangleShape _play;




};




#endif //SFML_TEMPLATE_PLAYER_H
