#[macro_export]
macro_rules! myassert {
    ($($arg:tt)+) => {{
        core::assert!($($arg)+);
    }}
}
