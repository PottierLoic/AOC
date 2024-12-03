import os
import math

fn is_safe_report(levels []int) bool {
	if levels.len <= 1 {
		return true
	}
	is_increasing := levels[1] > levels[0]
	for i in 0 .. levels.len - 1 {
		dist := levels[i + 1] - levels[i]
		if (levels[i + 1] > levels[i]) != is_increasing {
			return false
		}
		if math.abs(dist) < 1 || math.abs(dist) > 3 {
			return false
		}
	}
	return true
}

fn main() {
	content := os.read_lines('./inputs/2')!
	mut safe_count := 0
	for line in content {
		levels := line.split(' ').map(it.int())
		if is_safe_report(levels) {
			safe_count += 1
			continue
		}
		for i in 0 .. levels.len {
			mut new_levels := levels.clone()
			new_levels.delete(i)
			if is_safe_report(new_levels) {
				safe_count += 1
				break
			}
		}
	}
	println(safe_count)
}
