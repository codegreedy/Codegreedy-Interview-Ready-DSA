# Selection Sort

Selection Sort is one of the simplest sorting algorithms to understand.

Instead of swapping elements again and again, Selection Sort works differently.

It **finds the smallest element from the unsorted part of the array and places it in its correct position.**

This process is repeated until the entire array becomes sorted.

---

## Think of it Like This

Imagine you have a group of students standing according to their heights.

Your job is to arrange them from the shortest to the tallest.

Instead of swapping everyone repeatedly, you simply:

1. Find the shortest student.
2. Bring them to the first position.
3. From the remaining students, find the next shortest.
4. Place them in the second position.
5. Repeat until everyone is standing in order.

Selection Sort follows exactly the same idea.

---

## Example

Suppose we have the following array:

```text
[64, 25, 12, 22, 11]
```

We want to sort it in **ascending order**.

---

# Pass 1

Current array

```text
[64, 25, 12, 22, 11]
 ^
Start searching for the smallest element.
```

Compare every remaining element.

```text
64 vs 25 → 25 is smaller

25 vs 12 → 12 is smaller

12 vs 22 → 12 is still smaller

12 vs 11 → 11 is smaller
```

The smallest element is **11**.

Swap it with the first element.

```text
[11, 25, 12, 22, 64]
```

Now the first element is fixed.

```text
[11 | 25, 12, 22, 64]
```

---

# Pass 2

Now ignore the sorted part.

Current array

```text
[11 | 25, 12, 22, 64]
```

Search for the smallest element from

```text
25, 12, 22, 64
```

Comparisons

```text
25 vs 12 → 12 is smaller

12 vs 22 → 12 remains smaller

12 vs 64 → 12 remains smaller
```

Smallest element is **12**.

Swap it with 25.

```text
[11, 12, 25, 22, 64]
```

Now first two elements are sorted.

```text
[11 | 12 | 25, 22, 64]
```

---

# Pass 3

Current array

```text
[11 | 12 | 25, 22, 64]
```

Search for the smallest element from

```text
25, 22, 64
```

Comparisons

```text
25 vs 22 → 22 is smaller

22 vs 64 → 22 remains smaller
```

Swap 22 with 25.

```text
[11, 12, 22, 25, 64]
```

Now three elements are fixed.

```text
[11 | 12 | 22 | 25, 64]
```

---

# Pass 4

Current array

```text
[11 | 12 | 22 | 25, 64]
```

Search in

```text
25, 64
```

25 is already the smallest.

No swap is needed.

```text
[11, 12, 22, 25, 64]
```

---

The array is now completely sorted.

---

# Complete Process

```text
Initial

[64, 25, 12, 22, 11]

↓

Find smallest (11)

[11, 25, 12, 22, 64]

↓

Find smallest (12)

[11, 12, 25, 22, 64]

↓

Find smallest (22)

[11, 12, 22, 25, 64]

↓

Already Sorted

[11, 12, 22, 25, 64]
```

---

# Visual Walkthrough

```text
Pass 1

[64, 25, 12, 22, 11]
 ^
 Searching...

Smallest = 11

Swap

[11, 25, 12, 22, 64]
 ✓
```

---

```text
Pass 2

[11 | 25, 12, 22, 64]
     ^

Searching...

Smallest = 12

Swap

[11 | 12 | 25, 22, 64]
          ✓
```

---

```text
Pass 3

[11 | 12 | 25, 22, 64]
          ^

Searching...

Smallest = 22

Swap

[11 | 12 | 22 | 25, 64]
               ✓
```

---

## Why is it called Selection Sort?

Because in every pass, we **select the smallest element** from the unsorted part of the array and place it in its correct position.

The algorithm does not repeatedly swap adjacent elements.

Instead, it performs **only one swap per pass** after finding the minimum element.

---

## Number of Passes

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

## Time Complexity

| Case | Complexity |
|------|------------|
| Best Case | O(n²) |
| Average Case | O(n²) |
| Worst Case | O(n²) |

Unlike Bubble Sort, Selection Sort always searches the remaining array for the smallest element, so its time complexity remains **O(n²)** even if the array is already sorted.

---

## Space Complexity

```text
O(1)
```

Selection Sort performs sorting in-place and uses only one temporary variable during swapping.

---

## Algorithm

```text
Repeat (N - 1) times

    Assume the current element is the smallest.

    Search the remaining array.

    If a smaller element is found,
        Remember its index.

    Swap the smallest element with the current position.
```

---

## Key Takeaways

- Divide the array into **sorted** and **unsorted** parts.
- In every pass, search the unsorted part for the smallest element.
- Perform only one swap after finding the minimum element.
- After every pass, one more element reaches its correct position.
- Continue until the entire array is sorted.

---

## Bubble Sort vs Selection Sort

| Bubble Sort | Selection Sort |
|-------------|----------------|
| Compares adjacent elements | Searches for the smallest element |
| Multiple swaps in one pass | Only one swap in one pass |
| Largest element moves to the end | Smallest element moves to the beginning |
| Easier to understand | More efficient in terms of number of swaps |

---

## Summary

Selection Sort is a simple comparison-based sorting algorithm that repeatedly finds the smallest element from the unsorted portion of the array and places it in its correct position. Although it is not suitable for large datasets because of its **O(n²)** time complexity, it is easy to understand and is a good algorithm for learning the fundamentals of sorting.