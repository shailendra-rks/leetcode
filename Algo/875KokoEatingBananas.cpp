class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        int64_t sum = 0;

        for(int pile : piles){
            high = high > pile ? high : pile;
            sum += pile;
        }

        if(piles.size() == h){
            return high;
        }

        int low = ((sum-1)/h)+1;
        while(low < high){
            int mid = low + (high -low)/2;
            int time = 0;
            int i = 0;
            while( i < piles.size()){
                time += ((piles[i]-1)/mid) + 1;
                i++;
            }
            if(time <= h){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};