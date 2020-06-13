/*

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/64064?language=java

*/

import java.util.*;

class Solution {
    static int[] comb = new int[10];
    static boolean[] check = new boolean[10];
    static Set<Set<Integer>> S = new HashSet<>();
    
    public void getComb(int x, String[] U, String[] B) {
        if(x >= B.length) {
            boolean flag = false;
            for(int i=0; i<B.length; i++) {
                String user = U[comb[i]];
                String ban = B[i];
                
                if(user.length() != ban.length()) {
                    flag = true;
                    break;
                }
                
                for(int j=0; j<ban.length(); j++) {
                    if(ban.charAt(j) == '*') continue;

                    if(ban.charAt(j) != user.charAt(j)) {
                        flag = true;
                        break;
                    }
                }

                if(flag) break;
            }
            
            if(!flag) {
                Set<Integer> temp = new HashSet<>();
                for(int i=0; i<B.length; i++) temp.add(comb[i]);
                S.add(temp);
            }
        }
        else {
            for(int i=0; i<U.length; i++) {
                if(!check[i]) {
                    check[i] = true;
                    comb[x] = i;
                    getComb(x+1, U, B);
                    check[i] = false;
                }
            }
        }
    }
    
    public int solution(String[] user_id, String[] banned_id) {
        int answer = 0;
        
        Solution solution = new Solution();
        solution.getComb(0, user_id, banned_id);
        
        answer = S.size();
        
        return answer;
    }
}