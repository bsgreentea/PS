import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.min

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var visited = Array(5) { BooleanArray(5) }
var visited2 = Array(5) { BooleanArray(5) }
var map = Array(5) { charArrayOf() }
var dist = Array(5) { Array(5) { IntArray(5) } }

var px = IntArray(6)
var py = IntArray(6)

var cx = IntArray(6)
var cy = IntArray(6)

val dx = intArrayOf(0, 0, 1, -1)
val dy = intArrayOf(1, -1, 0, 0)

var c = 0
var ans = Int.MAX_VALUE

fun isIn(x: Int, y: Int): Boolean = x in 0 until 5 && y in 0 until 5

fun calc(state: Int, cnt: Int, now: Int) {

    if (cnt == c) {
        ans = min(ans, now)
        return
    }

    for (i in 0 until c) {
        if (state and (1 shl i) > 0) continue
        calc(state or (1 shl i), cnt + 1, now + dist[cx[cnt]][cy[cnt]][i])
    }
}

fun dfs(x: Int, y: Int) {

    visited2[x][y] = true

    for (i in 0 until 4) {
        val nx = x + dx[i]
        val ny = y + dy[i]
        if (!isIn(nx, ny) || visited2[nx][ny] || !visited[nx][ny]) continue

        dfs(nx, ny)
    }
}

fun chk(): Int {

    var ret = 0

    for (i in 0 until c) {
        if (visited2[cx[i]][cy[i]]) continue
        dfs(cx[i], cy[i])
        ret++
    }

    for (i in 0 until c) visited2[cx[i]][cy[i]] = false

    return ret;
}

fun make(cnt: Int) {

    if (cnt == c) {
        if(chk() == 1) calc(0, 0, 0)
        return
    }

    for (i in 0 until 5) {
        for (j in 0 until 5) {

            if (visited[i][j]) continue

            cx[cnt] = i
            cy[cnt] = j
            visited[i][j] = true
            make(cnt + 1)
            visited[i][j] = false
        }
    }

}

fun main() {

    for (i in 0 until 5) {
        map[i] = br.readLine().toCharArray()
        for (j in 0 until 5) {
            if (map[i][j] == '*') {
                px[c] = i
                py[c] = j
                c++
            }
        }
    }

    for (i in 0 until 5) {
        for (j in 0 until 5) {
            for (k in 0 until c) {
                dist[i][j][k] = kotlin.math.abs(px[k] - i) + kotlin.math.abs(py[k] - j)
            }
        }
    }

    make(0)

    bw.write("$ans")
    bw.close()
}