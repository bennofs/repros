extern crate brotli2;

use std::io::prelude::*;
use std::fs::File;
use brotli2::write::BrotliDecoder;

fn main() {
    let mut file = File::open("input.br").unwrap();
    let mut decoder = BrotliDecoder::new(Vec::new());
    let mut data = Vec::new();
    file.read_to_end(&mut data);
    println!("loaded: {} bytes!", data.len());
    const i: usize = 100;
    println!("write!");
    decoder.write_all(&data[..i]);
    println!("drop!");
    std::mem::drop(decoder);
    println!("end!");
}
