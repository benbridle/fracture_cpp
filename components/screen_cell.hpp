#pragma once
#include "colour.hpp"
#include <codecvt>
#include <locale>
#include <optional>

struct ScreenCell {
    char32_t character;
    std::optional<Colour> foreground_colour;
    std::optional<Colour> background_colour;

    ScreenCell() {
        this->character = ' ';
        this->foreground_colour = Colour(1, 0, 0);
    }

    ScreenCell(char32_t character) {
        this->character = character;
    }

    void set_foreground_colour() {
        this->foreground_colour.reset();
    }

    void set_foreground_colour(Colour new_colour) {
        this->foreground_colour = new_colour;
    }

    void set_background_colour() {
        this->background_colour.reset();
    }

    void set_background_colour(Colour new_colour) {
        this->background_colour = new_colour;
    }

    std::string to_string() {
        using namespace std;
        wstring_convert<codecvt_utf8<char32_t>, char32_t> converter;
        return converter.to_bytes(this->character);
    }
};