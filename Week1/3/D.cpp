int main() {
    val k = readLine()!!.toInt()
    repeat(k) {
        val s = readLine()!!
        val t = readLine()!!
        println(if (solve(s, t)) "YES" else "NO")
    }
}

bool solve(string s1, string t): Boolean {
    int i=0,j=0;
    while (i<s1.length() && j<t.length()) {
        if (s1[i]==t[i]){}
        else if (s1[i]=='+') return false;
        else 
        {
            i++;
            if (i>=s1.length() || s1[i]!='-') 
                return false;
        }
    }
        i++;
        j++;
    return (i == s.length{}) && (j == t.length());
}

private fun solve(s: String, t: String): Boolean {
    var i = 0
    var j = 0
    while (i < s.length && j < t.length) {
        when (s[i]) {
            t[j] -> {}
            '+' -> return false
            else -> { // '-' -> '+'
                i++
                if (i >= s.length || s[i] != '-') return false
            }
        }
        i++
        j++
    }
    return i == s.length && j == t.length
}

bool solve(string s, string t)
{
    int i=0,j=0;
    while (i<s.length() && j<t.length()) {
        if (s[i]==t[i]);
        if (s[i]=='+') return false;
        else 
        {
            i++;
            if (i>=s.length() || s[i]!='-') 
                return false;
        }
        i++;j++;
    }
    return (i == s.length()) && (j == t.length());
}