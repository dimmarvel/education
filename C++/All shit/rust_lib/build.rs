extern crate cc;

fn main()
{    
    cc::Build::new()
        .cpp(true)
        .file("libcpp.cpp")
        .compile("mcpp_lib");
}