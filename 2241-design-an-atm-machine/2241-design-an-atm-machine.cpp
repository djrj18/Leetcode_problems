class ATM {
public:
    vector<long long int> cnts;
    map<int,int>mp;
    ATM() {
        cnts.resize(5);
        for(int i = 0;i<5;i++){
            cnts[i] = 0;
        }
        mp[0] = 20;
        mp[1]  =50;
        mp[2]  =100;
        mp[3] = 200;
        mp[4] = 500;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0;i<5;i++){
            cnts[i] += (long long)banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);
       for(int i = 4;i>=0;i--){
           long long int desire = (long long)amount/mp[i];
           amount -= (long long)min(desire,cnts[i])*(long long)mp[i];
           ans[i] = min(desire,cnts[i]);
       }
        if(amount){
            return {-1};
        }
        for(int i = 0;i<5;i++){
            cnts[i] -= ans[i];
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */