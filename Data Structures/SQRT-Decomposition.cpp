struct sqrtDecomp{

    static const int MAXN = 10000;
    static const int BLOCK_SZ = sqrt(MAXN);
    static const int I = 0 ;

    int arr[MAXN];
    int block[BLOCK_SZ]; // since BLOCK_SZ = MAXN/BLOCK_SZ

    inline int op(int a,int b){
        return a + b;
    }

    sqrtDecomp(){
        memset(arr, 0, sizeof arr);
        memset(block, 0, sizeof block);
    }

    // build in : O(n)
    void build(int input[], int n){

        for(int i = 0; i < BLOCK_SZ; ++i)
            block[i] = I;

        for(int i = 0; i < n; ++i){
            arr[i] = input[i];
            block[i/BLOCK_SZ] = op(block[i/BLOCK_SZ], arr[i]);
        }
    }


    // get in : O(sqrt(n))

    int get(int st, int ed){

        int res = I;
        while( st%BLOCK_SZ!=0 && st<=ed ){
            res = op(res, arr[st]);
            st++;
        }
        while(st+BLOCK_SZ-1<=ed){
            res = op( res, block[st/BLOCK_SZ] );
            st += BLOCK_SZ;
        }
        while(st <= ed){
            res = op(res, arr[st]);
            st++;
        }
        return res;
    }

    // update in : O(1) for "Sum" query - valid for special kind of operations (op)
    /*
    void update(int idx, int val){
        int blockNumber = idx / blk_sz;
        block[blockNumber] += val - arr[idx];
        arr[idx] = val;
    }
    */

    // update in :  O(sqrt(n))
    void update(int idx, int val){

        int start_block = idx/BLOCK_SZ;
        int st = start_block * BLOCK_SZ;

        arr[idx] = val;
        block[start_block] = I;

        do{ // update the block
            block[start_block] = op(block[start_block], arr[st++]);
        }while(st%BLOCK_SZ!=0);
    }
};
