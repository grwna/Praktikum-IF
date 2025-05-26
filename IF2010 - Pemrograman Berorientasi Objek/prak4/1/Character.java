class Character extends Unit implements Damageable {
    private int score;

    public Character(){
        super("Player1", 100);
        this.score = 0;
    } 

    public Character(String name, int health, int score){
        super(name, health);
        this.score = score;
    } 

    public int getScore(){
        return this.score;
    }
    public void setScore(int score){
        this.score = score;
    }

    public void takeDamage(int damage){
        this.health -= damage;
        if (this.health <= 0){
            System.out.print(name);
            System.out.println(" has been defeated");
        }
    }
    public void increaseScore(int points){
        this.score += points;
    }

    @Override
    public String toString(){
        String string = name + " [Health: " + health + ", Score: " + score + "]";
        return string;
    }
}