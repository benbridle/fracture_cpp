#pragma once
#include "key_definitions.hpp"
#include <map>
#include <string>

enum ModifierKey {
    Control = 1 << 0,
    Shift = 1 << 1,
    Alt = 1 << 2,
};

struct KeyPress {
    // A dumb data structure, with basic display methods
    Key key;
    int modifier_keys = 0;

    KeyPress(Key key) {
        this->key = key;
    }

    KeyPress(Key key, int modifier_keys) {
        this->key = key;
        this->modifier_keys = modifier_keys;
    }

    std::string to_string() {
        std::string output = "";
        if (this->modifier_keys & ModifierKey::Control) output += "Control+";
        if (this->modifier_keys & ModifierKey::Shift) output += "Shift+";
        if (this->modifier_keys & ModifierKey::Alt) output += "Alt+";
        // if (keypress_to_string.find(*this) != keypress_to_string.end()) {
        //     output += keypress_to_string.at(*this);
        // }
        return output;
    }

    bool operator==(KeyPress other) {
        if (this->key != other.key) {
            return false;
        }
        if (this->modifier_keys != other.modifier_keys) {
            return false;
        }
        return true;
    }

    bool operator<(KeyPress other) const {
        // Allows this struct to be used as a map key
        int this_value = static_cast<int>(this->key) * this->modifier_keys;
        int other_value = static_cast<int>(other.key) * other.modifier_keys;
        return this_value < other_value;
    }
};

