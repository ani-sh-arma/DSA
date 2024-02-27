class Solution(object):
    def isAnagram(self, s, t):
        str1 = s.replace(" ", "")
        str2 = t.replace(" ", "")

        if len(str1) != len(str2):
            return False
        
        str1 = sorted(str1)
        str2 = sorted(str2)

        if str1 != str2:
            return False
        
        return True
    
    def otherWay(self, s, t):
        return sorted(s) == sorted(t)
    
obj = Solution()
print("Is anagram? : ",obj.isAnagram("garamna", "nagaram"))
print("Is anagram? : ",obj.otherWay("garamna", "nagaram"))
        