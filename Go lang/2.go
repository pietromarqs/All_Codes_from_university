package main

import (
	"fmt"
)

func main() {
	var (
		n      int
		divInt = 0
	)

	fmt.Println("Digite:")
	fmt.Scan(&n)

	for divisor := 2; divisor <= n; divisor++ {
		fmt.Println(divisor)
		if n%divisor == 0 {
			divInt++
		} else {
			continue
		}
	}

	if divInt > 1 {
		fmt.Printf("O valor %d não é primo", n)
	} else {
		fmt.Printf("O valor %d é primo", n)
	}
}
