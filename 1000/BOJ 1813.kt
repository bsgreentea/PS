import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

const val MAX = 100000

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var cnt = IntArray(MAX + 1)

fun main() {

    val n = br.readLine().toInt()
    val arr = br.readLine().split(' ').map { it.toInt() }.toIntArray()

    for (e in arr) cnt[e]++

    var f = 0
    var res = -1
    for (i in 1..100000) {
        if (i == cnt[i]) {
            res = i
        } else f += cnt[i]
    }

    if(f == n) res = 0

    bw.write(res.toString())
    bw.close()
}