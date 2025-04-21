#include "Footballer.hpp"

// string name;
// string playPosition;
// int birthYear;
// 
// string nationality;
// int height;
// int weight;

// Default cosntructor set nilai attribut sebagai berikut:
// name = "noname"; birthYear = 2000; playPosition = "none";
// nationality = "Indonesia"; height = 180, weight = 70
// ...
Footballer::Footballer(){
    this->name = "noname";
    this->birthYear = 2000;
    this->playPosition = "none";
    this->nationality = "Indonesia";
    this->height = 180;
    this->weight = 70;
}

// User-defined constructor:
// set nilai atribut berdasarkan nilai parameter masukan
// dengan urutan: name, birthYear, playPosition, nationality, height, weight
// ...
Footballer::Footballer(string name, int birthYear, string position, string nationality, int height, int weight){
    this->name = name;
    this->birthYear = birthYear;
    this->playPosition = position;
    this->nationality = nationality;
    this->height = height;
    this->weight = weight;
}

// Copy constructor
Footballer::Footballer(const Footballer& other){
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->playPosition = other.playPosition;
    this->nationality = other.nationality;
    this->height = other.height;
    this->weight = other.weight;
}

// Destructor
Footballer::~Footballer() {}

// Operator assignment
Footballer& Footballer::operator=(const Footballer& other){
    this->name = other.name;
    this->birthYear = other.birthYear;
    this->playPosition = other.playPosition;
    this->nationality = other.nationality;
    this->height = other.height;
    this->weight = other.weight;
    return *this;
}

// Getter dan setter name
// setName(...)
// getName()
void Footballer::setName(string newName){
    this->name = newName;
}
string Footballer::getName() const{
    return this->name;
}

// Getter dan setter playPosition
// setPlayPosition(...)
// getPlayPosition()
void Footballer::setPlayPosition(string newPos){
    this->playPosition = newPos;
}
string Footballer::getPlayPosition() const{
    return this->playPosition;
}

// Getter dan setter nationality
// setNationality(...)
// getNationality()
void Footballer::setNationality(string newNationality){
    this->nationality = newNationality;
}
string Footballer::getNationality() const{
    return this->nationality;
}

// Getter dan setter height and weight
// setHeight(...)
// getHeight()
void Footballer::setHeight(int newHeight){
    this->height = newHeight;
}
int Footballer::getHeight() const{
    return this->height;
}
// setWeight(...)
// getWeight()
void Footballer::setWeight(int newWeight) {
    this->weight = newWeight;
}
int Footballer::getWeight() const{
    return this->weight;
}

// gunakan CURRENT_YEAR untuk menghitung umur
// getAge()
int Footballer::getAge() const{
    return CURRENT_YEAR - this->birthYear;
}

// gunakan height and weight untuk menghitung BMI
// BMI = weight(kg) / (height(m))²
// getBMI()
float Footballer::getBMI() const{
    float heightm = this->height / 100.0;
    return (float)weight / ((float)heightm * (float)heightm);
}
// gunakan BMI untuk mendapat category
// BMI < 18.5         -> Underweight
// 18.5 ≤ BMI < 25.0  -> Normal
// 25.0 ≤ BMI < 30.0  -> Overweight
// BMI ≥ 30.0         -> Obese
// getCategory() -> string
string Footballer::getCategory() const{
    string cat;
    if (this->getBMI() < 18.5) return "Underweight";
    else if (this->getBMI() < 25.0) return "Normal";
    else if (this->getBMI() < 30.0) return "Overweight";
    else return "Obese";
}

// Mencetak informasi footballer dengan format sebagai berikut:
// Name: {name}
// Age: {hasil pemanggilan getAge()}
// Position: {playPosition}
// Nationality: {nationality}
// BMI: {<BMI> (<getCategory()>)}, BMI 2 angka di belakang koma, HINT: "cout << fixed << setprecision(2);"
// Transfer Rate: {hasil pemanggilan transferRate()}
// displayInfo()
void Footballer::displayInfo() {
    cout << "Name: " << this->getName() << endl;
    cout << "Age: " << this->getAge() << endl;
    cout << "Position: " << this->getPlayPosition() << endl;
    cout << "Nationality: " << this->getNationality() << endl;
    cout << "BMI: ";
    cout << fixed << setprecision(2) << this-> getBMI();
    cout << " (" << this->getCategory() << ")" << endl;
    cout << "Transfer Rate: " << transferRate() << endl;
}
