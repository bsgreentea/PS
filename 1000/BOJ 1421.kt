import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Long.max

val br = BufferedReader(InputStreamReader(System.`in`))
var tree = IntArray(1010)

fun main() {

    val (n, c, w) = br.readLine().split(' ').map { it.toInt() }
    for (i in 1..n) tree[i] = br.readLine().toInt()
    br.close()

    var res = 0L

    for (unit in 1..10000) {

        var temp = 0L
        for (i in 1..n) {
            var num = tree[i] / unit
            if (num > 0) {
                if (tree[i] % unit > 0) {
                    if (unit * w - c > 0)
                        temp += unit * num * w - c * num
                } else {
                    if (unit * w * num - c * (num - 1) > 0)
                        temp += unit * num * w - c * (num - 1)
                }
            }
        }

        res = max(res, temp)
    }

    println(res)
}