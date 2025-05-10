using System.Security.Cryptography.X509Certificates;
using Helper;

namespace CSharp;


struct Testcase
{
    public int[] nums1;
    public int[] nums2;
}

class Program
{
    static void Main(string[] args)
    {
        Solution sol = new Solution();
        IEnumerable<Testcase> testcases = new List<Testcase>()
        {
            new Testcase
            {
                nums1 = new int[] { 3, 2, 0, 1, 0 },
                nums2 = new int[] { 6, 5, 0 }
            },
            new Testcase
            {
                nums1 = new int[] { 2,0,2,0 },
                nums2 = new int[] { 1, 4 }
            },
        };

        foreach (var test in testcases)
        {
            var result = sol.MinSum(test.nums1, test.nums2);
            Support.PrintOutResult(result);
        }


    }
}

public class Solution
{
    public long MinSum(int[] nums1, int[] nums2)
    {
        long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        nums1.ToList().ForEach((x) =>
        {
            sum1 += x;

            if (x == 0)
            {
                sum1++;
                zero1++;
            }
        });

        nums2.ToList().ForEach((x) =>
        {
            sum2 += x;

            if (x == 0)
            {
                sum2++;
                zero2++;
            }
        });

        if (zero1 == 0 && sum1 < sum2 || zero2 == 0 && sum2 < sum1) return -1;

        return Math.Max(sum1, sum2);
    }
}
