import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

const val MAX = 100000

var line = List(MAX + 1) { mutableSetOf<Int>() }
var list = List(MAX + 1) { mutableListOf<Int>() }
var disc = BooleanArray(MAX + 1)
var passed = BooleanArray(MAX + 1)

class Info(now: Int, cnt: Int) {
    var now = now
    var cnt = cnt
}

fun main() {

    val (n, l) = br.readLine().split(' ').map { it.toInt() }

    for (i in 1..l) {
        var arr = br.readLine().split(' ').map { it.toInt() }.toIntArray()
        val sz = arr.size
        for (a in 0..sz - 2) {
            line[i].add(arr[a])
            list[arr[a]].add(i)
        }
    }

    val (from, to) = br.readLine().split(' ').map { it.toInt() }
    br.close()

    var qu: Queue<Info> = LinkedList()

    for (li in list[from]) {
        qu.add(Info(li, 0))
        disc[li] = true
    }

    var res = -1
    while (qu.size > 0) {

        var now = qu.peek().now
        var cnt = qu.peek().cnt
        qu.poll()

        if (to in line[now]) {
            res = cnt
            break
        }

        for (station in line[now]) {
            if (passed[station]) continue
            passed[station] = true

            for (next in list[station]) {
                if (disc[next]) continue
                disc[next] = true
                qu.add(Info(next, cnt + 1))
            }
        }
    }

    bw.write(res.toString())
    bw.close()
}