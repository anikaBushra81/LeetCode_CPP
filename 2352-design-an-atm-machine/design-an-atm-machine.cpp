class ATM {
private:
    long long bank[5] = {0};
    static constexpr int val[5] = {20, 50, 100, 200, 500};
public:
    ATM() {}
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; ++i) bank[i] += banknotesCount[i];
    }
    vector<int> withdraw(int amount) {
        vector<int> res(5 , 0);
        for(int i = 4; i >= 0; --i){
            long long note = val[i];
            res[i] = min(bank[i] , amount / note);
            amount -= res[i] * note;
        }
        if(amount) return {-1};
        for(int i = 0; i < 5; ++i) bank[i] -= res[i];
        return res;
    }
};