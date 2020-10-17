#include "asciidaw_components/clip.hpp"
#include "components/key_press.hpp"
#include "components/screen.hpp"
#include "components/widget.hpp"
#include "iostream"
#include "utils/terminal_control.hpp"
#include "utils/terminal_formatting.hpp"
#include "utils/terminal_info.hpp"
#include "widgets/clip_widget.hpp"
#include "widgets/decorated_window.hpp"
#include "widgets/label.hpp"
#include <math.h>
#include <random>
#define _USE_MATH_DEFINES // For M_PI

struct Fracture {
    // Store as a pointer to prevent 'object slicing'
    Widget *root_widget;

    Fracture() {
        // terminal::enable_raw_mode();
    }

    ~Fracture() {
        // terminal::disable_raw_mode();
    }

    Fracture(Widget &root_widget) {
        this->root_widget = &root_widget;
    }

    void set_root_widget(Widget &new_root_widget) {
        this->root_widget = &new_root_widget;
    }

    void render_to_viewport() {
        // TODO: Remove the shrinkage here
        Screen viewport = Screen(terminal::get_width() - 1, terminal::get_height() - 2);

        this->root_widget->render(viewport);

        for (int y = 0; y < viewport.height; y++) {
            for (int x = 0; x < viewport.width; x++) {
                ScreenCell sc = viewport.get_screen_cell(Point(x, y));
                render_screencell(sc);
            }
            std::cout << std::endl;
        }
    }

private:
    void render_screencell(ScreenCell sc) {
        if (sc.foreground_colour) {
            terminal::set_foreground_colour(sc.foreground_colour.value());
        }
        if (sc.background_colour) {
            terminal::set_background_colour(sc.background_colour.value());
        }
        std::cout << sc.to_string();
        terminal::reset_colours();
    }
};

int main() {
    Clip c = Clip();
    // `i` is `double` so that division is double division, not integer division
    for (double i = 0; i < 90000; i++) {
        // c.append_sample(0.5 * (1 + sin(2 * M_PI * 3 * (i / 48000))));
        c.append_sample((double)random() / RAND_MAX);
    }

    ClipWidget cw = ClipWidget(c);
    Label label = Label("1");
    DecoratedWindow inner = DecoratedWindow("Inner window");
    DecoratedWindow outer = DecoratedWindow("Outer window");

    inner.set_sub_widget(cw);
    outer.set_sub_widget(inner);
    Fracture frac = Fracture(outer);

    KeyPress kp = KeyPress(Key::K_P, ModifierKey::Control | ModifierKey::Shift);
    label.text = kp.to_string();
    frac.render_to_viewport();

    // for (int i = 0; i < 100; i++) {
    //     label.text = std::to_string(i);
    //     frac.render_to_viewport();
    // }
}
