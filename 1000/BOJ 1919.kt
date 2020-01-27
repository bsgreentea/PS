import java.lang.Integer.min
import java.util.*
fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val a = nextLine()
    val b = nextLine()

    var arrA = Array(26, {0})
    var arrB = Array(26, {0})

    val lenA = a.length
    val lenB = b.length

    for (c in a){
        arrA[c - 'a']++
    }
    for (c in b){
        arrB[c - 'a']++
    }

    var res = 0
    for (i in 0..25){
        res += min(arrA[i], arrB[i])
    }
    print(lenA + lenB - 2*res)
}