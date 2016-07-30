extern crate lib;

pub fn bar() {
    lib::foo2();
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
    }
}
