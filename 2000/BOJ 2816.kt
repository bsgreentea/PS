import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder

fun main() {

    var reader = BufferedReader(InputStreamReader(System.`in`))
    val n = reader.readLine().toInt()

    var k1 = 0
    var k2 = 0
    var name = ""

    for (i in 1..n){
        name = reader.readLine()
        if(name.equals("KBS1")) k1 = i
        else if(name.equals("KBS2")) k2 = i
    }

    var ans = StringBuilder()

    if(k1 == 2 && k2 == 3) print("33")
    else if(k2 == 1 && k1 == 2) ans.append('3')
    else if(k1 < k2){
        for (i in 1..k1-1) ans.append('1')
        for (i in 1..k1-1) ans.append('4')
        for (i in 1..k2-1) ans.append('1')
        for (i in 1..k2-2) ans.append('4')
    }
    else{
        for (i in 1..k2-1) ans.append('1')
        for (i in 1..k2-1) ans.append('4')
        for (i in 1..k1-1) ans.append('1')
        for (i in 1..k1-1) ans.append('4')
    }

    print(ans)
}