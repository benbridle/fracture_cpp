#pragma once
#include "../components/colour.hpp"
#include <iostream>
using namespace std;

namespace terminal {

    string get_24_bit_colour_code(Colour colour) {
        string _24bit_colour_code = "8;2;";
        _24bit_colour_code += to_string((int)(colour.red * 255)) + ";";
        _24bit_colour_code += to_string((int)(colour.green * 255)) + ";";
        _24bit_colour_code += to_string((int)(colour.blue * 255));
        return _24bit_colour_code;
    }

    void set_foreground_colour(Colour colour) {
        cout << "\e[3";
        cout << get_24_bit_colour_code(colour);
        cout << "m";
    }

    void set_background_colour(Colour colour) {
        cout << "\e[4";
        cout << get_24_bit_colour_code(colour);
        cout << "m";
    }

    void reset_foreground_colour() {
        cout << "\e[39m";
    }
    void reset_background_colour() {
        cout << "\e[49m";
    }

    void reset_colours() {
        reset_foreground_colour();
        reset_background_colour();
    }
} // namespace terminal
