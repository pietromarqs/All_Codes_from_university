package main

import "strings"

func main() {
	var (
		palavra string = "Ana"
		frase   string = "Ana e Mariana gostam de Banana"
		cont    int    = 0
	)
	i := 0
	for i < len(frase)-2 {
		lowerfrase := strings.ToLower(frase)
		lowepalavra := strings.ToLower(palavra)
		if lowepalavra == lowerfrase[i:i+3] {
			cont++
		}
		i++
	}
	println(cont)

}
