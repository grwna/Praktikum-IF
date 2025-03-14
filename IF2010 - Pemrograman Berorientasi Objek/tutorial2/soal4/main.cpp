# include "Pokemon.hpp"
# include "FirePokemon.hpp"
# include "WaterPokemon.hpp"
# include "GrassPokemon.hpp"
# include <iostream>
using namespace std;

int main(){
    FirePokemon charm("Charmander");
    WaterPokemon squirt("Squirtle", 100, 20, 10);
    squirt.heal(10);
    squirt.attack(charm);
    charm.attack(squirt);
    squirt.attack(charm);

    GrassPokemon bulb("Bulbasaur", 100, 50, 20);
    squirt.attack(bulb);
    bulb.attack(squirt);
    return 0;
}