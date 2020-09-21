#include "../components/widget.hpp"
#include <string>

struct DecoratedWindow : Widget {
    std::string title;
    Widget *sub_widget = NULL;

    DecoratedWindow() {
        this->title = "";
        this->sub_widget;
    }

    DecoratedWindow(std::string new_title) {
        this->title = new_title;
        this->sub_widget;
    }

    void set_sub_widget(Widget &sub_widget) {
        this->sub_widget = &sub_widget;
    }

    void render_sub_widget(Screen &screen) {
        if (this->sub_widget) {
            this->sub_widget->render(screen);
        };
    }

    void render(Screen &screen) {
        Screen sub_screen = Screen(screen.width - 2, screen.height - 2);
        this->render_sub_widget(sub_screen);
        screen.draw(1, 1, sub_screen);

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

        // Add a gap to either side of the title
        std::string title = ' ' + this->title + ' ';
        // Calculate the horizontal offset needed to shift the title to
        //  the center of the frame
        int offset = ((screen.width - 2) - title.length()) / 2;
        for (int i = 0; i < title.length(); i++) {
            char c = title[i];
            screen.draw(i + offset, 0, c);
        };
    };
};