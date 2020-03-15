import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

fun main() {

    var (n, k, q) = br.readLine().split(' ').map { it.toLong() }

    for (t in 1..q) {

        var (x, y) = br.readLine().split(' ').map { it.toLong() }

        if (k == 1L) {
            bw.write(if (x > y) (x - y).toString() + "\n" else (y - x).toString() + "\n")
            continue
        }

        x--
        y--

        var dist = 0
        while (x != y) {

            if (x > y) {
                x--
                x /= k
            } else {
                y--
                y /= k
            }

            dist++
        }

        bw.write(dist.toString() + "\n")
    }
    bw.close()
}