#pragma once
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <random>


int rand_range(int start_r, int end_r);



class Track
{

private:

    std::string trackName;
    std::tm dateOfCreation;
    int seconds = 0;
    bool pause = false;
    bool isPlaying = false;

public:

    void inputTrack()
    {
        std::cout << "Input a track name: ";
        std::cin >> trackName;

        while (trackName.empty())
        {
            std::cerr << "Wrong input, please input again: " << std::endl;
            std::cin >> trackName;
        }

        time_t temp = time(nullptr);
        dateOfCreation = *localtime(&temp);
        std::cout << "Input the creation date: " << std::endl;
        std::cin >> std::get_time(&dateOfCreation, "%d/%m/%Y");

        std::cout << "Input the duration of the track in seconds: " << std::endl;
        //std::cin >> seconds;

        while (seconds < 0 || seconds > 3599)
        {
            std::cerr << "Wrong input, please, input again: " << std::endl;
            std::cin >> seconds;
        }
        return;
    }

    std::string getName()
    {
        return trackName;
    }
    std::tm getTime()
    {
        return dateOfCreation;
    }
    int getSeconds() const
    {
        return seconds;
    }
    bool isPlay() const
    {
        return isPlaying;
    }

    friend class Player;
};



class Player
{

private:

    std::vector<Track *> PlayerVec;
    Track* currentTrack;

public:

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

        PlayerVec.resize(c);

        for (int i = 0; i < c; i++)
        {
            PlayerVec[i]->inputTrack();

            bool f = false;

            for (int j = 0; j < i; j++)
            {
                /*if (PlayerVec[j]->trackName == PlayerVec[i]->trackName)
                {
                    f = true;
                }*/
            }

            while (f)
            {
                PlayerVec[i]->inputTrack();

                f = false;

                for (int j = 0; j < i; j++)
                {
                    if (PlayerVec[j]->trackName == PlayerVec[i]->trackName)
                    {
                        f = true;
                    }
                }
            }
        }
    }

    void play()
    {
        if (!currentTrack->isPlaying) {

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

                for (int i = 0; i < PlayerVec.size(); i++) {
                    if (currentTrackName == PlayerVec[i]->trackName)
                    {
                        trackIndex = i;
                        break;
                    }
                }
            }
            currentTrack = PlayerVec[trackIndex];
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
        currentTrack->pause = true;
        std::cout << "Track has been paused" << std::endl;
    }

    void next()
    {
        int rIndex;
        rIndex = rand_range(0, PlayerVec.size());
        currentTrack->isPlaying = false;
        currentTrack->pause = false;

        currentTrack = PlayerVec[rIndex];
    }

    void stop()
    {
        currentTrack->isPlaying = false;
        std::cout << "Track has been stopped" << std::endl;
    }
};