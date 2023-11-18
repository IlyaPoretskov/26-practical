#include "audio-player.h"


int rand_range(int start_r, int end_r)
{
    std::srand(time(nullptr));
    return start_r + rand() % (end_r - start_r);
}