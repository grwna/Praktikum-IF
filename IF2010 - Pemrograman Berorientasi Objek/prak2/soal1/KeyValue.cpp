#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 10;

template<class T>
bool isEqual(T a, T b) {
    return a == b;
}

template<>
bool isEqual<double>(double a, double b) {
    return abs(a - b) < 0.01;
}

template<class T, class U>
class KeyValue {
private:
    T* keys;
    U* values;
    int count;

    
    public:
    KeyValue() {
        keys = new T[MAX];
        values = new U[MAX];
        count = 0;
    }

    KeyValue(const KeyValue<T, U>& other) {
        keys = new T[MAX];
        values = new U[MAX];
        count = other.count;
        for (int i = 0; i < count; i++) {
            keys[i] = other.keys[i];
            values[i] = other.values[i];
        }
    }

    ~KeyValue() {
        delete[] keys;
        delete[] values;
    }

    void set(T key, U value) {
        for (int i = 0; i < count; i++) {
            if (isEqual(keys[i], key)) {
                values[i] = value;
                return;
            }
        }

        if (count < MAX) {
            keys[count] = key;
            values[count] = value;
            count++;
        } else {
            cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
        }
    }


    void display(T key) {
        for (int i = 0; i < count; i++) {
            if (isEqual(keys[i], key)) {
                cout << values[i] << endl;
                return;
            }
        }
        cout << "Key tidak ditemukan!" << endl;
    }
};
