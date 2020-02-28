package main

import (
	"fmt"
	"project_2/automata"
	"project_2/stack"
)

func main() {

	pa := automata.Automata{
		STRA: []string{automata.Epsilon, "1", "0"},
		STKA: []string{"Stack, A, B, 0, 1"},
		T: automata.Transitions{
			Start: "AB",
			// only define transitions to different characters
			Map: map[int]map[string]automata.Conversions{
				// From initial state
				0: {
					"A": {
						"1": automata.Conversion{S: 1, PR: "1A00"},
						"0": automata.Conversion{S: -1, PR: automata.Epsilon},
					},

				},
				1: {
					"A": {
						"1": automata.Conversion{S: 1, PR: "1A00"},
						"0": automata.Conversion{S: 1, PR: automata.Epsilon},
					},
					"B": {
						"1": automata.Conversion{S: 1, PR: "111B0"},
						"0": automata.Conversion{S: 1, PR: automata.Epsilon},
					},
				},
			},
		},
		Stack: stack.Stack("AB"),
	}

	str := "100110"
	err := pa.Test(str)
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Printf("String \"%s\": PASS\n", str)
	}
}