std::map<KeyPress, std::string> keypress_to_string{
    {KeyPress(Key::K_A, ModifierKey::Control), "^A"},
    {KeyPress(Key::K_B, ModifierKey::Control), "^B"},
    {KeyPress(Key::K_C, ModifierKey::Control), "^C"},
    {KeyPress(Key::K_D, ModifierKey::Control), "^D"},
    {KeyPress(Key::K_E, ModifierKey::Control), "^E"},
    {KeyPress(Key::K_F, ModifierKey::Control), "^F"},
    {KeyPress(Key::K_G, ModifierKey::Control), "^G"},
    {KeyPress(Key::K_H, ModifierKey::Control), "^H"},
    {KeyPress(Key::K_I, ModifierKey::Control), "^I"},
    {KeyPress(Key::K_J, ModifierKey::Control), "^J"},
    {KeyPress(Key::K_K, ModifierKey::Control), "^K"},
    {KeyPress(Key::K_L, ModifierKey::Control), "^L"},
    {KeyPress(Key::K_M, ModifierKey::Control), "^M"},
    {KeyPress(Key::K_N, ModifierKey::Control), "^N"},
    {KeyPress(Key::K_O, ModifierKey::Control), "^O"},
    {KeyPress(Key::K_P, ModifierKey::Control), "^P"},
    {KeyPress(Key::K_Q, ModifierKey::Control), "^Q"},
    {KeyPress(Key::K_R, ModifierKey::Control), "^R"},
    {KeyPress(Key::K_S, ModifierKey::Control), "^S"},
    {KeyPress(Key::K_T, ModifierKey::Control), "^T"},
    {KeyPress(Key::K_U, ModifierKey::Control), "^U"},
    {KeyPress(Key::K_V, ModifierKey::Control), "^V"},
    {KeyPress(Key::K_W, ModifierKey::Control), "^W"},
    {KeyPress(Key::K_X, ModifierKey::Control), "^X"},
    {KeyPress(Key::K_Y, ModifierKey::Control), "^Y"},
    {KeyPress(Key::K_Z, ModifierKey::Control), "^Z"},

    {KeyPress(Key::K_A, ModifierKey::Shift), "A"},
    {KeyPress(Key::K_B, ModifierKey::Shift), "B"},
    {KeyPress(Key::K_C, ModifierKey::Shift), "C"},
    {KeyPress(Key::K_D, ModifierKey::Shift), "D"},
    {KeyPress(Key::K_E, ModifierKey::Shift), "E"},
    {KeyPress(Key::K_F, ModifierKey::Shift), "F"},
    {KeyPress(Key::K_G, ModifierKey::Shift), "G"},
    {KeyPress(Key::K_H, ModifierKey::Shift), "H"},
    {KeyPress(Key::K_I, ModifierKey::Shift), "I"},
    {KeyPress(Key::K_J, ModifierKey::Shift), "J"},
    {KeyPress(Key::K_K, ModifierKey::Shift), "K"},
    {KeyPress(Key::K_L, ModifierKey::Shift), "L"},
    {KeyPress(Key::K_M, ModifierKey::Shift), "M"},
    {KeyPress(Key::K_N, ModifierKey::Shift), "N"},
    {KeyPress(Key::K_O, ModifierKey::Shift), "O"},
    {KeyPress(Key::K_P, ModifierKey::Shift), "P"},
    {KeyPress(Key::K_Q, ModifierKey::Shift), "Q"},
    {KeyPress(Key::K_R, ModifierKey::Shift), "R"},
    {KeyPress(Key::K_S, ModifierKey::Shift), "S"},
    {KeyPress(Key::K_T, ModifierKey::Shift), "T"},
    {KeyPress(Key::K_U, ModifierKey::Shift), "U"},
    {KeyPress(Key::K_V, ModifierKey::Shift), "V"},
    {KeyPress(Key::K_W, ModifierKey::Shift), "W"},
    {KeyPress(Key::K_X, ModifierKey::Shift), "X"},
    {KeyPress(Key::K_Y, ModifierKey::Shift), "Y"},
    {KeyPress(Key::K_Z, ModifierKey::Shift), "Z"},

    {KeyPress(Key::K_A), "a"},
    {KeyPress(Key::K_B), "b"},
    {KeyPress(Key::K_C), "c"},
    {KeyPress(Key::K_D), "d"},
    {KeyPress(Key::K_E), "e"},
    {KeyPress(Key::K_F), "f"},
    {KeyPress(Key::K_G), "g"},
    {KeyPress(Key::K_H), "h"},
    {KeyPress(Key::K_I), "i"},
    {KeyPress(Key::K_J), "j"},
    {KeyPress(Key::K_K), "k"},
    {KeyPress(Key::K_L), "l"},
    {KeyPress(Key::K_M), "m"},
    {KeyPress(Key::K_N), "n"},
    {KeyPress(Key::K_O), "o"},
    {KeyPress(Key::K_P), "p"},
    {KeyPress(Key::K_Q), "q"},
    {KeyPress(Key::K_R), "r"},
    {KeyPress(Key::K_S), "s"},
    {KeyPress(Key::K_T), "t"},
    {KeyPress(Key::K_U), "u"},
    {KeyPress(Key::K_V), "v"},
    {KeyPress(Key::K_W), "w"},
    {KeyPress(Key::K_X), "x"},
    {KeyPress(Key::K_Y), "y"},
    {KeyPress(Key::K_Z), "z"},
};

