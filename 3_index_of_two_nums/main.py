class Solution(object):
    def twoSum(self, nums, target):

        for i in range(len(nums)):
            for j in range(len(nums)):
                if i == j:
                    continue
                if nums[i] + nums[j] == target:
                    return [i, j]
        
        

list = [21,7,2,15,5]
target = 12

obj = Solution()
print("Two Sum : ",obj.twoSum(list,target))