# include "Item.hpp"

int Item::totalRevenue = 0;
int Item::totalItems = 0;

Item::Item() : serialNum(totalItems+1){
    stock = 0;
    price = 0;
    sold = 0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum(totalItems+1){
    this->stock = stock;
    this->price = price;
    this->sold = 0;
    totalItems++;
}

Item::Item(const Item& other) : stock(other.stock), price(other.price), sold(other.sold), serialNum(totalItems+1){
    totalItems++;
}

Item::~Item(){
}

int Item::getSerialNum() const{
    return this->serialNum;
}

int Item::getSold() const{
    return this->sold;
}

int Item::getPrice() const{
    return this->price;
}

void Item::addStock(int addedStock){
    this->stock += addedStock > 0 ? addedStock : 0;
}

void Item::sell(int soldStock){
    int tempSold = soldStock > stock ? stock : soldStock;
    this->sold += tempSold;
    this->stock -= tempSold;
    totalRevenue += (tempSold * this->price);
}

void Item::setPrice(int newPrice){
    this->price = newPrice;
}