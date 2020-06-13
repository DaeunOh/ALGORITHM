/*

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/17686?language=java

*/

import java.util.*;

class Solution {
    class MyFile implements Comparable<MyFile>{
        String HEAD;
        int NUMBER, IDX;
        
        MyFile(String HEAD, int NUMBER, int IDX) {
            this.HEAD = HEAD;
            this.NUMBER = NUMBER;
            this.IDX = IDX;
        }
        
        public int compareTo(MyFile mf) {
            if(this.HEAD.equals(mf.HEAD) && this.NUMBER == mf.NUMBER)
                return this.IDX - mf.IDX;
            else if(this.HEAD.equals(mf.HEAD))
                return this.NUMBER - mf.NUMBER;
            else
                return this.HEAD.compareTo(mf.HEAD);
        }
    }
    
    public String[] solution(String[] files) {
        String[] answer = {};
        ArrayList<MyFile> list = new ArrayList<>();
        
        for(int i=0; i<files.length; i++) {
            String HEAD = "", NUMBER = "";
            for(int j=0; j<files[i].length(); j++) {
                if(Character.isDigit(files[i].charAt(j))) {
                    HEAD = files[i].substring(0, j);
                    
                    for(int k=j; k<files[i].length(); k++) {
                        if(k < j+5 && Character.isDigit(files[i].charAt(k)))
                            NUMBER += files[i].charAt(k);
                        else break;
                    }
                    break;
                }
            }
            
            list.add(new MyFile(HEAD.toLowerCase(), Integer.parseInt(NUMBER), i));
        }
        
        Collections.sort(list);
        answer = new String[list.size()];
        
        for(int i=0; i<answer.length; i++) {
            answer[i] = files[list.get(i).IDX];
        }
        
        return answer;
    }
}