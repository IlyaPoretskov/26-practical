#pragma once
#include <iostream>

#define DEBUG 0

#if DEBUG

    #define WEIGHT 80
    #define HEIGHT 50

#endif


#if !DEBUG

    enum monitor
    {
        WEIGHT = 80,
        HEIGHT = 50
    };

#endif


struct coordinate
{
    double x = 0, y = 0;
};

class Window
{

private:

    coordinate upperLeftCorner = {0, 0};
    double weight = 0, height = 0;

public:

    void display()
    {
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WEIGHT; j++)
            {
                if (i <= upperLeftCorner.x || j <= upperLeftCorner.y || i >= weight || j >= height)
                {
                    std::cout << "0";
                }
                else
                {
                    std::cout << "1";
                }
            }
            std::cout << std::endl;
        }
    }

    void resize()
    {
        std::cout << "Input new weight and height of the window:" << std::endl;
        std::cin >> weight >> height;

        while (upperLeftCorner.x + weight > 80 || upperLeftCorner.y + height > 50)
        {
            std::cerr << "Wrong input, please input again" << std::endl;
            std::cin >> weight >> height;
        }
    }

    void move()
    {
        std::cout << "Input new coordinates for left upper window corner:" << std::endl;
        std::cin >> upperLeftCorner.x >> upperLeftCorner.y;

        while (upperLeftCorner.x < 0 || upperLeftCorner.y < 0)
        {
            std::cerr << "Wrong input, please input again" << std::endl;
            std::cin >> upperLeftCorner.x >> upperLeftCorner.y;
        }

        std::cout << "Input weight and height of the window:" << std::endl;
        std::cin >> weight >> height;

        while (upperLeftCorner.x + weight > 80 || upperLeftCorner.y + height > 50)
        {
            std::cerr << "Wrong input, please input again" << std::endl;
            std::cin >> weight >> height;
        }
    }
};