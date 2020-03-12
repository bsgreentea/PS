import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var board = Array<IntArray>(101, { IntArray(101) })

fun chk(x: Int, y: Int, n: Int): Boolean = x in 0 until n && y in 0 until n

fun main() {

    val n = br.readLine().toInt()
    val route = br.readLine().toString()

    var res = Array<CharArray>(n, {CharArray(n)})

    br.close()

    var x = 0
    var y = 0

    for (d in route) {
        var dx = 0
        var dy = 0
        when (d) {
            'D' -> dx++
            'U' -> dx--
            'R' -> dy++
            'L' -> dy--
        }
        var nx = x + dx
        var ny = y + dy

        if (chk(nx, ny, n)) {

            if (dx != 0) board[x][y] = board[x][y] or (1 shl 0)
            else board[x][y] = board[x][y] or (1 shl 1)

            x = nx
            y = ny

            if (dx != 0) board[x][y] = board[x][y] or (1 shl 0)
            else board[x][y] = board[x][y] or (1 shl 1)
        }
    }

    for (i in 0..n - 1) {
        for (j in 0..n - 1) {
            when(board[i][j]){
                0 -> res[i][j] = '.'
                1 -> res[i][j] = '|'
                2 -> res[i][j] = '-'
                3 -> res[i][j] = '+'
            }
        }
        bw.write(res[i])
        bw.write("\n")
    }

    bw.close()
}