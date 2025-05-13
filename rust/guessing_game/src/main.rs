use::rand::Rng;
use::std::cmp::Ordering;
use::std::io;

fn main() {
    println!("Guess the Number!");

    let secret: u32 = rand::rng().random_range(1..=100);

    loop {
        println!("Input Your Guess!");

        let mut guess: String = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You Guessed: {}", guess);

        match guess.cmp(&secret) {
            Ordering::Less => println!("Too Small!"),
            Ordering::Greater => println!("Too Big!"),
            Ordering::Equal => {
                println!("You Win!");
                break;
            }
        };
    }
}