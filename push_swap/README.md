# Push Swap

<p align="center">
	<img src="img/push_swapm.png" alt="Push Swap Badge" width="15%">
</p>


## Overview
Push Swap is a sorting algorithm project designed to sort a stack of integers using a limited set of operations. The goal is to sort the stack with the least number of moves.

## Features
- Implements sorting algorithms tailored for small stacks.
- Uses a predefined set of operations:
	- `sa`, `sb`, `ss`: Swap the first two elements of a stack.
	- `pa`, `pb`: Push the top element from one stack to another.
	- `ra`, `rb`, `rr`: Rotate a stack upwards.
	- `rra`, `rrb`, `rrr`: Rotate a stack downwards.

## Usage
1. Clone the repository:
	 ```bash
	 git clone https://github.com/yourusername/push_swap.git
	 cd push_swap
	 ```
2. Compile the program:
	 ```bash
	 make
	 ```
3. Run the program with a list of integers:
	 ```bash
	 ./push_swap 4 67 3 87
	 ```
4. Run the program with a list of random integers (here 500 integers) _⚠️ Only in bash_:
	 ```bash
	 ARGS=$(shuf -i 0-499); ./push_swap $ARGS
	 ```

## Testing

- Check using the 42 checker (`checker + _linux || _mac`)
```bash
ARGS=$(shuf -i 0-499); ./push_swap $ARGS | ./checkers/checker_linux $ARGS
```

## Resources
- [42 Project Guidelines](https://projects.intra.42.fr)
- [Sorting Algorithm Basics](https://en.wikipedia.org/wiki/Sorting_algorithm)


## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
