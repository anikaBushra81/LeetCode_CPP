class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (int a : apple) {
            totalApples += a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int currCapacity = 0;
        int boxes = 0;

        for (int cap : capacity) {
            currCapacity += cap;
            boxes++;
            if (currCapacity >= totalApples) {
                return boxes;
            }
        }

        return boxes; 
    }
};
