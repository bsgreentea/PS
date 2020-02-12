import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max

val br = BufferedReader(InputStreamReader(System.`in`))

var locate = IntArray(1010)
var dp = Array<IntArray>(1010, { IntArray(33) { -1 } })

fun solve(sec: Int, move: Int): Int {

    if (sec <= 0 || move < 0 || move > sec) return -1
    if (dp[sec][move] != -1) return dp[sec][move]

    val oddEven = 1 - (move % 2)
    var plus = 0

    if (oddEven + locate[sec] == 2) plus++

    var temp1 = solve(sec - 1, move - 1)
    if (temp1 == -1) temp1 = 0
    var temp2 = solve(sec - 1, move)
    if (temp2 == -1) temp2 = 0

    dp[sec][move] = max(temp1, temp2) + plus
    return dp[sec][move]
}

fun main() {

    val (n, w) = br.readLine().split(' ').map { it.toInt() }

    for (i in 1..n) locate[i] = br.readLine().toInt()

    var res = 0
    for (i in 0..w) res = max(res, solve(n, i))

    println(res)
}