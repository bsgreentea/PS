import java.io.BufferedReader
import java.io.InputStreamReader

val br = BufferedReader(InputStreamReader(System.`in`))

fun isPalindrome(str: String, idx: Int, center: Int): Boolean {

    val n = str.length
    var diff = 0

    if(n == 1) return true

    while (true) {
        diff++
        if(idx+diff-1+center >= n || idx-diff < 0) return true
        if (str[idx + diff - 1 + center] != str[idx - diff]) return false
    }
    return true
}

fun main() {

    var pal = br.readLine().toString()
    val n = pal.length

    var res = 2 * n - 1

    for (i in n / 2..n - 1) {
        if (i > n/2 && isPalindrome(pal, i, 0)) {
            res = i * 2
            break
        }
        if (isPalindrome(pal, i, 1)) {
            res = i * 2 + 1
            break
        }
    }

    var flag = 0
    for (i in 0..n/2){
        if(pal[i] != pal[n-1-i]){
            flag = 1
            break
        }
    }

    if(flag == 1) print(res)
    else print(n)
}