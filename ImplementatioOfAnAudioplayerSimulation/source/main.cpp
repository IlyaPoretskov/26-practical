#include "audio-player.h"

using namespace std;

int main()
{

    Player *player = nullptr;

    player->inputPlayer();

    while (true)
    {
        string command;
        cout << "Input the command: " << endl;
        cin >> command;

        while (command != "play"  &&
               command != "pause" &&
               command != "next"  &&
               command != "stop"  &&
               command != "exit")
        {
            cerr << "Wrong input, input the command again: " << endl;
            cin >> command;
        }

        if (command == "play")
        {
            player->play();
        }

        else if (command == "pause")
        {
            player->pause();
        }

        else if (command == "next")
        {
            player->next();
        }

        else if (command == "stop")
        {
            player->stop();
        }

        else if (command == "exit")
        {
            break;
        }
    }
    system("pause");
    return 0;
}
