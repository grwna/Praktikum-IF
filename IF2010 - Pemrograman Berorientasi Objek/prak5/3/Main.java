import java.util.ArrayList;
import java.util.List;
public class Main{
    public static void main(String args[]){
        Inventory inventory2 = new Inventory(new ArrayList<Box<?>>());
        inventory2.openAll();
        Box<String> temp = new Box<>("Hello, World!");
        Box<Double> temp2 = new Box<>(321.32323);
        Box<Box<?>> temp3 = new Box<>(temp2);
        inventory2.addBox(temp);
        inventory2.addBox(temp2);
        inventory2.addBox(temp3);
        inventory2.openAll();
        inventory2.removeBox(temp2);
        inventory2.openAll();
    }
}
