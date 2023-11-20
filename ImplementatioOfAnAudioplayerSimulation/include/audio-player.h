#pragma once

#include <memory>
#include <vector>
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <random>



class Player
{

private:

    class Track
    {
    public:

        std::string trackName;
        std::tm dateOfCreation{};
        int seconds = 0;
        bool pause = false;
        bool isPlaying = false;
    };
    std::vector<std::unique_ptr<Track>> PlayerVec;


    Track *currentTrack;

public:

    Player()
    {
        currentTrack = new Track();
    }

    ~Player()
    {
        PlayerVec.clear();
        delete currentTrack;
    }

    void inputPlayer()
    {
        int c;
        std::cout << "Input how many audio recordings will be in a list: ";
        std::cin >> c;

        while (c <= 0)
        {
            std::cerr << "Wrong input, try again" << std::endl;
            std::cin >> c;
        }

        for (int i = 0; i < c; i++)
        {
            auto tmpTrack = std::make_unique<Track>();

            std::cout << "Input a track name: ";
            std::cin >> tmpTrack->trackName;

            std::cout << "Input the creation date: " << std::endl;
            std::cin >> std::get_time(&tmpTrack->dateOfCreation, "%d/%m/%Y");

            std::cout << "Input the duration of the track in seconds: " << std::endl;
            std::cin >> tmpTrack->seconds;

            while (tmpTrack->seconds < 0 || tmpTrack->seconds > 3599)
            {
                std::cerr << "Wrong input, please, input again: " << std::endl;
                std::cin >> tmpTrack->seconds;
            }

            PlayerVec.push_back(std::move(tmpTrack));
        }
    }

    void play()
    {
        if (currentTrack && !currentTrack->isPlaying)
        {
            int trackIndex = -1;

            std::cout << "Input track name: " << std::endl;
            std::string currentTrackName;
            std::cin >> currentTrackName;

            while (currentTrackName.empty())
            {
                std::cerr << "Wrong input, try again" << std::endl;
                std::cin >> currentTrackName;
            }

            for (int i = 0; i < PlayerVec.size(); i++)
            {
                if (currentTrackName == PlayerVec[i]->trackName)
                {
                    trackIndex = i;
                    break;
                }
            }

            while (trackIndex == -1)
            {
                std::cerr << "Wrong input, please, input again" << std::endl;
                std::cin >> currentTrackName;

                for (int i = 0; i < PlayerVec.size(); i++)
                {
                    if (currentTrackName == PlayerVec[i]->trackName)
                    {
                        trackIndex = i;
                        break;
                    }
                }
            }
            currentTrack = PlayerVec[trackIndex].get();
            currentTrack->isPlaying = true;
            currentTrack->pause = false;
        }

        std::cout << "Is playing: " << std::endl <<
                  "Name: " << currentTrack->trackName << std::endl <<
                  "Date of creation: " << std::put_time(&currentTrack->dateOfCreation, "%d/%m/%Y") << std::endl <<
                  "Duration: " << currentTrack->seconds / 60 << ":" << currentTrack->seconds % 60 << std::endl;
    }

    void pause()
    {
        if (currentTrack)
        {
            currentTrack->pause = true;
            std::cout << "Track has been paused" << std::endl;
        }
    }

    void next()
    {
        if (currentTrack)
        {
            currentTrack->isPlaying = false;
            currentTrack->pause = false;
        }

        int rIndex;
        srand(time(nullptr));
        rIndex = rand() % PlayerVec.size();

        currentTrack = PlayerVec[rIndex].get();
    }

    void stop()
    {
        if (currentTrack)
        {
            currentTrack->isPlaying = false;
            std::cout << "Track has been stopped" << std::endl;
        }
    }
};