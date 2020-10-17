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

    int kbhit() {
        // Returns the number of characters waiting to be read from stdin
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

    std::optional<KeyPress> get_key() {
        int keycode = 0;
        if (kbhit() > 0) {
            keycode = getchar();
        } else {
            return std::optional<KeyPress>();
        };
        if (keycode_to_keypress.count(keycode) == 0) {
            return std::optional<KeyPress>();
        } else {
            return keycode_to_keypress.at(keycode);
        };
    }
} // namespace terminal