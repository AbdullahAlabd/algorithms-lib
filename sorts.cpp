//bubble
int ar[55];
int bsort(int n){
    int needed = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(ar[j] > ar[j+1]){
                swap(ar[j], ar[j+1]);
                needed++;
            }
        }
    }
    return needed;
}
