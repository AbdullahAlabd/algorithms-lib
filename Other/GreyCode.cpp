int greyToDec(int g) {
    int n = 0;
    while(g) {
        n ^= g;
        g >>= 1;
    }
    return n;
}

int decToGray(int n){
    return n^(n>>1);
}
