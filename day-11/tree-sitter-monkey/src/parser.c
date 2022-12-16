#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 36
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 30
#define ALIAS_COUNT 0
#define TOKEN_COUNT 17
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 7

enum {
  anon_sym_COMMA = 1,
  sym_integer = 2,
  aux_sym_operand_token1 = 3,
  anon_sym_old = 4,
  anon_sym_PLUS = 5,
  anon_sym_SLASH = 6,
  anon_sym_DASH = 7,
  anon_sym_STAR = 8,
  anon_sym_Startingitems_COLON = 9,
  anon_sym_Operation_COLONnew_EQ = 10,
  anon_sym_Test_COLONdivisibleby = 11,
  anon_sym_Iftrue_COLON = 12,
  anon_sym_Iffalse_COLON = 13,
  anon_sym_throwtomonkey = 14,
  anon_sym_Monkey = 15,
  anon_sym_COLON = 16,
  sym_source_file = 17,
  sym_integer_list = 18,
  sym_operand = 19,
  sym_operator = 20,
  sym_monkey_attributes = 21,
  sym_starting_items = 22,
  sym_operation = 23,
  sym_item_test = 24,
  sym_throw_to_monkey = 25,
  sym_monkey = 26,
  aux_sym_source_file_repeat1 = 27,
  aux_sym_integer_list_repeat1 = 28,
  aux_sym_monkey_attributes_repeat1 = 29,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COMMA] = ",",
  [sym_integer] = "integer",
  [aux_sym_operand_token1] = "operand_token1",
  [anon_sym_old] = "old",
  [anon_sym_PLUS] = "+",
  [anon_sym_SLASH] = "/",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_Startingitems_COLON] = "Starting items: ",
  [anon_sym_Operation_COLONnew_EQ] = "Operation: new = ",
  [anon_sym_Test_COLONdivisibleby] = "Test: divisible by",
  [anon_sym_Iftrue_COLON] = "If true:",
  [anon_sym_Iffalse_COLON] = "If false:",
  [anon_sym_throwtomonkey] = "throw to monkey",
  [anon_sym_Monkey] = "Monkey",
  [anon_sym_COLON] = ":",
  [sym_source_file] = "source_file",
  [sym_integer_list] = "integer_list",
  [sym_operand] = "operand",
  [sym_operator] = "operator",
  [sym_monkey_attributes] = "monkey_attributes",
  [sym_starting_items] = "starting_items",
  [sym_operation] = "operation",
  [sym_item_test] = "item_test",
  [sym_throw_to_monkey] = "throw_to_monkey",
  [sym_monkey] = "monkey",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_integer_list_repeat1] = "integer_list_repeat1",
  [aux_sym_monkey_attributes_repeat1] = "monkey_attributes_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym_integer] = sym_integer,
  [aux_sym_operand_token1] = aux_sym_operand_token1,
  [anon_sym_old] = anon_sym_old,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_Startingitems_COLON] = anon_sym_Startingitems_COLON,
  [anon_sym_Operation_COLONnew_EQ] = anon_sym_Operation_COLONnew_EQ,
  [anon_sym_Test_COLONdivisibleby] = anon_sym_Test_COLONdivisibleby,
  [anon_sym_Iftrue_COLON] = anon_sym_Iftrue_COLON,
  [anon_sym_Iffalse_COLON] = anon_sym_Iffalse_COLON,
  [anon_sym_throwtomonkey] = anon_sym_throwtomonkey,
  [anon_sym_Monkey] = anon_sym_Monkey,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_source_file] = sym_source_file,
  [sym_integer_list] = sym_integer_list,
  [sym_operand] = sym_operand,
  [sym_operator] = sym_operator,
  [sym_monkey_attributes] = sym_monkey_attributes,
  [sym_starting_items] = sym_starting_items,
  [sym_operation] = sym_operation,
  [sym_item_test] = sym_item_test,
  [sym_throw_to_monkey] = sym_throw_to_monkey,
  [sym_monkey] = sym_monkey,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_integer_list_repeat1] = aux_sym_integer_list_repeat1,
  [aux_sym_monkey_attributes_repeat1] = aux_sym_monkey_attributes_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_operand_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_old] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Startingitems_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Operation_COLONnew_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Test_COLONdivisibleby] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Iftrue_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Iffalse_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_throwtomonkey] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Monkey] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_integer_list] = {
    .visible = true,
    .named = true,
  },
  [sym_operand] = {
    .visible = true,
    .named = true,
  },
  [sym_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_monkey_attributes] = {
    .visible = true,
    .named = true,
  },
  [sym_starting_items] = {
    .visible = true,
    .named = true,
  },
  [sym_operation] = {
    .visible = true,
    .named = true,
  },
  [sym_item_test] = {
    .visible = true,
    .named = true,
  },
  [sym_throw_to_monkey] = {
    .visible = true,
    .named = true,
  },
  [sym_monkey] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_integer_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_monkey_attributes_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_attrs = 1,
  field_id = 2,
  field_operation = 3,
  field_starting_items = 4,
  field_test = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_attrs] = "attrs",
  [field_id] = "id",
  [field_operation] = "operation",
  [field_starting_items] = "starting_items",
  [field_test] = "test",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 1},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 4, .length = 1},
  [5] = {.index = 5, .length = 3},
  [6] = {.index = 8, .length = 6},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_attrs, 3},
    {field_id, 1},
  [2] =
    {field_starting_items, 0},
  [3] =
    {field_operation, 0},
  [4] =
    {field_test, 0},
  [5] =
    {field_operation, 0, .inherited = true},
    {field_starting_items, 0, .inherited = true},
    {field_test, 0, .inherited = true},
  [8] =
    {field_operation, 0, .inherited = true},
    {field_operation, 1, .inherited = true},
    {field_starting_items, 0, .inherited = true},
    {field_starting_items, 1, .inherited = true},
    {field_test, 0, .inherited = true},
    {field_test, 1, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(82);
      if (lookahead == '*') ADVANCE(93);
      if (lookahead == '+') ADVANCE(90);
      if (lookahead == ',') ADVANCE(83);
      if (lookahead == '-') ADVANCE(92);
      if (lookahead == '/') ADVANCE(91);
      if (lookahead == ':') ADVANCE(101);
      if (lookahead == 'I') ADVANCE(32);
      if (lookahead == 'M') ADVANCE(54);
      if (lookahead == 'O') ADVANCE(59);
      if (lookahead == 'S') ADVANCE(68);
      if (lookahead == 'T') ADVANCE(23);
      if (lookahead == 'o') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(33);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(22);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(16);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(94);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(95);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(47);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(21);
      END_STATE();
    case 8:
      if (lookahead == ' ') ADVANCE(50);
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(40);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(73);
      END_STATE();
    case 11:
      if (lookahead == ':') ADVANCE(97);
      END_STATE();
    case 12:
      if (lookahead == ':') ADVANCE(98);
      END_STATE();
    case 13:
      if (lookahead == ':') ADVANCE(2);
      END_STATE();
    case 14:
      if (lookahead == ':') ADVANCE(8);
      END_STATE();
    case 15:
      if (lookahead == ':') ADVANCE(4);
      END_STATE();
    case 16:
      if (lookahead == '=') ADVANCE(5);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(44);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(72);
      END_STATE();
    case 20:
      if (lookahead == 'b') ADVANCE(45);
      END_STATE();
    case 21:
      if (lookahead == 'b') ADVANCE(80);
      END_STATE();
    case 22:
      if (lookahead == 'd') ADVANCE(36);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(79);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(46);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(11);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(7);
      END_STATE();
    case 32:
      if (lookahead == 'f') ADVANCE(1);
      END_STATE();
    case 33:
      if (lookahead == 'f') ADVANCE(17);
      if (lookahead == 't') ADVANCE(60);
      END_STATE();
    case 34:
      if (lookahead == 'g') ADVANCE(9);
      END_STATE();
    case 35:
      if (lookahead == 'h') ADVANCE(61);
      END_STATE();
    case 36:
      if (lookahead == 'i') ADVANCE(76);
      END_STATE();
    case 37:
      if (lookahead == 'i') ADVANCE(20);
      END_STATE();
    case 38:
      if (lookahead == 'i') ADVANCE(49);
      END_STATE();
    case 39:
      if (lookahead == 'i') ADVANCE(66);
      END_STATE();
    case 40:
      if (lookahead == 'i') ADVANCE(74);
      END_STATE();
    case 41:
      if (lookahead == 'i') ADVANCE(55);
      END_STATE();
    case 42:
      if (lookahead == 'k') ADVANCE(25);
      END_STATE();
    case 43:
      if (lookahead == 'k') ADVANCE(30);
      END_STATE();
    case 44:
      if (lookahead == 'l') ADVANCE(65);
      END_STATE();
    case 45:
      if (lookahead == 'l') ADVANCE(31);
      END_STATE();
    case 46:
      if (lookahead == 'm') ADVANCE(67);
      END_STATE();
    case 47:
      if (lookahead == 'm') ADVANCE(58);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 49:
      if (lookahead == 'n') ADVANCE(34);
      END_STATE();
    case 50:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 51:
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 52:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 53:
      if (lookahead == 'o') ADVANCE(87);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(53)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 54:
      if (lookahead == 'o') ADVANCE(48);
      END_STATE();
    case 55:
      if (lookahead == 'o') ADVANCE(52);
      END_STATE();
    case 56:
      if (lookahead == 'o') ADVANCE(6);
      END_STATE();
    case 57:
      if (lookahead == 'o') ADVANCE(78);
      END_STATE();
    case 58:
      if (lookahead == 'o') ADVANCE(51);
      END_STATE();
    case 59:
      if (lookahead == 'p') ADVANCE(24);
      END_STATE();
    case 60:
      if (lookahead == 'r') ADVANCE(75);
      END_STATE();
    case 61:
      if (lookahead == 'r') ADVANCE(57);
      END_STATE();
    case 62:
      if (lookahead == 'r') ADVANCE(70);
      END_STATE();
    case 63:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 64:
      if (lookahead == 's') ADVANCE(69);
      END_STATE();
    case 65:
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 66:
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 67:
      if (lookahead == 's') ADVANCE(15);
      END_STATE();
    case 68:
      if (lookahead == 't') ADVANCE(18);
      END_STATE();
    case 69:
      if (lookahead == 't') ADVANCE(13);
      END_STATE();
    case 70:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 71:
      if (lookahead == 't') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(71)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(85);
      END_STATE();
    case 72:
      if (lookahead == 't') ADVANCE(41);
      END_STATE();
    case 73:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 74:
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 75:
      if (lookahead == 'u') ADVANCE(28);
      END_STATE();
    case 76:
      if (lookahead == 'v') ADVANCE(39);
      END_STATE();
    case 77:
      if (lookahead == 'w') ADVANCE(3);
      END_STATE();
    case 78:
      if (lookahead == 'w') ADVANCE(10);
      END_STATE();
    case 79:
      if (lookahead == 'y') ADVANCE(100);
      END_STATE();
    case 80:
      if (lookahead == 'y') ADVANCE(96);
      END_STATE();
    case 81:
      if (lookahead == 'y') ADVANCE(99);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(84);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_integer);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(85);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_operand_token1);
      if (lookahead == 'd') ADVANCE(89);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_operand_token1);
      if (lookahead == 'l') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_operand_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_old);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(88);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_Startingitems_COLON);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_Operation_COLONnew_EQ);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_Test_COLONdivisibleby);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_Iftrue_COLON);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_Iffalse_COLON);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_throwtomonkey);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_Monkey);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 53},
  [19] = {.lex_state = 53},
  [20] = {.lex_state = 53},
  [21] = {.lex_state = 71},
  [22] = {.lex_state = 53},
  [23] = {.lex_state = 71},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 71},
  [26] = {.lex_state = 53},
  [27] = {.lex_state = 71},
  [28] = {.lex_state = 71},
  [29] = {.lex_state = 71},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 71},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [aux_sym_operand_token1] = ACTIONS(1),
    [anon_sym_old] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_Startingitems_COLON] = ACTIONS(1),
    [anon_sym_Operation_COLONnew_EQ] = ACTIONS(1),
    [anon_sym_Test_COLONdivisibleby] = ACTIONS(1),
    [anon_sym_Iftrue_COLON] = ACTIONS(1),
    [anon_sym_Iffalse_COLON] = ACTIONS(1),
    [anon_sym_Monkey] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(35),
    [sym_monkey] = STATE(16),
    [aux_sym_source_file_repeat1] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_Monkey] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 1,
    ACTIONS(7), 11,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Iftrue_COLON,
      anon_sym_Iffalse_COLON,
      anon_sym_Monkey,
  [14] = 8,
    ACTIONS(11), 1,
      anon_sym_Startingitems_COLON,
    ACTIONS(14), 1,
      anon_sym_Operation_COLONnew_EQ,
    ACTIONS(17), 1,
      anon_sym_Test_COLONdivisibleby,
    STATE(3), 1,
      aux_sym_monkey_attributes_repeat1,
    STATE(12), 1,
      sym_starting_items,
    STATE(13), 1,
      sym_operation,
    STATE(14), 1,
      sym_item_test,
    ACTIONS(9), 2,
      ts_builtin_sym_end,
      anon_sym_Monkey,
  [40] = 8,
    ACTIONS(22), 1,
      anon_sym_Startingitems_COLON,
    ACTIONS(24), 1,
      anon_sym_Operation_COLONnew_EQ,
    ACTIONS(26), 1,
      anon_sym_Test_COLONdivisibleby,
    STATE(3), 1,
      aux_sym_monkey_attributes_repeat1,
    STATE(12), 1,
      sym_starting_items,
    STATE(13), 1,
      sym_operation,
    STATE(14), 1,
      sym_item_test,
    ACTIONS(20), 2,
      ts_builtin_sym_end,
      anon_sym_Monkey,
  [66] = 8,
    ACTIONS(22), 1,
      anon_sym_Startingitems_COLON,
    ACTIONS(24), 1,
      anon_sym_Operation_COLONnew_EQ,
    ACTIONS(26), 1,
      anon_sym_Test_COLONdivisibleby,
    STATE(4), 1,
      aux_sym_monkey_attributes_repeat1,
    STATE(12), 1,
      sym_starting_items,
    STATE(13), 1,
      sym_operation,
    STATE(14), 1,
      sym_item_test,
    STATE(24), 1,
      sym_monkey_attributes,
  [91] = 1,
    ACTIONS(28), 6,
      ts_builtin_sym_end,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Iffalse_COLON,
      anon_sym_Monkey,
  [100] = 2,
    ACTIONS(32), 1,
      anon_sym_COMMA,
    ACTIONS(30), 5,
      ts_builtin_sym_end,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Monkey,
  [111] = 2,
    ACTIONS(32), 1,
      anon_sym_COMMA,
    ACTIONS(34), 5,
      ts_builtin_sym_end,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Monkey,
  [122] = 1,
    ACTIONS(36), 5,
      ts_builtin_sym_end,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Monkey,
  [130] = 1,
    ACTIONS(38), 5,
      ts_builtin_sym_end,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Monkey,
  [138] = 2,
    STATE(18), 1,
      sym_operator,
    ACTIONS(40), 4,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_DASH,
      anon_sym_STAR,
  [148] = 1,
    ACTIONS(42), 5,
      ts_builtin_sym_end,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Monkey,
  [156] = 1,
    ACTIONS(44), 5,
      ts_builtin_sym_end,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Monkey,
  [164] = 1,
    ACTIONS(46), 5,
      ts_builtin_sym_end,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Monkey,
  [172] = 1,
    ACTIONS(48), 5,
      ts_builtin_sym_end,
      anon_sym_Startingitems_COLON,
      anon_sym_Operation_COLONnew_EQ,
      anon_sym_Test_COLONdivisibleby,
      anon_sym_Monkey,
  [180] = 3,
    ACTIONS(5), 1,
      anon_sym_Monkey,
    ACTIONS(50), 1,
      ts_builtin_sym_end,
    STATE(17), 2,
      sym_monkey,
      aux_sym_source_file_repeat1,
  [191] = 3,
    ACTIONS(52), 1,
      ts_builtin_sym_end,
    ACTIONS(54), 1,
      anon_sym_Monkey,
    STATE(17), 2,
      sym_monkey,
      aux_sym_source_file_repeat1,
  [202] = 2,
    STATE(10), 1,
      sym_operand,
    ACTIONS(57), 2,
      aux_sym_operand_token1,
      anon_sym_old,
  [210] = 2,
    STATE(30), 1,
      sym_operand,
    ACTIONS(57), 2,
      aux_sym_operand_token1,
      anon_sym_old,
  [218] = 2,
    STATE(11), 1,
      sym_operand,
    ACTIONS(57), 2,
      aux_sym_operand_token1,
      anon_sym_old,
  [226] = 3,
    ACTIONS(59), 1,
      sym_integer,
    STATE(15), 1,
      sym_integer_list,
    STATE(23), 1,
      aux_sym_integer_list_repeat1,
  [236] = 2,
    STATE(6), 1,
      sym_operand,
    ACTIONS(57), 2,
      aux_sym_operand_token1,
      anon_sym_old,
  [244] = 2,
    ACTIONS(61), 1,
      sym_integer,
    STATE(25), 1,
      aux_sym_integer_list_repeat1,
  [251] = 1,
    ACTIONS(63), 2,
      ts_builtin_sym_end,
      anon_sym_Monkey,
  [256] = 2,
    ACTIONS(65), 1,
      sym_integer,
    STATE(25), 1,
      aux_sym_integer_list_repeat1,
  [263] = 1,
    ACTIONS(68), 2,
      aux_sym_operand_token1,
      anon_sym_old,
  [268] = 2,
    ACTIONS(70), 1,
      anon_sym_throwtomonkey,
    STATE(33), 1,
      sym_throw_to_monkey,
  [275] = 2,
    ACTIONS(70), 1,
      anon_sym_throwtomonkey,
    STATE(9), 1,
      sym_throw_to_monkey,
  [282] = 1,
    ACTIONS(72), 1,
      sym_integer,
  [286] = 1,
    ACTIONS(74), 1,
      anon_sym_Iftrue_COLON,
  [290] = 1,
    ACTIONS(76), 1,
      sym_integer,
  [294] = 1,
    ACTIONS(32), 1,
      anon_sym_COMMA,
  [298] = 1,
    ACTIONS(78), 1,
      anon_sym_Iffalse_COLON,
  [302] = 1,
    ACTIONS(80), 1,
      anon_sym_COLON,
  [306] = 1,
    ACTIONS(82), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 14,
  [SMALL_STATE(4)] = 40,
  [SMALL_STATE(5)] = 66,
  [SMALL_STATE(6)] = 91,
  [SMALL_STATE(7)] = 100,
  [SMALL_STATE(8)] = 111,
  [SMALL_STATE(9)] = 122,
  [SMALL_STATE(10)] = 130,
  [SMALL_STATE(11)] = 138,
  [SMALL_STATE(12)] = 148,
  [SMALL_STATE(13)] = 156,
  [SMALL_STATE(14)] = 164,
  [SMALL_STATE(15)] = 172,
  [SMALL_STATE(16)] = 180,
  [SMALL_STATE(17)] = 191,
  [SMALL_STATE(18)] = 202,
  [SMALL_STATE(19)] = 210,
  [SMALL_STATE(20)] = 218,
  [SMALL_STATE(21)] = 226,
  [SMALL_STATE(22)] = 236,
  [SMALL_STATE(23)] = 244,
  [SMALL_STATE(24)] = 251,
  [SMALL_STATE(25)] = 256,
  [SMALL_STATE(26)] = 263,
  [SMALL_STATE(27)] = 268,
  [SMALL_STATE(28)] = 275,
  [SMALL_STATE(29)] = 282,
  [SMALL_STATE(30)] = 286,
  [SMALL_STATE(31)] = 290,
  [SMALL_STATE(32)] = 294,
  [SMALL_STATE(33)] = 298,
  [SMALL_STATE(34)] = 302,
  [SMALL_STATE(35)] = 306,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand, 1),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_monkey_attributes_repeat1, 2, .production_id = 6),
  [11] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_monkey_attributes_repeat1, 2, .production_id = 6), SHIFT_REPEAT(21),
  [14] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_monkey_attributes_repeat1, 2, .production_id = 6), SHIFT_REPEAT(20),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_monkey_attributes_repeat1, 2, .production_id = 6), SHIFT_REPEAT(19),
  [20] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_monkey_attributes, 1, .production_id = 5),
  [22] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_throw_to_monkey, 2),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_list, 2),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_list, 1),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_item_test, 6),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operation, 4),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_monkey_attributes_repeat1, 1, .production_id = 2),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_monkey_attributes_repeat1, 1, .production_id = 3),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_monkey_attributes_repeat1, 1, .production_id = 4),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_starting_items, 2),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(29),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_monkey, 4, .production_id = 1),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_integer_list_repeat1, 2), SHIFT_REPEAT(32),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator, 1),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_integer_list_repeat1, 2),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [82] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_monkey(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
