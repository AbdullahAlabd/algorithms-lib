int mex(set<int> &s){ // mex in O(n)
    int i = 0;
    for(auto it = s.begin(); it != s.end(); i++, it++)
        if( *it!= i)
            break;
    return i;
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
