*This project has been created as part of the 42 curriculum by pokuzmic, dibrayev.*

# push_swap

## Description

**push_swap** is an algorithm project from the 42 curriculum. The program receives a list of
integers, places them in a stack `a`, and must print the shortest possible sequence of
*Push_swap operations* that sorts them in ascending order (smallest on top), using only a
second, initially empty stack `b`.

The goal is to discover algorithmic complexity in a concrete way: the cost of a strategy is
measured in the **number of operations printed**, not in CPU time.

This version of the subject requires four sorting strategies in one binary:

| Strategy | Flag | Algorithm used | Complexity (operations) |
|----------|------|----------------|-------------------------|
| Simple   | `--simple`   | Selection sort (min extraction) | O(n²) |
| Medium   | `--medium`   | Chunk-based sort (chunks of ~2.5√n) | O(n√n) |
| Complex  | `--complex`  | LSD binary radix sort | O(n log n) |
| Adaptive | `--adaptive` (default) | Chooses one of the above from the measured disorder | depends on regime |

### The operations

| Op | Effect |
|----|--------|
| `sa` / `sb` / `ss` | Swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | Push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | Rotate up: the first element becomes the last |
| `rra` / `rrb` / `rrr` | Reverse rotate: the last element becomes the first |

## Instructions

### Compilation

```sh
make          # builds libft, then the push_swap binary
make clean    # removes object files
make fclean   # removes object files and the binary
make re       # full rebuild
```

Requirements: `cc` and `make`. The project compiles with `-Wall -Wextra -Werror` and does not relink.

### Execution

```sh
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers...>
```

- Numbers can be given as separate arguments, as one quoted string, or a mix of both:
  `./push_swap 3 2 1`, `./push_swap "3 2 1"`, `./push_swap "3 2" 1`.
- The first number is the top of stack `a`.
- Flags can appear anywhere among the arguments. Without a strategy flag, `--adaptive` is used.
- With no arguments, or with an already sorted list, nothing is printed.
- Operations are written to **stdout**, one per line.

### Benchmark mode

`--bench` prints a report on **stderr** after sorting, so it never mixes with the operations:

```sh
$ ./push_swap --bench 4 67 3 87 23 > /dev/null
disorder: 40.00%
strategy: adaptive
complexity: O(n*sqrt(n))
total operations: 9
sa: 0
sb: 0
ss: 0
pa: 2
pb: 2
ra: 4
rb: 0
rr: 0
rra: 1
rrb: 0
rrr: 0
```

### Error handling

`Error\n` is printed on **stderr** (exit status 1) when an argument is not an integer, is
outside the `int` range, or appears twice:

```sh
$ ./push_swap 0 one 2 3
Error
$ ./push_swap 3 2 3
Error
$ ./push_swap 2147483648
Error
```

## Algorithms: explanation and justification

### Data structure

Each stack is a dynamic `int` array with a `size` and a capacity (`t_stack`), index `0` being
the top. Both stacks, the eleven operation counters and the bench switch live in one `t_ps`
structure that is passed to every function, so no global variable is needed. Every operation
function (`ft_sa`, `ft_pb`, ...) prints its name and increments its counter, which is what
makes the `--bench` report exact.

### Disorder metric

Before any move, `disorder()` counts the inversions: every pair `(i, j)` with `i < j` and
`a[i] > a[j]` is a mistake. The result is `mistakes / total_pairs`, from `0` (sorted) to `1`
(reverse sorted). It costs no operations.

### Simple: selection sort, O(n²)

1. Find the minimum of `a`.
2. Rotate it to the top by the shortest way (`ra` if it is in the top half, `rra` otherwise).
3. `pb`. Repeat until `a` is empty, then `pa` everything back.

**Why:** it is the most direct translation of a quadratic sort to two stacks, easy to prove
correct, and very cheap when the input is nearly sorted because the minimum is then always
near the top.

**Complexity:** bringing a minimum to the top costs at most n/2 rotations, done n times, plus
2n pushes: at most n²/2 + 2n operations, so O(n²). Space: O(n) for the two stacks.

### Medium: chunk sort, O(n√n)

1. Build a sorted copy of `a` to know each value's final rank.
2. Split the ranks into chunks of size `2.5 × ⌈√n⌉`.
3. For each chunk, from the smallest values upward: find the nearest element of the chunk
   from the top or from the bottom of `a`, rotate it to the top, and `pb`. If the element is in
   the lower half of its chunk, `rb` sends it to the bottom of `b`, so `b` stays roughly
   ordered inside each chunk.
