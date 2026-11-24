using System;

class Program
{
    static void Main()
    {
        int a, b, c;
        Console.Write("Введите значение a: ");
        if (int.TryParse(Console.ReadLine(), out a))
        {
            Console.Write("Введите значение b: ");
            if (int.TryParse(Console.ReadLine(), out b))
            {
                int c = a + b;
                if (ContainsFive(a) || ContainsFive(b) || ContainsFive(c))
                {
                    Console.WriteLine("Бебра");
                }
                else
                {
                    Console.WriteLine("Результат сложения a и b: " + c);
                }
            }
            else
            {
                Console.WriteLine("Ошибка при вводе b. Введите целое число");
            }
        }
        else
        {
            Console.WriteLine("Ошибка при вводе a. ВВедите целое число");
        }
        static bool ContainsFive(int number)
        {
            return number.ToString().Contains("5");
        }
    }
}
