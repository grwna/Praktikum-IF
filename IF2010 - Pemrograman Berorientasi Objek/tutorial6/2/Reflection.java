import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods(){
        ArrayList<String> methodNames = new ArrayList<>();
        Class<?> ghost = null;
        try {
            ghost = Class.forName("Ghost");
        }
        catch (Exception e){
            return new ArrayList<>();
        }
        Method[] methods = ghost.getDeclaredMethods();
        for (Method m : methods){
            m.setAccessible(true);
            methodNames.add(m.getName());
        }
        return methodNames;
    }   

    public Integer sumGhost() throws Exception{
        Class<?> ghost = null;
        int sum = 0;
        try {ghost = Class.forName("Ghost");}
        catch (Exception e) {}

        Object ghostz = ghost.getDeclaredConstructor().newInstance();

        Method[] methods = ghost.getDeclaredMethods();
        for (Method m : methods){
            if (m.getReturnType() == Integer.class){
                m.setAccessible(true);
                sum += (Integer) m.invoke(ghostz);
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception{
        Class<?> ghost = null;
        String result = "";
        try {ghost = Class.forName("Ghost");}
        catch (Exception e) {}

        Object ghostz = ghost.getDeclaredConstructor().newInstance();

        Method[] methods = ghost.getDeclaredMethods();
        for (Method m : methods){
            if (m.getReturnType() == String.class){
                m.setAccessible(true);
                result += (String) m.invoke(ghostz);
            }
        }
        return result;
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception {
        for (Secret s : sl){
            if (s.isThis(email)){
                Field field = Secret.class.getDeclaredField("uniqueId");
                field.setAccessible(true);
                return (String) field.get(s);
            }
        }
        return "NaN";
    }
}
