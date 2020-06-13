/*

▶ 풀이
https://programmers.co.kr/learn/courses/30/lessons/42888?language=java

*/

import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        String[] answer = {};
        HashMap<String, String> hm = new HashMap<>();
        ArrayList<String> flag = new ArrayList<>();
        ArrayList<String> id = new ArrayList<>();
        
        for(int i=0; i<record.length; i++) {
            String[] info = record[i].split(" ");
            
            if(info[0].equals("Enter")) {
                hm.put(info[1], info[2]);
                flag.add(info[0]);
                id.add(info[1]);
            }
            else if(info[0].equals("Leave")) {
                flag.add(info[0]);
                id.add(info[1]);
            }
            else {
                hm.put(info[1], info[2]);
            }
        }
        
        answer = new String[flag.size()];
        for(int i=0; i<flag.size(); i++) {
            if(flag.get(i).equals("Enter")) {
                answer[i] = hm.get(id.get(i)) + "님이 들어왔습니다.";
            }
            else {
                answer[i] = hm.get(id.get(i)) + "님이 나갔습니다.";
            }
        }
        
        return answer;
    }
}