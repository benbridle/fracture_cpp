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
        assert_is_valid_screen_coordinates(x, y);
        return this->content[y][x];
    }

    void set_screen_cell(unsigned short x, unsigned short y, ScreenCell sc) {
        assert_is_valid_screen_coordinates(x, y);
        this->content[y][x] = sc;
    }

    bool draw(int x, int y, char32_t new_character) {
        if (!is_valid_screen_coordinates(x, y)) {
            return false;
        };
        this->content[y][x].character = new_character;
        return true;
    }

    bool draw(int x, int y, Screen screen) {
        // Draws a Screen onto this screen, with the top-left corner at the specified point
        // Returns `true` if provided screen is contained within this screen, `false` otherwise

        bool success_state = true;
        ScreenCell transplant;

        for (int y_offset = 0; y_offset < screen.height; y_offset++) {
            for (int x_offset = 0; x_offset < screen.width; x_offset++) {
                if (!is_valid_screen_coordinates(x + x_offset, y + y_offset)) {
                    success_state = false;
                    continue;
                }
                transplant = screen.get_screen_cell(x_offset, y_offset);
                this->set_screen_cell(x + x_offset, y + y_offset, transplant);
            }
        }
        return success_state;
    }

    // TODO: Add a draw(string) method, then refactor the DecoratedWindow title drawing for loop.

private:
    bool is_valid_screen_coordinates(unsigned short x, unsigned short y) {
        if (x >= this->width || y >= this->height || x < 0 || y < 0) {
            return false;
        };
        return true;
    }
    void assert_is_valid_screen_coordinates(unsigned short x, unsigned short y) {
        if (!is_valid_screen_coordinates(x, y)) {
            throw invalid_argument("Given coordinates are out of bounds");
        }
    }
};