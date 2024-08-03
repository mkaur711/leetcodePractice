// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         int count=0;
//         for(int i=0;i<flowerbed.size();i++){
//             if((i%2==0 && flowerbed[i]==1) || (i%2==1 && flowerbed[i]==0)){
//                 continue;
//             }
//             else if(i!=flowerbed.size()-1 && i%2==0 && flowerbed[i]==0 && flowerbed[i+1]!=1){
//                 count++;
//             }
//             else if(i%2==0 && i==flowerbed.size()-1 && flowerbed[i]==0){
//                 count++;
//             }
//         }
//         return(count>=n);
//     }
// };
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int length = flowerbed.size();
        
        for (int i = 0; i < length; ++i) {
            if (flowerbed[i] == 0) {
                // Check if previous and next positions are empty (or out of bounds)
                bool prev_empty = (i == 0) || (flowerbed[i-1] == 0);
                bool next_empty = (i == length-1) || (flowerbed[i+1] == 0);
                
                if (prev_empty && next_empty) {
                    // Plant a flower here
                    flowerbed[i] = 1;
                    count++;
                    
                    // If we've planted enough flowers, return true
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        
        // If we finish the loop and haven't planted enough flowers, return false
        return count >= n;
    }
};
