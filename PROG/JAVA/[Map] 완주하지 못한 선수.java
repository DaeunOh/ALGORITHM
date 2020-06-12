/*

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/42576

*/

import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";

        HashMap<String, Integer> m = new HashMap<>();

        for(int i=0; i<completion.length; i++) {
            if(m.containsKey(completion[i])) m.put(completion[i], m.get(completion[i]) + 1);
            else m.put(completion[i], 1);
        }

        for(int i=0; i<participant.length; i++) {
            if(m.containsKey(participant[i]) && m.get(participant[i]) > 0)
                m.put(participant[i], m.get(participant[i]) - 1);
            else {
                answer = participant[i];
                break;
            }
        }
        
        return answer;
    }
}