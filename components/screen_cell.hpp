#pragma once
#include <codecvt>
#include <locale>

struct ScreenCell {
    char32_t character;

    ScreenCell() {
        this->character = '.';
    }

    ScreenCell(char32_t character) {
        this->character = character;
    }

    std::string to_string() {
        using namespace std;
        wstring_convert<codecvt_utf8<char32_t>, char32_t> converter;
        return converter.to_bytes(this->character);
    }
};