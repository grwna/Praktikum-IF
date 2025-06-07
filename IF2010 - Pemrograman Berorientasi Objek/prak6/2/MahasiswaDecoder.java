import java.lang.reflect.*;

public class MahasiswaDecoder {
  private Mahasiswa mahasiswa; 


  MahasiswaDecoder(Mahasiswa mahasiswa) {
    this.mahasiswa = mahasiswa;
  }



  public void addMatkul(String name) throws Exception {
    Method add = Mahasiswa.class.getDeclaredMethod("addMatkul", String.class);
    add.setAccessible(true);
    add.invoke(mahasiswa, name);
  }



  public int getNIM() throws Exception {
    Field nim = Mahasiswa.class.getDeclaredField("NIM");
    nim.setAccessible(true);
    return (int)nim.get(this.mahasiswa);
  }



  public double getIPK() throws Exception {
    Field ipk = Mahasiswa.class.getDeclaredField("IPK");
    ipk.setAccessible(true);
    return (double)ipk.get(this.mahasiswa);
  }
}