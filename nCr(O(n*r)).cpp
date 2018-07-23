int nCr(int n, int r) {
  return ( (r == 0 || r == n) ? 1 : nCr(n-1, r-1) + nCr(n-1, r) );
}
