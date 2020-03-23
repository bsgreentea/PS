import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.StringBuilder

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

var cand: MutableList<String> = mutableListOf()

fun main() {

    var str = br.readLine().toString()
    br.close()

    val n = str.length
    for (i in 1 until n) {
        for (j in i + 1 until n) {
            var left = str.subSequence(0, i)
            var mid = str.subSequence(i, j)
            var right = str.subSequence(j, n)

            var temp = StringBuilder()
            temp.append(left.reversed())
            temp.append(mid.reversed())
            temp.append(right.reversed())

            cand.add(temp.toString())
        }
    }

    cand.sort()
    bw.write(cand[0])
    bw.close()
}