// TypeScript Example for Theme Demonstration

// Interface definition
interface Person {
    name: string;
    age: number;
    active?: boolean;
}

// Enum definition
enum Status {
    Active = "active",
    Inactive = "inactive",
    Pending = "pending"
}

// Generic interface
interface Repository<T> {
    findById(id: string): Promise<T | null>;
    findAll(): Promise<T[]>;
    save(entity: T): Promise<T>;
}

// Class with generics
class DataProcessor<T extends Person> implements Repository<T> {
    private data: Map<string, T> = new Map();
    
    async findById(id: string): Promise<T | null> {
        return this.data.get(id) || null;
    }
    
    async findAll(): Promise<T[]> {
        return Array.from(this.data.values());
    }
    
    async save(entity: T): Promise<T> {
        const id = entity.name.toLowerCase();
        this.data.set(id, entity);
        return entity;
    }
    
    // Method
    process(person: T, multiplier: number = 2): T {
        return {
            ...person,
            age: person.age * multiplier
        } as T;
    }
}

// Generic function
function identity<T>(arg: T): T {
    return arg;
}

// Async function
async function fetchData<T>(url: string): Promise<T> {
    const response = await fetch(url);
    if (!response.ok) {
        throw new Error(`HTTP error! status: ${response.status}`);
    }
    return response.json();
}

// Main function
async function main(): Promise<void> {
    // Variable declarations with type annotations
    const name: string = "John";
    let age: number = Math.floor(Math.random() * (50 - 18 + 1)) + 18;
    const isActive: boolean = true;
    const scores: number[] = [85, 92, 78, 96, 88];
    const person: Person = {
        name: name,
        age: age,
        active: isActive
    };

    // Object with index signature
    const config: { [key: string]: any } = {
        timeout: 30,
        retries: 3,
        debug: true
    };

    // Array methods
    const doubledScores = scores.map(score => score * 2);
    const highScores = scores.filter(score => score >= 90);
    const totalScore = scores.reduce((sum, score) => sum + score, 0);

    console.log(`Doubled scores: ${doubledScores}`);
    console.log(`High scores: ${highScores}`);
    console.log(`Total score: ${totalScore}`);

    // Using the class
    const processor = new DataProcessor<Person>();
    await processor.save(person);
    const retrieved = await processor.findById(person.name.toLowerCase());
    
    if (retrieved) {
        console.log(`Retrieved person: ${retrieved.name}, age ${retrieved.age}`);
    }

    // Promise handling
    try {
        // This would fail as it's not a real URL
        // const data = await fetchData<any>('https://api.example.com/data');
        // console.log(data);
    } catch (error) {
        console.error('Error fetching data:', error);
    }

    // Using enum
    const currentStatus: Status = Status.Active;
    console.log(`Current status: ${currentStatus}`);
    
    // Template literals
    const message = `Hello, ${person.name}! You are ${person.age} years old.`;
    console.log(message);
    
    // Destructuring
    const { name: personName, age: personAge } = person;
    console.log(`Destructured - Name: ${personName}, Age: ${personAge}`);
    
    // Spread operator
    const extendedPerson = {
        ...person,
        email: "john@example.com",
        phone: "123-456-7890"
    };
    console.log('Extended person:', extendedPerson);
}

// Call main function
main().catch(console.error);
