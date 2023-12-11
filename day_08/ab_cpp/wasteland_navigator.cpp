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

        auto node = line.substr(0, 3);
        network[node] = {line.substr(7, 3), line.substr(12, 3)};
        if (node.back() == 'A')
        {
            start.push_back(node);
        }
    }
}

int WastelandNavigator::Navigate()
{
    std::vector<std::string> nodes = start;
    auto direction = sequence.begin();

    auto steps = 0;

    while (true)
    {
        auto done = true;

        for (auto it = nodes.begin(); it != nodes.end(); it++)
        {
            if (it->back() != 'Z')
            {
                done = false;
                break;
            }
        }

        if (done)
        {
            return steps;
        }

        for (auto it = nodes.begin(); it != nodes.end(); it++)
        {
            *it = network[*it][*direction];
        }

        direction++;
        if (direction == sequence.end())
        {
            direction = sequence.begin();
        }

        steps++;
    }
}
