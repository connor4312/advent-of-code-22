module.exports = grammar({
  name: 'monkey',

  rules: {
    source_file: ($) => repeat($.monkey),

    integer_list: ($) => seq(repeat(seq($.integer, ',')), $.integer),
    integer: ($) => /\d+/,
    operand: ($) => choice(/[a-z0-9]+/, 'old'),
    operator: ($) => choice('+', '/', '-', '*'),

    monkey_attributes: ($) =>
      repeat1(
        choice(
          field('starting_items', $.starting_items),
          field('operation', $.operation),
          field('test', $.item_test),
        ),
      ),
    monkey_attribute: ($) =>
      choice(
        field('starting_items', $.starting_items),
        field('operation', $.operation),
        field('test', $.item_test),
      ),

    starting_items: ($) => seq('Starting items: ', $.integer_list),
    operation: ($) => seq('Operation: new = ', $.operand, $.operator, $.operand),
    item_test: ($) =>
      seq(
        'Test: divisible by',
        $.operand,
        'If true:',
        $.throw_to_monkey,
        'If false:',
        $.throw_to_monkey,
      ),
    throw_to_monkey: ($) => seq('throw to monkey', $.operand),

    monkey: ($) => seq('Monkey', field('id', $.integer), ':', field('attrs', $.monkey_attributes)),
  },
});
