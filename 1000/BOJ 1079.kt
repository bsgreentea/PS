import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max

val br = BufferedReader(InputStreamReader(System.`in`))

var r = Array<IntArray>(20) { IntArray(20) }
var crime = IntArray(20)
var ans = 0

fun game(state: Int, n: Int, me: Int, alive: Int, rem: Int) {

    if (rem % 2 == 1) {

        var now = Int.MIN_VALUE
        var idx = 0

        for (i in 0 until n) {
            if (crime[i] > now && (1 shl i) and state == 0) {
                now = crime[i]
                idx = i
            }
        }

        if (idx == me) {
            ans = max(ans, alive)
            return
        }

        game(state or (1 shl idx), n, me, alive, rem - 1)

    } else {

        if (rem == 2) {
            ans = max(ans, alive + 1)
            return
        }

        for (i in 0 until n) {
            if (i != me && (1 shl i) and state == 0) {
                for (j in 0 until n) crime[j] += r[i][j]
                game(state or (1 shl i), n, me, alive + 1, rem - 1)
                for (j in 0 until n) crime[j] -= r[i][j]
            }
        }
    }
}

fun main() {

    var n = br.readLine().toInt()
    crime = br.readLine().split(' ').map { it.toInt() }.toIntArray()

    for (i in 0 until n)
        r[i] = br.readLine().split(' ').map { it.toInt() }.toIntArray()

    var me = br.readLine().toInt()

    br.close()

    if (n > 1)
        game(0, n, me, 0, n)

    println(ans)
}