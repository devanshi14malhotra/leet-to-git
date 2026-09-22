class Solution {
public:
    int n, K;
    vector<int> tprod;
    vector<array<int,25>> tmat;

    void pull(int node){
        int L=node*2, R=node*2+1;
        tprod[node] = (tprod[L]*tprod[R])%K;
        auto &M = tmat[node]; M.fill(0);
        int pL = tprod[L];
        for(int in=0; in<K; in++){
            for(int out=0; out<K; out++) M[in*K+out] += tmat[L][in*K+out];
            int sh = (in*pL)%K;
            for(int out=0; out<K; out++) M[in*K+out] += tmat[R][sh*K+out];
        }
    }
    void setLeaf(int node,int vm){
        tprod[node]=vm;
        auto &M=tmat[node]; M.fill(0);
        for(int in=0;in<K;in++) M[in*K+((in*vm)%K)]=1;
    }
    void build(int node,int l,int r,vector<int>&mod){
        if(l==r){ setLeaf(node,mod[l]); return; }
        int mid=(l+r)/2;
        build(node*2,l,mid,mod); build(node*2+1,mid+1,r,mod);
        pull(node);
    }
    void update(int node,int l,int r,int idx,int vm){
        if(l==r){ setLeaf(node,vm); return; }
        int mid=(l+r)/2;
        if(idx<=mid) update(node*2,l,mid,idx,vm); else update(node*2+1,mid+1,r,idx,vm);
        pull(node);
    }
    void query(int node,int l,int r,int ql,int qr,int &curIn,vector<int>&ans){
        if(qr<l||r<ql) return;
        if(ql<=l&&r<=qr){
            for(int out=0;out<K;out++) ans[out]+=tmat[node][curIn*K+out];
            curIn=(curIn*tprod[node])%K;
            return;
        }
        int mid=(l+r)/2;
        query(node*2,l,mid,ql,qr,curIn,ans);
        query(node*2+1,mid+1,r,ql,qr,curIn,ans);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n=nums.size(); K=k;
        vector<int> mod(n);
        for(int i=0;i<n;i++) mod[i]=nums[i]%K;
        tprod.assign(4*n,0);
        tmat.assign(4*n, array<int,25>{});
        build(1,0,n-1,mod);

        vector<int> res;
        res.reserve(queries.size());
        for(auto &q: queries){
            int index=q[0], value=q[1], start=q[2], x=q[3];
            update(1,0,n-1,index, value%K);
            int curIn = 1 % K;
            vector<int> ans(K,0);
            query(1,0,n-1,start,n-1,curIn,ans);
            res.push_back(ans[x]);
        }
        return res;
    }
};