import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max
import java.util.*

val br = BufferedReader(InputStreamReader(System.`in`))

var res = 0
var n = 0
var dog: IntArray = intArrayOf()
var cand = Stack<Int>()

fun chk(): Int {

    var cnt = 1
    var left = 0
    var right = 0
    var sum = 0
    while (right < n) {

        if (sum >= 50) {
            if (sum == 50) cnt++
            sum -= cand[left++]
        } else sum += cand[right++]
    }

    return cnt - 1
}

fun solve(state: Int, cnt: Int): Int {

    if (cnt == n) {
        res = max(res, chk())
        return res
    }

    var ret = 0
    for (i in 0 until n) {
        if (state and (1 shl i) > 0) continue
        cand.push(dog[i])
        var temp = solve(state or (1 shl i), cnt + 1)
        ret = max(ret, temp)
        cand.pop()
    }
    return ret
}

fun main() {

    n = br.readLine().toInt()
    dog = br.readLine().split(' ').map { it.toInt() }.toIntArray()

    println(solve(0, 0))
}