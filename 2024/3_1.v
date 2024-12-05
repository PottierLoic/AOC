import os

fn main() {
	content := os.read_file('./inputs/3')!
	mut total := 0
	mut i := 0
	for i < content.len {
		if i + 4 <= content.len && content[i..i + 4] == 'mul(' {
			mut j := i + 4
			mut num1 := ''
			mut num2 := ''
			for j < content.len && content[j].is_digit() {
				num1 += content[j].ascii_str()
				j += 1
			}
			if j >= content.len || content[j] != `,` {
				i += 1
				continue
			}
			j += 1
			for j < content.len && content[j].is_digit() {
				num2 += content[j].ascii_str()
				j += 1
			}
			if j >= content.len || content[j] != `)` {
				i += 1
				continue
			}
			if num1.len < 1 || num1.len > 3 || num2.len < 1 || num2.len > 3 {
				i += 1
				continue
			}
			num1_int := num1.int()
			num2_int := num2.int()
			total += num1_int * num2_int
			i = j + 1
		} else {
			i += 1
		}
	}
	println(total)
}
