class SegmentTree{
    private:
    vector<int> sgmt;
    vector<int> lazy;
    public:
    SegmentTree(int n){
        this->sgmt.resize(4*n,0);
        this->lazy.resize(4*n,0);
    }
    
    void Build(int si,int left,int right,vector<int> &num){
        if(left==right){
            sgmt[si]=num[left-1];
            return;
        }
        
        int mid=left+(right-left)/2;
        Build(2*si,left,mid,num);
        Build(2*si+1,mid+1,right,num);
        
        sgmt[si]=sgmt[2*si]+sgmt[2*si+1];
    }
    
    void update(int si,int left,int right,int qi,int val){
        if(left==right){
            sgmt[si]=val;
            return;
        }
        
         int mid=left+(right-left)/2;
      if(qi<=mid) {
          update(2*si,left,mid,qi,val);}
       else{ 
       update(2*si+1,mid+1,right,qi,val);}
        
        sgmt[si]=sgmt[2*si]+sgmt[2*si+1];
    }
    
    int query(int si,int left,int right,int qleft,int qright){
        if(qleft>right or qright<left){
            return 0;
        }
        
        if(qleft<=left and qright>=right){
            return sgmt[si];
        }
        int mid=left+(right-left)/2;
        return query(2*si,left,mid,qleft,qright)+query(2*si+1,mid+1,right,qleft,qright);
    }
};




class NumArray {
public:
   
    SegmentTree *T;
    int n;
    NumArray(vector<int>& nums) {
        
        n=nums.size();
        T=new SegmentTree(n);T->Build(1,1,nums.size(),nums);
    }
    
    void update(int index, int val) {
        T->update(1,1,n,index+1,val);
    }
    
    int sumRange(int left, int right) {
        return T->query(1,1,n,left+1,right+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */