int ganganji(int x) {
  int result = x + (x >> 3);
  int overflow = ~(1 << 31);
  int msb = ((result >> 31) & 1);
  int status_overflow = msb << 31 >> 31;

  return (~status_overflow & result) | (status_overflow & overflow);
}