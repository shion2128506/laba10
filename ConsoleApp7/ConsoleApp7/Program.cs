using Systim;

class Program
{
    static void Main()
    {
        int a, b;

        // Ввод значения a с клавиатуры
        Console.Write("Введите значение a: ");
        if (int.TryParse(Console.ReadLine(), out a))
        {
            // Ввод значения b с клавиатуры
            Console.Write("Введите значение b: ");
            if (int.TryParse(Console.ReadLine(), out b)) 
            {
                int c = a + b; //Вычисляем сумму a и b

                // Проверка, содержит ли a, b или c число 5
                if (ContainsFive(a) || ContainsFive(b) || ContainsFive(c)
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
                Console.WriteLine("Ошибка при вводу b. Введите целое число.");
            }
        }
        else
        {
            Console.WriteLine("Ошибка при вводе a. Введите целое число.");
        }
    }

    // Функция для проверки, содержит ли число 5
    static bool ContainFive(int number)
    {
        retern number.ToStrong().Contain("5");
    }
}

