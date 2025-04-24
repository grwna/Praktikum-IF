class Goose{
    private String name;
    private int honk;

    public Goose(){
        this.name = "Horrible";
        this.honk = 1;
    }

    public Goose(String name, int honk){
        this.name = name;
        this.honk = honk;
    }

    /* Methods */
    public void steal(String thing){
        System.out.println(this.name + " steals " + thing);
    }

    public String toString(){
        String s = this.name + " goose says ";
        for (int i = 0; i < this.honk; i++){
            s += "honk";
            if (i < this.honk - 1){
                s += " ";
            }
        }
        return s;
    }
}