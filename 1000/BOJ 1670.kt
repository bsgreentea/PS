import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

const val MOD = 987654321L

var dp = LongArray(10010) { -1 }

fun solve(n: Int): Long {

    if (dp[n] != -1L) return dp[n]
    dp[n] = 0

    for (i in 0..n - 2 step 2) {
        dp[n] += solve(i) * solve(n - 2 - i)
        dp[n] %= MOD
    }

    return dp[n]
}

fun main() {

    dp[0] = 1
    dp[2] = 1

    val n = br.readLine().toInt()
    br.close()
    bw.write(solve(n).toString())
    bw.close()
}