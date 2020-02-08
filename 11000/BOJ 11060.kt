import java.lang.Integer.min
import java.util.*

const val INF = 10000

var n = 0
var arr = IntArray(1001)
var dp = IntArray(1001){INF}

fun main() = with(Scanner(System.`in`)) {

    n = nextInt()
    arr = IntArray(n) { nextInt() }

    dp[0] = 0

    for (i in 0..n - 1) {
        for (j in 1..arr[i]) {
            if (i + j >= n) continue
            dp[i + j] = min(dp[i + j], dp[i] + 1)
        }
    }

    if (dp[n-1] == INF) print(-1)
    else print(dp[n-1])
}