using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _03.Vectors
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] vector = new int[n];
            List<string> vectors = new List<string>();
            vectors = GenerateVectors(0, vector, vectors);
            foreach (var v in vectors)
            {
                Console.WriteLine(v);
            }
        }

        public static List<string> GenerateVectors(int index, int[] vector, List<string> vectors)
        {
            if (index > vector.Length - 1)
            {
                vectors.Add(string.Join(" ", vector));
                return vectors;
            }
            else
            {
                vector[index] = 0;
                vectors = GenerateVectors(index + 1, vector, vectors);


                vector[index] = 1;
                vectors = GenerateVectors(index + 1, vector, vectors);
            }
            return vectors;
        }
    }
}
