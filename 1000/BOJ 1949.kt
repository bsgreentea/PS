import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max

val br = BufferedReader(InputStreamReader(System.`in`))

var population: IntArray = intArrayOf()
var tree: MutableList<MutableList<Int>> = mutableListOf()

var dp = Array<IntArray>(10010) { IntArray(2) { -1 } }

fun solve(par: Int, now: Int, colored: Int): Int {

    if (dp[now][colored] != -1) return dp[now][colored]

    var temp = 0

    if (colored == 1) {
        for (child in tree[now]) {
            if (child == par) continue
            temp += max(solve(now, child, 0), solve(now, child, 1))
        }
    } else {
        var temp1 = population[now]
        var temp2 = 0
        for (child in tree[now]) {
            if (child == par) continue
            temp1 += solve(now, child, 1)
            temp2 += solve(now, child, 0)
        }
        temp = max(temp1, temp2)
    }

    dp[now][colored] = temp
    return dp[now][colored]
}

fun main() {

    val n = br.readLine().toInt()
    population = br.readLine().split(' ').map { it.toInt() }.toIntArray()

    for (i in 0..n) tree.add(mutableListOf())

    for (i in 1 until n) {
        val (a, b) = br.readLine().split(' ').map { it.toInt() }
        tree[a - 1].add(b - 1)
        tree[b - 1].add(a - 1)
    }

    println(max(solve(-1, 0, 0), solve(-1, 0, 1)))
}