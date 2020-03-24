import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var dp = Array(111) { Array(111) { LongArray(111) { -1L } } }

fun w(a: Int, b: Int, c: Int): Long {

    if (dp[a][b][c] != -1L) return dp[a][b][c]

    if (a <= 50 || b <= 50 || c <= 50) return 1
    if (a > 70 || b > 70 || c > 70) {
        dp[70][70][70] = w(70, 70, 70)
        return dp[70][70][70]
    }
    if (b in (a + 1) until c) {
        dp[a][b][c - 1] = w(a, b, c - 1)
        dp[a][b - 1][c - 1] = w(a, b - 1, c - 1)
        dp[a][b - 1][c] = w(a, b - 1, c)
        return dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c]
    }

    dp[a - 1][b][c] = w(a - 1, b, c)
    dp[a - 1][b - 1][c] = w(a - 1, b - 1, c)
    dp[a - 1][b][c - 1] = w(a - 1, b, c - 1)
    dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1)

    return dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1]
}


fun main() {

    while (true) {
        val (a, b, c) = br.readLine().split(' ').map { it.toInt() }
        if (a == -1 && b == -1 && c == -1) break

        bw.write(String.format("w(%d, %d, %d) = %d\n", a, b, c, w(a + 50, b + 50, c + 50)))
    }

    br.close()
    bw.close()
}