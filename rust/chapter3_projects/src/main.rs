use std::io::{self, Write};

fn main() {
    converter();
    fibonacci();
}

fn converter() {
    loop {
        let mut choice = String::new();
        println!("=================================");
        println!("Welcome to temperature converter");
        println!("1. Convert celcius to fahrenheit");
        println!("2. Convert fahrenheit to celcius");
        println!("3. Exit program");
        print!("Choice (1-3): ");
        io::stdout().flush().unwrap();
        io::stdin()
            .read_line(&mut choice)
            .expect("Failed to read line");
        println!("=================================");
        
        let choice: i32 = match choice.trim().parse() {
            Ok(n) => n,
            Err(_) => {
                println!("Please input a number, try again!");
                continue;
            }
        };

        if choice == 1 {
            print!("Input temperature in celcius: ");
            io::stdout().flush().unwrap();
            let mut temperature = String::new();
            io::stdin()
                .read_line(&mut temperature)
                .expect("Failed to read line");
            let mut temperature: f64 = match temperature.trim().parse() {
                Ok(n) => n,
                Err(_) => {
                    println!("Please input a number, try again!");
                    continue;
                }
            };
            temperature = temperature * 9.0 / 5.0 + 32.0;
            println!("The temperature in fahrenheit is: {}", temperature);
        } else if choice == 2 {
            print!("Input temperature in fahrenheit: ");
            io::stdout().flush().unwrap();
            let mut temperature = String::new();
            io::stdin()
                .read_line(&mut temperature)
                .expect("Failed to read line");
            let mut temperature: f64 = match temperature.trim().parse() {
                Ok(n) => n,
                Err(_) => {
                    println!("Please input a number, try again!");
                    continue;
                }
            };
            temperature = (temperature - 32.0) * 5.0 / 9.0;
            println!("The temperature in celcius is: {}", temperature);
        } else if choice == 3 {
            println!("Exiting program..");
            break;
        } else {
            println!("Choice does not exists, try again");
            continue;
        }
    }
}

fn fibonacci() {
    loop {
        println!("=================================");
        println!("Welcome to fibonacci calculator");
        print!("Input the nth fibonacci: ");
        io::stdout().flush().unwrap();
        let mut nth = String::new();
        io::stdin()
            .read_line(&mut nth)
            .expect("Failed to read line");
        let nth: i32 = match nth.trim().parse() {
            Ok(n) => n,
            Err(_) => {
                println!("Please input a number, try again!");
                continue;
            }
        };
        let mut fib: i128 = 0;
        if nth == 0 {fib = 0;};
        if nth == 1 {fib = 1;};
        let mut prev = 1;
        let mut prev2 = 0;
        for _ in 2..=nth {
            fib = prev + prev2;
            prev2 = prev;
            prev = fib;
        }
        println!("The {} th fibonacci number is: {}", nth, fib);
        println!("=================================");
        break;
    }
}
