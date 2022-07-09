// class Node {
//     public:
//       int data;
//       int id;
//       Node *next;
//       Node * prev;
//     Node(int d,int id){
//         this->data = d;
//         this->id = id;
//         this->next = this->prev = NULL;
//     }
// };

// class Deque{
//     public:
//       Node *front;
//       Node* tail;
//     Deque(){
//         front = tail = NULL;
//     }
//     void pushFront(int d, int i){
//         Node * n = new Node(d, i);
//         n->next = front;
//         if(front){
//             front->prev = n;
//         }
//         front = n;
//         if(!tail){
//             tail = n;
//         }
//     }
//     void pushBack(int d, int i){
//         Node *n = new Node(d, i);
//         n->prev = tail;
//         if(tail){
//             tail->next = n;
//         }
//         tail = n;
//         if(!front){
//             front = tail;
//         }
//     }
//     void popFront(){
//         Node *n = front;
//         front = front->next;
//         if(front){
//             front->prev = NULL;
//         }else{
//             front = tail = NULL;
//         }
        
//         delete n;
//     }
//     void popBack(){
//         Node *n = tail;
//         tail = tail->prev;
//         if(tail){
//             tail->next = NULL;
//         }else{
//             front = tail = NULL;
//         }
//         delete n;
//     }
// };

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
       deque<pair<int,int>> dq;
        int n = nums.size();
        dq.push_front({nums[n-1],n-1});
        int i = n-2;
        int sz = k;
        k--;
        while(k-- and i >= 0){
            int d = dq.front().first;
            while(dq.size() and dq.back().first <= nums[i]+d){
                dq.pop_back();
            }
            dq.push_back({nums[i]+d,i});
            i--;
        }
        for(int j = i ;j >= 0 ;j--){
            while(dq.size() and dq.front().second > j+sz){
                dq.pop_front();
            }
            int d = dq.front().first;
            while(dq.size() and dq.back().first <= nums[j]+d){
                dq.pop_back();
            }
            dq.push_back({nums[j]+d,j});
        }
        return dq.back().first;
    }
};