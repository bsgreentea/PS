import java.util.*

fun main() = with(Scanner(System.`in`)){

    var koong = LongArray(70){0}
    koong[0] = 1
    koong[1] = 1
    koong[2] = 2
    koong[3] = 4

    var qu = 8L
    for (i in 4..68){
        koong[i] = qu
        qu -= koong[i-4]
        qu += koong[i]
    }

    var t = nextInt()
    for (i in 1..t) println(koong[nextInt()])
}