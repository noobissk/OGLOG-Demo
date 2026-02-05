#pragma once



class Mood_C {
public:
    enum Mood {
        HAPPY,
        ANGRY,
        SAD
    };
    Mood mood = HAPPY;
    bool is_enabled = true;


    explicit Mood_C() = default;
    ~Mood_C() = default;
};