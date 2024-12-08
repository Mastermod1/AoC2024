use std::io::{self, Read};
use std::collections::{HashMap, HashSet};

fn in_range(x: i32, y: i32) -> bool {
    let max: i32 = 50;
    return x >= 0 && x < max && y >= 0 && y < max;
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).expect("Failed");
    let mut map: HashMap<char, Vec<(i32, i32)>> = HashMap::new();
    let mut x: i32 = 0;
    let mut y: i32 = 0;
    for ch in input.chars() {
        if ch == '\n' {
            y = 0;
            x += 1;
            continue;
        }
        if ch == '.' { 
            y += 1;
            continue;
        }
        map.entry(ch).or_insert(vec![]).push((x, y));
        y += 1;
    }

    let mut set: HashSet<(i32, i32)> = HashSet::new();
    for (_key, values) in map {
        for i in 0..values.len() {
            for j in i + 1..values.len() {
                let (x1, y1) = values[i];
                let (x2, y2) = values[j];
                let (vec1, vec2) = (x1 - x2, y1 - y2);

                let c1 = (x1 + vec1, y1 + vec2);
                if in_range(c1.0, c1.1) {
                    set.insert(c1);
                }
                
                let c2 = (x2 - vec1, y2 - vec2);
                if  in_range(c2.0, c2.1) {
                    set.insert(c2);
                }
            }
        }
        
    }

    println!("{}", set.len());

}
