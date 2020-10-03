#include "../components/widget.hpp"
#include <string>
#pragma once

struct Label : Widget {
    std::string text;

    Label() {
        this->text = "";
    }

    Label(std::string new_text) {
        this->text = new_text;
    }

    void render(Screen &screen) {
        screen.draw(Point(), this->text);
    }
};
