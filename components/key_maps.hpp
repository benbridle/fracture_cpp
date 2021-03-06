#pragma once
#include "key_press.hpp"
#include <map>

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

#define keycode_vec std ::vector<int>
std::map<keycode_vec, KeyPress> keycodes_to_keypress{
    {keycode_vec{1}, KeyPress(Key::K_A, ModifierKey::Control)},
    {keycode_vec{2}, KeyPress(Key::K_B, ModifierKey::Control)},
    {keycode_vec{3}, KeyPress(Key::K_C, ModifierKey::Control)},
    {keycode_vec{4}, KeyPress(Key::K_D, ModifierKey::Control)},
    {keycode_vec{5}, KeyPress(Key::K_E, ModifierKey::Control)},
    {keycode_vec{6}, KeyPress(Key::K_F, ModifierKey::Control)},
    {keycode_vec{7}, KeyPress(Key::K_G, ModifierKey::Control)},
    {keycode_vec{8}, KeyPress(Key::K_H, ModifierKey::Control)},
    {keycode_vec{9}, KeyPress(Key::K_I, ModifierKey::Control)},
    {keycode_vec{10}, KeyPress(Key::K_J, ModifierKey::Control)},
    {keycode_vec{11}, KeyPress(Key::K_K, ModifierKey::Control)},
    {keycode_vec{12}, KeyPress(Key::K_L, ModifierKey::Control)},
    {keycode_vec{13}, KeyPress(Key::K_M, ModifierKey::Control)},
    {keycode_vec{14}, KeyPress(Key::K_N, ModifierKey::Control)},
    {keycode_vec{15}, KeyPress(Key::K_O, ModifierKey::Control)},
    {keycode_vec{16}, KeyPress(Key::K_P, ModifierKey::Control)},
    {keycode_vec{17}, KeyPress(Key::K_Q, ModifierKey::Control)},
    {keycode_vec{18}, KeyPress(Key::K_R, ModifierKey::Control)},
    {keycode_vec{19}, KeyPress(Key::K_S, ModifierKey::Control)},
    {keycode_vec{20}, KeyPress(Key::K_T, ModifierKey::Control)},
    {keycode_vec{21}, KeyPress(Key::K_U, ModifierKey::Control)},
    {keycode_vec{22}, KeyPress(Key::K_V, ModifierKey::Control)},
    {keycode_vec{23}, KeyPress(Key::K_W, ModifierKey::Control)},
    {keycode_vec{24}, KeyPress(Key::K_X, ModifierKey::Control)},
    {keycode_vec{25}, KeyPress(Key::K_Y, ModifierKey::Control)},
    {keycode_vec{26}, KeyPress(Key::K_Z, ModifierKey::Control)},

    {keycode_vec{27}, KeyPress(Key::K_Escape)},

    {keycode_vec{27, 91, 53, 126}, KeyPress(Key::K_PageUp)},
    {keycode_vec{27, 91, 54, 126}, KeyPress(Key::K_PageDown)},

    {keycode_vec{27, 91, 65}, KeyPress(Key::K_UpArrow)},
    {keycode_vec{27, 91, 66}, KeyPress(Key::K_DownArrow)},
    {keycode_vec{27, 91, 67}, KeyPress(Key::K_RightArrow)},
    {keycode_vec{27, 91, 68}, KeyPress(Key::K_LeftArrow)},

    {keycode_vec{27, 91, 72}, KeyPress(Key::K_Home)},
    {keycode_vec{27, 91, 52, 126}, KeyPress(Key::K_End)},
    {keycode_vec{27, 91, 52, 104}, KeyPress(Key::K_Insert)},
    {keycode_vec{27, 91, 80}, KeyPress(Key::K_Delete)},

    {keycode_vec{27, 91, 49, 59, 50, 65}, KeyPress(Key::K_UpArrow, ModifierKey::Shift)},
    {keycode_vec{27, 91, 49, 59, 50, 66}, KeyPress(Key::K_DownArrow, ModifierKey::Shift)},
    {keycode_vec{27, 91, 49, 59, 50, 67}, KeyPress(Key::K_RightArrow, ModifierKey::Shift)},
    {keycode_vec{27, 91, 49, 59, 50, 68}, KeyPress(Key::K_LeftArrow, ModifierKey::Shift)},

    {keycode_vec{27, 91, 49, 59, 53, 65}, KeyPress(Key::K_UpArrow, ModifierKey::Control)},
    {keycode_vec{27, 91, 49, 59, 53, 66}, KeyPress(Key::K_DownArrow, ModifierKey::Control)},
    {keycode_vec{27, 91, 49, 59, 53, 67}, KeyPress(Key::K_RightArrow, ModifierKey::Control)},
    {keycode_vec{27, 91, 49, 59, 53, 68}, KeyPress(Key::K_LeftArrow, ModifierKey::Control)},

    {keycode_vec{27, 91, 49, 59, 54, 65}, KeyPress(Key::K_UpArrow, ModifierKey::Control | ModifierKey::Shift)},
    {keycode_vec{27, 91, 49, 59, 54, 66}, KeyPress(Key::K_DownArrow, ModifierKey::Control | ModifierKey::Shift)},
    {keycode_vec{27, 91, 49, 59, 54, 67}, KeyPress(Key::K_RightArrow, ModifierKey::Control | ModifierKey::Shift)},
    {keycode_vec{27, 91, 49, 59, 54, 68}, KeyPress(Key::K_LeftArrow, ModifierKey::Control | ModifierKey::Shift)},

    {keycode_vec{27, 79, 80}, KeyPress(Key::K_F1)},
    {keycode_vec{27, 79, 81}, KeyPress(Key::K_F2)},
    {keycode_vec{27, 79, 82}, KeyPress(Key::K_F3)},
    {keycode_vec{27, 79, 83}, KeyPress(Key::K_F4)},

    {keycode_vec{27, 91, 49, 53, 126}, KeyPress(Key::K_F5)},
    {keycode_vec{27, 91, 49, 55, 126}, KeyPress(Key::K_F6)},
    {keycode_vec{27, 91, 49, 56, 126}, KeyPress(Key::K_F7)},
    {keycode_vec{27, 91, 49, 57, 126}, KeyPress(Key::K_F8)},

    {keycode_vec{27, 91, 50, 48, 126}, KeyPress(Key::K_F9)},
    {keycode_vec{27, 91, 50, 49, 126}, KeyPress(Key::K_F10)},
    {keycode_vec{27, 91, 50, 51, 126}, KeyPress(Key::K_F11)},
    {keycode_vec{27, 91, 50, 52, 126}, KeyPress(Key::K_F12)},

    {keycode_vec{34}, KeyPress(Key::K_Quote, ModifierKey::Shift)},

    {keycode_vec{39}, KeyPress(Key::K_Quote)},

    {keycode_vec{44}, KeyPress(Key::K_Comma)},
    {keycode_vec{45}, KeyPress(Key::K_Minus)},
    {keycode_vec{46}, KeyPress(Key::K_Period)},
    {keycode_vec{47}, KeyPress(Key::K_ForwardSlash)},

    {keycode_vec{48}, KeyPress(Key::K_0)},
    {keycode_vec{49}, KeyPress(Key::K_1)},
    {keycode_vec{50}, KeyPress(Key::K_2)},
    {keycode_vec{51}, KeyPress(Key::K_3)},
    {keycode_vec{52}, KeyPress(Key::K_4)},
    {keycode_vec{53}, KeyPress(Key::K_5)},
    {keycode_vec{54}, KeyPress(Key::K_6)},
    {keycode_vec{55}, KeyPress(Key::K_7)},
    {keycode_vec{56}, KeyPress(Key::K_8)},
    {keycode_vec{57}, KeyPress(Key::K_9)},
    {keycode_vec{58}, KeyPress(Key::K_Semicolon, ModifierKey::Shift)},
    {keycode_vec{59}, KeyPress(Key::K_Semicolon)},

    {keycode_vec{60}, KeyPress(Key::K_Comma, ModifierKey::Shift)},
    {keycode_vec{61}, KeyPress(Key::K_Equal)},
    {keycode_vec{62}, KeyPress(Key::K_Period, ModifierKey::Shift)},
    {keycode_vec{63}, KeyPress(Key::K_ForwardSlash, ModifierKey::Shift)},

    {keycode_vec{65}, KeyPress(Key::K_A, ModifierKey::Shift)},
    {keycode_vec{66}, KeyPress(Key::K_B, ModifierKey::Shift)},
    {keycode_vec{67}, KeyPress(Key::K_C, ModifierKey::Shift)},
    {keycode_vec{68}, KeyPress(Key::K_D, ModifierKey::Shift)},
    {keycode_vec{69}, KeyPress(Key::K_E, ModifierKey::Shift)},
    {keycode_vec{70}, KeyPress(Key::K_F, ModifierKey::Shift)},
    {keycode_vec{71}, KeyPress(Key::K_G, ModifierKey::Shift)},
    {keycode_vec{72}, KeyPress(Key::K_H, ModifierKey::Shift)},
    {keycode_vec{73}, KeyPress(Key::K_I, ModifierKey::Shift)},
    {keycode_vec{74}, KeyPress(Key::K_J, ModifierKey::Shift)},
    {keycode_vec{75}, KeyPress(Key::K_K, ModifierKey::Shift)},
    {keycode_vec{76}, KeyPress(Key::K_L, ModifierKey::Shift)},
    {keycode_vec{77}, KeyPress(Key::K_M, ModifierKey::Shift)},
    {keycode_vec{78}, KeyPress(Key::K_N, ModifierKey::Shift)},
    {keycode_vec{79}, KeyPress(Key::K_O, ModifierKey::Shift)},
    {keycode_vec{80}, KeyPress(Key::K_P, ModifierKey::Shift)},
    {keycode_vec{81}, KeyPress(Key::K_Q, ModifierKey::Shift)},
    {keycode_vec{82}, KeyPress(Key::K_R, ModifierKey::Shift)},
    {keycode_vec{83}, KeyPress(Key::K_S, ModifierKey::Shift)},
    {keycode_vec{84}, KeyPress(Key::K_T, ModifierKey::Shift)},
    {keycode_vec{85}, KeyPress(Key::K_U, ModifierKey::Shift)},
    {keycode_vec{86}, KeyPress(Key::K_V, ModifierKey::Shift)},
    {keycode_vec{87}, KeyPress(Key::K_W, ModifierKey::Shift)},
    {keycode_vec{88}, KeyPress(Key::K_X, ModifierKey::Shift)},
    {keycode_vec{89}, KeyPress(Key::K_Y, ModifierKey::Shift)},
    {keycode_vec{90}, KeyPress(Key::K_Z, ModifierKey::Shift)},

    {keycode_vec{96}, KeyPress(Key::K_Grave)},

    {keycode_vec{97}, KeyPress(Key::K_A)},
    {keycode_vec{98}, KeyPress(Key::K_B)},
    {keycode_vec{99}, KeyPress(Key::K_C)},
    {keycode_vec{100}, KeyPress(Key::K_D)},
    {keycode_vec{101}, KeyPress(Key::K_E)},
    {keycode_vec{102}, KeyPress(Key::K_F)},
    {keycode_vec{103}, KeyPress(Key::K_G)},
    {keycode_vec{104}, KeyPress(Key::K_H)},
    {keycode_vec{105}, KeyPress(Key::K_I)},
    {keycode_vec{106}, KeyPress(Key::K_J)},
    {keycode_vec{107}, KeyPress(Key::K_K)},
    {keycode_vec{108}, KeyPress(Key::K_L)},
    {keycode_vec{109}, KeyPress(Key::K_M)},
    {keycode_vec{110}, KeyPress(Key::K_N)},
    {keycode_vec{111}, KeyPress(Key::K_O)},
    {keycode_vec{112}, KeyPress(Key::K_P)},
    {keycode_vec{113}, KeyPress(Key::K_Q)},
    {keycode_vec{114}, KeyPress(Key::K_R)},
    {keycode_vec{115}, KeyPress(Key::K_S)},
    {keycode_vec{116}, KeyPress(Key::K_T)},
    {keycode_vec{117}, KeyPress(Key::K_U)},
    {keycode_vec{118}, KeyPress(Key::K_V)},
    {keycode_vec{119}, KeyPress(Key::K_W)},
    {keycode_vec{120}, KeyPress(Key::K_X)},
    {keycode_vec{121}, KeyPress(Key::K_Y)},
    {keycode_vec{122}, KeyPress(Key::K_Z)},
};

