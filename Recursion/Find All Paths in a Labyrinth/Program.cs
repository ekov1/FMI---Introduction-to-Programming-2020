using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Find_All_Paths_in_a_Labyrinth
{
    class Program
    {

        public static int rows;
        public static int cols;
        public static char[,] matrix;
        static void Main()
        {
            matrix = ReadMatrix();
           
        }

        public static void PrintMatrix()
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        public static char[,] ReadMatrix()
        {
            rows = int.Parse(Console.ReadLine());
            cols = int.Parse(Console.ReadLine());

            char[,] matrix = new char[rows, cols];

            for (int i = 0; i < rows; i++)
            {
                string line = Console.ReadLine();
                for (int j = 0; j < cols; j++)
                {
                    matrix[i, j] = line[j];
                }
            }

            return matrix;
        }
    }
}
