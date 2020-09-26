import java.util.*

fun main() = with(Scanner(System.`in`)) {

    val n = readLine()!!.toInt()

    var list = mutableListOf<Int>()
    var ans = 0

    (1..n).forEach {
        val num = readLine()!!.toInt()
        list.add(num)
    }

    val sz = list.size

    for (i in list.indices) {

        if (i > 0) {
            val higherLevel = list[sz - 1 - i + 1]
            val now = list[sz - 1 - i]

            val diff = (higherLevel - 1) - now
            if (diff <= 0) {
                list[sz - 1 - i] = higherLevel - 1
                ans += -diff
            }
        }
    }

    println(ans)
}