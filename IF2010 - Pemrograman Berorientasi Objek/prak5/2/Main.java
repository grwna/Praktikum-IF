public class Main{
    public static void main(String args[]){
        SistemMasukSekolahList sml = new SistemMasukSekolahListImpl();
        Student lol = new Student("haha", 23, 23);
        sml.addFirstStudent(lol);
    }
}