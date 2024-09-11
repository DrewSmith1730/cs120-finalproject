#ifndef GRAPHICSEXAMPLES_RECT_H
#define GRAPHICSEXAMPLES_RECT_H

#include "shape.h"

// add an enum for if the block is dead
enum screen{
    start = 0,
    level1 = 1,
    level2 = 2,
    level3 = 3,
    win = 4,
    loss = 5
};

enum isHit{
    alive = 0,
    dead = 1
};

enum isJump{
    yes = 0,
    no = 1
};

struct dimensions {
    double width;
    double height;

    /* Constructors */
    dimensions();
    dimensions(double w, double h);

    /* Overloaded Operator */
    friend std::ostream& operator << (std::ostream& outs, const dimensions &d);
};

class Rect : public Shape {
private:
    dimensions size;
    screen sc;
    isHit h;
    isJump j;
    int score;
    int jtime;

public:
    /* Constructors */
    Rect();
    explicit Rect(dimensions size);
    explicit Rect(color fill);
    explicit Rect(point2D center);
    Rect(color fill, point2D center);
    Rect(double red, double green, double blue, double alpha);
    Rect(double x, double y);
    Rect(double red, double green, double blue, double alpha, double x, double y);
    Rect(color fill, double x, double y);
    Rect(double red, double green, double blue, double alpha, point2D center);
    Rect(color fill, dimensions size);
    Rect(point2D center, dimensions size);
    Rect(color fill, point2D center, dimensions size);
    Rect(double red, double green, double blue, double alpha, dimensions size);
    Rect(double x, double y, dimensions size);
    Rect(double red, double green, double blue, double alpha, double x, double y, dimensions size);
    Rect(color fill, double x, double y, dimensions size);
    Rect(double red, double green, double blue, double alpha, point2D center, dimensions size);

    /* Destructor */
    virtual ~Rect() = default;

    /* Getters */
    dimensions getSize() const;
    double getWidth() const;
    double getHeight() const;
    double getLeftX() const override;
    double getRightX() const override;
    double getTopY() const override;
    double getBottomY() const override;
    screen getSC() const;
    isHit getIsHit() const;
    int getScore() const;
    isJump getIsJump() const;
    int getJTime() const;

    /* Setters */
    void setSize(dimensions size);
    void setSize(double width, double height);
    void setWidth(double width);
    void setHeight(double height);
    void setSC(screen sc);
    void setIsHit(isHit h);
    void changeSize(double deltaWidth, double deltaHeight);
    void changeWidth(double delta);
    void changeHeight(double delta);
    void setScore(int s);
    void setIsJump(isJump j);
    void setJTime(int jtime);
    void incrimentJTime();


    /* Check if two Rect objects are overlapping */
    bool isOverlapping(const Rect &r) const;

    /* Draw */
    void draw() const override;

};


#endif //GRAPHICSEXAMPLES_RECT_H
