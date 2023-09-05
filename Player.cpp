/* CSCI 261: Final Project
 *
 * Author: Gordon DIna
 * Resources used (Office Hours(Connors office hours, helped with collision), SFML website (things related to sfml), lab 8A (got majority of the ball class), ):
 *
 * builds the paddle, and looks at the keyboard input from the user and tells which way the paddle should go. Also used in the Ball class to check for collision
 */

//
// Created by gwdin on 12/5/2021.
//

#include "Player.h"

RectangleShape Player:: getShape(){
    return _play;
}


Player::Player(){
    _play.setSize( Vector2f( 10, 100 ) );
    _play.setPosition(115, 280); //y:300 = contact, 280
    _play.setFillColor(Color::White);

}

void Player::movement(char direction, float speed){
    if (direction == 'u'){
        _play.move(0, speed);
    }
    if (direction == 'd'){
        _play.move(0, speed);
    }

    if(_play.getPosition().y < 0){
        _play.setPosition(_play.getPosition().x, 0);
    }
    if(_play.getPosition().y + _play.getGlobalBounds().height > 640){
        _play.setPosition(_play.getPosition().x, 640 - _play.getGlobalBounds().height);
    }

}
float Player::positionx(){
    return _play.getPosition().x;

}

float Player::positiony(){
    return _play.getPosition().y;

}


