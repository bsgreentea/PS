import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))

var board = Array<CharArray>(33) { CharArray(33) }

fun chkLine(c: Char, x: Int, y: Int): Char {

    var ver = 0
    var hor = 0
    var dia = 0

    for (i in 0..2) {
        var v = 0
        var h = 0
        for (j in 0..2) {
            if (board[x + j][y + i] == c) v++
            if (board[x + i][y + j] == c) h++
        }

        if (v == 3) ver++
        if (h == 3) hor++
    }

    if (board[x][y] == c && board[x + 1][y + 1] == c && board[x + 2][y + 2] == c) dia++
    if (board[x][y + 2] == c && board[x + 1][y + 1] == c && board[x + 2][y] == c) dia++

    return if (ver + hor + dia > 0) c else '.'
}

fun main() {

    val n = br.readLine().toInt()
    for (i in 0..n - 1) {
        val temp = br.readLine().toString()
        for (j in 0..n - 1) board[i][j] = temp[j]
    }

    var res = "ongoing"

    if (n >= 3) {
        for (i in 0..n - 3) {
            for (j in 0..n - 3) {
                for (k in 0..25) {
                    var chk = chkLine('a' + k, i, j)
                    if (chk != '.') res = ('a' + k).toString()
                    chk = chkLine('A' + k, i, j)
                    if (chk != '.') res = ('A' + k).toString()
                }
            }
        }
    }

    println(res)
}