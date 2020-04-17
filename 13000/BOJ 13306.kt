import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

const val MAX = 200000

var originPar = IntArray(MAX + 1)
var par = IntArray(MAX + 1)
var tree = Array(MAX + 1) { MutableList(0) { 0 } }

fun find(curr: Int): Int {
    if (par[curr] == curr) return curr
    par[curr] = find(par[curr])
    return par[curr]
}

fun merge(x: Int, y: Int) {
    var a = find(x)
    var b = find(y)
    if (a == b) return

    par[a] = b
}

fun main() {

    val (n, q) = br.readLine().split(' ').map { it.toInt() }

    for (i in 1..n) par[i] = i

    var info = mutableListOf<Int>()
    for (i in 1 until n) {
        val num = br.readLine().toInt()
        info.add(num)
        originPar[i + 1] = num
    }

    var cutSet = mutableSetOf<Int>()
    var queryList = mutableListOf<MutableList<Int>>()
    for (i in 0 until n - 1 + q) {

        val arr = br.readLine().split(' ').map { it.toInt() }.toMutableList()
        if (arr[0] == 0) cutSet.add(arr[1])

        queryList.add(arr)
    }

    var cnt = 1
    for (v in info) {
        cnt++
        if (cnt in cutSet) continue
        merge(v, cnt)
    }

    queryList.reverse()
    var res = mutableListOf<String>()

    for (query in queryList) {
        if (query[0] == 0) {
            merge(query[1], originPar[query[1]])
        } else {
            if (find(query[1]) == find(query[2])) {
                res.add("YES\n")
            } else {
                res.add("NO\n")
            }
        }
    }

    res.reverse()
    for (e in res) bw.write(e)

    bw.close()
}