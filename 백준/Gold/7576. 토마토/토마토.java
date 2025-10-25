import java.io.*;
import java.util.*;

public class Main {
    static class Pos {
        int x, y;
        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int M = sc.nextInt(); // 가로 (열)
        int N = sc.nextInt(); // 세로 (행)

        int[][] tomatoes = new int[N][M];
        Queue<Pos> q = new LinkedList<>();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tomatoes[i][j] = sc.nextInt();
                if (tomatoes[i][j] == 1) {
                    q.add(new Pos(i, j));
                }
            }
        }

        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};

        // BFS
        while (!q.isEmpty()) {
            Pos cur = q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (tomatoes[nx][ny] != 0) continue;

                tomatoes[nx][ny] = tomatoes[cur.x][cur.y] + 1;
                q.add(new Pos(nx, ny));
            }
        }

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tomatoes[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
                answer = Math.max(answer, tomatoes[i][j]);
            }
        }

        System.out.println(answer - 1);
    }
}
