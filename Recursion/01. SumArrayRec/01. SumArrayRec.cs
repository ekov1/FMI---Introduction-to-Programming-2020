using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01.SumArrayRec
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        private static int Sum(int[] numbers, int index)
        {
            if (index == numbers.Length - 1)
            {

            }

            return numbers[index] + Sum(numbers, index + 1);
        }
    }
}
