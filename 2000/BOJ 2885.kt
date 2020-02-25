import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))

fun main() {

    var n = br.readLine().toInt()

    var hi = 0
    var lo = -1
    var cnt = 0
    var origin = 1

    while (n > 0) {
        if (n % 2 == 1) {
            hi = cnt
            if (lo == -1) lo = cnt
        }
        cnt++
        origin *= 2
        n /= 2
    }

    if(hi == lo) print("${origin/2} 0\n")
    else print("$origin ${hi - lo + 1}\n")
}