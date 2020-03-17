import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))
var board = Array<CharArray>(3) { CharArray(3) }

fun getDiff(): Int {

    var diff = 0
    for (i in 0..2) for (j in 0..2)
        if (board[i][j] == 'X') diff++ else if (board[i][j] == 'O') diff--

    return diff
}

fun linesOf(c: Char): Int {
    var vertical = 0
    var horizontal = 0

    for (i in 0..2) {
        var ver = 0
        var hor = 0
        for (j in 0..2) {
            if (board[i][j] == c) hor++
            if (board[j][i] == c) ver++
        }
        if (hor == 3) horizontal++
        if (ver == 3) vertical++
    }

    var diagonal = 0
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) diagonal++
    if (board[2][0] == c && board[1][1] == c && board[0][2] == c) diagonal++

    return horizontal + vertical + diagonal
}

fun main() {

    while (true) {

        val ttt = br.readLine().toString()
        if (ttt[0] == 'e') break

        var dots = 0

        for (i in 0..8) {
            board[i / 3][i % 3] = ttt[i]
            if (ttt[i] == '.') dots++
        }

        var flag = 0
        val diff = getDiff()

        val OOO = linesOf('O')
        val XXX = linesOf('X')

        if (diff == 1) {
            if (OOO == 0) {
                if (XXX == 0 && dots == 0) flag++
                else if (XXX == 1) flag++
                else if (XXX == 2) flag++
            }
        } else if (diff == 0) {
            if (XXX == 0) {
                if (OOO == 1) flag++
            }
        }

        if (flag > 0) bw.write("valid\n")
        else bw.write("invalid\n")
    }

    bw.close()
}