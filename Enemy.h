#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
protected:
    int row;
    int col;
    int hp;
    int speed;

public:
    Enemy(int r, int h, int s);

    virtual void move();
    void takeDamage(int dmg);
    bool isDead();

    int getRow();
    int getCol();
    int getHP();
};

class NormalEnemy : public Enemy {
public:
    NormalEnemy(int r);
};

class FastEnemy : public Enemy {
public:
    FastEnemy(int r);
};

#endif
