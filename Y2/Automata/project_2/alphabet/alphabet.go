package alphabet

// Alphabet describes an alphabet.
type Alphabet []string

func (a Alphabet) Contains(i string) bool {
	for _, c := range []string(a) {
		if c == i {
			return true
		}
	}
	return false
}
