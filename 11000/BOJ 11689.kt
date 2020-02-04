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

    var n = br.readLine().toLong()

    var i = 2L
    var res = 1L
    var cnt = 0L

    if (n % i == 0L) {
        cnt = 0L
        while (n % i == 0L) {
            cnt++
            n /= i
        }
        res *= (pow(i, cnt) - pow(i, cnt - 1L))
    }
    i++

    while (true) {
        if(i*i > n) break

        if (n % i == 0L) {
            cnt = 0L
            while (n % i == 0L) {
                cnt++
                n /= i
            }
            res *= (pow(i, cnt) - pow(i, cnt - 1L))
        }
        i += 2
    }

    if(n > 1) res *= n-1

    println(res)
}