import os

fn main() {
	mut content := []string{}
	mut list1 := []int{}
	mut list2 := []int{}
	content << os.read_lines('./inputs/1')!
	for line in content {
		extract := line.rsplit('   ')
		list1 << extract[1].int()
		list2 << extract[0].int()
	}
	list1.sort()
	list2.sort()

	mut similarity := 0
	for num1 in list1 {
		mut count := 0
		for num2 in list2 {
			if num1 == num2 {
				count += 1
			}
		}
		similarity += num1 * count
	}
	println(similarity)
}
