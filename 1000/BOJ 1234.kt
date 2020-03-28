import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var fact = LongArray(11)
var dp = Array(11) { Array(101) { Array(101) { LongArray(101) } } }

fun main() {

    fact[1] = 1
    for (i in 2..10) fact[i] = fact[i - 1] * i

    val (n, red, green, blue) = br.readLine().split(' ').map { it.toInt() }
    br.close()

    if (red >= 1) dp[1][1][0][0] = 1
    if (green >= 1) dp[1][0][1][0] = 1
    if (blue >= 1) dp[1][0][0][1] = 1

    var res = 0L
    for (i in 1..n) {

        for (r in 0..red) {
            for (g in 0..green) {
                for (b in 0..blue) {

                    if (i == n) {
                        res += dp[i][r][g][b]
                        continue
                    }

                    for (j in 1..3) {
                        if ((i + 1) % j == 0) {
                            var diff = (i + 1) / j
                            var nr = r + diff <= red
                            var ng = g + diff <= green
                            var nb = b + diff <= blue

                            val now = dp[i][r][g][b]

                            when (j) {
                                1 -> {
                                    if (nr) dp[i + 1][r + diff][g][b] += now
                                    if (ng) dp[i + 1][r][g + diff][b] += now
                                    if (nb) dp[i + 1][r][g][b + diff] += now
                                }
                                2 -> {
                                    if (nr && ng)
                                        dp[i + 1][r + diff][g + diff][b] += now * (fact[i + 1] / (fact[diff] * fact[diff]))
                                    if (nr && nb)
                                        dp[i + 1][r + diff][g][b + diff] += now * (fact[i + 1] / (fact[diff] * fact[diff]))
                                    if (ng && nb)
                                        dp[i + 1][r][g + diff][b + diff] += now * (fact[i + 1] / (fact[diff] * fact[diff]))
                                }
                                3 -> {
                                    if (nr && ng && nb)
                                        dp[i + 1][r + diff][g + diff][b + diff] += now * (fact[i + 1] / (fact[diff] * fact[diff] * fact[diff]))
                                }
                            }
                        }
                    }

                }
            }

        }
    }

    bw.write(res.toString())
    bw.close()
}