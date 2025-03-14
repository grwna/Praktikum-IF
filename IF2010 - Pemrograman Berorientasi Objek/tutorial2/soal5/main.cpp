# include "Pokemon.hpp"
# include "FirePokemon.hpp"
# include "WaterPokemon.hpp"
# include "GrassPokemon.hpp"
# include <iostream>
using namespace std;

int main(){
    FirePokemon *charm = new FirePokemon("Charmander");
    FirePokemon *charmCopy = new FirePokemon(*charm);
    WaterPokemon squirt("Squirtle", 100, 20, 10);
    squirt.heal(10);
    WaterPokemon *magik = new WaterPokemon("Magikarp", 100, 20, 0);
    squirt = squirt;
    squirt.attack(*charm);
    squirt.attack(*charm);
    delete charm;

    return 0;
}

/*
Charmander is born
Charmander is born with type: fire | HP: 100 | ATT: 20 | attack count: 0
Charmander is copied
Charmander (copy) is born with type: fire | HP: 100 | ATT: 20 | attack count: 0
Squirtle is born
Squirtle is born with type: water | HP: 100 | ATT: 20 | attack boost: 10
Squirtle heals 10 points | HP: 110
Magikarp is born
Magikarp is born with type: water | HP: 100 | ATT: 20 | attack boost: 0
Squirtle is assigned with type: water | HP: 110 | ATT: 20 | attack boost: 10
Squirtle used Water Gun on Charmander for 40 damage and it's super effective!
Charmander took 40 damage and now has 60 HP
Squirtle's Flow State increases! Current damage: 30
Squirtle used Water Gun on Charmander for 60 damage and it's super effective!
Charmander took 60 damage and now has 0 HP
Charmander has fainted
Squirtle's Flow State increases! Current damage: 40
Charmander has run away
Squirtle has run away
*/