#include "window.h"

int main()
{
    std::string command;
    Window wind;

    while (true)
    {
        std::cout << "Input a command:" << std::endl;
        std::cin >> command;

        while (command != "move" &&
               command != "resize" &&
               command != "display" &&
               command != "close")
        {
            std::cerr << "Wrong input, try again" << std::endl;
            std::cin >> command;
        }

        if (command == "move")
        {
            wind.move();
        }
        else if (command == "resize")
        {
            wind.resize();
        }
        else if (command == "display")
        {
            wind.display();
        }
        else
        {
            break;
        }
    }
    system("pause");
    return 0;
}
