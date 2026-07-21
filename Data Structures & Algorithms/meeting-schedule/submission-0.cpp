/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& inter) {
        sort(inter.begin(),inter.end(),[](auto& x, auto& y){
            return x.start<y.start;
        });
        for(int i=1;i<inter.size();i++){
            if(inter[i-1].end > inter[i].start)return false;
        }
        return true;
    }
};
