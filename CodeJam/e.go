package main

import (
	"fmt"
	"math/rand"
)

const Seed = 12345
var N, k int

func rand2(a, b int) (int, int) {
	if rand.Intn(2) == 0 {
		return a, b
	}
	return b, a
}

func Latin(n int) {
iter := 0
loop:
	xy := make([][]int, n)
	xz := make([][]int, n)
	yz := make([][]int, n)
	for i := 0; i < n; i++ {
		xy[i] = make([]int, n)
		yz[i] = make([]int, n)
		xz[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			k := (i + j) % n
			xy[i][j] = k
			xz[i][k] = j
			yz[j][k] = i
		}
	}

	var mxy, mxz, myz int
	var m [3]int
	proper := true
	minIter := n * n * n
	for iter := 0; iter < minIter || !proper; iter++ {
		var i, j, k, i2, j2, k2 int
		var i2_, j2_, k2_ int

		if proper {
			// Pick a random 0 in the array
			i, j, k = rand.Intn(n), rand.Intn(n), rand.Intn(n)
			for xy[i][j] == k{
				i, j, k = rand.Intn(n), rand.Intn(n), rand.Intn(n)
			}
			// find i2 such that [i2, j, k] is 1. same for j2, k2
			i2 = yz[j][k]
			j2 = xz[i][k]
			k2 = xy[i][j]
			i2_, j2_, k2_ = i, j, k
		} else {
			i, j, k = m[0], m[1], m[2]
			// find one such that [i2, j, k] is 1, same for j2, k2.
			// each is either the value stored in the corresponding
			// slice, or one of our three temporary "extra" 1s.
			// That's because (i, j, k) is -1.
			i2, i2_ = rand2(yz[j][k], myz)
			j2, j2_ = rand2(xz[i][k], mxz)
			k2, k2_ = rand2(xy[i][j], mxy)
			
		}
		
		proper = xy[i2][j2] == k2
		if !proper {
			m = [3]int{i2, j2, k2}
			mxy = xy[i2][j2]
			myz = yz[j2][k2]
			mxz = xz[i2][k2]
		}

		xy[i][j] = k2_
		xy[i][j2] = k2
		xy[i2][j] = k2
		xy[i2][j2] = k

		yz[j][k] = i2_
		yz[j][k2] = i2
		yz[j2][k] = i2
		yz[j2][k2] = i

		xz[i][k] = j2_
		xz[i][k2] = j2
		xz[i2][k] = j2
		xz[i2][k2] = j
	}
	sum := 0
	for i := 0; i < n; i++ {
		sum += xy[i][i] + 1
	}
	if sum != k {
		iter++
		if iter > 2000 {
			fmt.Println("IMPOSSIBLE")
			return
		}
		goto loop
	}
	fmt.Println("POSSIBLE")
	for _, row := range xy {
		for i, c := range row {
			if i > 0 {
				fmt.Print(" ")
			}
			fmt.Printf("%d", c+1)
		}
		fmt.Printf("\n")
	}
}

func main() {
	rand.Seed(Seed)
	var t int
	fmt.Scan(&t)
	for tc := 1; tc <= t; tc++ {
		fmt.Printf("Case #%d: ", tc)
		fmt.Scan(&N, &k)		
		Latin(N)
	}
}
