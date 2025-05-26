public class Main {
    public static void main(String[] args) {
        Character p1 = new Character();
        Character p2 = new Character("Alice", 50, 120);

        System.out.println(p1);
        System.out.println(p2);

        p2.takeDamage(30);
        p2.increaseScore(20);
        System.out.println(p2);

        p2.takeDamage(100);

        NPC npc = new NPC("Gandalf", 200, "You shall not pass!");
        System.out.println(npc);
        npc.interact();
    }
}   