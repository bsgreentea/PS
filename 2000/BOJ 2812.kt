import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    var list = mutableListOf<Char>()

    var (n, k) = readLine()!!.split(' ').map { it.toInt() }
    var num = nextLine()

    for (i in 0..k-1) {
        while(list.size > 0 && list.last() - '0' < num[i] - '0') list.removeAt(list.lastIndex)
        var point = list.lastIndex + 1
        if(point <= 0) point = 0
        list.add(point, num[i])
    }
    for (i in k..n-1){
        while(list.size > 0 && list.last() - '0' < num[i] - '0') list.removeAt(list.lastIndex)
        var point = list.lastIndex + 1
        if(point <= 0) point = 0
        list.add(point, num[i])

        print("${list.first()}")
        list.removeAt(0)
    }
    print("\n")
}