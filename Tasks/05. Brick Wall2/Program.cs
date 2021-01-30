using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _05.Brick_Wall2
{
    class Program
    {
        public static int n;
        public static int m;
        public static int[,] firstLayer;
        public static int[,] secondLayer;
        public static HashSet<int> briks = new HashSet<int>();

        static void Main()
        {
            int[] row = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            n = row[0];
            m = row[1];

            firstLayer = new int[n, m];

            // read first layer
            for (int i = 0; i < n; i++)
            {
                row = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                for (int j = 0; j < m; j++)
                {
                    firstLayer[i, j] = row[j];
                    briks.Add(row[j]);
                }
            }

            // create secondLayer
            secondLayer = new int[n, m];

            PrintMatrix(firstLayer, n, m);
            PrintMatrix(secondLayer, n, m);
        }

        bool PutBricks()
        {
            if (briks.Count == 0)
            {
                return true;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (secondLayer[i, j] == 0)
                    {
                        bool result = PutBrick(i, j);
                        if (result)
                        {
                            PutBricks();
                            RemoveBrick();
                        }
                    }
                }
            }

            return false;
        }

        public static void RemoveBrick()
        {
            throw new NotImplementedException();
        }

        public static bool PutBrick(int i, int j)
        {
            bool result = false;
            // w
            if (j + 1 < m && secondLayer[i,j+1]==0)
            {
                foreach (var brick in briks)
                {
                    //if (brik != firstLayer[i,j] )
                    //{

                    //}
                }
            }
            return result;
        }

        public static void PrintMatrix(int[,] matrix, int n, int m)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i < 10)
                    {
                        Console.Write(matrix[i, j] + "  ");
                    }
                    else
                    {
                        Console.Write(matrix[i, j] + " ");
                    }

                }
                Console.WriteLine();
            }
        }
    }
}
