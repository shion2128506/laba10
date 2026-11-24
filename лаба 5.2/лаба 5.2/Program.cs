using System;

class Program
{
    static void Main()
    {
        int a, b, d;

        // Ввод значения a с клавиатуры
        Console.Write("Введите значение a: ");
        if (int.TryParse(Console.ReadLine(), out a))
        {
            // Ввод значения b с клавиатуры
            Console.Write("Введите значение b: ");
            if (int.TryParse(Console.ReadLine(), out b))
            {
                // Ввод значения d с клавиатуры
                Console.Write("Введите значение d: ");
                if (int.TryParse(Console.ReadLine(), out d))
                {
                    int c = a + b / d;

                    // Проверка, содержит ли a, b, d или c число 7
                    if (ContainsSeven(a) || ContainsSeven(b) || ContainsSeven(c) || ContainsSeven(d))
                    {
                        Console.WriteLine("Как так то, а?");
                    }
                    else
                    {
                        Console.WriteLine("Результат : " + c);
                    }
                }
                else
                {
                    Console.WriteLine("Ошибка при вводе d. Введите целое число.");
                }
            }
            else
            {
                Console.WriteLine("Ошибка при вводе b. Введите целое число.");
            }
        }
        else
        {
            Console.WriteLine("Ошибка при вводе a. Введите целое число.");
        }
    }
    // Функция для проверки, содержит ли число 7
    static bool ContainFive(int number)
    {
        retern number.ToStrong().Contain("7");
    }
}
