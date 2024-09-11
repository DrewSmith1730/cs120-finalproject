//
// Created by Drew Smith on 4/30/21.
//
#include "graphics.h"
#include "rect.h"
#include "circle.h"
#include <iostream>
#include <vector>

GLdouble width, height;
int wd;
using namespace std;

Rect user;
Rect user2;
Rect midbar;
Rect ground;
Rect platform1;
vector<Rect> lev1;
vector<Rect> lev2;
vector<Rect> lev3;

const color skyBlue(77/255.0, 213/255.0, 240/255.0);
const color grassGreen(26/255.0, 176/255.0, 56/255.0);
const color white(1, 1, 1);
const color brickRed(201/255.0, 20/255.0, 20/255.0);
const color darkBlue(1/255.0, 110/255.0, 214/255.0);
const color purple(119/255.0, 11/255.0, 224/255.0);
const color black(0, 0, 0);
const color magenta(1, 0, 1);
const color orange(1, 163/255.0, 22/255.0);
const color cyan (0, 1, 1);

void init() {
    width = 1000;
    height = 1000;
    initUsers();
    initGameWorld();
    initLevel1();
    initLevel2();
    initLevel3();
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void initGameWorld(){
    // bar to seperate maps
    midbar.setColor(white);
    midbar.setSize(width/2, 5);
    midbar.setCenter(width/2, height/2);

    // floor
    ground.setColor(white);
    ground.setSize(width, 7);
    ground.setCenter(width/2, height-3);

    // platform on pole
    platform1.setColor(white);
    platform1.setSize(100, 5);
    platform1.setCenter(width/2, 902);
}

void initLevel1(){
    dimensions size = {110, 5};
    dimensions goal = {25, 25};
    lev1.push_back(Rect(white, 700, 820, size));
    lev1.push_back(Rect(white, 925, 740, size));
    lev1.push_back(Rect(white, 700, 700, size));
    lev1.push_back(Rect(white, 400, 750, size));
    lev1.push_back(Rect(white, 275, 640, size));
    lev1.push_back(Rect(white, 50, 570, size));
    lev1.push_back(Rect(darkBlue, width/2, height/2-15, goal));
}

void initLevel2(){
    dimensions size = {70, 5};
    dimensions goal = {25,25};
    lev2.push_back(Rect(white, 700, 820, size));
    lev2.push_back(Rect(white, 925, 740, size));
    lev2.push_back(Rect(white, 700, 700, size));
    lev2.push_back(Rect(white, 400, 750, size));
    lev2.push_back(Rect(white, 275, 640, size));
    lev2.push_back(Rect(white, 50, 570, size));
    lev2.push_back(Rect(white, 400, 420, size));
    lev2.push_back(Rect(white, 600, 420, size));
    lev2.push_back(Rect(white, 500, 300, size));
    lev2.push_back(Rect(white, 300, 230, size));
    lev2.push_back(Rect(white, 120, 135, size));
    lev2.push_back(Rect(white, 20, 55, size));
    lev2.push_back(Rect(darkBlue, 20, 40, goal));
}

void initLevel3(){
    dimensions size = {25, 5};
    dimensions goal = {25,25};
    lev3.push_back(Rect(white, 700, 820, size));
    lev3.push_back(Rect(white, 925, 740, size));
    lev3.push_back(Rect(white, 700, 700, size));
    lev3.push_back(Rect(white, 400, 750, size));
    lev3.push_back(Rect(white, 275, 640, size));
    lev3.push_back(Rect(white, 50, 570, size));
    lev3.push_back(Rect(white, 400, 420, size));
    lev3.push_back(Rect(white, 600, 420, size));
    lev3.push_back(Rect(white, 500, 300, size));
    lev3.push_back(Rect(white, 300, 230, size));
    lev3.push_back(Rect(white, 120, 135, size));
    lev3.push_back(Rect(white, 20, 55, size));
    lev3.push_back(Rect(darkBlue, 20, 40, goal));
}

// user init
void initUsers(){
    // make the player on the right and left
    user.setColor(cyan);
    user.setSize(20, 20);
    user.setCenter(980, 980);
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE (unless you're on a Mac running Catalina)

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

    /*
     * Draw here
     */

    // stuff that is on every screen
    user.draw();
    midbar.draw();
    ground.draw();
    platform1.draw();

    // start screen
    if(user.getSC() == start){
        string message3 = "Platformer";
        glColor3f(1,1,1);
        point2D center3 = {width/2, 100};
        glRasterPos2i(center3.x - (4 * message3.length()), center3.y + 7);
        for (const char &letter : message3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        string message2 = "Press space to start";
        glColor3f(1,1,1);
        point2D center2 = {width/2, 750};
        glRasterPos2i(center2.x - (4 * message2.length()), center2.y + 7);
        for (const char &letter : message2) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        string message = "Complete all 3 levels in one life";
        glColor3f(1,1,1);
        point2D center = {width/2, 200};
        glRasterPos2i(center.x - (4 * message.length()), center.y + 7);
        for (const char &letter : message) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        string message4 = "Good Luck Have Fun";
        glColor3f(1,1,1);
        point2D center4 = {width/2, 250};
        glRasterPos2i(center4.x - (4 * message4.length()), center4.y + 7);
        for (const char &letter : message4) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    // level 1
    if(user.getSC() == level1){
        string message3 = "Level 1";
        glColor3f(1,1,1);
        point2D center3 = {width/2, 100};
        glRasterPos2i(center3.x - (4 * message3.length()), center3.y + 7);
        for (const char &letter : message3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        for(int i = 0; i < lev1.size(); i++){
            lev1[i].draw();
        }
    }

    // level 2
    if(user.getSC() == level2){
        string message3 = "Level 2";
        glColor3f(1,1,1);
        point2D center3 = {width/2, 100};
        glRasterPos2i(center3.x - (4 * message3.length()), center3.y + 7);
        for (const char &letter : message3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        for(int i = 0; i < lev2.size(); i++){
            lev2[i].draw();
        }
    }

    // level 3
    if(user.getSC() == level3){
        string message3 = "Level 3";
        glColor3f(1,1,1);
        point2D center3 = {width/2, 100};
        glRasterPos2i(center3.x - (4 * message3.length()), center3.y + 7);

        for(int i = 0; i < lev3.size(); i++){
            lev3[i].draw();
        }
    }

    // Win scree
    if(user.getSC() == win){
        string message3 = "Congratulations you finished the game";
        glColor3f(1,1,1);
        point2D center3 = {width/2, 100};
        glRasterPos2i(center3.x - (4 * message3.length()), center3.y + 7);
        for (const char &letter : message3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        string message2 = "Press space to reset or escape to exit";
        glColor3f(1,1,1);
        point2D center2 = {width/2, 750};
        glRasterPos2i(center2.x - (4 * message2.length()), center2.y + 7);
        for (const char &letter : message2) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y){
    if(key == 27){
        glutDestroyWindow(wd);
        exit(0);
    }

    // if space is presed to start the game or reset it
    if(key == 32){
        if(user.getSC() == start){
            user.setSC(level1);
        } else {
            user.setSC(start);
            user.setCenter(980, 980);
        }
    }
    if(key == 119){
        // jump
        user.setYVelocity(-7);
        user.setIsJump(yes);
    }
    if(key == 97){
        // a key move left
        user.moveX(-20);
    }
    if(key == 100){
        // d key move right
        user.moveX(20);
    }

    // up and down for left player will be w and s
    glutPostRedisplay();
}


void kbdS(int key, int x, int y) {
    switch(key) {
        // up and down for right player will be up and down arrow keys
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:
            // set right and left velocity
            user.moveX(-20);
            // set key pressed to true
            break;
        case GLUT_KEY_RIGHT:
            user.moveX(20);
            break;
        case GLUT_KEY_UP:
            user.setYVelocity(-7);
            user.setIsJump(yes);
            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {

    glutPostRedisplay();
}

void timer(int dummy) {
    // jump
    if (user.getIsJump() == yes && user.getJTime() != 20) {
        user.moveY(user2.getYVelocity());
        user.incrimentJTime();
    }
    if (user.getJTime() == 20) {
        user.setIsJump(no);
        user.setJTime(0);
        // reset downward velocity to pull user back to ground
        user.setYVelocity(5);
    }

    // check colision to add gravity
    if(user.getRightX() > width){
        user.setCenterX(990);
    }

    if(user.getLeftX() < 0){
        user.setCenterX(10);
    }

    // ground
    if(user.isOverlapping(ground)){
        // sets y velocity to 0 and moves the cube out of the ground
        user.setCenterY(980);
    }

    // big bar in middle of map colision
    if(user.isOverlapping(midbar)){
        user.setYVelocity(0);
        if(user.getTopY() < platform1.getBottomY()){
            user.setYVelocity(7);
        }
        if(user.getIsJump() == yes){
            user.setYVelocity(-7);
        }
        user.setCenterY(midbar.getTopY()-17);
    }

    // main platform in all levels colision
    if(user.isOverlapping(platform1)){
        user.setYVelocity(0);
        if(user.getTopY() < platform1.getBottomY()){
            user.setYVelocity(7);
        }
        if(user.getIsJump() == yes){
            user.setYVelocity(-7);
        }
        user.setCenterY(884);
    }

    // level 1 colision
    if(user.getSC() == level1){
        for(int i = 0; i < lev1.size(); i++){
            if(lev1[i].getCenterX() == width/2 && lev1[i].getCenterY() == height/2-15 && user.isOverlapping(lev1[i])){
                user.setSC(level2);
                user.setCenter(980, 980);
            }
            if(user.isOverlapping(lev1[i])){
                user.setYVelocity(0);
                if(user.getTopY() < lev1[i].getBottomY()){
                    user.setYVelocity(7);
                }
                if(user.getIsJump() == yes){
                    user.setYVelocity(-7);
                }
                user.setCenterY(lev1[i].getTopY()-17);
            }
        }
    }

    // level 2 collision
    if(user.getSC() == level2){
        for(int i = 0; i < lev2.size(); i++){
            if(lev2[i].getCenterX() == 20 && lev2[i].getCenterY() == 40 && user.isOverlapping(lev2[i])){
                user.setSC(level3);
                user.setCenter(980, 980);
            }
            if(user.isOverlapping(lev2[i])){
                user.setYVelocity(0);
                if(user.getTopY() < lev2[i].getBottomY()){
                    user.setYVelocity(7);
                }
                if(user.getIsJump() == yes){
                    user.setYVelocity(-7);
                }
                user.setCenterY(lev2[i].getTopY()-17);
            }
        }
    }

    // level 3 collision
    if(user.getSC() == level3){
        for(int i = 0; i < lev3.size(); i++){
            if(lev3[i].getCenterX() == 20 && lev3[i].getCenterY() == 40 && user.isOverlapping(lev3[i])){
                user.setSC(win);
                user.setCenter(980, 980);
            }
            if(user.isOverlapping(lev3[i])){
                user.setYVelocity(0);
                if(user.getTopY() < lev3[i].getBottomY()){
                    user.setYVelocity(7);
                }
                if(user.getIsJump() == yes){
                    user.setYVelocity(-7);
                }
                user.setCenterY(lev3[i].getTopY()-17);
            }
        }
    }

    // finally move based off what ever collision is happening
    user.moveY(user.getYVelocity());

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Platformer Working Title" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}


