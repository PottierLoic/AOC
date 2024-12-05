import os

fn check_direction(content []string, i int, j int, dx int, dy int, word string) bool {
  mut txt := ""
  for k in 0..word.len {
    ni := i + k * dx
    nj := j + k * dy
    if ni < 0 || ni >= content.len || nj < 0 || nj >= content[0].len {
      return false
    }
    txt += content[ni][nj].ascii_str()
  }
  return txt == word
}

fn main() {
	content := os.read_lines('./inputs/4')!
  mut count := 0
  for i in 0..content.len {
    for j in 0..content[0].len {
      if content[i][j] == `X` {
        for dir in [[1, 0], [0, 1], [1, 1], [1, -1], [-1, 0], [0, -1], [-1, -1], [-1, 1]] {
					if check_direction(content, i, j, dir[0], dir[1], "XMAS") {
						count++
					}
				}
			}
    }
  }
  println(count)
}
