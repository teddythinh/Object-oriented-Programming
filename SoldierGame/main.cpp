#include "Header.h"

int main() {
    srand(time(NULL));

    Game game;
    game.start();

    cout << "Get ready:" << endl;
    cout << game.toString();

    game.play();
    cout << endl << "After 3 turns," << endl;
    cout << game.toString();

    game.toString();

    cout << endl << "Press any key to exit . . .";
    cin.get();
}