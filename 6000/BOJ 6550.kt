import java.util.*

fun main() = with(Scanner(System.`in`)) {

    while (hasNextLine()) {

        val (s, t) = nextLine().split(' ').map { it }

        val ns = s.length
        val nt = t.length

        var chk = 0

        var i = 0
        var j = 0

        while(i < ns && j < nt){

            if(s[i] == t[j]){
                i++
                chk++
            }
            j++
        }

        print(if (chk == ns) "Yes\n" else "No\n")
    }

}