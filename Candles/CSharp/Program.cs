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
            new Testcase { candles = 9, candleCompose = 1}, // -> Note that if the k or candleCompose = 1, the loop will take forever
            new Testcase { candles = 4, candleCompose = 2},
            new Testcase { candles = 7, candleCompose = 3},
            new Testcase { candles = 134, candleCompose = 45},
        };

        int order = 1;
        foreach (var testcase in testcases)
        {
            Helper.WriteMessage($"Testcase {order}", ConsoleColor.Blue);
            var res = Task.Run(() => sol.CandlesBurn(testcase.candles, testcase.candleCompose));
            bool isExceed = res.Wait(TimeSpan.FromSeconds(3));

            if (isExceed)
            {
                Helper.WriteMessage($"Result: {res.Result}\n", ConsoleColor.DarkGreen);
            }
            else
            {
                Helper.WriteMessage($"Result: Time Limit Exceed!\n", ConsoleColor.Red);
            }

            order++;
        }
    }
}

class Solution
{
    public int CandlesBurn(int candles, int leftoverToBuildOne)
    {
        int burned = 0;
        int leftover = 0;

        while (candles > 0)
        {
            burned += candles;
            leftover += candles;
            candles = leftover / leftoverToBuildOne;
            leftover %= leftoverToBuildOne;
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
