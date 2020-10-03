#include "components/screen.hpp"
#include "components/widget.hpp"
#include "iostream"
#include "utils/terminal_formatting.hpp"
#include "utils/terminal_info.hpp"
#include "widgets/decorated_window.hpp"
#include "widgets/label.hpp"

struct Fracture {
    // Store as a pointer to prevent 'object slicing'
    Widget *root_widget;

    Fracture() {
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
        std::cout << sc.to_string();
        terminal::reset_colours();
    }
};

int main() {
    Label label = Label("Test");
    DecoratedWindow inner = DecoratedWindow("Inner window");
    DecoratedWindow dw = DecoratedWindow("Outer window");
    dw.set_sub_widget(inner);
    inner.set_sub_widget(label);
    Fracture frac = Fracture(dw);
    frac.render_to_viewport();
}
