import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var cnt = Array(111) { LongArray(111) }
var impossible = mutableSetOf<Pair<Int, Int>>()

fun main() {

    val (n, m) = br.readLine().split(' ').map { it.toInt() }
    val k = br.readLine().toLong()

    for (i in 1..k) {
        val (a, b, c, d) = br.readLine().split(' ').map { it.toInt() }
        if (a + b < c + d) impossible.add(Pair(a * 1000 + b, c * 1000 + d))
        else impossible.add(Pair(c * 1000 + d, a * 1000 + b))
    }

    cnt[0][0] = 1

    for (i in 0..n) {
        for (j in 0..m) {
            if (i + 1 <= n && Pair(i * 1000 + j, (i + 1) * 1000 + j) !in impossible)
                cnt[i + 1][j] += cnt[i][j]
            if (j + 1 <= m && Pair(i * 1000 + j, i * 1000 + j + 1) !in impossible)
                cnt[i][j + 1] += cnt[i][j]
        }
    }

    bw.write(cnt[n][m].toString())
    bw.close()
}