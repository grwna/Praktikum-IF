# include "Kendaraan.cpp"
# include <iostream>
using namespace std;

class Mobil : public Kendaraan {
    private:
        string supir;
    public:
        Mobil() : Kendaraan(), supir("XXXX"){}
        Mobil(int nomor, int tahun_keluaran, string merk, string supir) : Kendaraan(nomor, tahun_keluaran, merk), supir(supir){}

        void printInfo() override{
            Kendaraan::printInfo();
            cout << "Kategori: Mobil" << endl;
        }

        int biayaSewa(int lamaSewa) override{
            return lamaSewa * 500000;
        }
};

class Minibus : public Kendaraan {
    public:
        Minibus() : Kendaraan(){}
        Minibus(int nomor, int tahun_keluaran, string merk) : Kendaraan(nomor, tahun_keluaran, merk){}

        void printInfo() override{
            Kendaraan::printInfo();
            cout << "Kategori: Minibus" << endl;
        }

        int biayaSewa(int lamaSewa) override{
            return lamaSewa <= 5 ? 5000000 : 5000000 + 500000 * (lamaSewa - 5);
        }
};

class Bus : public Kendaraan {
    private:
        int kapasitas;
    public:
        Bus() : Kendaraan(), kapasitas(0){}
        Bus(int nomor, int tahun_keluaran, string merk, int kapasitas) : Kendaraan(nomor, tahun_keluaran, merk), kapasitas(kapasitas){}

        void printInfo() override{
            Kendaraan::printInfo();
            cout << "Kategori: Bus" << endl;
        }

        int biayaSewa(int lamaSewa) override{
            return lamaSewa * 1000000;
        }

        double diskonSewa(int lamaSewa) {
            if (lamaSewa > 10){
                return biayaSewa(lamaSewa) * 0.9;
            }
            return biayaSewa(lamaSewa);
        }
};