/*

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/43164?language=java

*/

import java.util.*;

class Solution {
    boolean[] visited = new boolean[10010];
    ArrayList<String> temp = new ArrayList<>();
    String[][] tickets;
    String[] answer = {};
    
    public boolean dfs(String start) {
        temp.add(start);
        
        if(temp.size() == tickets.length + 1) {
            answer = new String[temp.size()];
            
            for(int i=0; i<answer.length; i++)
                answer[i] = temp.get(i);
            
            return true;
        }
        
        for(int i=0; i<tickets.length; i++) {
            if(!visited[i] && tickets[i][0].equals(start)) {
                visited[i] = true;
                
                boolean success = dfs(tickets[i][1]);
                if(success) return true;
                visited[i] = false;
            }
        }
        
        temp.remove(temp.size() - 1);
        
        return false;
    }
    
    public String[] solution(String[][] tickets) {
        this.tickets = tickets;
        
        Arrays.sort(tickets,(o1, o2) -> {
            if(o1[0].equals(o2[0])){
                return o1[1].compareTo(o2[1]);
            }
            else{
                return o1[0].compareTo(o2[0]);
            }
        });
        
        dfs("ICN");
        
        return answer;
    }
}