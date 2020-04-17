import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.System.exit
import java.util.*
import kotlin.system.exitProcess

val br = BufferedReader(InputStreamReader(System.`in`))

fun main() {

    val n = br.readLine().toInt()

    var qu: Queue<Long> = LinkedList()

    var cnt = -1
    for (i in 0..9L) {
        qu.add(i)
        cnt++
        if (cnt == n) {
            println(i)
            exitProcess(0)
        }
    }

    while (qu.isNotEmpty()) {
        var num = qu.poll()
        var digit = num % 10
        for (i in 0 until digit) {
            qu.add(num * 10 + i)
            cnt++

            if (cnt == n) {
                println(num * 10 + i)
                exitProcess(0)
            }
        }
    }
    println(-1)
}