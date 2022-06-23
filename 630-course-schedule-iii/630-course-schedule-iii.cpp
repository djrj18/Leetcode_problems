class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        int timetill = 0;
        priority_queue<int>pq;
        for(auto c : courses){
            int dur = c[0];
            int till = c[1];
            if(timetill+dur <= till){
                timetill += dur;
                pq.push(dur);
            }
            else if(pq.size() and pq.top() > dur){
                timetill += dur-pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};