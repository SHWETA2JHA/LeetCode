class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& pre) {
        int n=pre.size();
        vector<vector<int>>adj(n);
        vector<int>in(n,0);
        for(int i=0; i<pre.size(); i++){
            for(auto j: pre[i]){
                adj[j].push_back(i);
                in[i]++;
            }
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(in[i]==0)q.push(i);
        }

        vector<int>course;

        while(!q.empty()){
            int c=q.front();
            q.pop();
            course.push_back(c);

            for(auto node: adj[c]){
                in[node]--;
                if(in[node]==0)q.push(node);
            }
        }
        sort(course.begin(), course.end());
        return course;

    }
};