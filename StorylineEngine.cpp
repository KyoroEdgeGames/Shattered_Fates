#include <iostream>
#include <vector>
#include <string>

// Class representing a Character
class Character {
public:
    std::string name;
    std::string trait;

    Character(const std::string& n, const std::string& t) : name(n), trait(t) {}

    void speak(const std::string& line) const {
        std::cout << name << ": \"" << line << "\"\n";
    }

    void action(const std::string& act) const {
        std::cout << name << " " << act << ".\n";
    }
};

// Class representing a Chapter
class Chapter {
public:
    std::string title;
    std::string summary;
    std::vector<std::string> textLines;

    Chapter(const std::string& t, const std::string& s) : title(t), summary(s) {}

    void addLine(const std::string& line) {
        textLines.push_back(line);
    }

    void display() const {
        std::cout << "=== " << title << " ===\n";
        if (!summary.empty()) {
            std::cout << "(Summary: " << summary << ")\n\n";
        }
        for (const auto& line : textLines) {
            std::cout << line << "\n";
        }
        std::cout << "\n";
    }
};

// Class to manage the Story
class StoryManager {
private:
    std::vector<Chapter> chapters;

public:
    void addChapter(const Chapter& chap) {
        chapters.push_back(chap);
    }

    void playStory() const {
        for (const auto& chap : chapters) {
            chap.display();
        }
    }
};

int main() {
    // Create Characters
    Character Ivy("Ivy", "Mismatched eyes, dangerous claws");
    Character Coal("Coal", "Loyal, obsessive");
    Character Silence("Silence", "Mute, protective");
    Character Stolenstar("Stolenstar", "Leader, powerful, terrifying");

    // Create Chapter 1
    Chapter chapter1("Prologue", "Ivy awakens and meets their mother, Silence. The warning of fate begins.");
    chapter1.addLine("The morning light crept into the room in thin, hesitant beams...");
    chapter1.addLine("Coal nudged Ivy's side, soft and persistent.");
    chapter1.addLine("Ivy yawned, showing sharp little teeth.");
    chapter1.addLine("Coal: \"Woah… your eyes… they’re two totally different colors.\"");
    chapter1.addLine("Silence watched Ivy with a look that was both tender and strained.");

    // Create Chapter 2
    Chapter chapter2("The Flames", "Ivy and Coal practice outside, and Ivy’s power begins to show.");
    chapter2.addLine("The backyard was a frozen strip of earth, trapped between the house and the glass barrier.");
    chapter2.addLine("Ivy: \"Oh yes I can!\" They darted after Coal, paws pounding like a heartbeat.");
    chapter2.addLine("Coal: \"I’m sorry, Ivy. I will listen better next time.\"");
    chapter2.addLine("Silence's tail flicked sharply, signaling them to come inside.");

    // Create Chapter 3
    Chapter chapter3("A Life Once Stolen", "Ivy grows stronger, showing new abilities.");
    chapter3.addLine("Ivy's body felt heavier, stronger, more… real.");
    chapter3.addLine("Ivy: \"Wake up, you lazy stack of pelts!\"");
    chapter3.addLine("Coal: \"Why must you do that?\"");
    chapter3.addLine("Silence signed gently: Eat first. Then you can go outside and play fight.");

    // Story manager
    StoryManager story;
    story.addChapter(chapter1);
    story.addChapter(chapter2);
    story.addChapter(chapter3);

    // Play story
    story.playStory();

    // Example of characters interacting
    std::cout << "\n--- Character Dialog Demo ---\n";
    Ivy.speak("We have to find our father.");
    Coal.speak("I will follow you, no matter what.");
    Stolenstar.action("stands tall, his gaze fierce, leading the kits to Bloodclan");

    return 0;
}
