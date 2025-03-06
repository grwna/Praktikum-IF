#include "SpacingGuildShip.hpp"

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), serialNum(producedShips+1){
    passengerCount = 0;
    spiceStock = 50;
    operatingGuildNavigator = 3;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : 
    maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips+1){
    this->spiceStock = spiceStock;
    this->passengerCount = 0;
    this->operatingGuildNavigator = guildNavigatorCount;
    producedShips++;
};

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& cp) : 
    maxPassengerCap(cp.maxPassengerCap), guildNavigatorCount(cp.guildNavigatorCount), serialNum(producedShips+1), 
    passengerCount(cp.passengerCount), spiceStock(cp.spiceStock), operatingGuildNavigator(cp.operatingGuildNavigator){
    producedShips++;
}

SpacingGuildShip::~SpacingGuildShip(){
}

int SpacingGuildShip::getShipSerialNum() const {
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const {
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance){
    if (operatingGuildNavigator > 0){
        totalGuildTravel += distance / (E * E *  operatingGuildNavigator);
        operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers){
    this->passengerCount += addedPassengers;
    if (this->passengerCount > maxPassengerCap){this->passengerCount = 50;}
}

void SpacingGuildShip::dropOff(int droppedPassengers){
    this->passengerCount -= droppedPassengers;
    if (this->passengerCount < 0){this->passengerCount = 0;}
}

void SpacingGuildShip::refreshNavigator(int n){
    int usedSpice = n * GUILD_NAVIGATOR_SPICE_DOSE;
    while(usedSpice > spiceStock){
        usedSpice -= GUILD_NAVIGATOR_SPICE_DOSE;
        n--;
    }
    operatingGuildNavigator += n;
    spiceStock -= usedSpice;
}

void SpacingGuildShip::transitToArrakis(int addedSpice){
    this->spiceStock += addedSpice;
}