#include <wasteland_navigator.hpp>

#include <fstream>

WastelandNavigator::WastelandNavigator(const char *input)
{
    std::ifstream buf(input);

    char c = buf.get();
    while (c == 'L' || c == 'R')
    {
        sequence.push_back(c == 'L' ? 0 : 1);
        c = buf.get();
    }

    std::string line;
    while (std::getline(buf, line))
    {
        if (line.empty())
        {
            continue;
        }

        network[line.substr(0, 3)] = {line.substr(7, 3), line.substr(12, 3)};
    }
}

int WastelandNavigator::Navigate(const std::string &destination)
{
    std::string node = "AAA";
    auto direction = sequence.begin();

    auto steps = 0;

    while (node != destination)
    {
        node = network[node][*direction];

        direction++;
        if (direction == sequence.end())
        {
            direction = sequence.begin();
        }

        steps++;
    }

    return steps;
}
