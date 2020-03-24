import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.max

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var dist = Array(303) { IntArray(303) }
var dp = Array(303) { IntArray(303) }

fun main() {

    val (n, m, k) = br.readLine().split(' ').map { it.toInt() }

    for (t in 1..k) {
        val (a, b, c) = br.readLine().split(' ').map { it.toInt() }
        if (a > b) continue
        dist[a][b] = max(dist[a][b], c)
    }
    br.close()

    var res = 0
    for (i in 1 until n) {
        for (j in i + 1..n) {
            if (dist[i][j] == 0) continue
            for (k in 1 until m) {
                if(i != 1 && dp[i][k] == 0) continue
                dp[j][k + 1] = max(dp[j][k + 1], dp[i][k] + dist[i][j])
                if(j == n) res = max(res, dp[j][k + 1])
            }
        }
    }

    bw.write(res.toString())
    bw.close()
}