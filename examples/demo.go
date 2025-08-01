// Go Example for Theme Demonstration

package main

import (
	"fmt"
	"errors"
	"strings"
	"time"
)

// Struct definition
type Person struct {
	Name    string
	Age     int
	Address string
}

// Interface definition
type Processor interface {
	Process(data string) (string, error)
}

// Method on struct
func (p Person) Greet() string {
	return fmt.Sprintf("Hello, my name is %s", p.Name)
}

// Function with multiple returns
func divide(a, b float64) (float64, error) {
	if b == 0 {
		return 0, errors.New("division by zero")
	}
	return a / b, nil
}

// Function implementing interface
func (p Person) Process(data string) (string, error) {
	if data == "" {
		return "", errors.New("empty data")
	}
	return strings.ToUpper(data), nil
}

// Generic function (Go 1.18+)
func Map[T any](slice []T, fn func(T) T) []T {
	result := make([]T, len(slice))
	for i, v := range slice {
		result[i] = fn(v)
	}
	return result
}

// Goroutine function
func worker(id int, jobs <-chan int, results chan<- int) {
	for j := range jobs {
		fmt.Printf("Worker %d processing job %d\n", id, j)
		time.Sleep(time.Second)
		results <- j * 2
	}
}

func main() {
	// Variable declarations
	var name string = "John"
	age := 30
	isActive := true
	scores := []int{85, 92, 78, 96, 88}
	
	// Struct instantiation
	person := Person{
		Name:    name,
		Age:     age,
		Address: "123 Main St",
	}
	
	// Method call
	greeting := person.Greet()
	fmt.Println(greeting)
	
	// Function call with error handling
	result, err := divide(10.0, 2.0)
	if err != nil {
		fmt.Printf("Error: %v\n", err)
	} else {
		fmt.Printf("Division result: %.2f\n", result)
	}
	
	// Slice operations
	fmt.Printf("Scores: %v\n", scores)
	fmt.Printf("First score: %d\n", scores[0])
	fmt.Printf("Last score: %d\n", scores[len(scores)-1])
	
	// Map creation and usage
	config := map[string]interface{}{
		"timeout": 30,
		"retries": 3,
		"debug":   true,
	}
	
	fmt.Printf("Config: %v\n", config)
	
	// Goroutines and channels
	jobs := make(chan int, 5)
	results := make(chan int, 5)
	
	// Start workers
	for w := 1; w <= 3; w++ {
		go worker(w, jobs, results)
	}
	
	// Send jobs
	for j := 1; j <= 5; j++ {
		jobs <- j
	}
	close(jobs)
	
	// Collect results
	for a := 1; a <= 5; a++ {
		result := <-results
		fmt.Printf("Result: %d\n", result)
	}
}
