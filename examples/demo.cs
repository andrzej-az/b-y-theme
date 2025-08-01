// C# Example for Theme Demonstration

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace ThemeDemo
{
    // Interface definition
    public interface IDataProcessor
    {
        int Process(int value);
        string Name { get; }
    }

    // Enum definition
    public enum Status
    {
        Inactive = 0,
        Active = 1,
        Pending = 2
    }

    // Class with generics
    public class DataProcessor<T> : IDataProcessor where T : class
    {
        // Properties
        public string Name { get; private set; }
        public Status CurrentStatus { get; set; }
        private readonly List<T> _items;

        // Constructor
        public DataProcessor(string name)
        {
            Name = name;
            _items = new List<T>();
            CurrentStatus = Status.Inactive;
        }

        // Method with parameters and return type
        public int Process(int value)
        {
            if (value <= 0)
                throw new ArgumentException("Value must be positive", nameof(value));
            
            return value * 2;
        }

        // Async method
        public async Task<List<T>> GetItemsAsync()
        {
            await Task.Delay(100); // Simulate I/O
            return new List<T>(_items);
        }

        // Generic method
        public void AddItem<U>(U item) where U : T
        {
            _items.Add(item);
        }
    }

    // Extension method
    public static class Extensions
    {
        public static IEnumerable<T> Shuffle<T>(this IEnumerable<T> source)
        {
            return source.OrderBy(x => Guid.NewGuid());
        }
    }

    // Main program class
    class Program
    {
        static async Task Main(string[] args)
        {
            // Variable declarations
            var processor = new DataProcessor<object>("DemoProcessor");
            int number = 42;
            string message = "Hello, C#!";
            bool isActive = true;
            var items = new List<string> { "item1", "item2", "item3" };

            // Using the processor
            try
            {
                var result = processor.Process(number);
                Console.WriteLine($"{message} Result: {result}");
                
                // LINQ query
                var filteredItems = items
                    .Where(x => x.Length > 4)
                    .Select(x => x.ToUpper())
                    .ToList();
                
                // Async operation
                var retrievedItems = await processor.GetItemsAsync();
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine($"Error: {ex.Message}");
            }
            finally
            {
                processor.CurrentStatus = Status.Inactive;
            }
        }
    }
}
