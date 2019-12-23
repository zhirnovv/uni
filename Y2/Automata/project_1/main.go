package main

import (
	"bufio"
	"fmt"
	"os"
)

// Transitions is a helper type for a map of a states transitions, with accepted symbols as keys and new states as values..
type Transitions map[string]int

// FSM defines a finite state machine via a map with states as keys and available transitions as values.
type FSM map[int]Transitions

// buildFSM builds and returns an FSM variable according to the assignment.
func buildFSM() FSM {
	fsm := FSM{
		1: Transitions{
			"+": 2,
			"a": 1,
			"b": 1,
			"c": 1,
			"-": 1,
		},
		2: Transitions{
			"+": 2,
			"a": 3,
			"b": 4,
			"c": 5,
			"-": 6,
		},
		3: Transitions{
			"+": 10,
			"a": 3,
			"b": 6,
			"c": 6,
			"-": 7,
		},
		4: Transitions{
			"+": 10,
			"a": 6,
			"b": 4,
			"c": 6,
			"-": 8,
		},
		5: Transitions{
			"+": 10,
			"a": 6,
			"b": 6,
			"c": 5,
			"-": 9,
		},
		6: Transitions{
			"+": 1,
			"a": 6,
			"b": 6,
			"c": 6,
			"-": 6,
		},
		7: Transitions{
			"+": 1,
			"a": 6,
			"b": 4,
			"c": 5,
			"-": 6,
		},
		8: Transitions{
			"+": 1,
			"a": 3,
			"b": 6,
			"c": 5,
			"-": 6,
		},
		9: Transitions{
			"+": 1,
			"a": 3,
			"b": 4,
			"c": 6,
			"-": 6,
		},
		10: Transitions{},
	}
	return fsm
}

// test looks a provided string according to a provided FSM.
func (machine FSM) test(input string) {
	// set initial state to 1
	currentState := 1
	startPosition := -1
	endPosition := -1
	validString := ""
	found := false
	fmt.Printf("Testing string %s...\n", input)

	for pos, char := range input {
		state, ok := machine[currentState]
		if !ok {
			panic("Fatal error: state not defined.")
		}

		newState, ok := state[string(char)]
		if !ok {
			panic("Fatal error: transition not defined.")
		}
		// If transition is present and the current state is one, the FSM is starting its operation.
		if ok && currentState == 1 {
			startPosition = pos
			endPosition = pos + 1
		}
		switch newState {
		// If new state is one, reset the result generator
		case 1:
			startPosition = -1
			endPosition = -1
			validString = ""
			currentState = 1
		// If new state is 10, append the last symbol, print results, and reset the FSM.
		case 10:
			validString += string(char)
			endPosition = pos
			found = true
			fmt.Printf("Found substring - starting position: %d, final position: %d, value: %s.\n", startPosition, endPosition, validString)
			currentState = 1
			startPosition = -1
			endPosition = -1
			validString = ""
		// By default, set new state and change result values
		default:
			currentState = newState
			validString += string(char)
			endPosition = pos
		}
	}
	// if no substring was found, return an empty print
	if !found {
		fmt.Println("No substrings found.")
	}
}

func main() {
	fsm := buildFSM()
	file, err := os.Open("./tests.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		fsm.test(scanner.Text())
	}
}
