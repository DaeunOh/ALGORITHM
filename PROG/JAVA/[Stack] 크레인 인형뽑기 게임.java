/*

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/64061?language=java

*/

import java.util.Stack;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> s = new Stack<>();
        
        for(int i=0; i<moves.length; i++) {
            int col = moves[i]-1;
            
            int num = -1;
            for(int j=0; j<board.length; j++) {
                if(board[j][col] != 0) {
                    num = board[j][col];
                    board[j][col] = 0;
                    break;
                }
            }
            
            if(num != -1) {
                if(!s.isEmpty() && s.peek() == num) {
                    s.pop();
                    answer += 2;
                }
                else s.push(num);
            }
        }
        
        return answer;
    }
}