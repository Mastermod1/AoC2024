package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
    "math"
)

func combinations(length int, vector *[]string, txt string) {

    if (length == len(txt)) {
        *vector = append(*vector, txt)
        return;
    }
    combinations(length, vector, txt + "+");
    combinations(length, vector, txt + "*");
    combinations(length, vector, txt + "|");
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    res := 0
    for {
        line, err := reader.ReadString('\n')
        if err != nil {
            break;
        }
        expected := 0
        var vector []int
        val := ""
        for _, char := range line {
            if char == ':' || char ==  ' ' || char == '\n' {
                if char == ':' {
                    expected, _ = strconv.Atoi(val)
                } else if len(val) > 0 {
                    val, _ := strconv.Atoi(val)
                    vector = append(vector, val)
                }
                val = ""
                continue
            }
            val = val + string(char)
        }
        var combi []string;
        combinations(len(vector) - 1, &combi, "")
        for _, c := range combi {
            ufo := vector[0]
            for i, sign := range c {
                if sign == '+' {
                    ufo += vector[i + 1]
                } else if sign == '*' {
                    ufo *= vector[i + 1]
                } else {
                    n := vector[i + 1]
                    count := 1
                    if n != 0 {
                        count =  int(math.Log10(math.Abs(float64(n)))) + 1
                    }
                    ufo *= int(math.Pow10(count))
                    ufo += n
                }
            }       
            if ufo == expected {
                res += expected
                break
            }
        }
    }
    fmt.Println(res)
}
