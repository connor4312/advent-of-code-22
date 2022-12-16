use std::path::PathBuf;

fn main() {
    let dir: PathBuf = ["tree-sitter-monkey", "src"].iter().collect();

    println!("cargo:rerun-if-changed=tree-sitter-monkey/src/parser.c");

    cc::Build::new()
        .include(&dir)
        .file(dir.join("parser.c"))
        .compile("tree-sitter-monkey");
}
