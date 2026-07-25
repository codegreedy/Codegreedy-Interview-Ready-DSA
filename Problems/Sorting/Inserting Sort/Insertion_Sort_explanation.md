# Insertion Sort

Insertion Sort is one of the easiest sorting algorithms to understand because it works exactly the way most people sort playing cards in their hands.

Whenever you pick a new card, you don't rearrange all the cards again. Instead, you place the new card in its correct position among the already sorted cards.

Insertion Sort follows the same idea.

- Assume the first element is already sorted.
- Pick the next element.
- Compare it with the sorted elements on its left.
- Shift the larger elements one position to the right.
- Insert the current element into its correct position.
- Repeat until all elements are sorted.

---

## Think of it Like This

Imagine you are holding playing cards.

Initially, you have only one card.

```text
[7]
```

A single card is already sorted.

Now someone gives you another card.

```text
5
```

Instead of shuffling everything, you simply insert **5** before **7**.

```text
[5, 7]
```

Now you receive another card.

```text
6
```

You compare it with 7.

Since 6 is smaller, move 7 one step right.

Now compare 6 with 5.

Since 6 is greater than 5, place it after 5.

```text
[5, 6, 7]
```

This is exactly how Insertion Sort works.

---

# Example

Suppose we have the following array.

```text
[7, 5, 3, 9, 2]
```

We want to sort it in ascending order.

---

# Initial State

Only the first element is considered sorted.

```text
[7 | 5, 3, 9, 2]
```

Sorted Part

```text
[7]
```

Unsorted Part

```text
[5, 3, 9, 2]
```

---

# Pass 1

Current element (Key)

```text
5
```

Current array

```text
[7 | 5, 3, 9, 2]
```

Compare 5 with 7.

Since

```text
5 < 7
```

Shift 7 one position to the right.

```text
[7, 7, 3, 9, 2]
```

Insert 5.

```text
[5, 7 | 3, 9, 2]
```

Now first two elements are sorted.

---

# Pass 2

Current Key

```text
3
```

Current array

```text
[5, 7 | 3, 9, 2]
```

Compare with 7.

```text
3 < 7
```

Shift 7.

```text
[5, 7, 7, 9, 2]
```

Compare with 5.

```text
3 < 5
```

Shift 5.

```text
[5, 5, 7, 9, 2]
```

Insert 3.

```text
[3, 5, 7 | 9, 2]
```

Now first three elements are sorted.

---

# Pass 3

Current Key

```text
9
```

Current array

```text
[3, 5, 7 | 9, 2]
```

Compare with 7.

```text
9 > 7
```

No shifting is required.

Insert 9 in the same position.

```text
[3, 5, 7, 9 | 2]
```

---

# Pass 4

Current Key

```text
2
```

Current array

```text
[3, 5, 7, 9 | 2]
```

Compare with 9.

Shift 9.

```text
[3, 5, 7, 9, 9]
```

Compare with 7.

Shift 7.

```text
[3, 5, 7, 7, 9]
```

Compare with 5.

Shift 5.

```text
[3, 5, 5, 7, 9]
```

Compare with 3.

Shift 3.

```text
[3, 3, 5, 7, 9]
```

Insert 2.

```text
[2, 3, 5, 7, 9]
```

The array is now completely sorted.

---

# Complete Process

```text
Initial

[7, 5, 3, 9, 2]

↓

Insert 5

[5, 7, 3, 9, 2]

↓

Insert 3

[3, 5, 7, 9, 2]

↓

Insert 9

[3, 5, 7, 9, 2]

↓

Insert 2

[2, 3, 5, 7, 9]
```

---

# Visual Walkthrough

```text
Pass 1

[7 | 5, 3, 9, 2]

Take 5

↓

Shift 7

↓

Insert 5

[5, 7 | 3, 9, 2]
```

---

```text
Pass 2

[5, 7 | 3, 9, 2]

Take 3

↓

Shift 7

↓

Shift 5

↓

Insert 3

[3, 5, 7 | 9, 2]
```

---

```text
Pass 3

[3, 5, 7 | 9, 2]

Take 9

↓

No Shift

↓

Insert 9

[3, 5, 7, 9 | 2]
```

---

```text
Pass 4

[3, 5, 7, 9 | 2]

Take 2

↓

Shift 9

↓

Shift 7

↓

Shift 5

↓

Shift 3

↓

Insert 2

[2, 3, 5, 7, 9]
```

---

# Why is it called Insertion Sort?

Because in every pass, we **insert** one element into its correct position inside the already sorted part of the array.

Instead of searching for the smallest element or repeatedly swapping adjacent elements, Insertion Sort keeps growing the sorted portion one element at a time.

---

# Number of Passes

For an array of **N** elements,

```text
Maximum Passes = N - 1
```

Example

```text
5 elements

5 - 1 = 4 passes
```

---

# Time Complexity

| Case | Complexity |
|------|------------|
| Best Case (Already Sorted) | O(n) |
| Average Case | O(n²) |
| Worst Case (Reverse Sorted) | O(n²) |

If the array is already sorted, only one comparison is needed for each element, making the best case **O(n)**.

---

# Space Complexity

```text
O(1)
```

Insertion Sort performs sorting in-place and does not require any extra array.

---

# Algorithm

```text
Assume the first element is sorted.

Repeat for every remaining element

    Pick the current element.

    Compare it with elements on the left.

    Shift all larger elements one position to the right.

    Insert the current element into its correct position.
```

---

# Key Takeaways

- Divide the array into **sorted** and **unsorted** parts.
- The sorted part grows one element after every pass.
- Shift larger elements to create space.
- Insert the current element at the correct position.
- Very efficient for small or nearly sorted arrays.

---

# Bubble Sort vs Selection Sort vs Insertion Sort

| Bubble Sort | Selection Sort | Insertion Sort |
|-------------|----------------|----------------|
| Swaps adjacent elements | Finds the smallest element | Inserts one element into its correct position |
| Many swaps | One swap per pass | Mostly shifting elements |
| Largest element moves to the end | Smallest element moves to the beginning | Sorted part grows from left to right |
| Best Case O(n) (Optimized) | Best Case O(n²) | Best Case O(n) |

---

# Summary

Insertion Sort is a simple comparison-based sorting algorithm that builds the sorted array one element at a time. During each pass, it picks one element from the unsorted part, shifts all larger elements to the right, and inserts the element into its correct position. Because of its simplicity and excellent performance on small or nearly sorted datasets, it is widely used as a building block in many advanced sorting algorithms.