#include "PetShelter.hpp"

template <class T>
PetShelter<T>::PetShelter(std::string shelterName) {
    this->shelterName = shelterName;
    this->dogCapacity = 8;
    this->catCapacity = 12;
    this->petCount = 0;
    this->currentDogs = 0;
    this->currentCats = 0;

    for (int i = 0; i < MAX_SHELTER_CAPACITY; ++i) {
        this->pets[i] = nullptr;
    }
}

template <class T>
PetShelter<T>::PetShelter(std::string shelterName, int dogCapacity, int catCapacity) {
    int totCap = dogCapacity + catCapacity;

    this->shelterName = shelterName;
    this->dogCapacity = dogCapacity;
    this->catCapacity = catCapacity;
    this->petCount = 0;
    this->currentDogs = 0;
    this->currentCats = 0;
    
    for (int i = 0; i < MAX_SHELTER_CAPACITY; ++i) {
        this->pets[i] = nullptr;
    }
    if (totCap > MAX_SHELTER_CAPACITY) {
        std::cout << "The total capacity you construct is " << totCap << ", meanwhile the shelter capacity is " << MAX_SHELTER_CAPACITY << "." << std::endl;
        this->dogCapacity = 8;
        this->catCapacity = 12;
    }

}


template <class T>
PetShelter<T>::~PetShelter() {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        delete pets[i];
        pets[i] = nullptr;
    }
}

template<class T>
std::string PetShelter<T>::getShelterName() const {
    return this->shelterName;
}

template<class T>
void PetShelter<T>::addPet(const std::string &petName, int age, bool isDog, const std::string &extraInfo) {
    std::string petId;
    Pet* newPet = nullptr;
    int addIndex = -1;

    if (petCount >= MAX_SHELTER_CAPACITY) {
        std::cout << "Error: Shelter is at full capacity!" << std::endl;
        return;
    }

    if (isDog && currentDogs >= dogCapacity) {
        std::cout << "Error: No space for more dogs!" << std::endl;
        return;
    }
    if (!isDog && currentCats >= catCapacity) {
        std::cout << "Error: No space for more cats!" << std::endl;
        return;
    }

    for (int i = 0; i < MAX_SHELTER_CAPACITY; ++i) {
        if (pets[i] == nullptr) {
            addIndex = i;
            break;
        }
    }

    if (addIndex == -1) {
        std::cout << "Error: Shelter is at full capacity!" << std::endl;
        return;
    }

    if (isDog) {
        newPet = new Dog(petName, age, extraInfo);
        petId = "D" + std::to_string(currentDogs + 1);
        currentDogs++;
    } else {
        newPet = new Cat(petName, age, extraInfo);
        petId = "C" + std::to_string(currentCats + 1);
        currentCats++;
    }

    newPet->setId(petId);
    pets[addIndex] = newPet;
    petCount++;

    std::cout << "Success: " << petName << " has been added as a "
              << (isDog ? "Dog" : "Cat") << "! Pet ID: " << petId << std::endl;
}


template<class T>
T* PetShelter<T>::findPet(const std::string &petID) const {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] != nullptr && pets[i]->getId() == petID) {
            pets[i]->displayInfo();
            return dynamic_cast<T*>(pets[i]);
        }
    }
    std::cout << "Pet ID is invalid!" << std::endl;
    return nullptr;
}


template<class T>
void PetShelter<T>::listAllPets() const {
    if (petCount == 0) {
        std::cout << "No pets in the shelter yet!" << std::endl;
        return;
    }
    int displayNum = 1;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] != nullptr) {
            std::cout << displayNum++ << ". ";
            pets[i]->displayInfo();
        }
    }
}


template<class T>
int PetShelter<T>::calculateCost() const {
    int cost = 0;
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] != nullptr) {
            if (dynamic_cast<Dog*>(pets[i])) cost += 75;
            else if (dynamic_cast<Cat*>(pets[i])) cost += 60;
        }
    }
    return cost;
}


template<class T>
void PetShelter<T>::removePet(const std::string &petID) {
    for (int i = 0; i < MAX_SHELTER_CAPACITY; i++) {
        if (pets[i] != nullptr && pets[i]->getId() == petID) {
            std::cout << pets[i]->getName() << " has been removed from the shelter." << std::endl;
            if (dynamic_cast<Dog*>(pets[i])) currentDogs--;
            else if (dynamic_cast<Cat*>(pets[i])) currentCats--;

            delete pets[i];
            pets[i] = nullptr;
            petCount--;
            return;
        }
    }
    std::cout << "Pet ID is invalid!" << std::endl;
}

template class PetShelter<Pet>;
template class PetShelter<Cat>;
template class PetShelter<Dog>;