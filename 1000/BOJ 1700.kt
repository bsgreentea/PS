import java.util.*

val INF = 1000
var arr = Array(101, {0})
var tab = Array(101, {0})
var determinIdx = Array(101, {0})

fun chk(n:Int, target:Int):Boolean {
    for (i in 0..n-1) {
        if (tab[i] == target) return true
    }
    for (i in 0..n-1) {
        if (tab[i] == 0){
            tab[i] = target
            return true
        }
    }
    return false
}

fun change(n:Int, from:Int, to:Int) {
    for (i in 0..n-1) {
        if(tab[i] == from){
            tab[i] = to
            return
        }
    }
}

fun main() = with(Scanner(System.`in`)) {

    var (n,k) = readLine()!!.split(' ').map{it.toInt()}

    for (i in 0..k-1) arr[i] = nextInt()

    var cnt = 0

    for (i in 0..k-1){
        if(!chk(n, arr[i])){
            for (j in 0..n-1) determinIdx[j] = INF
            for (j in k-1 downTo i){
                for (ed in 0..n-1){
                    if(tab[ed] == arr[j]){
                        determinIdx[ed] = j
                        break
                    }
                }
            }

            var temp = -INF
            var targetIdx = 0
            for (j in 0..n-1){
                if(temp < determinIdx[j]){
                    temp = determinIdx[j]
                    targetIdx = j
                }
            }

            change(n,tab[targetIdx],arr[i])

            cnt++
        }
    }

    println(cnt)
}