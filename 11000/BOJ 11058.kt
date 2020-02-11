import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Long.max

var dp = LongArray(111)

fun main() {

    val n = BufferedReader(InputStreamReader(System.`in`)).readLine().toLong()
    val N = n.toInt()

    for (i in 1..N) dp[i] = i.toLong()
    for (i in 7..N) {
        for (j in 3..i-1) dp[i] = max(dp[i], dp[i - j] * (j - 1))
    }

    println(dp[N])
}