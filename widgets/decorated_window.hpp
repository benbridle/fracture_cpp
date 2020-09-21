#include "../components/widget.hpp"
#include <string>

struct DecoratedWindow : Widget {
    std::string title;

    DecoratedWindow() {
        this->title = "";
    }

    DecoratedWindow(std::string new_title) {
        this->title = new_title;
    }

    void render(Screen &screen) {
        unsigned short right = screen.width - 1;
        unsigned short bottom = screen.height - 1;

        for (int x = 0; x < screen.width; x++) {
            screen.draw(x, 0, U'─');
            screen.draw(x, bottom, U'─');
        };
        for (int y = 0; y < screen.height; y++) {
            screen.draw(0, y, U'│');
            screen.draw(right, y, U'│');
        };
        screen.draw(0, 0, U'┌');
        screen.draw(right, 0, U'┐');
        screen.draw(0, bottom, U'└');
        screen.draw(right, bottom, U'┘');

        // Don't draw title if title is empty
        if (this->title == "") {
            return;
        };

        // Calculate the horizontal offset needed to shift the title to
        //  the center of the frame
        int offset = ((screen.width - 2) - this->title.length()) / 2;
        int i = 0;
        // Add a gap to either side of the title
        for (char c : ' ' + this->title + ' ') {
            screen.draw(i + offset, 0, c);
            i++;
        };
    };
};