import java.io.BufferedReader
import java.io.InputStreamReader

var br = BufferedReader(InputStreamReader(System.`in`))

fun pow(A: Long, B: Long): Long {
    var ret = 1L

    var a = A
    var b = B

    while (b > 0) {
        if (b % 2 == 1L) ret *= a
        a *= a
        b /= 2L
    }
    return ret
}

fun main() {

    var n = 0L
    while (true) {

        n = br.readLine().toLong()
        if (n == 0L) break

        var i = 2L
        var res = 1L
        var cnt = 0L

        while (true) {
            if(n <= 1) break

            if (n % i == 0L) {
                cnt = 0L
                while (n % i == 0L) {
                    cnt++
                    n /= i
                }
                res *= (pow(i, cnt) - pow(i, cnt - 1L))
            }

            i++
        }

        println(res)
    }
}