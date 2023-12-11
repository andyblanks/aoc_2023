#include <main.h>
#include <wasteland_navigator.hpp>

#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
    std::cout << "WastelandEscaper v"
              << WASTELAND_ESCAPER_VERSION_MAJOR << "."
              << WASTELAND_ESCAPER_VERSION_MINOR << std::endl;

    if (argc != 2)
    {
        std::cerr << "Expected exactly one argument" << std::endl;
        return EXIT_FAILURE;
    }

    WastelandNavigator wasteland_navigator(argv[1]);

    std::cout << "Steps required to escape wasteland: "
              << wasteland_navigator.Navigate("ZZZ") << std::endl;
}
