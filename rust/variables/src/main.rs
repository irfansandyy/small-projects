fn main() {
    mutability();
    shadowing();
    arithmetic();
    datatypes();

    println!("\nFunctions: ");
    print_labeled_measurement(5, 'h');
    statement_expression();
    println!("The value of x is: {}", five());
}

fn mutability() {
    println!("\nMutability");
    let mut x = 5;
    println!("The value of x is: {x}");
    x = 6;
    println!("The value of x is: {x}");
}

fn shadowing() {
    println!("\nShadowing");
    let x = 5;

    let x = x + 1;

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {x}");
    }

    println!("The value of x is: {x}");
}

fn arithmetic() {
    println!("\nArithmetic Operations");
    let sum = 5 + 10;
    let difference = 95.5 - 4.3;
    let product = 4 * 30;
    let quotient = 56.7 / 32.2;
    let truncated = -5 / 3; // Results in -1
    let remainder = 43 % 5;
    println!("sum: {}\ndifference: {}\nproduct: {}\nquotient: {}\ntruncated: {}\nremainder: {}", sum, difference, product, quotient, truncated, remainder);
}

fn datatypes() {
    println!("\nDatatypes");

    let i32x = 10;
    println!("Integer: {}", i32x);

    let f64x= 2.0;
    let f32y: f32 = 3.0;
    println!("Floating point: {}, {}", f64x, f32y);

    let tbool = true;
    let fbool: bool = false;
    println!("Boolean: {}, {}", tbool, fbool);

    let cchar = 'z';
    let zchar: char = 'ℤ';
    let heart_eyed_cat = '😻';
    println!("Char: {}, {}, {}", cchar, zchar, heart_eyed_cat);

    let mut tup: (i64, f64, f64) = (10, 0.5, -10.9);
    tup.0 = 15;
    println!("Tuples: ({}, {}, {})", tup.0, tup.1, tup.2);

    let months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    let arraya: [i32; 5] = [1, 2, 3, 4, 5];
    println!("Array: {}, {}", months[2], arraya[3]);

}

fn print_labeled_measurement(value: i32, unit_label: char) {
    println!("The measurement is: {value}{unit_label}");
}

fn statement_expression() {
    let y = {
        let x = 3;
        x + 1
    };

    println!("The value of y is: {y}");
}

fn five() -> i32 {
    5
}