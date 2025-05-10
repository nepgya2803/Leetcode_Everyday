namespace Helper
{
    class Support()
    {
        public static void PrintOutResult(Object result)
        {
            switch (result)
            {
                case bool b:
                    Console.WriteLine(((bool)result ? "true" : "false"));
                    break;
                case Array array:
                    if (array.Rank == 1)
                    {
                        Console.Write("[ ");
                        foreach (var value in array)
                        {
                            Console.Write($"{value} ,");
                        }
                        Console.Write(" ]");
                    }
                    else
                    {
                        PrintMultiDimensionalArray(array);
                    }
                    break;
                default:
                    Console.WriteLine(result);
                    break;
            }
        }

        private static void PrintMultiDimensionalArray(Array array)
        {
            int[] indices = new int[array.Rank];
            PrintRecursive(array, indices, 0);
        }

        private static void PrintRecursive(Array array, int[] indices, int dimension)
        {
            int length = array.GetLength(dimension);
            for (int i = 0; i < length; i++)
            {
                indices[dimension] = i;

                if (dimension < array.Rank - 1)
                {
                    PrintRecursive(array, indices, dimension + 1);
                }
                else
                {
                    object? value = array.GetValue(indices);
                    Console.WriteLine(value);
                }
            }
        }
    }
}