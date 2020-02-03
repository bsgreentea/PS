import java.util.*

var arr = FloatArray(101)

fun main() = with(Scanner(System.`in`)){

    var n = nextInt()
    var m = nextInt()
    var k = nextInt()

    for (i in 0..m-1){
        for (j in 0..n-1){
            var id = nextInt()
            var s = nextFloat()
            if(arr[id] < s) arr[id] = s
        }
    }

    arr.sortDescending()

    var res = 0.0
    for (i in 0..k-1) res += arr[i]

    print(String.format("%.1f", res))
}