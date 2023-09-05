/* CSCI 261: Final Project
 *
 * Author: Gordon DIna
 * Resources used (Office Hours(Connors office hours, helped with collision), SFML website (things related to sfml), lab 8A (got majority of the ball class), ):
 *
 * Runs the ball movement and collsion, as well ends the program if the player fails to hit
 */

//
// Created by gwdin on 12/5/2021.
//

#include "Ball.h"
#include "Player.h"



CircleShape Ball:: getShape(){
    return _shape;
}
double Ball::getX(){
    return _xDir;
}

double Ball::getY(){
    return _yDir;
}
void Ball::updatePosition(Player play){
    double newX;
    double newY;

    if((_shape.getPosition().x > 640-_shape.getRadius()) ||(_shape.getPosition().x < 0)){
        _xDir *= -1;
    }
    if((_shape.getPosition().y > 640-_shape.getRadius()) ||(_shape.getPosition().y < 0)){
        _yDir *= -1;
    }

    if (_shape.getPosition().x < play.positionx()){
        if (_shape.getPosition().y <= play.positiony() + play.getShape().getLocalBounds().height
        && _shape.getPosition().y >= play.positiony()){
           _xDir *= -1;
           auto currentPosition = _shape.getPosition();
           _shape.setPosition(currentPosition.x + 2, currentPosition.y);
            // It hit the paddle
            cout << "HIT" << endl;
        }
        else{
            _xDir *= 1;
        }
    }

    if(_shape.getPosition().x < 0){
        cout << "Game Over" << endl;
        exit(0);

    }


    newX = _shape.getPosition().x + xDir;
    newY = _shape.getPosition().y + yDir;

    _shape.setPosition(newX, newY);


}
//vector<Music*>& sounds
Ball::Ball(double _xDir, double _yDir){
    this->_xDir = _xDir;
    this->_yDir = _yDir;
    _shape.setRadius(9);
    _shape.setPosition(300, 300);
    _shape.setFillColor(Color::White);
}


