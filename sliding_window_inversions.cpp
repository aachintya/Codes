class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int flag = 1;
        int idx = -1;
        int n = gas.size();
        for(int i = 0; i < n; i++){
            int fuel = gas[i];
            int f = 1;
            for(int j = i; j < i + n; j++){
                int curr = j % n;
                if(fuel - cost[curr] < 0){
                    f = 0;
                    break;
                }
                fuel = fuel - cost[curr] + gas[(curr + 1) % n];
            }
            if(f == 1){
                idx = i;
                break;
            }
        }
        return idx;
    }
};