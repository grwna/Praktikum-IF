#include <iostream>
#include <string>
#include <vector> // Include if PetShelter uses std::vector internally

// --- Include your header files ---
// Make sure these paths are correct relative to your main.cpp
#include "Pet.hpp"         // Base Pet class (ensure virtual destructor!)
#include "Dog.hpp"         // Derived Dog class
#include "Cat.hpp"         // Derived Cat class
#include "PetShelter.hpp" // PetShelter template class declaration

int main() {
    // --- Create a PetShelter instance ---
    // Using the constructor with custom capacities (e.g., 3 dogs, 2 cats)
    // Ensure MAX_SHELTER_CAPACITY in PetShelter.hpp is >= 5 for this example
    std::cout << "Creating Pet Shelter 'Happy Paws' (Capacity: 3 Dogs, 2 Cats)..." << std::endl;
    PetShelter<Pet> happyPaws("Happy Paws", 3, 2);
    std::cout << "Shelter Name: " << happyPaws.getShelterName() << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // --- List pets when empty ---
    std::cout << "\nListing pets initially:" << std::endl;
    happyPaws.listAllPets();
    std::cout << "----------------------------------------" << std::endl;

    // --- Add Pets ---
    std::cout << "\nAdding pets..." << std::endl;
    happyPaws.addPet("Buddy", 5, true, "Golden Retriever"); // Dog 1 (ID: D0)
    happyPaws.addPet("Lucy", 3, true, "Beagle");         // Dog 2 (ID: D1)
    happyPaws.addPet("Whiskers", 2, false, "Tabby");       // Cat 1 (ID: C0)
    happyPaws.addPet("Max", 7, true, "German Shepherd"); // Dog 3 (ID: D2)
    std::cout << "----------------------------------------" << std::endl;

    // --- List all pets ---
    std::cout << "\nListing all pets after additions:" << std::endl;
    happyPaws.listAllPets();
    std::cout << "----------------------------------------" << std::endl;

    // --- Test adding beyond capacity ---
    std::cout << "\nAttempting to add beyond capacity:" << std::endl;
    happyPaws.addPet("Rocky", 4, true, "Boxer");      // Should fail (Dog capacity full)
    happyPaws.addPet("Shadow", 1, false, "Siamese");   // Cat 2 (ID: C1) - Should succeed
    happyPaws.addPet("Misty", 6, false, "Persian");    // Should fail (Cat capacity full)
    happyPaws.addPet("Daisy", 2, true, "Poodle");     // Should fail (Dog capacity full)
    std::cout << "----------------------------------------" << std::endl;

    // --- List all pets again ---
    std::cout << "\nListing all pets after capacity tests:" << std::endl;
    happyPaws.listAllPets();
    std::cout << "----------------------------------------" << std::endl;

    // --- Find Pets ---
    std::cout << "\nFinding pets:" << std::endl;
    std::cout << "Finding Pet ID D1:" << std::endl;
    Pet* foundPet = happyPaws.findPet("D1"); // Find Lucy (Dog)
    // Note: findPet in your implementation already prints details.
    // If findPet returned nullptr, we could check here:
    // if (foundPet) { std::cout << "Found: " << foundPet->getName() << std::endl; }

    std::cout << "\nFinding Pet ID C0:" << std::endl;
    happyPaws.findPet("C0"); // Find Whiskers (Cat)

    std::cout << "\nFinding Pet ID Z9 (invalid):" << std::endl;
    happyPaws.findPet("Z9"); // Try finding a non-existent pet
    std::cout << "----------------------------------------" << std::endl;

    // --- Calculate Maintenance Cost ---
    // Assumes Dog=75, Cat=60
    // Expected: 3 Dogs * 75 + 2 Cats * 60 = 225 + 120 = 345
    std::cout << "\nCalculating total daily cost:" << std::endl;
    int totalCost = happyPaws.calculateCost();
    std::cout << "Total daily maintenance cost: " << totalCost << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // --- Remove Pets ---
    std::cout << "\nRemoving pets:" << std::endl;
    happyPaws.removePet("D1"); // Remove Lucy (Dog)
    happyPaws.removePet("X5"); // Try removing invalid ID
    happyPaws.removePet("C0"); // Remove Whiskers (Cat)
    std::cout << "----------------------------------------" << std::endl;

    // --- List pets after removal ---
    std::cout << "\nListing pets after removals:" << std::endl;
    happyPaws.listAllPets();
    std::cout << "----------------------------------------" << std::endl;

    // --- Calculate cost after removal ---
    // Expected: 2 Dogs * 75 + 1 Cat * 60 = 150 + 60 = 210
    std::cout << "\nCalculating cost after removals:" << std::endl;
    totalCost = happyPaws.calculateCost();
    std::cout << "Total daily maintenance cost: " << totalCost << std::endl;
    std::cout << "----------------------------------------" << std::endl;

     // --- Add another pet to test slot reuse (if implemented) ---
    std::cout << "\nAdding another dog after removal:" << std::endl;
    happyPaws.addPet("Charlie", 1, true, "Labrador"); // Should add Dog (ID: D3 - assuming simple counter)
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "\nListing pets at the end:" << std::endl;
    happyPaws.listAllPets();
    std::cout << "----------------------------------------" << std::endl;

    std::cout << "\nTesting complete. Shelter object going out of scope (destructor called)." << std::endl;

    return 0; // Indicates successful execution
} // happyPaws destructor is called here, cleaning up remaining pets