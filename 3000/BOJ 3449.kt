import java.util.*

val sc:Scanner = Scanner(System.`in`)

fun main() {

    val n = sc.nextInt()
    sc.nextLine()
    for (i in 1..n){
        val a = sc.nextLine()
        val b = sc.nextLine()

        val len = a.length
        var diff = 0
        for (j in 0..len-1){
            if(a[j] != b[j]) diff++
        }

        print("Hamming distance is $diff.\n")
    }
}