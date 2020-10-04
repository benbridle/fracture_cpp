#include "../asciidaw_components/clip.hpp"
#include "../components/point.hpp"
#include "../components/screen.hpp"
#include "../components/widget.hpp"

struct ClipWidget : Widget {
    Clip clip;

    ClipWidget(Clip &clip) {
        this->clip = clip;
    }

    void render(Screen &screen) {
        unsigned int bucket_size = this->clip.size() / screen.width;
        for (int x = 0; x < screen.width; x++) {
            double sum = 0;
            for (int i = bucket_size * x; i < bucket_size * (x + 1); i++) {
                sum += this->clip.get_sample(i).value;
            }
            double average = sum / bucket_size;
            screen.draw(Point(x, 0), sample_to_screencell(average));
        }
    }

private:
    ScreenCell sample_to_screencell(double sample) {
        char32_t character;
        if (sample < 1 / 8.0) {
            character = U'▁';
        } else if (sample < 2 / 8.0) {
            character = U'▂';
        } else if (sample < 3 / 8.0) {
            character = U'▃';
        } else if (sample < 4 / 8.0) {
            character = U'▄';
        } else if (sample < 5 / 8.0) {
            character = U'▅';
        } else if (sample < 6 / 8.0) {
            character = U'▆';
        } else if (sample < 7 / 8.0) {
            character = U'▇';
        } else {
            character = U'█';
        }

        return ScreenCell(character);
    }
};