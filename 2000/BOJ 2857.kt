import java.util.*

fun main() {

    val sc:Scanner = Scanner(System.`in`)

    val regex = Regex(pattern = "FBI")
    var flag = true

    for(i in 1..5){
        val matched = regex.containsMatchIn(sc.nextLine())
        if(matched) {
            flag = false
            print("$i ")
        }
    }

    if(flag)
        println("HE GOT AWAY!")
}