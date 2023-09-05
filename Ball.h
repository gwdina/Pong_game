//
// Created by gwdin on 12/5/2021.
//

#ifndef SFML_TEMPLATE_BALL_H
#define SFML_TEMPLATE_BALL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Player.h" // class for collision
using namespace std;

using namespace sf;

class Ball {
public:


    /** @brief ball collision and movement
   * @desc this will make the ball move and will make it bounce if it comes into contact with the player/walls
     * @param the player class
   * @return the new position/direction of the ball
   */
    void updatePosition(Player play);
    /** @brief grabs xDir
   * @desc gets access to XDir variable
   * @return the xDir given in the main
   */
    double getX();
    /** @brief grabs yDir
   * @desc gets access to yDir variable
   * @return the yDir given in the main
   */
    double getY();
    /** @brief creates a default constructor
   * @desc get xDir and yDir via this parameter as well sets the radius, position, and color of the ball
   * @param LHS x direction of the ball
   * @param RHS y direction of the ball
   */
    Ball(double _xDir, double _yDir);
    /** @brief vairable name for the circle
   * @desc will just return a shape from private that gives access to CircleShape
    * @return the varible used to give access to the circle
   */
    CircleShape getShape();



private:
    CircleShape _shape;
    double _xDir;
    double _yDir;


};


#endif //SFML_TEMPLATE_BALL_H
