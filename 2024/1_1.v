import os
import math

fn main() {
	mut content := []string{}
	content << os.read_lines('./inputs/1')!
	mut list1 := []int{}
	mut list2 := []int{}
	for line in content {
		extract := line.rsplit('   ')
		list1 << extract[1].int()
		list2 << extract[0].int()
	}
	list1.sort()
	list2.sort()
	mut dist := 0
	for i in 0 .. list1.len {
		dist += math.abs(list2[i] - list1[i])
	}
	println(dist)
}
