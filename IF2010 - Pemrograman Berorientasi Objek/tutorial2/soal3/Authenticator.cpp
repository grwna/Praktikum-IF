# include "Authenticator.hpp"
using namespace std;

Authenticator::Authenticator(){
    secretResource = "Ini adalah data rahasia!";
    userCount = 0;
    currentUser = nullptr;
    for (int i = 0; i < MAX_USERS; i++){
        users[i] = nullptr;
    }
}

void Authenticator::registerUser(const string &username, const string &password, bool isAdmin){
  if (userCount == MAX_USERS){
    cout << "Gagal: Kapasitas user penuh!" << endl;
    return;
  }

  for (int i = 0; i < userCount; i++){
    if (users[i]->getUsername() == username){
        cout << "Gagal: Username sudah digunakan!" << endl;
        return;
    }
  }

  cout << "Sukses: User " << username << " berhasil terdaftar!" << endl;
  User *newUser;
if (isAdmin){
    newUser = new AdminUser(username, password);
} else {
    newUser = new User(username, password);
}
users[userCount] = newUser;
userCount++;

}

void Authenticator::login(const string &username, const string &password){
    for (int i = 0; i < userCount; i++){
        bool cond1 = users[i]->getUsername() == username;
        bool cond2 = users[i]->checkPassword(password);
        if (cond1 && cond2){
            cout << "Sukses: Login berhasil! Selamat datang, " << username << "." << endl;
            currentUser = users[i];
            return;
        }
    }
    cout << "Gagal: Username atau password salah!" << endl;
}

void Authenticator::logout(){
    if (!currentUser){
        cout << "Gagal: Tidak ada user yang sedang login!" << endl;
    } else {
        cout << "Sukses: User " << currentUser->getUsername() << " telah logout." << endl;
    }
    
    currentUser = nullptr;
}

void Authenticator::accessResource() const{
    if (!currentUser) {
        cout << "Akses ditolak! Silakan login terlebih dahulu." << endl;
    } else {
        cout << "Resource: " << secretResource << endl;
    }
}

void Authenticator::setResource(const string &newResource){
    if (!currentUser){
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu." << endl;
    }
    else if (!currentUser->isAdmin()){
        cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini." << endl;
    } else {
        cout << "Sukses: Resource telah diperbarui oleh " << currentUser->getUsername() << "." << endl;
        secretResource = newResource;
    }
}

Authenticator::~Authenticator(){
    currentUser = nullptr;
    for (int i = 0; i < userCount; i++){
        delete users[i];
        users[i] = nullptr;
    }
}