#include "Weed.hpp"
#include <iostream>

Weed::Weed(){
    many = 1;
}

Weed::Weed(int n){
    many = n;
}

Weed::Weed(const Weed &b) : many(b.many){}

Weed::~Weed(){};

void Weed::step(){
    int n = many;
    while (n--){
        std::cout << "kresek...";
    }
    std::cout << std::endl;
}