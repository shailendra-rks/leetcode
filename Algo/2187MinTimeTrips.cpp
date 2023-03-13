class Solution {
public:
    bool validateLeastTrip(vector<int>& time, long long givenTime, int totalTrips){
        long long trips = 0;
        int i = 0;
        while(trips < totalTrips && i < time.size()){
            trips += givenTime/time[i];
            i++;
        }
        if(trips < totalTrips){
            return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long max = time[0];
        for(int t : time){
            max = t > max ? t : max;
        }
        long long low = 1;
        long long high = totalTrips * max;
        while(low < high){
            long long mid = low + (high - low)/2;
            if(validateLeastTrip(time, mid, totalTrips)){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};