

class SparseVector:
    def __init__(self, nums : List[int]):
        self.nums = []
        for idx, num in enumerate(nums):
            if num:
                self.nums.append((idx, num))
        
    def dotProduct(self, vec: 'SparseVector') -> int:
        dot_product = 0
        i = j = 0
        
        while i < len(self.nums) and j < len(vec.nums):
            i_idx, i_num = self.nums[i]
            j_idx, j_num = vec.nums[j]

            if i_idx == j_idx:
                dot_product += (i_num * j_num)
                i += 1
                j += 1
            
            if i_idx < j_idx:
                i += 1
            
            elif j_idx < i_idx:
                j += 1
            
        return dot_product