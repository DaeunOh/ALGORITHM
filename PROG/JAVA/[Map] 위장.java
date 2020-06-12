/*

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/42578?language=java

*/

import java.util.HashMap;
import java.util.Set;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        int sum = 1;
        HashMap<String, Integer> hm = new HashMap<>();
        
        for(int i=0; i<clothes.length; i++)
            hm.put(clothes[i][1], hm.getOrDefault(clothes[i][1], 0) + 1);
        
        Set<HashMap.Entry<String, Integer>> entries = hm.entrySet();
        for(HashMap.Entry<String, Integer> entry : entries) {
            sum *= entry.getValue() + 1;
        }
        
        answer = sum - 1;
        
        return answer;
    }
}