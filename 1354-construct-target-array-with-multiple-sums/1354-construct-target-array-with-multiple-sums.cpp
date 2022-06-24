class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long int sum = 0ll;
        priority_queue<int> pq;
        for(int i = 0 ; i < target.size() ; i++){
            sum += (long long)target[i];
            pq.push(target[i]);
        }
        
        while(pq.top() > 1){
            int tp  = pq.top();
            sum -= tp; 
            if(sum <= 0 or sum >= tp){
                return false;
            }
            int x = tp%sum;
            pq.pop();
            if(x == 0){
                pq.push(sum);
                sum += sum;
            }
            else{
                pq.push(x);
                sum += x;
            }
        }
        return true;
        
        
    }
};