import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var case = Array(66) { LongArray(10) }

fun main() {

    for (i in 0..9) case[1][i] = 1L

    for (i in 2..64) {
        for (j in 0..9) {
            for (k in 0..j) {
                case[i][j] += case[i - 1][k]
            }
        }
    }

    val T = br.readLine().toLong()
    for (t in 1..T) {
        val n = br.readLine().toInt()
        var res = 0L
        for (i in 0..9) res += case[n][i]
        bw.write(res.toString() + "\n")
    }
    br.close()
    bw.close()
}