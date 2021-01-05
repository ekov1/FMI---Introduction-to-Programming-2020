using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _03.The_Story_Telling
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> words = new List<string>();

            while (true)
            {
                string line = Console.ReadLine();

                if (line == "End")
                {
                    break;
                }

                string[] lineParts = line.Split(new string[] { "->", " " }, StringSplitOptions.RemoveEmptyEntries).ToArray();

                int index = words.IndexOf(lineParts[0]);
                if (index == -1)
                {
                    for (int i = 0; i < lineParts.Length; i++)
                    {
                        words.Add(lineParts[i]);
                    }
                }
                else
                {
                    for (int i = 1; i < lineParts.Length; i++)
                    {
                        int curWordIndex = words.IndexOf(lineParts[i]);
                        if (curWordIndex > index)
                        {
                            continue;
                        }
                        if (index > -1)
                        {
                            words.Remove(lineParts[i]);
                        }
                        words.Insert(index + 1, lineParts[i]);
                    }
                }
            }

            Console.WriteLine(string.Join(" ", words));
        }
    }
}
