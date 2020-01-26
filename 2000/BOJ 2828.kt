import java.util.*

val sc: Scanner = Scanner(System.`in`)

fun main() {

    sc.nextInt()
    val m = sc.nextInt()
    val j = sc.nextInt()

    var apple = 0
    var left = 1
    var right = m
    var moving = 0

    var diff = 0

    for (i in 1..j){
        apple = sc.nextInt()

        if (left <= apple && apple <= right) continue
        if (apple < left){
            diff = left - apple
            left -= diff
            right -= diff
            moving += diff
        }
        else{
            diff = apple - right
            left += diff
            right += diff
            moving += diff
        }
    }

    println(moving)
}