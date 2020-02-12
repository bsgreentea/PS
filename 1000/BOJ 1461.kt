import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val br = BufferedReader(InputStreamReader(System.`in`))

fun main() {

    val (n, m) = br.readLine().split(' ').map { it.toInt() }
    var locate = br.readLine().split(' ').map { it.toInt() }.toIntArray()

    locate.sort()

    var res = 0
    for (i in 0..n - 1 step m) {
        if (locate[i] < 0) res -= locate[i] * 2
        if (locate[n - 1 - i] > 0) res += locate[n - 1 - i] * 2
    }

    if (-locate[0] > locate[n - 1]) res += locate[0]
    else res -= locate[n - 1]

    println(res)
}