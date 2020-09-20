#include "components/screen.hpp"
#include "components/widget.hpp"
#include "iostream"
#include "utils/terminal_info.hpp"

struct Fracture {
    Widget root_widget;

    Fracture() {
    }

    void set_root_widget(Widget new_root_widget) {
        this->root_widget = new_root_widget;
    }

    void render_to_viewport() {
        unsigned short width = terminal::get_width() - 20;
        unsigned short height = terminal::get_height() - 2;
        Screen s = Screen(width, height);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                ScreenCell sc = s.get_screen_cell(x, y);
                std::cout << sc.to_string();
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Fracture frac = Fracture();
    frac.render_to_viewport();
}
