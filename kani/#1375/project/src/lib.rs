extern crate macrodef;
use macrodef::myassert;

pub fn foo() {
    assert!(false, format!("{}", 42));
    myassert!(false, format!("{}", 42));
}
