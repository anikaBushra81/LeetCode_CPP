class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // Step 1: store all info
        vector<tuple<int,int,char,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // Step 2: sort by position
        sort(robots.begin(), robots.end());
        
        stack<int> st; // store indices of robots
        vector<int> finalHealth(n, 0);
        
        for(int i = 0; i < n; i++) {
            auto &[pos, health, dir, idx] = robots[i];
            
            if(dir == 'R') {
                st.push(i);
            } else {
                // dir == 'L'
                while(!st.empty() && health > 0) {
                    auto &[pos2, health2, dir2, idx2] = robots[st.top()];
                    
                    if(health2 < health) {
                        // stack robot dies
                        health--;
                        health2 = 0;
                        st.pop();
                    }
                    else if(health2 > health) {
                        // current robot dies
                        health2--;
                        health = 0;
                        break;
                    }
                    else {
                        // equal → both die
                        health2 = 0;
                        health = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }
        
        // Step 5: collect survivors
        for(auto &[pos, health, dir, idx] : robots) {
            if(health > 0) {
                finalHealth[idx] = health;
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(finalHealth[i] > 0) {
                result.push_back(finalHealth[i]);
            }
        }
        
        return result;
    }
};