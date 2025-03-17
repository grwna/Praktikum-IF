/*
Nama : M. Rayhan Farrukh
NIM : 13523035
*/

#include <string>
#include <iostream>
using namespace std;

class Kendaraan {
    protected:
        int nomor;
        int tahun_keluaran;
        string merk;
    
        public:
            Kendaraan(){
                nomor = 0;
                tahun_keluaran = 0;
                merk = "XXX";
            }

            Kendaraan(int nomor, int tahun_keluaran, string merk){
                this->nomor = nomor;
                this->tahun_keluaran = tahun_keluaran;
                this->merk = merk;
            }

            Kendaraan(const Kendaraan& k) 
                : nomor(k.nomor), tahun_keluaran(k.tahun_keluaran), merk(k.merk){}
            
            virtual ~Kendaraan(){}

            virtual void printInfo(){
                cout << "Nomor: " << nomor << endl;
                cout << "Tahun Keluaran: " << tahun_keluaran << endl;
                cout << "Merk: " << merk << endl;
            };

            virtual int biayaSewa(int lamaSewa) = 0;
};          