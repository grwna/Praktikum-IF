# include "Playlist.hpp"
// string name;
// vector<Song> songs;

// Constructor
Playlist::Playlist(string playlistName){
    this->name = playlistName;
}

// Getters
const string& Playlist::getName() const {
    return this->name;
}

const vector<Song>& Playlist::getSongs() const{
    return this->songs;
}

/*
    * Menambahkan salinan lagu yang diberikan ke akhir playlist apabila lagu tersebut belum ada di playlist.
    * Menggunakan Song::operator== untuk perbandingan.
    */
void Playlist::addSong(const Song &song){
    bool found = false;
    for (int i = 0; i < songs.size(); i++){
        if (songs[i] == song) {
            found = true;
            break;
        }
    }
    if (!found){
        songs.push_back(song);
    }
}

/*
    * Menghapus kemunculan pertama dari lagu yang ditentukan dari playlist.
    * Mengembalikan true jika lagu berhasil dihapus, false jika tidak.
    * Menggunakan Song::operator== untuk perbandingan.
    */
bool Playlist::removeSong(const Song &songToRemove){
    for (int i = 0; i < songs.size(); i++){
        if (songs[i] == songToRemove) {
            songs.erase(songs.begin() + i);
            return true;
        }
    }
    return false;
}

/*
    * Menghapus lagu pada indeks yang ditentukan.
    * Melempar out_of_range jika indeks tidak valid.
    */
void Playlist::removeSongByIndex(size_t index){
    try{
        if (index < 0 || index >= songs.size()) throw out_of_range("Index out of range");
        songs.erase(songs.begin() + index);
    }
    catch (out_of_range e){
        cout << e.what() << endl;
    }
}

/*
    * Mengembalikan jumlah lagu dalam playlist.
    */
size_t Playlist::numberOfSongs() const{
    return songs.size();
}

/*
    * Friend function untuk mencetak isi playlist.
    * Format:
    * Playlist: <nama_playlist> (<jumlah_lagu> lagu)
    * 1. <lagu1>
    * 2. <lagu2>
    * ...
    * <jumlah_lagu>. <laguN> <endl>
    */
ostream &operator<<(ostream &os, const Playlist &pl){
    os << "Playlist: " << pl.name << " (" << pl.songs.size() << " lagu)" << endl;;
    for (int i = 0; i < pl.songs.size(); i++) {
        os << i+1 << ". " << pl.songs[i] << endl;
    }
    return os;
}
