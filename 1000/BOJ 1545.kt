import java.lang.StringBuilder
import java.lang.System.exit
import java.util.*

var cnt = Array<Int>(26, { 0 })
var chars = mutableListOf<Char>()

fun main() = with(Scanner(System.`in`)) {

    var s = nextLine()
    var len = s.length

    if(len == 1){
        print(s)
        exit(0)
    }

    for (c in s) {

        cnt[c - 'a']++
        chars.add(c)

        if (cnt[c - 'a'] > (len + 1) / 2) {
            print(-1)
            exit(0)
        }
    }

    chars.sort()

    var left = 0
    var right = 0

    if (len % 2 == 1 && chars[len / 2 - 1] == chars[len / 2 + 1]) {
        for (i in 0..(len / 2) - 1) {
            if (chars[i] == chars[len / 2]) left++
            if (chars[len - 1 - i] == chars[len / 2]) right++
        }
    } else if (len % 2 == 0 && chars[len / 2 - 1] == chars[len / 2]) {
        for (i in 0..(len / 2) - 1) {
            if (chars[i] == chars[len / 2]) left++
            if (chars[len - 1 - i] == chars[len / 2]) right++
        }
    } else {
        for (i in 0..len-1) print(chars[i])
        exit(0)
    }

    var newS = StringBuilder()

    for (i in 0..len - 1) {
        if (i >= (len+1)/2 && chars[i] == chars[len/2-1]) continue
        newS.append(chars[i])
    }

    var newLen = newS.length
    for (i in 0..newLen-1){
        print(newS[i])
        if(left == i - (len-1)/2){
            for (j in 1..right) print(chars[len/2-1])
        }
    }
}