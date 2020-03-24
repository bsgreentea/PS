import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

const val MOD = 1000000

var dp = IntArray(5050)

fun main() {

    val cipher = br.readLine().toString() + "000"
    br.close()
    val n = cipher.length - 3

    dp[0] = 1
    if ((cipher[0] - '0') * 10 + (cipher[1] - '0') in 11..26) dp[1] = 2 else dp[1] = 1
    if(cipher[0] == '2' && cipher[1] == '0') dp[1] = 1

    var flag = false
    for (i in 0 until n) {

        if (i > 0 && cipher[i] == '0' && cipher[i - 1] == '0') flag = true
        if (i > 0 && cipher[i - 1] - '0' > 2 && cipher[i] == '0') flag = true

        if (i + 1 > 1 && cipher[i + 1] != '0') dp[i + 1] += dp[i]
        dp[i + 1] %= MOD

        if ((cipher[i + 1] - '0') * 10 + (cipher[i + 2] - '0') in 10..26)
            dp[i + 2] += dp[i]

        dp[i + 2] %= MOD
    }

    if (cipher[0] == '0') flag = true

    if (flag) dp[n - 1] = 0

    bw.write(dp[n - 1].toString())
    bw.close()
}