import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))

var board1 = Array(20) { IntArray(20) }
var board2 = Array(20) { IntArray(20) }

fun main() {

    val (n, m, k) = br.readLine().split(' ').map { it.toInt() }

    var r = (k - 1) / m + 1
    var c = (k - 1) % m + 1

    if (k == 0) {
        r = n
        c = m
    }

    board1[1][1] = 1
    for (i in 1..r) {
        for (j in 1..c) {
            board1[i + 1][j] += board1[i][j]
            board1[i][j + 1] += board1[i][j]
        }
    }

    board2[r][c] = 1
    for (i in r..n) {
        for (j in c..m) {
            board2[i + 1][j] += board2[i][j]
            board2[i][j + 1] += board2[i][j]
        }
    }

    println(board1[r][c] * board2[n][m])
}