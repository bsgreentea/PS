import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

const val MOD = 1000000003

var comb = Array(1010) { LongArray(1010) { -1L } }

fun solve(now: Int, cnt: Int): Long {

    if (now < cnt * 2) return 0

    if (cnt == 1) return now.toLong()
    if (now < 1) return 0

    var temp = comb[now][cnt]
    if (temp != -1L) return temp

    temp = solve(now - 2, cnt - 1) % MOD + solve(now - 1, cnt) % MOD
    temp %= MOD
    comb[now][cnt] = temp
    return temp
}

fun main() {

    val n = br.readLine().toInt()
    val k = br.readLine().toInt()
    br.close()

    comb[1][1] = 1
    comb[2][1] = 2
    comb[3][1] = 3

    var res = solve(n, k)

    bw.write(res.toString())
    bw.close()
}