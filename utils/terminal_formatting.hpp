#pragma once
#include "../components/colour.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

enum struct TextWeight {
    Dim,
    Normal,
    Bold,
};

enum struct TextUnderline {
    Single,
    Double,
    Curly,
    None,
};

namespace TextDecoration {
    int Italic = 1 << 0;
    int ReverseColour = 1 << 1;
    int Strikethrough = 1 << 2;
} // namespace TextDecoration

void send_control_code(std::string code) {
    std::cout << "\e[" << code << "m";
}

namespace terminal {

    string get_24_bit_colour_code(Colour colour) {
        string _24bit_colour_code = "8;2;";
        _24bit_colour_code += to_string((int)(colour.red * 255)) + ";";
        _24bit_colour_code += to_string((int)(colour.green * 255)) + ";";
        _24bit_colour_code += to_string((int)(colour.blue * 255));
        return _24bit_colour_code;
    }

    void set_foreground_colour(Colour colour) {
        string colour_code = get_24_bit_colour_code(colour);
        send_control_code("3" + colour_code);
    }

    void set_background_colour(Colour colour) {
        string colour_code = get_24_bit_colour_code(colour);
        send_control_code("4" + colour_code);
    }

    void reset_foreground_colour() {
        send_control_code("39");
    }
    void reset_background_colour() {
        send_control_code("49");
    }

    void reset_colours() {
        reset_foreground_colour();
        reset_background_colour();
    }

    void set_text_weight(TextWeight weight) {
        switch (weight) {
        case TextWeight::Bold: send_control_code("1");
        case TextWeight::Dim: send_control_code("2");
        case TextWeight::Normal: send_control_code("22");
        default: throw invalid_argument("Unimplemented TextWeight style");
        }
    }

    void set_text_underline(TextUnderline underline) {
        switch (underline) {
        case TextUnderline::Single: send_control_code("4:1");
        case TextUnderline::Double: send_control_code("4:2");
        case TextUnderline::Curly: send_control_code("4:3");
        case TextUnderline::None: send_control_code("4:0");
        default: throw invalid_argument("Unimplemented TextUnderline style");
        }
    }

    void set_text_decoration(int decoration) {
        if (decoration & TextDecoration::Italic) {
            send_control_code("3");
        } else {
            send_control_code("23");
        };
        if (decoration & TextDecoration::ReverseColour) {
            send_control_code("7");
        } else {
            send_control_code("27");
        };
        if (decoration & TextDecoration::Strikethrough) {
            send_control_code("9");
        } else {
            send_control_code("29");
        };
    }
} // namespace terminal
