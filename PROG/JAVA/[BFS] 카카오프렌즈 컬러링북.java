/*

▶ 출처
https://programmers.co.kr/learn/courses/30/lessons/1829?language=java

*/

import java.util.*;

class Solution {
    static boolean[][] visited;
    static int[] dy = {-1,1,0,0};
    static int[] dx = {0,0,-1,1};
    
    class Pair{
        int first;
        int second;
        Pair(int first, int second){
            this.first = first;
            this.second = second;
        }
    }
    
    public int bfs(int y, int x, int k, int m, int n, int[][] picture) {
        Queue<Pair> q = new LinkedList<>();
        int cnt = 0;
        
        visited[y][x] = true;
        q.add(new Pair(y, x));
        
        while(!q.isEmpty()) {
            Pair front = q.remove();
            cnt++;
            
            for(int i=0; i<4; i++) {
                int ny = front.first + dy[i];
                int nx = front.second + dx[i];
                
                if(ny < 0 || ny > m-1 || nx < 0 || nx > n-1) continue;
                
                if(!visited[ny][nx] && picture[ny][nx] == k) {
                    visited[ny][nx] = true;
                    q.add(new Pair(ny, nx));
                }
            }
        }
        
        return cnt;
    }
    
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        visited = new boolean[m][n];
        
        Solution solution = new Solution();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(picture[i][j] == 0) continue;
                
                if(!visited[i][j]) {
                    numberOfArea++;
                    int cnt = bfs(i, j, picture[i][j], m, n, picture);
                    maxSizeOfOneArea = Math.max(cnt, maxSizeOfOneArea);
                }
            }
        }
        
        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}