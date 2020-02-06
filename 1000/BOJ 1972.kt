import java.io.BufferedReader
import java.io.InputStreamReader

var br = BufferedReader(InputStreamReader(System.`in`))

var chk = Array<IntArray>(26, { IntArray(26) })

fun init(){
    for (i in 0..25) for (j in 0..25) chk[i][j] = 0
}

fun main() {

    var str = ""
    while(true){
        str = br.readLine()
        if(str.equals("*")) break

        var n = str.length

        if(n <= 2){
            print(str + " is surprising.\n")
            continue
        }

        init()

        var flag = false
        for (i in 1..n-1){
            for (j in 0..n-i-1){
                var a = str[j] - 'A'
                var b = str[j+i] - 'A'

                if (chk[a][b] == i){
                    flag = true
                    break
                }
                chk[a][b] = i
            }
            if(flag) break
        }
        if(flag) print(str + " is NOT surprising.\n")
        else print(str + " is surprising.\n")
    }
}