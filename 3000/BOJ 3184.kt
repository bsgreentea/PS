import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var map = Array(255) { CharArray(255) }
var disc = Array(255) { BooleanArray(255) }

val dx = intArrayOf(0, 0, 1, -1)
val dy = intArrayOf(1, -1, 0, 0)

fun chk(x: Int, y: Int, r: Int, c: Int): Boolean = x in 0 until r && y in 0 until c

class Info(x: Int, y: Int) {
    var x = x
    var y = y
}

fun main() {

    val (r, c) = br.readLine().split(' ').map { it.toInt() }

    for (i in 0 until r) map[i] = br.readLine().map { it }.toCharArray()
    br.close()

    var sheep = 0
    var wolf = 0

    for (i in 0 until r) {
        for (j in 0 until c) {
            if (map[i][j] == '#' || disc[i][j]) continue

            var qu: Queue<Info> = LinkedList()

            var a = 0
            var b = 0

            qu.add(Info(i, j))
            disc[i][j] = true

            while (qu.size > 0) {

                val x = qu.peek().x
                val y = qu.peek().y
                qu.poll()

                if (map[x][y] == 'o') a++
                if (map[x][y] == 'v') b++

                for (k in 0 until 4) {
                    val nx = x + dx[k]
                    val ny = y + dy[k]

                    if (!chk(nx, ny, r, c) || disc[nx][ny] || map[nx][ny] == '#') continue

                    qu.add(Info(nx, ny))
                    disc[nx][ny] = true
                }
            }

            if (a > b) sheep += a
            else wolf += b
        }
    }

    bw.write("$sheep $wolf")
    bw.close()
}