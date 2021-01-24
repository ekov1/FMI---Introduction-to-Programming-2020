using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _21.AllPathsLabyrinth
{
    class Program
    {
        static void Main(string[] args)
        {
            int rows = int.Parse(Console.ReadLine());
            int cols = int.Parse(Console.ReadLine());

            char[,] lab = new char[rows, cols];
            List<char> directions = new List<char>();

            for (int i = 0; i < rows; i++)
            {
                string row = Console.ReadLine();
                for (int j = 0; j < cols; j++)
                {
                    lab[i, j] = row[j];
                }
            }

            FindAllPaths(lab, 0, 0, directions, '\0');
        }

        private static void FindAllPaths(char[,] lab, int row, int col, List<char> directions, char direction)
        {
            if (IsOutside(lab, row, col) || IsWall(lab, row, col) || IsVisited(lab, row, col))
            {
                return;
            }

            if (direction!='\0')
            {
                directions.Add(direction);
            }

            if (IsSolution(lab, row, col))
            {
                Console.WriteLine( string.Join("",directions.ToArray()));
                directions.Remove(directions.Last());
                return;
            }

            lab[row, col] = 'v';

            //Up
            FindAllPaths(lab, row - 1, col, directions, 'U');
            //Down
            FindAllPaths(lab, row + 1, col, directions, 'D');
            //Left
            FindAllPaths(lab, row, col - 1, directions, 'L');
            //Right
            FindAllPaths(lab, row, col + 1, directions, 'R');

            //free space on return
            lab[row, col] = '-';
            if (directions.Count>0)
            {
                directions.Remove(directions.Last());
            }
        }

        private static bool IsSolution(char[,] lab, int row, int col)
        {
            bool result = false;
            if (lab[row, col] == 'e')
            {
                result = true;
            }

            return result;
        }

        private static bool IsVisited(char[,] lab, int row, int col)
        {
            bool result = false;
            if (lab[row, col] == 'v')
            {
                result = true;
            }

            return result;
        }

        private static bool IsWall(char[,] lab, int row, int col)
        {
            bool result = false;
            if (lab[row, col] == '*')
            {
                result = true;
            }

            return result;
        }

        private static bool IsOutside(char[,] lab, int row, int col)
        {
            bool result = false;
            if (row < 0 || row >= lab.GetLength(0) || col < 0 || col >= lab.GetLength(1))
            {
                result = true;
            }

            return result;
        }
    }
}
