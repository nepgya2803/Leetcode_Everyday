namespace CSharp;

struct Testcase
{
    public int candles;
    public int candleCompose;
}

class Program
{
    static void Main(string[] args)
    {
        Solution sol = new Solution();
        IEnumerable<Testcase> testcases = new List<Testcase>
        {
            new Testcase { candles = 5, candleCompose = 2},
            new Testcase { candles = 9, candleCompose = 1},
        };

        int order = 1;
        foreach (var testcase in testcases)
        {
            var res = sol.CandlesBurn(testcase.candles, testcase.candleCompose);
            Helper.WriteMessage($"Testcase {order}", ConsoleColor.Blue);
            Helper.WriteMessage($"Result: {res}", ConsoleColor.DarkGreen);
            order++;
        }
    }
}

class Solution
{
    public int CandlesBurn(int candles, int candleCompose)
    {
        int burned = 0;
        int leftover = 0;

        while (candles > 0)
        {
            burned += candles;
            leftover += candles;
            candles = leftover / candleCompose;
            leftover %= candleCompose;
        }

        return burned;
    }
}

class Helper
{
    public static void WriteMessage(string message, ConsoleColor color)
    {
        Console.ForegroundColor = color;
        Console.WriteLine(message);
    }
}
