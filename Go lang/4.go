package main

import (
	"fmt"
)

func main() {
	var f, c int
	fmt.Println("Fahrenheit para Celsius:")
	fmt.Scan(&f)
	c = ((f - 32) * 5) / 9
	fmt.Printf("A temperatura em Celsius é de %dº", c)

}
