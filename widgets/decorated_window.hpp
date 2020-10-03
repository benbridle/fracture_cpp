#include "../components/point.hpp"
#include "../components/widget.hpp"
#include <iostream>
#include <string>

struct DecoratedWindow : Widget {
    std::string title;
    Widget *sub_widget = nullptr;

    DecoratedWindow() {
        this->title = "";
    }

    DecoratedWindow(std::string new_title) {
        this->title = new_title;
    }

    // Takes a reference
    void set_sub_widget(Widget &sub_widget) {
        // Set this->sub_widget pointer to point to the _address_ of sub_widget.
        this->sub_widget = &sub_widget;
    }

    void render_sub_widget(Screen &screen) {
        screen.draw(Point(1, 1), '^');
        if (this->sub_widget) {

            // this->sub_widget->render(screen);
            // I think that the screen isn't being passed by reference, but
            //  instead is being passed by value. The widget correctly renders
            //  itself to the screen in the above line.
            screen.draw(Point(1, 1), '^');
            screen.draw(Point(2, 2), 'D');
            // And yet, curiously, when a character is drawn to position (1,1) it
            //  clones itself across the entire Screen. But not when in any other
            //  position. This is the only way to get characters to draw down to
            //  the parent screen from here.
        };
    }

    void render(Screen &screen) {
        Screen sub_screen = Screen(screen.width - 2, screen.height - 2);
        // this->render_sub_widget(sub_screen);
        sub_screen.draw(Point(2, 2), '&');
        // Drawing the subscreen onto the screen at (1,1) doesn't print anything

        screen.draw(Point(1, 1), sub_screen);

        unsigned short right = screen.width - 1;
        unsigned short bottom = screen.height - 1;

        for (int x = 0; x < screen.width; x++) {
            screen.draw(Point(x, 0), U'─');
            screen.draw(Point(x, bottom), U'─');
        };
        for (int y = 0; y < screen.height; y++) {
            screen.draw(Point(0, y), U'│');
            screen.draw(Point(right, y), U'│');
        };
        screen.draw(Point(0, 0), U'┌');
        screen.draw(Point(right, 0), U'┐');
        screen.draw(Point(0, bottom), U'└');
        screen.draw(Point(right, bottom), U'┘');

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
            // TODO: Implement drawing a string to a Screen in order to tidy this up
            screen.draw(Point(i + offset, 0), c);
        };
    };
};