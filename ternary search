
typedef long long ll;

ll funci(int x){
    // return some value
}

ll ts(int st, int ed){ //ternary search for finding min in O(log n).
    int l = st, r = ed, l1, r1;

    while(l+3 <= r){
        l1 = l+(r-l)/3;
        r1 = r-(r-l)/3;

        if(funci(l1) < funci(r1)) // < for min
            r = r1;
        else
            l = l1;
    }

    int x = l;
    for(int i = l; i <= r; i++)
        if(funci(i) < funci(x)) // < for min
            x = i;

    return funci(x);
}
///////////////////////
typedef long double ld;

ld weakness(ld x){
    // here func
}

ld ts(ld st, ld ed){

    ld l = st, r = ed, l1, r1;

    for(int i = 0; i < 200; i++) {
        l1 = l+(r-l)/3;
        r1 = r-(r-l)/3;

        if(weakness(l1) < weakness(r1))
            r = r1;
        else
            l = l1;
    }
    return weakness(l);
}
