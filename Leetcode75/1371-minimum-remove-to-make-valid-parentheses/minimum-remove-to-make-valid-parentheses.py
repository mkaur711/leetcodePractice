class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        cnt = 0
        res = []

        for c in s:
            if c == "(":
                cnt += 1
                res.append(c)

            elif c == ")" and cnt > 0:
                res.append(c)
                cnt -= 1
            
            elif c != ")":
                res.append(c)
        
        filtered_string = []
        for ch in res[::-1]:
            if ch == "(" and cnt > 0:
                cnt -= 1
            else:
                filtered_string.append(ch)
        
        return "".join(filtered_string)[::-1]
