class Main {
public static void main(String[] args) {
  Goose g = new Goose();
  Goose h = new Goose("Sung Jin-woo", 3);
  System.out.println(g);
  System.out.println(h);
  h.steal("dagger");
}

}