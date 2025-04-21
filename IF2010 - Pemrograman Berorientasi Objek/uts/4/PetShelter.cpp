    // Pet* pets[MAX_SHELTER_CAPACITY]; // Array to store pets in the shelter
    // std::string shelterName; // Name of the shelter
    // int dogCapacity; // Maximum capacity for dogs
    // int catCapacity; // Maximum capacity for cats
    // int petCount; // Total number of pets in the shelter
    // int currentDogs; // Current number of dogs in the shelter
    // int currentCats; // Current number of cats in the shelter

#include "PetShelter.hpp"

template <typename T>
PetShelter<T>::PetShelter(std::string shelterName){
    this->shelterName = shelterName;
    this->dogCapacity = 8;
    this->catCapacity = 12;
    this->petCount = 0;
    this->currentDogs = 0;
    this->currentCats = 0;
}
/* Default constructor:
    * - Creates a shelter with the given name.
    * - Default capacity: 8 dogs, 12 cats.
    * - No pets in the shelter initially.
    */

template <typename T>
PetShelter<T>::PetShelter(std::string shelterName, int dogCapacity, int catCapacity){
    int totCap = dogCapacity + catCapacity;
    if ( totCap > MAX_SHELTER_CAPACITY){
        std::cout << "The total capacity you construct is " << totCap << ", meanwhile the shelter capacity is 20" << std::endl;
    } else {
        this->shelterName = shelterName;
        this->dogCapacity = dogCapacity;
        this->catCapacity = catCapacity;
        this->petCount = 0;
        this->currentDogs = 0;
        this->currentCats = 0;
    }
}

/* Constructor with specified capacities:
    * - Creates a shelter with custom capacities for dogs and cats.
    * - If total capacity exceeds MAX_SHELTER_CAPACITY, prints:
    *   "The total capacity you construct is <total>, meanwhile the shelter capacity is 20"
    */

template <typename T>
PetShelter<T>::~PetShelter(){
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        delete pets[i];
        pets[i] = nullptr;
    }
}
/* Destructor:
    * - Cleans up all dynamically allocated pets.
    * - Sets pet pointers to nullptr after deletion.
    */

template<class T>
std::string PetShelter<T>::getShelterName() const{
    return this->shelterName;
}
/* Returns the name of the shelter.
    * Output: Shelter name as a string.
    */

template<class T>
void PetShelter<T>::addPet(const std::string &petName, int age, bool isDog, const std::string &extraInfo){
    std::string petId;
    Pet* newPet;
    if (petCount == MAX_SHELTER_CAPACITY) {
        std::cout << "Error: Shelter is at full capacity!" << std::endl;
        return;
    }
    if (isDog){
        if (currentDogs == dogCapacity) {
            std::cout << "Error: No space for more dogs!" << std::endl;
            return;
        }
        newPet = new Dog(petName, age, extraInfo);
        petId = "D" + std::to_string(currentDogs);
        newPet->setId(petId);
        pets[petCount] = newPet;
        currentDogs++;
        petCount++;
        std::cout << "Success: " << petName << " has been added as a Dog!, Pet ID: " << petId << "" << std::endl;
        return;
    }

    if (currentCats == catCapacity) {
        std::cout << "Error: No space for more cats!" << std::endl;
        return;
    }
    newPet = new Cat(petName, age, extraInfo);
    petId = "C" + std::to_string(currentCats);
    newPet->setId(petId);
    pets[petCount] = newPet;
    currentCats++;
    petCount++;
    std::cout << "Success: " << petName << " has been added as a Cat!, Pet ID: " << petId << "" << std::endl;
    return;
}
/* Adds a pet to the shelter.
* Input:
* - petName: Name of the pet.
* - age: Age of the pet in years.
* - isDog: If true, adds a dog; if false, adds a cat.
* - extraInfo: For dogs, this is the breed; for cats, this is the color.
*
* Process:
* - If shelter is full, prints "Error: Shelter is at full capacity!".
* - If dog capacity is full, prints "Error: No space for more dogs!".
* - If cat capacity is full, prints "Error: No space for more cats!".
*
* - If addition is successful, system will create a **unique pet ID** based on pet type:
*   - If dog, ID will be "D" followed by the dog's sequential number. Ex: "D1", "D2", etc.
*   - If cat, ID will be "C" followed by the cat's sequential number. Ex: "C1", "C2", etc.
*
* - If addition is successful, prints:
*   "Success: <petName> has been added as a <Dog/Cat>! Pet ID: <petID>"
*/

template<class T>
T* PetShelter<T>::findPet(const std::string &petID) const{
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (pets[i] != nullptr && pets[i]->getId() == petID){
            pets[i]->displayInfo();
            return dynamic_cast<T*>(pets[i]);
        }
    }

    std::cout << "Pet ID is invalid!" << std::endl;
    return nullptr;
}

/* Checks if a pet with the given ID exists in the shelter.
    * Input:
    * - petID: ID of the pet to check.
    *
    * Output:
    * - If found, prints pet details using the displayInfo() method.
    * - If not found, prints "Pet ID is invalid!".
    * Note: Uses dynamic_cast to safely convert from Pet* to T* when returning.
    */
template<class T>
void PetShelter<T>::listAllPets() const {
    if (petCount == 0) {
        std::cout << "No pets in the shelter yet!" << std::endl;
        return;
    }
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (pets[i] != nullptr){
            std::cout << i+1 << ". ";
            pets[i]->displayInfo();
        }
    }
}
/* Displays a list of all pets in the shelter.
    * Output:
    * - If no pets in the shelter, prints "No pets in the shelter yet!".
    * - If pets exist, prints in the format:
    *   "<number>. <pet.displayInfo()>"
    *
    * - Numbering in output starts from 1.
    */
template<class T>
int PetShelter<T>::calculateCost() const{
    int cost = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (dynamic_cast<Dog*>(pets[i])) cost += 75;
        else if (dynamic_cast<Cat*>(pets[i])) cost += 60;
    }
    return cost;
}
/* Calculates total cost of maintaining all pets in the shelter.
    * - Dogs cost 75 per day.
    * - Cats cost 60 per day.
    * 
    * Output: Total daily maintenance cost as an integer.
    * Note: Uses dynamic_cast to determine the type of pet (Dog or Cat) 
    * to apply the correct maintenance cost.
    * Example:
    *   if (dynamic_cast<Dog*>(pets[i])) { cost += 75; }
    *   else if (dynamic_cast<Cat*>(pets[i])) { cost += 60; }
    */
template<class T>
void PetShelter<T>::removePet(const std::string &petID){
    std::string petName;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++){
        if (pets[i] != nullptr && pets[i]->getId() == petID){
            if (dynamic_cast<Dog*>(pets[i])) currentDogs--;
            else if (dynamic_cast<Cat*>(pets[i])) currentCats--;
            std::cout << pets[i]->getName() << " has been removed from the shelter." << std::endl;
            delete pets[i];
            pets[i] = nullptr;
            return;
        }
    }
    std::cout << "Pet ID is invalid!" << std::endl;
    return;
}
/* Removes a pet with the given ID from the shelter.
    * Input:
    * - petID: ID of the pet to remove.
    *
    * Output:
    * - If found and removed, prints "<petName> has been removed from the shelter."
    * - If not found, prints "Pet ID is invalid!"
    * Note: Uses dynamic_cast to determine pet type when updating counters:
    *   if (dynamic_cast<Dog*>(pets[i])) { currentDogs--; }
    *   else if (dynamic_cast<Cat*>(pets[i])) { currentCats--; }
    */
