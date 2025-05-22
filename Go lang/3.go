package main

import (
	"fmt"
)

func main() {
	var (
		n     int
		cont  = 0
		impar = 0
	)
	fmt.Println("Digite um valor para saber todos seus primeiros impares: ")
	fmt.Scan(&n)

	for impar < n {
		if cont%2 != 0 {
			impar++
			fmt.Printf("\nO valor %d é o impar ", cont)
			cont++
		} else {
			cont++
		}

	}
}
