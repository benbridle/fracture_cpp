#pragma once
#include "sample.hpp"
#include <stdexcept>
#include <string>
#include <vector>

struct Clip {
    std::vector<Sample> audio_data;

    Clip() {
    }

    void append_sample(Sample sample) {
        audio_data.push_back(sample);
    }

    Sample get_sample(int index) {
        assert_is_index_in_bounds(index);
        return audio_data[index];
    }

    unsigned int size() {
        return this->audio_data.size();
    }

private:
    void assert_is_index_in_bounds(int index) {
        if (!is_index_in_bounds(index)) {
            throw std::invalid_argument("Sample index is out of bounds");
        }
    }
    bool is_index_in_bounds(int index) {
        if (0 <= index && index <= this->audio_data.size()) {
            return true;
        }
        return false;
    }
};
