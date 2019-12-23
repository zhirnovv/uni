package stack

import (
	"bytes"
	"errors"
)

// Stack defines a pushdown automata's stack
type Stack string

// Push appends str to the front of the Stack string
func (stack *Stack) Push(str string) {
	buf := bytes.Buffer{}
	buf.WriteString(str)
	buf.WriteString(string(*stack))
	newStack := Stack(buf.String())
	*stack = newStack
}

// Pop removes the first element in a Stack
func (stack *Stack) Pop() error {
	if stack.Size() == 0 {
		return errors.New("Stack is already empty.")
	}
	newStack := Stack(string(*stack)[1:])
	*stack = newStack
	return nil
}

// Peek returns the string at the top of the stack.
func (stack Stack) Peek() string {
	return string(string(stack)[0])
}

func (stack Stack) Size() int {
	return len(string(stack))
}
