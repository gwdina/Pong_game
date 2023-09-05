/* CSCI 261: Final Project
 *
 * Author: Gordon DIna
 * Resources used (Office Hours(Connors office hours, helped with collision), SFML website (things related to sfml), lab 8A (got majority of the ball class), ):
 *
 * Allows the user to play pong with a random start up sound
 */

#include <fstream>          // for file streams (ifstream, ofstream)
#include <iomanip>          // for I/O Manipulators (precision, aligning, etc.)
#include <iostream>         // for standard input/output
#include <string>           // for string library
#include <vector>           // for vector library
#include <cstdlib>          // for srand(), rand()
#include <ctime>            // for time()

#include "Ball.h"
#include "Player.h"
using namespace std;// using the standard namespace

#include <SFML/Audio.hpp>                      // include the SFML Audio Library
#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
#include <SFML/System.hpp>
#include <SFML/Window.hpp>



using namespace sf;                             // using the sf namespace

int main() {
    //vector to be used to play the start up music
    vector<string> source;
    source.push_back("Start1.ogg");
    source.push_back("Start2.ogg");
    source.push_back("Start3.ogg");
    source.push_back("Start4.ogg");


    // create a RenderWindow object
    // specify the size to be 640x640
    // set the title to be "SFML Example Window"
    RenderWindow window( VideoMode(640, 640), "SFML Example Window" );





    // used for the movement inputs by the user
    float dt;
    Clock dt_clock;

    const float movementspeed = 1000;

    //calls the Ball class and gives the speed/dircetion of the ball
    Ball anything(.12, .13);

    // calls the player class
    Player another;


    //calls the music class within the SFML, will pick a random music file from the vector. the propeties of the music can be changed via SFML knowelge
    sf::Music music;
    // Open it from an audio file
    if (!music.openFromFile(source[rand() % source.size()]))
    {
        // error...
    }
    // Change some parameters
    music.setPitch(-1);           // increase the pitch
    music.setVolume(50);         // reduce the volume
    // Play it
    music.play();

    // while our window is open, keep it open
    // this is our draw loop
    while( window.isOpen() ) {
        window.clear( Color::Black );           // clear the contents of the old frame
                                                // by setting the window to black
        dt = dt_clock.restart().asSeconds();



        // takes keyboard inputs from user and sends to the Player class to modify the players posiion
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            another.movement('u', -movementspeed * dt);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            another.movement('d', movementspeed * dt);
        }



        //renders the ball
        window.draw(another.getShape());

        //keeps the ball moving
        anything.updatePosition(another);

        //renders the player
        window.draw(anything.getShape());


        window.display();                       // display the window

        //****************************************
        // HANDLE EVENTS BELOW HERE
        //****************************************
        Event event;
        while( window.pollEvent(event) ) {      // ask the window if any events occurred
            if( event.type == Event::Closed ) { // if event type is a closed event
                                                // i.e. they clicked the X on the window
                window.close();                 // then close our window
            }
        }
    }


    return EXIT_SUCCESS;                        // report our program exited successfully

}
