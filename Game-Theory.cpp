int mex(set<int> &s){ // mex in O(n)
    int i = 0;
    for(auto it = s.begin(); it != s.end(); i++, it++)
        if( *it!= i)
            break;
    return i;
}