4. Push back: repeatedly bring the maximum of `b` to the top by the shortest way and `pa`.
   Optimisation: if the second-largest value is closer than the largest, push it first, then
   the largest, and fix the order with one `sa`.

**Why:** chunks keep the rotations short in both phases, which gives the best results of our
three algorithms on 100 and 500 numbers. The 2.5 factor was chosen by testing.

**Complexity:** with chunk size c ≈ √n, a chunk element is found within about n/c ≈ √n
rotations of `a`, for n elements: O(n√n). In the push-back phase, the largest values are
always inside the last chunk pushed, which sits at the top of `b`, so each one needs O(√n)
rotations: O(n√n) again. Total O(n√n) operations. Space: O(n) (stacks plus the sorted copy).

### Complex: binary radix sort (LSD), O(n log n)

1. Replace every value by its rank `0 … n-1` (this also handles negative numbers).
2. For each bit, from the least significant: go through the n elements of `a`; if the bit is
   `1`, `ra`, otherwise `pb`. Then `pa` everything back.
3. After ⌈log₂ n⌉ passes the stack is sorted.

**Why:** the number of operations is fully predictable and does not depend on the input
order, which makes it a safe choice for highly shuffled input.

**Complexity:** each pass costs n operations (`ra`/`pb`) plus at most n `pa`, and there are
⌈log₂ n⌉ passes: at most 2n⌈log₂ n⌉ operations, so O(n log n). For 500 numbers that is
9 passes and always 6784 operations. Space: O(n).

### Adaptive: selection by disorder

| Regime | Condition | Method | Complexity |
|--------|-----------|--------|------------|
| Tiny input | n ≤ 5 | dedicated small sort | constant |
| Low disorder | disorder < 0.2 | selection sort | O(n²) |
| Medium disorder | 0.2 ≤ disorder < 0.5 | chunk sort | O(n√n) |
| High disorder | disorder ≥ 0.5 | radix sort | O(n log n) |

**Rationale for the thresholds.** The 0.2 and 0.5 limits are the ones fixed by the subject.
They match how each method behaves:

- Below 0.2 the stack is almost sorted, most elements are already close to their place and
  the simple method needs few rotations despite its quadratic upper bound.
- Between 0.2 and 0.5 the input is partly ordered; chunking takes advantage of what order
  exists while keeping rotations bounded by √n.
- From 0.5 upward the input is random or close to reversed, there is no structure left to
  exploit, so the method with the guaranteed O(n log n) bound is used.

**Small inputs.** For 5 numbers or fewer, the adaptive strategy pushes the smallest values to
`b` until three remain, sorts those three with at most two operations, and pushes back.

Space is O(n) in every regime.

### Measured performance

Averages over random inputs, verified to sort correctly:

| Input | `--simple` | `--medium` | `--complex` | `--adaptive` |
|-------|-----------:|-----------:|------------:|-------------:|
| 100 numbers | ~1420 | ~610 | 1084 | 610 – 1084 |
| 500 numbers | ~32400 | ~5300 | 6784 | 5300 – 6784 |

Random input has a disorder very close to 0.5, so the adaptive strategy lands on either the
medium or the complex method. Both stay under the subject's limits (2000 for 100 numbers,
12000 for 500).


## Contributions

| Login | Contribution |
|-------|--------------|
| **pokuzmic** | Argument parsing and error handling (`parsing/`), simple algorithm — selection sort (`algorithms/simple_algorithm.c`), medium algorithm — chunk sort (`algorithms/medium_*.c`), strategy flags (`flags/options.c`) and benchmark mode (`flags/benchmark.c`) |
| **dibrayev** | Stack operations (`operations/`), disorder metric (`algorithms/disorder.c`), complex algorithm — radix sort (`algorithms/complex.c`), adaptive strategy (`algorithms/adaptive.c`), header (`push_swap.h`), `Makefile` and this README |

Both of us took part in integrating the parts in `main.c`, testing, and reviewing each
other's code, and both of us can explain every part of the project.

## Resources

- *Mastering Algorithms with C*, Kyle Loudon (O'Reilly), available in the 42 Prague library
- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- The push_swap subject (version 1.1)

### AI usage

AI was used as a learning assistant and as a helper for review and testing. Every
suggested change was read, understood and tested by us before it was added to the project.

- **Learning the algorithms:** explaining how the sorting algorithms work (selection sort,
  chunk sort, radix sort) and what their complexity means in the Push_swap model, and
  clarifying the parts of the book that were not clear to us.
- **Understanding parsing:** explaining what parsing is and how to validate and convert the
  program arguments into integers.
- **Planning:** helping us understand which direction to take with the project and in which
  order to build its parts.
