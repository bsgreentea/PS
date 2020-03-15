import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {

    var n = BufferedReader(InputStreamReader(System.`in`)).readLine().toLong()

    var k = 1L
    var res = 0L
    while (n > 0) {

        if (n % 2 == 1L) {
            res += k
        }

        n /= 2L
        k *= 3
    }

    println(res)
}