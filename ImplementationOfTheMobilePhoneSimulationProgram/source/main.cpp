#include <phone.h>

int main()
{
    std::cout << "::The Mobile Phone Simulation Program::" << std::endl <<
                                                              std::endl;

    auto phoneBook_m = new PhoneBook();

    std::string command;

    while (true)
    {
        std::cout << "Input the command: " << std::endl;
        std::cin >> command;

        while (command != "add"  &&
               command != "call" &&
               command != "sms")
        {
            std::cout << "Wrong input, try again" << std::endl;
            std::cin >> command;
        }

        if (command == "add")
        {
            phoneBook_m->add();
        }
        else if  (command == "call")
        {
            phoneBook_m->call();
        }
        else if (command == "sms")
        {
            phoneBook_m->sms();
        }
        else if (command == "exit")
        {
            break;
        }
    }

    system("pause");
    delete phoneBook_m;
    return 0;
}