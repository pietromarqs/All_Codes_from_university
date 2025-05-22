package main

import (
	"fmt"
)

func main() {
	var x, expoente int

	fmt.Println("Digite o valor inteiro para ser multiplicado por um expoente e depois o expoente:")
	fmt.Scan(&x, &expoente)

	for x == expoente {
		x += x
	}

	fmt.Printf("O valor do resultado é %d", x)

}
