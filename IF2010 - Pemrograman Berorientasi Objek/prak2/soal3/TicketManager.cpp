# include "TicketManager.hpp"

TicketManager::TicketManager(string eventName){
    this->eventName = eventName;
    this->vipCapacity = 5;
    this->regularCapacity = 10;
    this->ticketCount = 0;
    this->currentVIPTickets = 0;
    this->currentRegularTickets = 0;
    for (int i = 0; i < VENUE_CAPACITY; i++){
        tickets[i] = nullptr;
    }
}

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity){
    if (vipCapacity + regularCapacity > VENUE_CAPACITY){
        cout << "The total capacity you construct is " << vipCapacity + regularCapacity <<", meanwhile the venue capacity is 15" << endl;
        return;
    }
    this->eventName = eventName;
    this->vipCapacity = vipCapacity;
    this->regularCapacity = regularCapacity;
    this->ticketCount = 0;
    this->currentVIPTickets = 0;
    this->currentRegularTickets = 0;
    for (int i = 0; i < VENUE_CAPACITY; i++){
        tickets[i] = nullptr;
    }
}

TicketManager::~TicketManager(){
    for (int i = 0; i < VENUE_CAPACITY; i++){
        tickets[i] = nullptr;
    }
}

string TicketManager::getEventName() const {
    return this->eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP){
    if (this->ticketCount == VENUE_CAPACITY){
        cout << "Error: All tickets are sold out!" << endl;
        return;
    }
    if (isVIP && (currentVIPTickets == vipCapacity)){
        cout << "Error: No VIP tickets left!" << endl;
        return;
    }
    if (!isVIP && (currentRegularTickets == regularCapacity)){
        cout << "Error: No Regular tickets left!" << endl;
        return;
    }
    if (isVIP){
        string ID = "V" + to_string(currentVIPTickets+1);
        tickets[ticketCount] = new VIPTicket(ID,ownerName);
        cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: " << ID << endl;
        currentVIPTickets++;
    } else {
        string ID = "R" + to_string(currentRegularTickets+1);
        tickets[ticketCount] = new RegularTicket(ID,ownerName);        
        cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: " << ID << endl;
        currentRegularTickets++;
    }
    ticketCount++;
}

void TicketManager::checkTicket(const string &ticketID) const{
    for (int i = 0; i < ticketCount; i++){
        if (tickets[i]->getTicketID() == ticketID){
            tickets[i]->printTicket();
            return;
        }
    }
    cout << "Ticket ID is invalid!" << endl;
}

void TicketManager::listAudience() const{
    if (ticketCount == 0){
        cout << "No audience yet!" << endl;
    } else {
        for(int i = 0; i < ticketCount; i++){
            cout << i+1 << ". ";
            tickets[i]->printTicket();
        }
    }
}

int TicketManager::calculateRevenue() const{
    return currentRegularTickets * 275 + currentVIPTickets * 500;
}