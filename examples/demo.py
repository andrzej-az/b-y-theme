# Python Example for Theme Demonstration

import functools
from typing import List, Dict, Optional

# Class definition
class DataProcessor:
    """A class to process data arrays."""
    
    def __init__(self, data: List[int]):
        self.data = data
        self._private_field = "private"
    
    @property
    def length(self) -> int:
        return len(self.data)
    
    def process(self, multiplier: int = 2) -> List[int]:
        """Process data with multiplier."""
        return [x * multiplier for x in self.data]
    
    @staticmethod
    def static_helper(value: str) -> bool:
        return bool(value)

# Function with decorators
@functools.lru_cache(maxsize=128)
def fibonacci(n: int) -> int:
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

# Main execution
if __name__ == "__main__":
    # Variable assignments
    numbers: List[int] = [1, 2, 3, 4, 5]
    text: str = "Hello, World!"
    is_active: bool = True
    price: float = 99.99
    nothing: None = None
    
    # Dictionary and list operations
    config: Dict[str, int] = {
        "timeout": 30,
        "retries": 3,
        "port": 8080
    }
    
    # Object instantiation and method calling
    processor = DataProcessor(numbers)
    result = processor.process(3)
    
    # Print results
    print(f"Processed data: {result}")
    print(f"10th Fibonacci number: {fibonacci(10)}")
    
    # Exception handling
    try:
        value = config["nonexistent"]
    except KeyError as e:
        print(f"Key error: {e}")
    
    # Lambda and map
    squares = list(map(lambda x: x**2, numbers))
    print(f"Squares: {squares}")
