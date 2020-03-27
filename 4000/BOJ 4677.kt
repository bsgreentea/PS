import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var disc = Array(101) { BooleanArray(101) }
var map = Array(101) { CharArray(101) }

var dx = intArrayOf(0, 0, 1, -1, 1, 1, -1, -1)
var dy = intArrayOf(1, -1, 0, 0, 1, -1, 1, -1)

fun chk(x: Int, m: Int, y: Int, n: Int): Boolean = 0 <= x && x < m && 0 <= y && y < n

fun dfs(x: Int, y: Int, m: Int, n: Int) {

    disc[x][y] = true

    for (i in 0..7) {
        val nx = x + dx[i]
        val ny = y + dy[i]
        if (!chk(nx, m, ny, n) || disc[nx][ny] || map[nx][ny] == '*') continue
        dfs(nx, ny, m, n)
    }
}

fun main() {

    while (true) {
        val (m, n) = br.readLine().split(' ').map { it.toInt() }
        if (m + n == 0) break

        for (i in 0 until m) {
            map[i] = br.readLine().toCharArray()
        }

        var cnt = 0
        for (i in 0 until m) {
            for (j in 0 until n) {
                if (map[i][j] == '@' && !disc[i][j]) {
                    cnt++
                    dfs(i, j, m, n)
                }
            }
        }

        bw.write(cnt.toString() + "\n")

        for (i in 0 until m) for (j in 0 until n) disc[i][j] = false
    }

    br.close()
    bw.close()
}