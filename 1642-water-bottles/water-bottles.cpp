class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=numBottles;
        while(numBottles>=numExchange)
        {
            int newBottle=numBottles/numExchange;
            int reminder=numBottles%numExchange;
            total = total + newBottle;
            numBottles = newBottle + reminder;
        }
        return total;
    }
};