class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        
        vector<bool> visited(n, false);
        queue<int> q;
        
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            
            // If value becomes 0
            if (arr[i] == 0)
                return true;
            
            int forward = i + arr[i];
            int backward = i - arr[i];
            
            // Forward jump
            if (forward >= 0 && forward < n && !visited[forward]) {
                visited[forward] = true;
                q.push(forward);
            }
            
            // Backward jump
            if (backward >= 0 && backward < n && !visited[backward]) {
                visited[backward] = true;
                q.push(backward);
            }
        }
        
        return false;
    }
};