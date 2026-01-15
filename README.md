# push_swap

## 📘 Project Overview

**push_swap** is a project from 42 School that consists of sorting a stack of integers using a limited set of operations and the smallest possible number of moves.

The program manipulates two stacks, **A** and **B**, and outputs a sequence of instructions that sorts stack A in ascending order.

As required by the project constraints, the use of standard C library functions was restricted.  
Only functions previously re-implemented in the **libft** project were allowed.

To solve the problem efficiently, this implementation is based on the **Radix sort algorithm**, which provides reliable and consistent performance for large sets of numbers.

---

## 🔄 Allowed Operations

The program is limited to the following instructions:

- **pa (push A)**  
  Take the first element at the top of stack B and put it at the top of stack A.  
  Does nothing if stack B is empty.

- **pb (push B)**  
  Take the first element at the top of stack A and put it at the top of stack B.  
  Does nothing if stack A is empty.

- **sa (swap A)**  
  Swap the first two elements at the top of stack A.  
  Does nothing if there is one or no elements.

- **sb (swap B)**  
  Swap the first two elements at the top of stack B.  
  Does nothing if there is one or no elements.

- **ss**  
  Perform `sa` and `sb` simultaneously.

- **ra (rotate A)**  
  Shift all elements of stack A up by one.  
  The first element becomes the last one.

- **rb (rotate B)**  
  Shift all elements of stack B up by one.  
  The first element becomes the last one.

- **rr**  
  Perform `ra` and `rb` simultaneously.

- **rra (reverse rotate A)**  
  Shift all elements of stack A down by one.  
  The last element becomes the first one.

- **rrb (reverse rotate B)**  
  Shift all elements of stack B down by one.  
  The last element becomes the first one.

- **rrr**  
  Perform `rra` and `rrb` simultaneously.

---

## ⚙️ Compilation

Use the provided Makefile to build and manage the project:

- `make`  
  Compiles the project.

- `make clean`  
  Removes object files while keeping the executable.

- `make fclean`  
  Removes object files and the executable.

- `make re`  
  Removes all compiled files and recompiles the project from scratch.

---

## ▶️ Usage

Run the program by passing a list of **unique integers** as arguments:

```bash
./push_swap <numbers>
```

Exemple :

```bash
./push_swap 8 -23 89 -186 1 9 -188
```

⚠️ Duplicate numbers are not allowed and will result in an error.
