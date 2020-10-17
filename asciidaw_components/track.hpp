#pragma once
#include "clip.hpp"

struct Track {
    std::vector<Clip> clips = {};
    bool is_record_armed = false;

    Track() {
    }

    void create_clip(unsigned int start_time) {
        this->clips.push_back(Clip());
    }

    void delete_clip(int clip_index) {
        std::vector<Clip>::iterator it = clips.begin();
        advance(it, clip_index);
        clips.erase(it);
    }

    double get_sample(int channel, int time_in_samples, int &counter, int max_amplitude) {
        for (auto &clip : clips) {
            if (clip.getStartTime() <= time_in_samples && time_in_samples <= clip.getEndTime()) {
                //As audio is interleaved in wav, we must select sample from appropriate channel
                int sample_start = (time_in_samples - clip.getStartTime()) * 2;
                counter++;
                if (channel == 0) {
                    return clip.get_sample(sample_start);

                } else if (channel == 1) {
                    return clip.get_sample(sample_start + 1);
                }
            }
        }
        return 0;
    }

    void load_audio_clips(double max_amplitude_of_source) {
        for (auto &clip : clips) {
            clip.loadAudioStream(max_amplitude_of_source);
        }
    }
    void clear_audio_clips() {
        for (auto &clip : this->clips) {
            clip.audio_data.clear();
        }
    }
};
