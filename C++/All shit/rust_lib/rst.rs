extern "C"
{
    fn add_cpp_func(a: u32, b: u32) -> u64;
}

fn main() {
    
    let res: u64;

    unsafe { res = add_cpp_func(10, 20); }

    println!("Result: {}", res);
}