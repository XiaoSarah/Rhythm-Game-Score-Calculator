#include <iostream>
#include <cmath>

class RhythmGameScoreCalculator {
private:
    int baseScore;
    int comboMultiplier;
    int maxCombo;
    int currentCombo;

public:
    RhythmGameScoreCalculator() : baseScore(100), comboMultiplier(2), maxCombo(0), currentCombo(0) {}

    void processHit(int timingDifference) {
        if (std::abs(timingDifference) < 20) {
            // Perfect
            hit("Perfect", timingDifference);
        } else if (std::abs(timingDifference) < 50) {
            // Great
            hit("Great", timingDifference);
        } else if (std::abs(timingDifference) < 100) {
            // Good
            hit("Good", timingDifference);
        } else if (std::abs(timingDifference) < 150) {
            // Bad
            hit("Bad", timingDifference);
        } else {
            // Miss
            miss();
        }
    }

    void hit(const std::string& category, int timingDifference) {
        int timingBonus = calculateTimingBonus(timingDifference);
        int score = baseScore + timingBonus + calculateComboBonus();

        currentCombo++;
        maxCombo = std::max(maxCombo, currentCombo);

        displayScore(category, score);
    }

    void miss() {
        // Missed the note
        currentCombo = 0;
        displayMiss();
    }

    int calculateTimingBonus(int timingDifference) {
        // Example: Linear bonus based on timing difference
        // Formula can be modified based on scoring system
        return 100 - std::abs(timingDifference);
    }

    int calculateComboBonus() {
        // Example: Combo bonus based on the current combo streak
        // Formula can be modified based on scoring system
        return currentCombo * comboMultiplier;
    }

    void displayScore(const std::string& category, int score) {
        std::cout << category << " hit! Score: " << score << " | Combo: " << currentCombo << " | Max Combo: " << maxCombo << std::endl;
    }

    void displayMiss() {
        std::cout << "Missed the note! Combo reset." << std::endl;
    }
};

int main() {
    RhythmGameScoreCalculator scoreCalculator;

    // Simulate hits with different timing differences
    scoreCalculator.processHit(10);   // Perfect
    scoreCalculator.processHit(-30);  // Great
    scoreCalculator.processHit(80);   // Good
    scoreCalculator.processHit(-120); // Bad
    scoreCalculator.processHit(200);  // Miss

    return 0;
}