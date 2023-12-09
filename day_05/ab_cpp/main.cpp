#include <main.h>
#include <seed_mapper.hpp>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <array>
#include <map>
#include <tuple>

int main(int argc, char **argv)
{
    std::cout << "SeedMapper v" << SeedMapper_VERSION_MAJOR << "."
              << SeedMapper_VERSION_MINOR << std::endl;

    if (argc != 2)
    {
        std::cerr << "Expected exactly 2 arguments." << std::endl;
        return EXIT_FAILURE;
    }

    SeedMapper seed_mapper(argv[1]);
    seed_mapper.BuildMaps();
    seed_mapper.GetLocations();

    std::cout << "Lowest location: " << seed_mapper.GetLowestLocation() << std::endl;
}
