import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.StringBuilder
import java.util.*

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))
var chk = IntArray(200) { 0 }
var list = mutableSetOf<String>()

fun make(str: String, state: Int) {

    var sb = StringBuilder()

    for (i in 0..str.length - 1) {
        if (((1 shl chk[i]) and state) > 0) continue
        sb.append(str[i])
    }

    list.add(sb.toString())
}

fun solve(str: String, state: Int, cnt: Int, n: Int) {

    if (cnt > n) return
    if (state > 0) make(str, state)

    for (i in cnt + 1..n) {
        solve(str, state or (1 shl i), i, n)
    }
}

fun main() {

    val formula = br.readLine().toString()

    br.close()

    var cnt = 1
    var stack = Stack<Int>()
    val len = formula.length

    for (i in 0..len - 1) {
        if (formula[i] == '(') {
            stack.push(i)
        }
        if (formula[i] == ')') {
            var idx = stack.peek()
            chk[idx] = cnt
            chk[i] = cnt
            cnt++
            stack.pop()
        }
    }

    solve(formula, 0, 0, cnt - 1)

    val res = list.toMutableList()
    res.sort()

    for (e in res) bw.write(e+"\n")
    bw.close()
}