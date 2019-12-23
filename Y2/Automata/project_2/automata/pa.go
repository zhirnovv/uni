package automata

import (
	"errors"
	"fmt"
	"project_2/alphabet"
	"project_2/stack"
)

// Epsilon is a special variable which forces the stack to pop an element.
var Epsilon = " "

type Conversion struct {
	S  int    // new state
	PR string // new production
}

// Transitions define PAs transition functions.
// The key of the map is the character read from the string, and the value is the string to be pushed to the Stack.
type Conversions map[string]Conversion

// Transitions is a map that implements PAs transition functions.
// It follows the logic b(q, ST, Input) = (q, Output),
// where ST is the symbol on top of the stack, Input is the character read from the string, Output is the string to be pushed to the Stack.
// ST acts as a map key, Conversions map acts as a value.
type Transitions struct {
	Start string // string to be pushed to the stack on initialization.
	Map   map[int]map[string]Conversions
}

// PA defines a Pushdown Automata.
type Automata struct {
	STRA  alphabet.Alphabet // string alphabet
	STKA  alphabet.Alphabet // stack alphabet
	Stack stack.Stack
	State int
	T     Transitions
}

func (a *Automata) Transition(stk *stack.Stack, str string) error {
	fmt.Println("string: ", str)

	if stk.Size() == 0 {
		return errors.New("stack is already empty")
	}
	st := stk.Peek() // stack top

	// if stack top matches input character, pop
	if st == str {
		err := stk.Pop()
		if err != nil {
			return err
		}
		return nil
	}

	// find conversion
	cnv, ok := a.T.Map[a.State][st][str]
	if !ok {
		return errors.New(fmt.Sprintf("No conversions defined for input symbol \"%s\".", str))
	}
	fmt.Println("conversion:", cnv)

	// set new State
	a.State = cnv.S
	fmt.Println("new state", a.State)

	// if conversion is Epsilon, pop first symbol and the next matching 0.
	if cnv.PR == Epsilon {
		err := stk.Pop()
		if err != nil {
			return err
		}
		if stk.Size() != 0 && stk.Peek() != "A" || stk.Size() != 0 && stk.Peek() != "B" {
			err = stk.Pop()
			if err != nil {
				return err
			}
		}
		return nil
	}

	// if conversion is creating, pop first symbol, push new conversion, and pop the next matching symbol
	err := stk.Pop()
	if err != nil {
		return err
	}
	stk.Push(cnv.PR)
	err = stk.Pop()
	if err != nil {
		return err
	}

	return nil
}

// Test tests some provided string and returns an error.
// The error is nil when the string belongs to the language defined in the automata.
// Otherwise the error contains some message.
func (a Automata) Test(str string) error {
	// empty string passes test according to language definition
	if str == "" {
		return nil
	}

	fmt.Println("initial state:", a.State)
	for pos, char := range str {
		// check if string alphabet contains a character
		strChar := string(char)
		if !a.STRA.Contains(strChar) {
			return errors.New(fmt.Sprintf("String %s: FAIL AT POSITION %d - character \"%s\" is not defined in the alphabet.", str, pos+1, strChar))
		}

		// perform transition
		err := a.Transition(&a.Stack, strChar)
		if err != nil {
			return errors.New(fmt.Sprintf("String %s: FAIL AT POSITION %d, CHARACTER \"%s\" - %s", str, pos+1, strChar, err))
		}

		// return error if the machine dropped into failure state
		if a.State == -1 {
			return errors.New(fmt.Sprintf("String \"%s\": FAIL AT POSITION %d, CHARACTER \"%s\" - machine dropped into failure state", str, pos+1, strChar))
		}
	}

	// if top character is B, string is of type { 1^n0^2n1^02^0 }
	if a.Stack.Size() == 1 && a.Stack.Peek() == "B" {
		return nil
	}

	if a.Stack.Size() != 0 {
		return errors.New(fmt.Sprintf("String %s: FAIL AT POSITION %d, CHARACTER \"%c\" - Stack is not empty.", str, len(str), str[len(str)-1]))
	}
	return nil
}
