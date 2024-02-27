class Solution:
    def containsDuplicate(self, nums):
        list = []
        
        for num in nums:
            if num in list:
                return True 
            
            list.append(num)
        return False

    def otherWay(self, nums):
        return len(set(nums)) != len(nums)
    
obj = Solution()
print("Contains Duplicate? : ",obj.containsDuplicate([1,2,3,5,5,6,7,8,9,10]))
print("Contains Duplicate? : ",obj.otherWay([1,2,3,4,5,6,7,7,9,10]))