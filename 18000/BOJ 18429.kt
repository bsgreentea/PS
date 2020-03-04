import java.util.*

var n = 0
var k = 0
var arr = IntArray(10)
var cnt = 0

fun solve(day: Int, weight: Int, state: Int){

    if(day == n){
        cnt++
        return
    }

    for (i in 1..n){

        var chk = 0
        if((1 shl i) and state > 0) continue
        if(weight + arr[i] - k < 500) continue

        solve(day+1, weight + arr[i] - k, state or (1 shl i))
    }
}

fun main() = with(Scanner(System.`in`)){

    n = nextInt()
    k = nextInt()

    for (i in 1..n) arr[i] = nextInt()

    solve(0, 500, 0)

    print(cnt)
}