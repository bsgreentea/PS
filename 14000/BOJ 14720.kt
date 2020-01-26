import java.util.*

val sc:Scanner = Scanner(System.`in`)
var cnt = 0
var now = 2

fun main() {

    val n = sc.nextInt()
    for (i in 1..n){

        val milk = sc.nextInt()
        if((now + 1) % 3 == milk){
            cnt++
            now = milk
        }
    }

    println(cnt)
}