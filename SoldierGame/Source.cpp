#include "Header.h"

// Implementation
int RandomIntegerGenerator::next() {
    return rand() % 100;
}
int RandomIntegerGenerator::next(int max) {
    return rand() % max;
}
int RandomIntegerGenerator::next(int min, int max) {
    return rand() % (max - min + 1) + min;
}

Character::Character(int hp, int atk) {
    _hp = hp;
    _atk = atk;
    _state = new NormalState();
}

void IVisitor::select(Character* opponent) {
    if (typeid(*opponent) == typeid(Swordman)) {
        attack(*((Swordman*)opponent));
    }
    else if (typeid(*opponent) == typeid(Knight)) {
        attack(*((Knight*)opponent));
    }
    else if (typeid(*opponent) == typeid(Spikeman)) {
        attack(*((Spikeman*)opponent));
    }
}

int Character::hp() { return _state->transfromHp(_hp); }
int Character::atk() { return _state->transfromAtk(_atk); }

void Character::setHp(int value) { _hp = value > 0 ? value : 0; }
void Character::setAtk(int value) { _atk = value > 0 ? value : 0; }

bool Character::isAlive() { return _hp > 0; }
void Character::setState(State* state) { _state = state; }


// --- Swordman --- 
Swordman::Swordman(int hp, int atk) : Character(hp, atk) {}

string Swordman::toString() {
    stringstream ss;
    ss << "Swordman (HP " << hp() << ", ATK " << atk() << ")";
    string result = ss.str();
    return result;
}

void Swordman::attack(Swordman& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}

void Swordman::attack(Knight& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}

void Swordman::attack(Spikeman& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}

void Swordman::attack(Character* opponent) {
    select(opponent);
}

void Swordman::hitBy(Swordman& opponent) { _hp = _hp - opponent.atk(); }
void Swordman::hitBy(Knight& opponent) { _hp = _hp - opponent.atk() + 10; }
void Swordman::hitBy(Spikeman& opponent) { _hp = _hp - opponent.atk(); }


// --- Knight ---
Knight::Knight(int hp, int atk) : Character(hp, atk) {}

string Knight::toString() {
    stringstream ss;
    ss << "Knight (HP " << hp() << ", ATK " << atk() << ")";
    string result = ss.str();
    return result;
}

void Knight::attack(Swordman& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}

void Knight::attack(Knight& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}

void Knight::attack(Spikeman& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}

void Knight::attack(Character* opponent) {
    select(opponent);
}

void Knight::hitBy(Swordman& opponent) { _hp = _hp - opponent.atk(); }
void Knight::hitBy(Knight& opponent) { _hp = _hp - opponent.atk(); }
void Knight::hitBy(Spikeman& opponent) { _hp = _hp - opponent.atk() + 25; }

// --- Spikeman ---
Spikeman::Spikeman(int hp, int atk) : Character(hp, atk) {}

string Spikeman::toString() {
    stringstream ss;
    ss << "Spikeman (HP " << hp() << ", ATK " << atk() << ")";
    string result = ss.str();
    return result;
}

void Spikeman::attack(Swordman& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}

void Spikeman::attack(Knight& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}

void Spikeman::attack(Spikeman& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}

void Spikeman::attack(Character* opponent) {
    select(opponent);
}

void Spikeman::hitBy(Swordman& opponent) { _hp = _hp - opponent.atk() + 12; }
void Spikeman::hitBy(Knight& opponent) { _hp = _hp - opponent.atk(); }
void Spikeman::hitBy(Spikeman& opponent) { _hp = _hp - opponent.atk(); }

// --- State ---
int NormalState::transfromHp(int old) { return old; }
int NormalState::transfromAtk(int old) { return old; }

int ThreeSwordmanState::transfromHp(int old) { return old; }
int ThreeSwordmanState::transfromAtk(int old) { return old * 3; }

int ThreeKnightState::transfromHp(int old) { return old; }
int ThreeKnightState::transfromAtk(int old) { return old * 2; }

int ThreeSpikemanState::transfromHp(int old) { return old * 2; }
int ThreeSpikemanState::transfromAtk(int old) { return old * 5; }

// --- Player ---
void Player::add(Character* piece) {
    _pieces.push_back(piece);
}

