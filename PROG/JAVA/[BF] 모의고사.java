/*

▶ 소요시간 및 실행시간
10분, 2ms

▶ 문제
1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열이 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 구하시오.

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/42840

*/

import java.util.ArrayList;

class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        int[] p1 = {1, 2, 3, 4, 5};
        int[] p2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        int[] scores = new int[3];
        
        for(int i=0; i<answers.length; i++) {
            if(p1[i % p1.length] == answers[i]) scores[0]++;
            if(p2[i % p2.length] == answers[i]) scores[1]++;
            if(p3[i % p3.length] == answers[i]) scores[2]++;
        }
        
        int maxScore = Math.max(scores[0], Math.max(scores[1], scores[2]));
        ArrayList<Integer> list = new ArrayList<>();
        
        if(scores[0] == maxScore) list.add(1);
        if(scores[1] == maxScore) list.add(2);
        if(scores[2] == maxScore) list.add(3);
        
        answer = new int[list.size()];
        
        for(int i=0; i<answer.length; i++) answer[i] = list.get(i);
        
        return answer;
    }
}