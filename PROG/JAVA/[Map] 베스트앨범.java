/*

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/42579?language=java

*/

import java.util.*;

class Solution {
    static class MyPair implements Comparable<MyPair>{
        private Integer first, second;

        public MyPair(Integer first, Integer second) {
            this.first = first;
            this.second = second;
        }

        public Integer getFirst() {
            return first;
        }

        public Integer getSecond() {
            return second;
        }

        @Override
        public int compareTo(MyPair o) {
            if(this.first == o.getFirst())
                return this.second - o.getSecond();
            else
                return this.first - o.getFirst();
        }
    }
    
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        
        HashMap<String, Integer> hm = new HashMap<>();

        for(int i=0; i<genres.length; i++)
            hm.put(genres[i], hm.getOrDefault(genres[i], 0) + plays[i]);

        TreeMap<Integer, String> rev = new TreeMap<>();

        Set<Map.Entry<String, Integer>> entries = hm.entrySet();
        for(Map.Entry<String, Integer> entry : entries)
            rev.put(-entry.getValue(), entry.getKey());

        ArrayList<Integer> ans = new ArrayList<>();
        for(String gen : rev.values()) {
            ArrayList<MyPair> myPairs = new ArrayList<>();
            for(int i=0; i<genres.length; i++) {
                if(gen.compareTo(genres[i]) == 0) myPairs.add(new MyPair(-plays[i], i));
            }

            Collections.sort(myPairs);
            if(myPairs.size() == 1) ans.add(myPairs.get(0).getSecond());
            else {
                ans.add(myPairs.get(0).getSecond());
                ans.add(myPairs.get(1).getSecond());
            }
        }

        answer = new int[ans.size()];
        for(int i=0; i<answer.length; i++) answer[i] = ans.get(i);
        
        return answer;
    }
}