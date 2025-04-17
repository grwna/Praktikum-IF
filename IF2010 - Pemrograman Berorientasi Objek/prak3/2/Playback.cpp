#include "Playback.hpp"
// queue<Song> playbackQueue;

/*
* Menambahkan satu lagu ke akhir queue pemutaran.
* Tidak perlu mengecek apakah lagu sudah ada di queue (boleh ada duplikat)
*/
void Playback::addToQueue(const Song &song){
    playbackQueue.push(song);
}

/*
* Menambahkan semua lagu dari playlist yang diberikan ke akhir queue pemutaran,
* dengan mempertahankan urutan mereka dari playlist.
* Tidak perlu mengecek apakah lagu sudah ada di queue (boleh ada duplikat)
*/
void Playback::addToQueue(const Playlist &playlist){
    for (int i = 0; i < playlist.numberOfSongs(); i++){
        playbackQueue.push(playlist.getSongs()[i]);
    }
}

/*
* Memutar lagu berikutnya: Mencetak dengan format "Memutar: <lagu> <endl>" dan menghapusnya dari queue.
* Jika queue kosong, mencetak pesan "Antrian kosong"
*/
void Playback::next(){
    if (!playbackQueue.size()) {
        cout << "Antrian kosong" << endl;
        return;
    }
    cout << "Memutar: " << playbackQueue.front() << endl;
    playbackQueue.pop();
}

/*
* Memutar semua lagu dari queue pemutaran.
* Mencetak dengan format "Memutar: <lagu> <endl>" untuk setiap lagu di queue.
* Jika queue kosong, mencetak pesan "Antrian kosong"
*/
void Playback::playAll(){
    if (!playbackQueue.size()) {
        cout << "Antrian kosong" << endl;
        return;
    }
    while (playbackQueue.size()) {
        next();
    }
}

/*
* Melewati lagu berikutnya: Menghapus lagu dari depan queue tanpa mencetak detail.
* Jika queue kosong, mencetak pesan "Antrian kosong"
*/
void Playback::skip(){
    if (!playbackQueue.size()) {
        cout << "Antrian kosong" << endl;
        return;
    }
    playbackQueue.pop();
}

/*
* Menghapus semua lagu dari queue pemutaran.
*/
void Playback::clearQueue(){
    while (playbackQueue.size()){
        skip();
    }
}

/*
* Memeriksa apakah queue pemutaran kosong.
*/
bool Playback::isEmpty() const{
    return !playbackQueue.size();
}

/*
* Mengembalikan jumlah lagu yang ada dalam queue.
*/
size_t Playback::queueSize() const{
    return playbackQueue.size();
}
