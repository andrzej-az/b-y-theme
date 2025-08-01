// C++ Example for Theme Demonstration

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <thread>
#include <chrono>
#include <exception>

// Namespace
namespace demo {
    // Class definition
    class Person {
    private:
        std::string name;
        int age;
        bool active;
    
    public:
        // Constructor
        Person(const std::string& n, int a) : name(n), age(a), active(true) {}
        
        // Getter methods
        const std::string& getName() const { return name; }
        int getAge() const { return age; }
        bool isActive() const { return active; }
        
        // Setter method
        void setActive(bool status) { active = status; }
        
        // Method
        void greet() const {
            std::cout << "Hello, my name is " << name << " and I am " << age << " years old\n";
        }
    };
    
    // Template function
    template<typename T>
    T maxValue(const T& a, const T& b) {
        return (a > b) ? a : b;
    }
    
    // Enum class
    enum class Status {
        Inactive = 0,
        Active = 1,
        Pending = 2
    };
    
    // Struct
    struct Point {
        double x;
        double y;
        
        // Method in struct
        double distance() const {
            return sqrt(x*x + y*y);
        }
    };
}

// Function with exception handling
double divide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

// Function template specialization
template<>
std::string demo::maxValue(const std::string& a, const std::string& b) {
    return (a.length() > b.length()) ? a : b;
}

int main() {
    // Variable declarations
    std::string name = "Alice";
    int age = 30;
    bool is_active = true;
    std::vector<int> scores = {85, 92, 78, 96, 88};
    
    // Object instantiation
    demo::Person person(name, age);
    
    // Method call
    person.greet();
    
    // Vector operations
    scores.push_back(95);
    
    std::cout << "Scores: ";
    for (const auto& score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    
    // Using template function
    int max_score = demo::maxValue(85, 92);
    std::cout << "Max score: " << max_score << std::endl;
    
    // Map usage
    std::map<std::string, int> config;
    config["timeout"] = 30;
    config["retries"] = 3;
    config["debug"] = 1;
    
    auto it = config.find("timeout");
    if (it != config.end()) {
        std::cout << "Timeout: " << it->second << std::endl;
    }
    
    // Exception handling
    try {
        double result = divide(10.0, 2.0);
        std::cout << "Division result: " << result << std::endl;
        
        // This will throw an exception
        // double error_result = divide(10.0, 0.0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Lambda function
    auto multiply = [](int x, int y) -> int { return x * y; };
    int result = multiply(5, 6);
    std::cout << "Multiplication result: " << result << std::endl;
    
    // Smart pointer
    std::unique_ptr<demo::Person> ptr = std::make_unique<demo::Person>("Bob", 25);
    ptr->greet();
    
    // Struct usage
    demo::Point point = {3.0, 4.0};
    std::cout << "Point distance: " << point.distance() << std::endl;
    
    // Threading
    std::thread t([]() {
        for (int i = 1; i <= 5; ++i) {
            std::cout << "Thread: " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
    
    for (int i = 1; i <= 3; ++i) {
        std::cout << "Main: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    
    t.join();
    
    // Range-based for loop with auto
    std::cout << "Scores again: ";
    for (const auto& score : scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
