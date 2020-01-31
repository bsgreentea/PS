import java.util.*

fun main() = with(Scanner(System.`in`)) {

    var n = nextInt()
    var m = nextInt()
    var arr = Array<Int>(n){0}

    for (i in 1..n){

        var p = nextInt()
        var l = nextInt()
        var pq = PriorityQueue<Int>()

        for (j in 1..p) pq.add(nextInt())

        while (pq.size > l) pq.poll()

        arr[i-1] = if(p < l) 1 else pq.peek()
    }

    arr.sort()

    var cnt = 0
    for (elem in arr){
//        print(elem)
        if(m >= elem){
            m -= elem
            cnt++
        }
    }

    print(cnt)
}