std::map<Key, std::string> key_to_keyname{
    {Key::K_Escape, "Escape"},
    {Key::K_F1, "F1"},
    {Key::K_F2, "F2"},
    {Key::K_F3, "F3"},
    {Key::K_F4, "F4"},
    {Key::K_F5, "F5"},
    {Key::K_F6, "F6"},
    {Key::K_F7, "F7"},
    {Key::K_F8, "F8"},
    {Key::K_F9, "F9"},
    {Key::K_F10, "F10"},
    {Key::K_F11, "F11"},
    {Key::K_F12, "F12"},
    {Key::K_PauseBreak, "PauseBreak"},
    {Key::K_Insert, "Insert"},
    {Key::K_Delete, "Delete"},

    {Key::K_A, "A"},
    {Key::K_B, "B"},
    {Key::K_C, "C"},
    {Key::K_D, "D"},
    {Key::K_E, "E"},
    {Key::K_F, "F"},
    {Key::K_G, "G"},
    {Key::K_H, "H"},
    {Key::K_I, "I"},
    {Key::K_J, "J"},
    {Key::K_K, "K"},
    {Key::K_L, "L"},
    {Key::K_M, "M"},
    {Key::K_N, "N"},
    {Key::K_O, "O"},
    {Key::K_P, "P"},
    {Key::K_Q, "Q"},
    {Key::K_R, "R"},
    {Key::K_S, "S"},
    {Key::K_T, "T"},
    {Key::K_U, "U"},
    {Key::K_V, "V"},
    {Key::K_W, "W"},
    {Key::K_X, "X"},
    {Key::K_Y, "Y"},
    {Key::K_Z, "Z"},

    {Key::K_Tab, "Tab"},
    {Key::K_Grave, "Grave"},
    {Key::K_0, "0"},
    {Key::K_1, "1"},
    {Key::K_2, "2"},
    {Key::K_3, "3"},
    {Key::K_4, "4"},
    {Key::K_5, "5"},
    {Key::K_6, "6"},
    {Key::K_7, "7"},
    {Key::K_8, "8"},
    {Key::K_9, "9"},
    {Key::K_Minus, "Minus"},
    {Key::K_Equal, "Equals"},
    {Key::K_Backspace, "Backspace"},

    {Key::K_Home, "Home"},
    {Key::K_PageUp, "PageUp"},
    {Key::K_PageDown, "PageDown"},
    {Key::K_End, "End"},

    {Key::K_UpArrow, "UpArrow"},
    {Key::K_DownArrow, "DownArrow"},
    {Key::K_LeftArrow, "LeftArrow"},
    {Key::K_RightArrow, "RightArrow"},

    {Key::K_BracketOpen, "["},
    {Key::K_BracketClose, "]"},
    {Key::K_BackSlash, "BackSlash"},
    {Key::K_Semicolon, "Semicolon"},
    {Key::K_Quote, "Quote"},
    {Key::K_Comma, "Comma"},
    {Key::K_Period, "Period"},
    {Key::K_ForwardSlash, "ForwardSlash"},

    {Key::K_Enter, "Enter"},
    {Key::K_Space, "Space"},
};