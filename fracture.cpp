#include "asciidaw_components/clip.hpp"
#include "components/key_press.hpp"
#include "components/screen.hpp"
#include "components/widget.hpp"
#include "iostream"
#include "utils/terminal_control.hpp"
#include "utils/terminal_cursor.hpp"
#include "utils/terminal_formatting.hpp"
#include "utils/terminal_info.hpp"
#include "widgets/clip_widget.hpp"
#include "widgets/decorated_window.hpp"
#include "widgets/label.hpp"
#include <math.h>
#include <random>
#include <unistd.h>
#define _USE_MATH_DEFINES // For M_PI

struct Fracture {
    // Store as a pointer to prevent 'object slicing'
    Widget *root_widget;

    Fracture(Widget &root_widget) {
        this->set_root_widget(root_widget);
        terminal::enable_raw_mode();
        terminal::cursor::hide();

        // Scroll display to clear it
        for (int y = 0; y < terminal::get_height(); y++) {
            terminal::cursor::line_feed();
        }
    }

    ~Fracture() {
        terminal::disable_raw_mode();
        terminal::cursor::show();
    }

    void set_root_widget(Widget &new_root_widget) {
        this->root_widget = &new_root_widget;
    }

    void render_to_viewport() {
        // TODO: Remove the shrinkage here
        Screen viewport = Screen(terminal::get_width() - 1, terminal::get_height() - 2);

        this->root_widget->render(viewport);

        terminal::cursor::move_to_top_left();
        for (int y = 0; y < viewport.height; y++) {
            for (int x = 0; x < viewport.width; x++) {
                ScreenCell sc = viewport.get_screen_cell(Point(x, y));
                render_screencell(sc);
            }
            terminal::cursor::carriage_return();
        }
    }

private:
    void render_screencell(ScreenCell &sc) {
        if (sc.foreground_colour) {
            terminal::set_foreground_colour(sc.foreground_colour.value());
        }
        if (sc.background_colour) {
            terminal::set_background_colour(sc.background_colour.value());
        }

        std::cout << sc.to_string();

        if (sc.foreground_colour) {
            terminal::reset_foreground_colour();
        }
        if (sc.background_colour) {
            terminal::reset_background_colour();
        }
    }
};

int main() {
    // Clip c = Clip();
    // `i` is `double` so that division is double division, not integer division
    // for (double i = 0; i < 90000; i++) {
    // c.append_sample(0.5 * (1 + sin(2 * M_PI * 3 * (i / 48000))));
    // c.append_sample((double)random() / RAND_MAX);
    // }

    // ClipWidget cw = ClipWidget(c);
    Label label = Label("Z");
    DecoratedWindow inner = DecoratedWindow("Inner window");
    DecoratedWindow outer = DecoratedWindow("Outer window");

    inner.set_sub_widget(label);
    outer.set_sub_widget(inner);
    Fracture frac = Fracture(outer);

    // while (true) {
    //     std::optional<KeyPress> kpo = terminal::get_key();
    //     if (kpo) {
    //         label.text = to_string(kpo.value());
    //     };
    //     frac.render_to_viewport();
    //     sleep(1);
    // }
    frac.render_to_viewport();

    for (int i = 0; i < 500; i++) {
        label.text = std::to_string(i);
        frac.render_to_viewport();
    }
}
