#include <optional>
#include <stdlib.h>
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <termios.h>
#include <unistd.h>

namespace terminal {
    struct termios orig_termios;

    void disable_raw_mode() {
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
    }

    void enable_raw_mode() {
        tcgetattr(STDIN_FILENO, &orig_termios);
        atexit(disable_raw_mode);
        struct termios raw = orig_termios;
        raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        raw.c_oflag &= ~(OPOST);
        raw.c_cflag |= (CS8);
        raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
        raw.c_cc[VMIN] = 0;
        raw.c_cc[VTIME] = 1;
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    }

    // std::optional<KeyPress> get_key() {
    //     int keycode = getchar();

    //     if (1 <= keycode && keycode <= 26) {
    //         return KeyPress(num_to_keycode[keycode - 1], ModifierKey::Control);
    //     }
    //     if (65 <= keycode && keycode <= 90) {
    //         return KeyPress(num_to_keycode[keycode - 65], ModifierKey::Shift);
    //     }
    //     if (97 <= keycode && keycode <= 122) {
    //         return KeyPress(num_to_keycode[keycode - 97]);
    //     }
    //     return KeyPress(KeyCode::Null);
    // }

    int kbhit() {
        static const int STDIN = 0;
        static bool initialized = false;

        if (!initialized) {
            // Use termios to turn off line buffering
            setbuf(stdin, NULL);
            initialized = true;
        }

        int bytesWaiting;
        ioctl(STDIN, FIONREAD, &bytesWaiting);
        return bytesWaiting;
    }
} // namespace terminal