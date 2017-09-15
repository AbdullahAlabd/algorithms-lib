int mex(set<int> &s){ // using set
    int mx = 0;
    for(auto it = s.begin(); it != s.end(); mx++, it++)
        if( *it != mx)
            break;
    return mx;
}

int mex(unordered_set<int> &s){ // using unorderd set
    int mx = 0;
    while(s.find(mx) != s.end())
        mx++;
    return mx;
}

// the fastest way
int mex(bool s[]){
    int mx = 0;
    while(s[mx]) ++mx;
    return mx;
    // in grundy() use : bool s[32]= {}; to initialize with zero
    // and fill occupied valid values by 1
}


bool nim(vector<int> &v){
    int ans = 0;
    for(int i = 0; i < (int)v.size(); ++i)
        ans ^= v[i];
    return ans != 0;
}

bool misere(vector<int> &v){
    int ans = 0;
    bool lastlv = 1;
    for(int i = 0; i < (int)v.size(); ++i){
        ans ^= v[i];
        lastlv &= v[i] <= 1;
    }
    if(lastlv)
        return ans == 0;
    return ans != 0;
}
