# include "Kompleks.hpp"

// double real; // Nilai real
// double imag; // Nilai imajiner
Kompleks::Kompleks(){
    real = 0;
    imag = 0;
}                    // Nilai default 0 + 0i
Kompleks::Kompleks(double r, double i){
    real = r;
    imag = i;
}  // r + i*i
Kompleks::Kompleks(const Kompleks& other){
    this->real = other.getReal();
    this->imag = other.getImag();
}

double Kompleks::getReal() const{
    return this->real;
}
double Kompleks::getImag() const{
    return this->imag;
}

double Kompleks::setReal(double r){
    this->real = r;
    return r;
}
double Kompleks::setImag(double i){
    this->imag = i;
    return i;
}

Kompleks Kompleks::operator+(const Kompleks& other) const{
    Kompleks res = Kompleks(this->real + other.getReal(), this->imag + other.getImag());
    return res;
}
// Menambahkan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a + b = (1+3) + (2+4)i = 4 + 6i

Kompleks Kompleks::operator-(const Kompleks& other) const{
    Kompleks res = Kompleks(this->real - other.getReal(), this->imag - other.getImag());
    return res;
}
// Mengurangi dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a - b = (1-3) + (2-4)i = -2 - 2i

Kompleks Kompleks::operator*(const Kompleks& other) const{
    double one = this->getReal() * other.getReal();
    double two = this->getReal() * other.getImag();
    double three = this->getImag() * other.getReal();
    double four = this->getImag() * other.getImag() * -1;
    Kompleks res = Kompleks(one + four, two + three);
    return res;
}
// Mengalikan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a * b = 1*3 + 1*4i + 2i*3 + 2i*4i = 3 + 4i + 6i - 8 = -5 + 10i

bool Kompleks::operator==(const Kompleks& other) const{
    return (this->getImag() == other.getImag() && this->getReal() == other.getReal());
}
// Membandingkan dua bilangan kompleks
// Misal: a = 1 + 2i, b = 3 + 4i;
// a == b = (1==3) && (2==4) = false
// Misal: a = 1 + 2i, b = 1 + 2i;
// a == b = (1==1) && (2==2) = true

Kompleks& Kompleks::operator=(const Kompleks& other){
    this->real = other.getReal();
    this->imag = other.getImag();
    return *this;
}
// Menyalin dua bilangan kompleks

ostream& operator<<(ostream& os, const Kompleks& c){
    string op;
    if (c.imag < 0) op = " - ";
    else op = " + ";
    os << c.real;
    if (c.imag != 0){
        if (c.imag < 0){
            os << op << c.getImag() * -1 << "i";
        } else {
            os << op << c.getImag() << "i";
        }
    }
    return os;
}
// Menampilkan bilangan kompleks
// Note: Tidak menggunakan endl
// Misal: Kompleks(1, 2)
// cout << a << endl; // Output: 1 + 2i
// Jika imajiner < 0; Misal: Kompleks(1, -2)
// cout << a << endl; // Output: 1 - 2i
// Jika nilai imajiner 0, jangan tampilkan i; Misal: Kompleks(1, 0)
// cout << a << endl; // Output: 1

