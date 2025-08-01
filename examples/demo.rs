// Rust Example for Theme Demonstration

use std::collections::HashMap;
use std::fmt;
use std::thread;
use std::time::Duration;

// Struct definition
#[derive(Debug, Clone)]
struct Person {
    name: String,
    age: u32,
    active: bool,
}

// Implementation block
impl Person {
    fn new(name: &str, age: u32) -> Person {
        Person {
            name: name.to_string(),
            age,
            active: true,
        }
    }

    fn greet(&self) -> String {
        format!("Hello, my name is {} and I am {} years old", self.name, self.age)
    }

    fn deactivate(&mut self) {
        self.active = false;
    }
}

// Trait definition
trait Display {
    fn display(&self) -> String;
}

// Trait implementation
impl Display for Person {
    fn display(&self) -> String {
        format!("{} (age: {}, active: {})", self.name, self.age, self.active)
    }
}

// Enum definition
#[derive(Debug)]
enum Result<T, E> {
    Ok(T),
    Err(E),
}

// Generic function
fn largest<T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut largest = list[0];

    for &item in list {
        if item > largest {
            largest = item;
        }
    }

    largest
}

// Function with error handling
fn divide(a: f64, b: f64) -> Result<f64, String> {
    if b == 0.0 {
        Result::Err("Division by zero".to_string())
    } else {
        Result::Ok(a / b)
    }
}

fn main() {
    // Variable bindings
    let name = "Alice";
    let age: u32 = 30;
    let is_active: bool = true;
    let mut scores = vec![85, 92, 78, 96, 88];
    
    // Struct instantiation
    let mut person = Person::new(name, age);
    
    // Method call
    let greeting = person.greet();
    println!("{}", greeting);
    
    // Vector operations
    scores.push(95);
    println!("Scores: {:?}", scores);
    
    let largest_score = largest(&scores);
    println!("Largest score: {}", largest_score);
    
    // HashMap
    let mut config = HashMap::new();
    config.insert("timeout", 30);
    config.insert("retries", 3);
    config.insert("debug", 1);
    
    match config.get("timeout") {
        Some(timeout) => println!("Timeout: {}", timeout),
        None => println!("Timeout not configured"),
    }
    
    // Pattern matching
    match divide(10.0, 2.0) {
        Result::Ok(value) => println!("Division result: {:.2}", value),
        Result::Err(e) => println!("Error: {}", e),
    }
    
    // Closure
    let multiply = |x: i32, y: i32| x * y;
    let result = multiply(5, 6);
    println!("Multiplication result: {}", result);
    
    // Iterator
    let squared: Vec<i32> = scores.iter().map(|x| x * x).collect();
    println!("Squared scores: {:?}", squared);
    
    // Threading
    let handle = thread::spawn(|| {
        for i in 1..10 {
            println!("Thread: {}", i);
            thread::sleep(Duration::from_millis(100));
        }
    });
    
    for i in 1..5 {
        println!("Main: {}", i);
        thread::sleep(Duration::from_millis(150));
    }
    
    handle.join().unwrap();
    
    // Trait usage
    println!("Person display: {}", person.display());
    
    // Mutable reference
    person.deactivate();
    println!("After deactivation: {:?}", person);
}
