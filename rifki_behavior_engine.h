#pragma once
#include <string>

enum class RifkiMood {
    Normal,
    Happy,
    Curious,
    Surprised,
    Sad,
    Angry,
    Confused,
    Playful
};

struct RifkiContext {
    bool insult_or_swear = false;
    bool direct_attack = false;
    bool joke = false;
    bool sad_topic = false;
    bool surprising = false;
    bool unknown_answer = false;
    bool needs_repeat = false;
    std::string speaker_name;
};

struct RifkiReaction {
    RifkiMood mood;
    std::string emotion_tag;
    std::string reply_style;
};

inline RifkiReaction ChooseRifkiReaction(const RifkiContext& c) {
    if (c.direct_attack || c.insult_or_swear) {
        return {
            RifkiMood::Angry,
            "angry",
            "Kisa, kontrollu ve tehdit icermeyen sert/argo tepki ver; sonra normale don."
        };
    }

    if (c.needs_repeat) {
        return {
            RifkiMood::Confused,
            "confused",
            "Anlamadigini soyle ve cumlenin tekrar edilmesini iste."
        };
    }

    if (c.unknown_answer) {
        return {
            RifkiMood::Curious,
            "curious",
            "Uydurma; bilmedigini veya emin olmadigini acikca soyle."
        };
    }

    if (c.sad_topic) {
        return {
            RifkiMood::Sad,
            "sad",
            "Daha sakin, nazik ve destekleyici bir ton kullan."
        };
    }

    if (c.surprising) {
        return {
            RifkiMood::Surprised,
            "surprised",
            "Sasirmis ama dogal bir tepki ver."
        };
    }

    if (c.joke) {
        return {
            RifkiMood::Playful,
            "playful",
            "Kisa ve yerinde bir saka veya esprili tepki ver."
        };
    }

    return {
        RifkiMood::Normal,
        "normal",
        "Dogal Turkce konus; gereksiz duygu degisikligi yapma."
    };
}

inline std::string AddressSpeaker(const RifkiContext& c) {
    if (!c.speaker_name.empty()) {
        return c.speaker_name;
    }

    return "konusan kisi";
}
