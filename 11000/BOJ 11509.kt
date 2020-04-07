import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

const val MAX = 1000000

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var chk = IntArray(MAX + 1)

fun main() {

    val n = br.readLine().toInt()
    val arr = br.readLine().split(' ').map { it.toInt() }.toIntArray()
    br.close()

    var cnt = 0
    for (i in 0 until n) {
        if(chk[arr[i] + 1] == 0) cnt++
        else chk[arr[i] + 1]--
        chk[arr[i]]++
    }

    bw.write("$cnt")
    bw.close()
}