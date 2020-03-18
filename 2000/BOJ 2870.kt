import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.StringBuilder

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

fun main() {

    var cand = mutableListOf<String>()

    val n = br.readLine().toInt()

    for (t in 1..n) {
        var line = br.readLine().toString()
        var sb = StringBuilder()
        val len = line.length

        for (i in 0..len - 1) {
            if (i == len - 1) {
                if(line[i].isDigit()) sb.append(line[i])
                if (!sb.isEmpty()) cand.add(sb.toString())
                sb.clear()
                break
            }
            if (line[i].isDigit()) {
                sb.append(line[i])
            } else {
                if (!sb.isEmpty()) cand.add(sb.toString())
                sb.clear()
            }
        }
    }

    br.close()

    var nums = mutableListOf<Pair<Int, String>>()
    for (num in cand) {
        var sb = StringBuilder()
        var len = num.length

        for (i in 0..len - 2) {
            if(num[i] == '0' && sb.isEmpty()) continue
            sb.append(num[i])
        }

        sb.append(num.last())
        sb.append('\n')
        nums.add(Pair(sb.length, sb.toString()))
    }

    var res = nums.sortedWith(compareBy({it.first},{it.second}))
    for (num in res) bw.write(num.second)

    bw.close()
}