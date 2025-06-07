
public class Redis<K, V> {
    private K key;
    private V value;
    private long ttl;

    public Redis(K k, V v, long ttl) throws InvalidTtlException {
        this.key = k;
        this.value = v;
        this.ttl = ttl;
        if (ttl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
    }

    public K getKey(){
        return this.key;
    } 
    
    public V getVal(long elapsedSeconds) throws TtlExpiredException {
        if (elapsedSeconds >= this.ttl){
            throw new TtlExpiredException(this.key + " expired");
        }
        return this.value;
    }
    
    public void setKey(K k){
        this.key = k;
    }

    public void setVal(V v){
        this.value = v;
    }

    public long getRemainingTtl(long elapsedSeconds){
        return Math.max(this.ttl - elapsedSeconds, 0);
    }

    public void refresh(long ttl) throws InvalidTtlException {
        if (ttl <= 0) {
            throw new InvalidTtlException("TTL must be positive");
        }
        this.ttl = ttl;
    }

    public boolean isEqual(Redis<?, ?> c){
        if (!this.key.equals(c.key)) return false; 
        if (!this.value.equals(c.value)) return false; 
        return true;
    }

    public int nearEQ(Redis<?,?>c){
        int eq = 0;
        if (this.key.equals(c.key)) eq += 1; 
        if (this.value.equals(c.value)) eq += 2; 
        return eq;
    }
}
