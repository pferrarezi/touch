use std::env;
use std::fs::OpenOptions;
use std::path::Path;

fn main() {
    let args: Vec<String> = env::args().collect();
    for arg in args {
        create_empty_file(arg);        
    }
}

fn create_empty_file(arg: String) {
    let path = Path::new(arg.as_str());

    let _file = OpenOptions::new().write(true).create_new(true).open(path);
}
