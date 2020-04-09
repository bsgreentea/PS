import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var map = Array(1010) { CharArray(1010) }

val dx = intArrayOf(0, 0, 1, -1)
val dy = intArrayOf(1, -1, 0, 0)

fun chk(x: Int, y: Int, h: Int, w: Int): Boolean = x in 0 until h && y in 0 until w
fun chkEdge(x: Int, y: Int, h: Int, w: Int): Boolean = x == 0 || x == h - 1 || y == 0 || y == w - 1

class Info(x: Int, y: Int) {
    val x = x
    val y = y
}

fun main() {

    val T = br.readLine().toInt()

    for (t in 1..T) {

        var flag = false
        var me: Queue<Info> = LinkedList()
        var fire: Queue<Info> = LinkedList()

        val (w, h) = br.readLine().split(' ').map { it.toInt() }
        for (i in 0 until h) {
            map[i] = br.readLine().toCharArray()
            for (j in 0 until w) {
                if (map[i][j] == '@') me.add(Info(i, j))
                else if (map[i][j] == '*') {
                    fire.add(Info(i, j))
                }
            }
        }

        var cnt = 0
        while (me.isNotEmpty()) {

            cnt++

            var qs = fire.size
            for (i in 1..qs) {

                val x = fire.peek().x
                val y = fire.peek().y
                fire.poll()

                for (j in 0 until 4) {
                    val nx = x + dx[j]
                    val ny = y + dy[j]
                    if (!chk(nx, ny, h, w) || map[nx][ny] == '#' || map[nx][ny] == '*') continue

                    map[nx][ny] = '*'
                    fire.add(Info(nx, ny))
                }
            }

            qs = me.size
            for (i in 1..qs) {

                val x = me.peek().x
                val y = me.peek().y
                me.poll()

                if(chkEdge(x,y,h,w)){
                    bw.write("$cnt\n")
//                    println(cnt)
                    flag = true
                    break
                }

                for (j in 0 until 4) {
                    val nx = x + dx[j]
                    val ny = y + dy[j]
                    if (!chk(nx, ny, h, w) || map[nx][ny] == '#' || map[nx][ny] == '*' || map[nx][ny] == '@') continue

                    map[nx][ny] = '@'
                    me.add(Info(nx, ny))
                }
                if (flag) break
            }
            if (flag) break
        }

        if (!flag) bw.write("IMPOSSIBLE\n")
//        if(!flag) println("IMPOSSIBLE")
    }

    br.close()
    bw.close()
}