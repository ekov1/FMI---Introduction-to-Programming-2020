using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01.Fibonacci
{
    class Program
    {
        static void Main()
        {
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine(Fib(n));
        }

        static Dictionary<int, long> memo = new Dictionary<int, long>();

        static long Fib(int n)
        {
            if (memo.ContainsKey(n))
            {
                return memo[n];
            }

            if (n == 1)
            {
                memo.Add(1, 1);
                return 1;
            }
            if (n == 2)
            {
                memo.Add(2, 1);
                return 1;
            }
            //if (n == 3)
            //{
            //    memo.Add(3, 1);
            //    return 1;
            //}

            long result = Fib(n - 1) + Fib(n - 2);
            memo.Add(n, result);

            return result;
        }
    }
}
