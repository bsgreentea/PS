import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.System.exit
import java.util.*
import kotlin.system.exitProcess

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var set = mutableSetOf<Int>()

fun main() {

    val (a, b) = br.readLine().split(' ').map { it.toInt() }
    br.close()

    var qu: Queue<Pair<Int, Int>> = LinkedList()

    if (a <= b) {
        bw.write((b - a).toString())
        bw.close()
        exitProcess(0)
    }

    qu.add(Pair(a, 0))
    set.add(a)

    while (qu.isNotEmpty()) {

        var now = qu.peek().first
        var cnt = qu.peek().second
        qu.poll()

        if (now <= b) {
            bw.write((cnt + b - now).toString())
            break
        }

        if (now % 2 == 0 && now / 2 !in set) {
            qu.add(Pair(now / 2, cnt + 1))
            set.add(now / 2)
        }
        if (now + 1 !in set) {
            qu.add(Pair(now + 1, cnt + 1))
            set.add(now + 1)
        }
    }
    bw.close()
}