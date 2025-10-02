class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalBottle=0,emptyBottle=0;
        totalBottle=totalBottle+numBottles;
        emptyBottle=emptyBottle+numBottles;
        while(emptyBottle>=numExchange)
        {
            emptyBottle=emptyBottle-numExchange;
            numExchange++;
            totalBottle++;
            emptyBottle++;
        }
        return totalBottle;
    }
};