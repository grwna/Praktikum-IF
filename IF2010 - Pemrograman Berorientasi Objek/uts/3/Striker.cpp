#include "Striker.hpp"
// atribut tambahan goalScore (jumlah gol yang dicetak striker)
// dan shotsOnTarget (jumlah tendangan tepat sasaran)
//   int goalScore;
//   int shotsOnTarget;

// Default constructor
// set atribut Footballer dengan nilai default,
// set goalScore dan shotsOnTarget ke 0, dan playPosition ke "striker"
Striker::Striker() : Footballer() {
    this->goalScore = 0;
    this->shotsOnTarget = 0;
    this->playPosition = "striker";
}

// User-defined constructor
// parameter: string name, int birthYear, int goalScore, int shotsOnTarget
// set atribut dengan nilai parameter, playPosition tetap "striker"
// nationality, height, dan weight gunakan nilai default superclass
Striker::Striker(string name, int birthYear, int goalScore, int shotsOnTarget) : Footballer() {
    this->name = name;
    this->birthYear = birthYear;
    this->goalScore = goalScore;
    this->shotsOnTarget = shotsOnTarget;
    this->playPosition = "striker";
}

// Getter dan Setter untuk goalScore
void Striker::setGoalScore(int score) {
    this->goalScore = score;
}

int Striker::getGoalScore() const {
    return this->goalScore;
}

// Getter dan Setter untuk shotsOnTarget
void Striker::setShotsOnTarget(int shots) {
    this->shotsOnTarget = shots;
}

int Striker::getShotsOnTarget() const {
    return this->shotsOnTarget;
}

// Method tambahan: menghitung conversion rate dalam persen
// conversionRate() = (goalScore / shotsOnTarget) * 100
// return dalam bentuk float
// Hint: Gunakan static_cast<float> untuk mengonversi int ke float
float Striker::conversionRate() {
    if (this->shotsOnTarget == 0) return 0;
    return (static_cast<float>(this->goalScore) / static_cast<float>(this->shotsOnTarget)) * 100;
}

// Override transferRate:
// rumus: 1.000.000 * goalScore + 10.000 * conversionRate()
// hasil berupa int
int Striker::transferRate() {
    return (1000000 * goalScore) + 10000 * (conversionRate());
}

// Override displayInfo():
// Cetak info Footballer + atribut tambahan striker (goalScore, conversionRate)
// Format:
// Goals: <goalScore>
// Conversion Rate: <conversionRate>%
void Striker::displayInfo() {
    Footballer::displayInfo();
    cout << "Goals: " << this->goalScore << "\n";
    cout << "Conversion Rate: ";
    cout << fixed << setprecision(2) << this->conversionRate() << "%" << "\n";
}
// Hint: Gunakan fixed dan setprecision(2) untuk menampilkan conversionRate
// Contoh: cout << fixed << setprecision(2) << conversionRate() << "%" << endl;
// ...