std::map<int, KeyPress> keycode_to_keypress{
    {1, KeyPress(Key::K_A, ModifierKey::Control)},
    {2, KeyPress(Key::K_B, ModifierKey::Control)},
    {3, KeyPress(Key::K_C, ModifierKey::Control)},
    {4, KeyPress(Key::K_D, ModifierKey::Control)},
    {5, KeyPress(Key::K_E, ModifierKey::Control)},
    {6, KeyPress(Key::K_F, ModifierKey::Control)},
    {7, KeyPress(Key::K_G, ModifierKey::Control)},
    {8, KeyPress(Key::K_H, ModifierKey::Control)},
    {9, KeyPress(Key::K_I, ModifierKey::Control)},
    {10, KeyPress(Key::K_J, ModifierKey::Control)},
    {11, KeyPress(Key::K_K, ModifierKey::Control)},
    {12, KeyPress(Key::K_L, ModifierKey::Control)},
    {13, KeyPress(Key::K_M, ModifierKey::Control)},
    {14, KeyPress(Key::K_N, ModifierKey::Control)},
    {15, KeyPress(Key::K_O, ModifierKey::Control)},
    {16, KeyPress(Key::K_P, ModifierKey::Control)},
    {17, KeyPress(Key::K_Q, ModifierKey::Control)},
    {18, KeyPress(Key::K_R, ModifierKey::Control)},
    {19, KeyPress(Key::K_S, ModifierKey::Control)},
    {20, KeyPress(Key::K_T, ModifierKey::Control)},
    {21, KeyPress(Key::K_U, ModifierKey::Control)},
    {22, KeyPress(Key::K_V, ModifierKey::Control)},
    {23, KeyPress(Key::K_W, ModifierKey::Control)},
    {24, KeyPress(Key::K_X, ModifierKey::Control)},
    {25, KeyPress(Key::K_Y, ModifierKey::Control)},
    {26, KeyPress(Key::K_Z, ModifierKey::Control)},

    {65, KeyPress(Key::K_A, ModifierKey::Shift)},
    {66, KeyPress(Key::K_B, ModifierKey::Shift)},
    {67, KeyPress(Key::K_C, ModifierKey::Shift)},
    {68, KeyPress(Key::K_D, ModifierKey::Shift)},
    {69, KeyPress(Key::K_E, ModifierKey::Shift)},
    {70, KeyPress(Key::K_F, ModifierKey::Shift)},
    {71, KeyPress(Key::K_G, ModifierKey::Shift)},
    {72, KeyPress(Key::K_H, ModifierKey::Shift)},
    {73, KeyPress(Key::K_I, ModifierKey::Shift)},
    {74, KeyPress(Key::K_J, ModifierKey::Shift)},
    {75, KeyPress(Key::K_K, ModifierKey::Shift)},
    {76, KeyPress(Key::K_L, ModifierKey::Shift)},
    {77, KeyPress(Key::K_M, ModifierKey::Shift)},
    {78, KeyPress(Key::K_N, ModifierKey::Shift)},
    {79, KeyPress(Key::K_O, ModifierKey::Shift)},
    {80, KeyPress(Key::K_P, ModifierKey::Shift)},
    {81, KeyPress(Key::K_Q, ModifierKey::Shift)},
    {82, KeyPress(Key::K_R, ModifierKey::Shift)},
    {83, KeyPress(Key::K_S, ModifierKey::Shift)},
    {84, KeyPress(Key::K_T, ModifierKey::Shift)},
    {85, KeyPress(Key::K_U, ModifierKey::Shift)},
    {86, KeyPress(Key::K_V, ModifierKey::Shift)},
    {87, KeyPress(Key::K_W, ModifierKey::Shift)},
    {88, KeyPress(Key::K_X, ModifierKey::Shift)},
    {89, KeyPress(Key::K_Y, ModifierKey::Shift)},
    {90, KeyPress(Key::K_Z, ModifierKey::Shift)},

    {97, KeyPress(Key::K_A)},
    {98, KeyPress(Key::K_B)},
    {99, KeyPress(Key::K_C)},
    {100, KeyPress(Key::K_D)},
    {101, KeyPress(Key::K_E)},
    {102, KeyPress(Key::K_F)},
    {103, KeyPress(Key::K_G)},
    {104, KeyPress(Key::K_H)},
    {105, KeyPress(Key::K_I)},
    {106, KeyPress(Key::K_J)},
    {107, KeyPress(Key::K_K)},
    {108, KeyPress(Key::K_L)},
    {109, KeyPress(Key::K_M)},
    {110, KeyPress(Key::K_N)},
    {111, KeyPress(Key::K_O)},
    {112, KeyPress(Key::K_P)},
    {113, KeyPress(Key::K_Q)},
    {114, KeyPress(Key::K_R)},
    {115, KeyPress(Key::K_S)},
    {116, KeyPress(Key::K_T)},
    {117, KeyPress(Key::K_U)},
    {118, KeyPress(Key::K_V)},
    {119, KeyPress(Key::K_W)},
    {120, KeyPress(Key::K_X)},
    {121, KeyPress(Key::K_Y)},
    {122, KeyPress(Key::K_Z)},
};