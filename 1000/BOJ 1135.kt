import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max

val br = BufferedReader(InputStreamReader(System.`in`))

var dp = IntArray(55) { -1 }
var tree = mutableListOf<MutableList<Int>>()

fun solve(now: Int): Int {

    if (dp[now] != -1) return dp[now]
    dp[now] = 0

    var tempList = mutableListOf<Int>()
    for (employee in tree[now]) {
        tempList.add(solve(employee))
    }

    tempList.sortDescending()

    var order = 0
    for (cnt in tempList) {
        dp[now] = max(dp[now], cnt + 1 + order++)
    }

    return dp[now]
}

fun main() {

    val n = br.readLine().toInt()
    var arr = br.readLine().split(' ').map { it.toInt() }.toIntArray()

    for (i in 0 until n) tree.add(mutableListOf())
    for (i in 1 until n) tree[arr[i]].add(i)

    println(solve(0))
}