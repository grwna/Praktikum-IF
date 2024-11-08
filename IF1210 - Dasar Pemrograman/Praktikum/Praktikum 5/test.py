
def lcg(modulus: int, a: int, c: int, seed: int):
    """Linear congruential generator."""
    while True:
        seed = (a * seed + c) % modulus
        yield seed
modulus = 2
seed = 0
a = 2
c = 5

rng = lcg(modulus,a,c,seed)
print([rng])