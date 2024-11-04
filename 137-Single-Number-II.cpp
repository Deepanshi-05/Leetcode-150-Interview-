class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;

        for(int num: nums){
          map[num]++;
        }
         // Use an iterator to find the number that appears only once
        for (std::unordered_map<int, int>::iterator i = map.begin(); i != map.end(); ++i) {
            if (i->second == 1) {  // Check if the frequency is 1
                return i->first;   // Return the number (key) with frequency 1
            }
        }
        return -1;
    }
};