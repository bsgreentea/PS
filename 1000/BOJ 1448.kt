import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))
const val MAX = 1000001

var chk = IntArray(MAX)
var straw = IntArray(MAX)

fun main() {

    val n = br.readLine().toInt()
    for (i in 1..n) chk[br.readLine().toInt()]++
    br.close()

    var idx = 0
    for (i in 1 until MAX) while (chk[i] > 0) {
        straw[idx++] = i
        chk[i]--
    }

    var res = -1
    for (i in n - 1 downTo 2) {
        if (straw[i] < straw[i - 1] + straw[i - 2]) {
            res = straw[i] + straw[i - 1] + straw[i - 2]
            break
        }
    }

    bw.write(res.toString())
    bw.close()
}