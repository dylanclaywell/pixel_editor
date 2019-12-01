#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "Cursor.h"

using namespace std;

bool Cursor::initialize(int cursorSize) {
    pixelSize = 32;

    return true;
}

void Cursor::draw() {
    cout << "X: " << x << ", Y: " << y << endl;
    al_draw_rectangle(
        x * pixelSize, 
        y * pixelSize, 
        (x * pixelSize) + 2, 
        (y * pixelSize) + 2, 
        al_map_rgb(255, 0, 0), 
        1
    );
}

void Cursor::update() {

}

void Cursor::moveLeft() {
    x--;
}

void Cursor::moveLeft(int units) {
    x -= units;
}

void Cursor::moveRight() {
    x++;
}

void Cursor::moveRight(int units) {
    x += units;
}

void Cursor::moveUp() {
    y--;
}

void Cursor::moveUp(int units) {
    y -= units;
}

void Cursor::moveDown() {
    y++;
}

void Cursor::moveDown(int units) {
    y += units;
}

// Accessors
int Cursor::getX() {
    return x;
}

int Cursor::getY() {
    return y;
}

void Cursor::setX(int newX) {
    x = newX;
}

void Cursor::setY(int newY) {
    y = newY;
}
