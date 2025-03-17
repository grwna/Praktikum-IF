# include "Kendaraan.cpp"

class KoleksiKendaraan {
    private:
        Kendaraan* listKendaraan;
        int size;
        int neff;

    public:
        KoleksiKendaraan(){
            size = 100;
            neff = 0;
            listKendaraan = new Kendaraan[size];
        }

        KoleksiKendaraan(int size){
            this->size = size;
            neff = 0;
            listKendaraan = new Kendaraan[size];  
        }

        KoleksiKendaraan(const KoleksiKendaraan& kk) :
            size(kk.size), neff(kk.neff){
                listKendaraan = new Kendaraan[size];
                for (int i = 0; i < neff; i++){
                    listKendaraan[i] = kk.listKendaraan[i];
                }
            }

        ~KoleksiKendaraan(){}

        void printAll(){
            for (int i = 0; i < neff; i++){
                listKendaraan[i].printInfo();
            }
        }

        KoleksiKendaraan& operator>>(Kendaraan k){
            listKendaraan[neff] = k;
            neff++; 
            return *this;
        }

        KoleksiKendaraan& operator>>(KoleksiKendaraan kk){
            for (int i = 0; i < kk.neff; i++){
                listKendaraan[neff] = kk.listKendaraan[i];
                neff++;
            }
            return *this;
        }
};