string Player::toString() {
    stringstream builder;
    for (int i = 0; i < _pieces.size(); i++) {
        // delete "," if it is the last one
        if (i == _pieces.size() - 1) {
            builder << _pieces[i]->toString();
        }
        else {
            builder << _pieces[i]->toString() << ", ";
        }
    }
    string result = builder.str();
    return result;
}

// --- Game ---
Game::Game() {
    _rules.push_back(new ThreeSwordmanRule());
    _rules.push_back(new ThreeKnightRule());
    _rules.push_back(new ThreeSpikemanRule());

    _blueTeam.checker = &Game::checkRule;
    _redTeam.checker = &Game::checkRule;
}

void Game::checkRule(Player* player) {
    for (int i = 0; i < _rules.size(); i++) {
        if (_rules[i]->satisfyWith(player)) {
            _rules[i]->apply(player);
        }
    }
}

void Game::start() {
    RandomIntegerGenerator rig;
    // random 3 pieces for each team
    for (int i = 0; i < 3; i++)
    {
        int bluePieces = rig.next(1, 3);
        int redPieces = rig.next(1, 3);
        if (bluePieces == 1) { _blueTeam.add(new Swordman(1000, 12)); }
        else if (bluePieces == 2) { _blueTeam.add(new Knight(800, 8)); }
        else if (bluePieces == 3) { _blueTeam.add(new Spikeman(1500, 18)); }

        if (redPieces == 1) { _redTeam.add(new Swordman(100, 12)); }
        else if (redPieces == 2) { _redTeam.add(new Knight(800, 12)); }
        else if (redPieces == 3) { _redTeam.add(new Spikeman(1500, 18)); }
    }
    checkRule(&_redTeam);
    checkRule(&_blueTeam);

}

void Game::play() {
    RandomIntegerGenerator rig;
    int decide = rig.next(1, 2);
    if (decide == 1) {
        cout << endl << "Red team goes first:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Turn " << i + 1 << endl;
            _redTeam._pieces[i]->attack(_blueTeam._pieces[i]);
            _blueTeam._pieces[i]->attack(_redTeam._pieces[i]);
            cout << _redTeam.toString() << endl;
            cout << _blueTeam.toString() << endl;
        }
    }
    else {
        cout << endl << "Blue team goes first:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Turn " << i + 1 << endl;
            _blueTeam._pieces[i]->attack(_redTeam._pieces[i]);
            _redTeam._pieces[i]->attack(_blueTeam._pieces[i]);
            cout << _redTeam.toString() << endl;
            cout << _blueTeam.toString() << endl;
        }
    }
}

string Game::toString() {
    stringstream builder;
    builder << "Red team: " << _redTeam.toString() << endl;
    builder << "Blue team: " << _blueTeam.toString() << endl;

    string result = builder.str();
    return result;
}


// --- Rules ---
bool ThreeSwordmanRule::satisfyWith(Player* player) {
    int count = 0;
    for (int i = 0; i < player->_pieces.size(); i++) {
        if (typeid(*player->_pieces[i]) == typeid(Swordman)) {
            count++;
        }
    }
    bool result = count == 3;
    return result;
}

void ThreeSwordmanRule::apply(Player* player) {
    for (int i = 0; i < player->_pieces.size(); i++) {
        player->_pieces[i]->setState(new ThreeSwordmanState());
    }
}

bool ThreeKnightRule::satisfyWith(Player* player) {
    int count = 0;
    for (int i = 0; i < player->_pieces.size(); i++) {
        if (typeid(*player->_pieces[i]) == typeid(Knight)) {
            count++;
        }
    }
    bool result = count == 3;
    return result;
}

void ThreeKnightRule::apply(Player* player) {
    for (int i = 0; i < player->_pieces.size(); i++) {
        player->_pieces[i]->setState(new ThreeKnightState());
    }
}

bool ThreeSpikemanRule::satisfyWith(Player* player) {
    int count = 0;
    for (int i = 0; i < player->_pieces.size(); i++) {
        if (typeid(*player->_pieces[i]) == typeid(Spikeman)) {
            count++;
        }
    }
    bool result = count == 3;
    return result;
}

void ThreeSpikemanRule::apply(Player* player) {
    for (int i = 0; i < player->_pieces.size(); i++) {
        player->_pieces[i]->setState(new ThreeSpikemanState());
    }
}
