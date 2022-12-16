use std::fs;
use tree_sitter::{Language, Node, Parser, Tree};

extern "C" {
    fn tree_sitter_monkey() -> Language;
}

const NUM_ROUNDS: usize = 10000; // 20 in part 1
const WORRY_FALLOFF: i64 = 1; // 3 in part 1

fn main() {
    let language = unsafe { tree_sitter_monkey() };
    let mut parser = Parser::new();
    parser.set_language(language).unwrap();

    let contents = fs::read_to_string("input.txt").expect("Should have been able to read the file");
    let tree = parser.parse(&contents, None).unwrap();

    let mut monkeys = tree_to_monkeys(&contents, tree);

    // find the lcm(ish) to avoid numbers exploding in size
    let lcm = monkeys
        .iter()
        .map(|m| m.test.div_by)
        .reduce(|a, b| a * b)
        .unwrap();

    print_monkeys(&monkeys);
    for i in 0..NUM_ROUNDS {
        println!("== round {}", i + 1);
        do_round(&mut monkeys, lcm);
    }
    print_monkeys(&monkeys);
}

fn print_monkeys(monkeys: &[Monkey]) {
    let mut activity_level = Vec::with_capacity(monkeys.len());
    for monkey in monkeys {
        println!(
            "{} -> {:?} (busy={})",
            monkey.id, monkey.items, monkey.times_inspected
        );
        activity_level.push(monkey.times_inspected);
    }
    activity_level.sort_unstable();
    activity_level.reverse();

    let level = activity_level[0] * activity_level[1];
    println!("total business = {}", level);
}

fn do_round(monkeys: &mut Vec<Monkey>, lcm: i64) {
    let mut items = vec![];
    for i in 0..monkeys.len() {
        items = std::mem::replace(&mut monkeys[i].items, items);

        for item in &items {
            let next_value = (monkeys[i].operation.execute(*item) / WORRY_FALLOFF) % lcm;
            let next_monkey = monkeys[i].test.evaluate(next_value);
            monkeys[i].times_inspected += 1;
            monkeys[next_monkey as usize].items.push(next_value);
        }

        items.truncate(0);
    }
}

fn read_str_at<'a, 'b>(src: &'a str, node: &'b Node) -> &'a str {
    &src[node.start_byte()..node.end_byte()]
}

fn read_i64_at(src: &str, node: &Node) -> i64 {
    match read_str_at(src, node).parse::<i64>() {
        Ok(i) => i,
        Err(_) => panic!(
            "could not parse {} as int (from {})",
            read_str_at(src, node),
            node.to_sexp()
        ),
    }
}

enum Operand {
    Old,
    Integer(i64),
}

impl Operand {
    fn from_tree(src: &str, node: &Node) -> Self {
        assert_eq!(node.kind(), "operand");
        let src = read_str_at(src, node);

        if src == "old" {
            Operand::Old
        } else {
            Operand::Integer(src.parse::<i64>().unwrap())
        }
    }
}

struct Monkey {
    id: i64,
    items: Vec<i64>,
    operation: Operation,
    test: Test,
    times_inspected: u64,
}

impl Monkey {
    fn from_tree(src: &str, monkey: &Node) -> Self {
        assert_eq!(monkey.kind(), "monkey");

        let id = monkey.child_by_field_name("id").unwrap();
        assert_eq!(id.kind(), "integer");

        let attrs = monkey.child_by_field_name("attrs").unwrap();
        assert_eq!(attrs.kind(), "monkey_attributes");

        let starting_list = attrs
            .child_by_field_name("starting_items")
            .unwrap()
            .child(1)
            .unwrap();

        Monkey {
            id: read_i64_at(src, &id),
            items: starting_list
                .children(&mut starting_list.walk())
                .filter(|c| c.kind() == "integer")
                .map(|c| read_i64_at(src, &c))
                .collect(),
            operation: Operation::from_tree(src, &attrs.child_by_field_name("operation").unwrap()),
            test: Test::from_tree(src, &attrs.child_by_field_name("test").unwrap()),
            times_inspected: 0,
        }
    }
}

struct Test {
    div_by: i64,
    on_true_throw: i64,
    on_false_throw: i64,
}

impl Test {
    fn from_tree(src: &str, node: &Node) -> Self {
        assert_eq!(node.kind(), "item_test");

        let operand = node.child(1).unwrap();
        let on_true = node.child(3).unwrap().child(1).unwrap();
        let on_false = node.child(5).unwrap().child(1).unwrap();

        Self {
            div_by: read_i64_at(src, &operand),
            on_true_throw: read_i64_at(src, &on_true),
            on_false_throw: read_i64_at(src, &on_false),
        }
    }

    fn evaluate(&self, value: i64) -> i64 {
        if value % self.div_by == 0 {
            self.on_true_throw
        } else {
            self.on_false_throw
        }
    }
}

struct Operation {
    left: Operand,
    op: String,
    right: Operand,
}

impl Operation {
    fn from_tree(src: &str, node: &Node) -> Self {
        assert_eq!(node.kind(), "operation");

        let left = node.child(1).unwrap();
        let operator = node.child(2).unwrap();
        let right = node.child(3).unwrap();

        Self {
            left: Operand::from_tree(src, &left),
            op: read_str_at(src, &operator).to_string(),
            right: Operand::from_tree(src, &right),
        }
    }

    fn execute(&self, old_value: i64) -> i64 {
        let left = match self.left {
            Operand::Integer(i) => i,
            Operand::Old => old_value,
        };
        let right = match self.right {
            Operand::Integer(i) => i,
            Operand::Old => old_value,
        };

        match self.op.as_str() {
            "*" => left * right,
            "/" => left / right,
            "+" => left + right,
            "-" => left - right,
            _ => panic!("unknown operator {}", self.op),
        }
    }
}

fn tree_to_monkeys(src: &str, tree: Tree) -> Vec<Monkey> {
    let root = tree.root_node();
    assert_eq!(root.kind(), "source_file");

    root.children(&mut root.walk())
        .map(|n| Monkey::from_tree(src, &n))
        .collect()
}
