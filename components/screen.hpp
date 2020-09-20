#pragma once
#include "screen_cell.hpp"
#include <stdexcept>
#include <vector>
using namespace std;

struct Screen {
    unsigned short width;
    unsigned short height;
    vector<vector<ScreenCell>> content;

    Screen() {}

    Screen(unsigned short width, unsigned short height) {
        // Set size of outer vector
        this->content = vector<vector<ScreenCell>>(height);
        for (int y = 0; y < height; y++) {
            // Initialise the width of each row
            this->content[y] = vector<ScreenCell>(width);
            for (int x = 0; x < width; x++) {
                // Initialise each character of the row
                this->content[y][x] = ScreenCell();
            };
        };
        this->width = width;
        this->height = height;
    }

    ScreenCell get_screen_cell(unsigned short x, unsigned short y) {
        if (!is_valid_screen_coordinates(x, y)) {
            throw invalid_argument("Given coordinates are out of bounds");
        }
        return this->content[y][x];
    }

private:
    bool is_valid_screen_coordinates(unsigned short x, unsigned short y) {
        if (x >= this->width || y >= this->height || x < 0 || y < 0) {
            return false;
        }
        return true;
    }
};