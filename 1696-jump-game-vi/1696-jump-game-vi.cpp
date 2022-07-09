class Node {
    public:
      int data;
      int id;
      Node *next;
      Node * prev;
    Node(int d,int id){
        this->data = d;
        this->id = id;
        this->next = this->prev = NULL;
    }
};

class Deque{
    public:
      Node *front;
      Node* tail;
    Deque(){
        front = tail = NULL;
    }
    void pushFront(int d, int i){
        Node * n = new Node(d, i);
        n->next = front;
        if(front){
            front->prev = n;
        }
        front = n;
        if(!tail){
            tail = n;
        }
    }
    void pushBack(int d, int i){
        Node *n = new Node(d, i);
        n->prev = tail;
        if(tail){
            tail->next = n;
        }
        tail = n;
        if(!front){
            front = tail;
        }
    }
    void popFront(){
        Node *n = front;
        front = front->next;
        if(front){
            front->prev = NULL;
        }else{
            front = tail = NULL;
        }
        
        delete n;
    }
    void popBack(){
        Node *n = tail;
        tail = tail->prev;
        if(tail){
            tail->next = NULL;
        }else{
            front = tail = NULL;
        }
        delete n;
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        Deque dq;
        int n = nums.size();
        dq.pushFront(nums[n-1],n-1);
        int i = n-2;
        int sz = k;
        k--;
        while(k-- and i >= 0){
            int d = dq.front->data;
            while(dq.tail and dq.tail->data <= nums[i]+d){
                dq.popBack();
            }
            dq.pushBack(nums[i]+d,i);
            i--;
        }
        for(int j = i ;j >= 0 ;j--){
            while(dq.front and dq.front->id > j+sz){
                dq.popFront();
            }
            int d = dq.front->data;
            while(dq.tail and dq.tail->data <= nums[j]+d){
                dq.popBack();
            }
            dq.pushBack(nums[j]+d,j);
        }
        return dq.tail->data;
    }
};