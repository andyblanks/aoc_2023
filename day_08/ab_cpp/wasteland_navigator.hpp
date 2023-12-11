#ifndef WASTELAND_NAVIGATOR_HPP
#define WASTELAND_NAVIGATOR_HPP

#include <array>
#include <map>
#include <string>
#include <vector>

class WastelandNavigator
{
    std::vector<char> sequence;
    std::map<std::string, std::array<std::string, 2>> network;

    std::vector<char>::const_iterator direction;
    std::string node;

    std::string NavigateNode(const std::string &, char);

public:
    WastelandNavigator(const char *);

    int Navigate(const std::string &);
};

#endif // WASTELAND_NAVIGATOR_HPP
