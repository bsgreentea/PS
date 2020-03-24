import java.util.*

const val MOD = 1000000

var state = Array(1010) { Array(3) { Array(2) { IntArray(3) } } }

fun main() = with(Scanner(System.`in`)) {

    val n = nextInt()

    state[1][0][0][0] = 1
    state[1][1][1][0] = 1
    state[1][2][0][1] = 1

    for (a in 1 until n) {

        state[a + 1][0][0][0] += state[a][2][0][2] + state[a][2][0][1] + state[a][0][0][0]
        state[a + 1][0][0][0] %= MOD
        state[a + 1][0][1][0] += state[a][0][1][0] + state[a][1][1][0] + state[a][2][1][1] + state[a][2][1][2]
        state[a + 1][0][1][0] %= MOD

        state[a + 1][1][1][0] += state[a][0][0][0] + state[a][2][0][1] + state[a][2][0][2]
        state[a + 1][1][1][0] %= MOD

        state[a + 1][2][0][1] += state[a][0][0][0]
        state[a + 1][2][0][1] %= MOD
        state[a + 1][2][0][2] += state[a][2][0][1]
        state[a + 1][2][0][2] %= MOD
        state[a + 1][2][1][1] += state[a][0][1][0] + state[a][1][1][0]
        state[a + 1][2][1][1] %= MOD
        state[a + 1][2][1][2] += state[a][2][1][1]
        state[a + 1][2][1][2] %= MOD
    }

    var res = 0
    for (i in 0..2) for (j in 0..2) res += (state[n][i][0][j] + state[n][i][1][j]) % MOD

    println(res % MOD)
}