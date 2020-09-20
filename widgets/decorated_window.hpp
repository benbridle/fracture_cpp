#include "../components/widget.hpp"
#include <string>

struct DecoratedWindow : Widget {
    std::string title;

    void render(Screen &screen) {
        unsigned short right = screen.width - 1;
        unsigned short bottom = screen.height - 1;

        screen.draw(0, 0, U'┌');
        screen.draw(right, 0, U'┐');
        screen.draw(0, bottom, U'└');
        screen.draw(right, bottom, U'┘');
    };
};