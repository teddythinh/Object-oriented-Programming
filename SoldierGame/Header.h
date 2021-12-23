#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

// Forward declaration

// --- Types of soldier ---
class Character;
class Swordman;
class Knight;
class Spikeman;

// --- Visitor design pattern ---
class IVisitor;

// --- State of soldier ---
class State;
class NormalState;
class ThreeSwordmanState;
class ThreeKnightState;
class ThreeSpikemanState;

// --- Observer design pattern (Game / Rule / Player) ---
class Game;
class Player;
class Rule;
class ThreeSwordmanRule;
class ThreeKnightRule;
class ThreeSpikemanRule;

// --- Random Number ---
class RandomIntegerGenerator;


// Declaration

class RandomIntegerGenerator {
public:
    int next();
    int next(int);
    int next(int, int);
};

class Character {
protected:
    int _hp;
    int _atk;
    State* _state;
public:
    Character(int hp, int atk);

    int hp();
    int atk();

    void setState(State*);
    void setHp(int);
    void setAtk(int);
    bool isAlive();

    virtual void attack(Character* opponent) = 0;
    virtual string toString() = 0;
};

class IVisitor {
public:
    virtual void attack(Swordman&) = 0;
    virtual void attack(Knight&) = 0;
    virtual void attack(Spikeman&) = 0;

    virtual void hitBy(Swordman&) = 0;
    virtual void hitBy(Knight&) = 0;
    virtual void hitBy(Spikeman&) = 0;

    void select(Character*);
};

class Swordman : public Character, public IVisitor {
public:
    Swordman(int, int);

    string toString();

    void attack(Swordman&);
    void attack(Knight&);
    void attack(Spikeman&);
    void attack(Character*);

    void hitBy(Swordman&);
    void hitBy(Knight&);
    void hitBy(Spikeman&);

};

class Knight : public Character, public IVisitor {
public:
    Knight(int, int);

    string toString();

    void attack(Swordman&);
    void attack(Knight&);
    void attack(Spikeman&);
    void attack(Character*);

    void hitBy(Swordman&);
    void hitBy(Knight&);
    void hitBy(Spikeman&);
};

class Spikeman : public Character, public IVisitor {
public:
    Spikeman(int, int);

    string toString();

    void attack(Swordman&);
    void attack(Knight&);
    void attack(Spikeman&);
    void attack(Character*);

    void hitBy(Swordman&);
    void hitBy(Knight&);
    void hitBy(Spikeman&);
};

class State {
public:
    virtual int transfromHp(int old) = 0;
    virtual int transfromAtk(int old) = 0;
};

class NormalState : public State {
public:
    int transfromHp(int old);
    int transfromAtk(int old);
};

class ThreeSwordmanState : public State {
public:
    int transfromHp(int old);
    int transfromAtk(int old);
};

class ThreeKnightState : public State {
public:
    int transfromHp(int old);
    int transfromAtk(int old);
};

class ThreeSpikemanState : public State {
public:
    int transfromHp(int old);
    int transfromAtk(int old);
};

class Player {
public:
    vector<Character*> _pieces;

    typedef void (Game::* checkCallBack) (Player*);
    checkCallBack checker = NULL;
public:
    void add(Character*);
    string toString();
};

class Game {
private:
    Player _blueTeam;
    Player _redTeam;

    vector<Rule*> _rules;
public:
    Game();
    void start();
    void play();
    //string attack(Player&, Player&);

    void checkRule(Player*);
    void apply(Player*);
    string toString();
};

class Rule {
public:
    virtual bool satisfyWith(Player*) = 0;
    virtual void apply(Player*) = 0;
};

class ThreeSwordmanRule : public Rule {
public:
    bool satisfyWith(Player*);
    void apply(Player*);
};

class ThreeKnightRule : public Rule {
public:
    bool satisfyWith(Player*);
    void apply(Player*);
};

class ThreeSpikemanRule : public Rule {
public:
    bool satisfyWith(Player*);
    void apply(Player*);
};

#endif

