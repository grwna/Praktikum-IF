// string nama;
// int berat; // dalam 

#include "Barang.hpp"

    /*
        Constructor Barang
        nama: nama barang
        berat: berat barang
    */
Barang::Barang(string nama, int berat){
    this->nama = nama;
    this->berat = berat;
}

Barang::~Barang(){}

string Barang::getNama() const {
    return nama;
}
int Barang::getBerat() const {
    return berat;
}