import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.max
import kotlin.math.min

const val MAX = 2001

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var parcel = Array(MAX + 1) { IntArray(MAX + 1) }
var truck = IntArray(MAX + 1)
var sum = 0

fun cutOverflow(start: Int, c: Int) {
    for (i in MAX downTo start) {
        if (sum > c) {
            var dec = min(sum - c, truck[i])
            truck[i] -= dec
            sum -= dec
        } else break
    }
}

fun main() {

    val (n, c) = br.readLine().split(' ').map { it.toInt() }
    val m = br.readLine().toInt()

    for (i in 1..m) {
        val (from, to, box) = br.readLine().split(' ').map { it.toInt() }
        parcel[from][to] = box
    }
    br.close()

    var res = 0
    for (i in 1..n) {
        res += truck[i]
        sum -= truck[i]
        for (j in i + 1..n) {
            truck[j] += parcel[i][j]
            sum += parcel[i][j]
        }
        cutOverflow(i + 1, c)
    }

    bw.write(res.toString())
    bw.close()
}