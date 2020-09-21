#include "components/screen.hpp"
#include "components/widget.hpp"
#include "iostream"
#include "utils/terminal_info.hpp"
#include "widgets/decorated_window.hpp"

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
                ScreenCell sc = viewport.get_screen_cell(x, y);
                std::cout << sc.to_string();
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    DecoratedWindow inner = DecoratedWindow("Inner window");
    DecoratedWindow dw = DecoratedWindow("Window");
    dw.set_sub_widget(inner);
    Fracture frac = Fracture(dw);
    frac.render_to_viewport();
}
