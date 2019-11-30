#ifndef _CURSOR_H_
#define _CURSOR_H_

class Cursor {
    private:
        int x, y, pixelSize;

    public:
        bool initialize(int);
        void update();
        void draw();

        void moveLeft();
        void moveLeft(int);

        void moveRight();
        void moveRight(int);

        void moveUp();
        void moveUp(int);

        void moveDown();
        void moveDown(int);

        // Accessors
        int getX();
        int getY();
        
        void setX(int);
        void setY(int);
};

#endif
