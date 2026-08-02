class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans=new ArrayList<>();
        if (digits.length() == 0) {
            return ans;
        }

        String[] map = {
            "",     
            "",     
            "abc",  
            "def",  
            "ghi",  
            "jkl",  
            "mno",  
            "pqrs", 
            "tuv",  
            "wxyz"  
        };
        ans.add("");
        for (char digit:digits.toCharArray()) {
            List<String> temp=new ArrayList<>();
            String letters=map[digit-'0'];
            for (String s:ans) {
                for (char ch:letters.toCharArray()) {
                    temp.add(s+ch);
                }
            }
            ans=temp;
        }
        return ans;
    }
}