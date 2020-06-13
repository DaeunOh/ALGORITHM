/*

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/17683?language=java

*/

import java.util.*;

class Solution {
    public String replaceStr(String s) {
        s = s.replaceAll("C#", "c");
        s = s.replaceAll("D#", "d");
        s = s.replaceAll("F#", "f");
        s = s.replaceAll("G#", "g");
        s = s.replaceAll("A#", "a");
        
        return s;
    }
    
    public String solution(String m, String[] musicinfos) {
        String answer = "(None)";
        int answerLen = 0;
        
        // m에 존재하는 #을 소문자로 치환한다.
        m = replaceStr(m);
        
        for(int i=0; i<musicinfos.length; i++) {
            String[] info = musicinfos[i].split(",");
            
            // 1) 재생 시간을 계산한다.
            int hour = Integer.parseInt(info[1].substring(0, 2)) - Integer.parseInt(info[0].substring(0, 2));
            int minute = Integer.parseInt(info[1].substring(3)) - Integer.parseInt(info[0].substring(3));
            int playLen = hour * 60 + minute;

            // 2) 악보에 존재하는 #을 소문자로 치환한다.
            info[3] = replaceStr(info[3]);

            // 3) 음악 길이와 재생 시간에 따라 새로운 악보를 만든다.
            String myScore = "";
            if(info[3].length() < playLen) {
                // 끊김 없이 반복 재생
                while(myScore.length() < playLen) myScore += info[3];
                myScore = myScore.substring(0, playLen);
            }
            else {
                // 처음 ~ 재생 시간 만큼만
                myScore = info[3].substring(0, playLen);
            }

            // 4) 새로운 악보에 m이 존재하는지 확인한다.
            if (myScore.indexOf(m) >= 0 && answerLen < playLen) {
                answer = info[2];
                answerLen = playLen;
            }
        }
        
        return answer;
    }
}