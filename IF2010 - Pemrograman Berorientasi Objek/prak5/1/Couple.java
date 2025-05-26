public class Couple<K, V> {
    private K key;
    private V value;

    public Couple(K key, V value){
        this.key = key;
        this.value = value;
    }

    public K getKey(){
        return this.key;
    }

    public V getVal(){
        return this.value;
    }

    public void setKey(K key){
        this.key = key;
    }

    public void setVal(V val){
        this.value = val;
    }

    public boolean isEqual(Couple c){
        return (this.key == c.key && this.value == c.value);
    }

    public int nearEQ(Couple c){
        if (isEqual(c)) return 3;
        else if (this.key != c.key && this.value == c.value) return 2;
        else if (this.key == c.key && this.value != c.value) return 1;
        return 0;
    }
}