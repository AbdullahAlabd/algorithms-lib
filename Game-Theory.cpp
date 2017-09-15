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
