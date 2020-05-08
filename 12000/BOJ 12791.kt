import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

val list = "1967 DavidBowie\n" +
        "1969 SpaceOddity\n" +
        "1970 TheManWhoSoldTheWorld\n" +
        "1971 HunkyDory\n" +
        "1972 TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars\n" +
        "1973 AladdinSane\n" +
        "1973 PinUps\n" +
        "1974 DiamondDogs\n" +
        "1975 YoungAmericans\n" +
        "1976 StationToStation\n" +
        "1977 Low\n" +
        "1977 Heroes\n" +
        "1979 Lodger\n" +
        "1980 ScaryMonstersAndSuperCreeps\n" +
        "1983 LetsDance\n" +
        "1984 Tonight\n" +
        "1987 NeverLetMeDown\n" +
        "1993 BlackTieWhiteNoise\n" +
        "1995 1.Outside\n" +
        "1997 Earthling\n" +
        "1999 Hours\n" +
        "2002 Heathen\n" +
        "2003 Reality\n" +
        "2013 TheNextDay\n" +
        "2016 BlackStar"

fun main() {

    val info: Array<List<String>> = list.split('\n').map { it.split(' ').map { it } }.toTypedArray()

    val q = br.readLine().toInt()
    for (t in 1..q) {
        val (s, e) = br.readLine().split(' ').map { it.toInt() }
        var cnt = 0
        for (i in info) {
            if (i[0].toInt() in s..e) cnt++
        }
        bw.write("$cnt\n")
        for (i in info) {
            if (i[0].toInt() in s..e) bw.write("${i[0]} ${i[1]}\n")
        }
    }

    bw.close()
}