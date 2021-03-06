use std::fs::File;
use std::io::prelude::*;

fn main() {
    let mut f = File::open("day_2_captcha.dat").expect("file not found");

    let mut contents = String::new();
    f.read_to_string(&mut contents)
        .expect("something went wrong reading the file");

    println!("With text:\n{}", contents);
}

