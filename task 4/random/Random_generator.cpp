#include "Random_generator.h"
#include <random>

static std::random_device rd;
static std::mt19937 gen(rd());

int RandomGenerator::getInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);

    return dist(gen);
}