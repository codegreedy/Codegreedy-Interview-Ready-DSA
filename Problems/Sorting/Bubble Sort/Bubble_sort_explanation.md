# Bubble Sort

Bubble Sort is one of the easiest sorting algorithms to understand.

The idea is very simple:

- Compare two neighboring (adjacent) elements.
- If they are in the wrong order, swap them.
- Keep doing this until the array becomes sorted.

With every complete pass, the **largest unsorted element moves to its correct position at the end of the array**, just like a bubble rises to the surface of water. That's why it is called **Bubble Sort**.

---

## Example

Suppose we have the following array:

```text
[5, 3, 8, 4, 2]
```

We want to sort it in **ascending order**.

---

# Pass 1

### Compare 5 and 3

Since **5 > 3**, swap them.

```text
[3, 5, 8, 4, 2]
```

---

### Compare 5 and 8

Since **5 < 8**, no swap is needed.

```text
[3, 5, 8, 4, 2]
```

---

### Compare 8 and 4

Since **8 > 4**, swap them.

```text
[3, 5, 4, 8, 2]
```

---

### Compare 8 and 2

Since **8 > 2**, swap them.

```text
[3, 5, 4, 2, 8]
```

At the end of the first pass, the largest element (**8**) has reached its correct position.

```text
[3, 5, 4, 2 | 8]
```

We don't need to compare **8** again.

---

# Pass 2

Current array:

```text
[3, 5, 4, 2 | 8]
```

Compare **3 and 5**

```text
[3, 5, 4, 2 | 8]
```

No swap.

---

Compare **5 and 4**

```text
[3, 4, 5, 2 | 8]
```

Swap.

---

Compare **5 and 2**

```text
[3, 4, 2, 5 | 8]
```

Swap.

Now **5** is also in its correct position.

```text
[3, 4, 2 | 5 | 8]
```

---

# Pass 3

Current array:

```text
[3, 4, 2 | 5 | 8]
```

Compare **3 and 4**

No swap.

---

Compare **4 and 2**

Swap them.

```text
[3, 2, 4 | 5 | 8]
```

Now **4** is fixed.

---

# Pass 4

Current array:

```text
[3, 2 | 4 | 5 | 8]
```

Compare **3 and 2**

Swap them.

```text
[2, 3, 4, 5, 8]
```

The array is now completely sorted.

---

## Complete Process

```text
Initial
[5, 3, 8, 4, 2]

↓

[3, 5, 8, 4, 2]

↓

[3, 5, 4, 8, 2]

↓

[3, 5, 4, 2, 8]

↓

[3, 4, 5, 2, 8]

↓

[3, 4, 2, 5, 8]

↓

[3, 2, 4, 5, 8]

↓

[2, 3, 4, 5, 8]
```

---

## Why is it called Bubble Sort?

Imagine air bubbles inside a glass of water.

The larger bubbles naturally move upward until they reach the surface.

Bubble Sort works in a similar way.

After every pass, the largest unsorted element "floats" to the end of the array.

For example,

```text
Before Pass 1

[5, 3, 8, 4, 2]

After Pass 1

[3, 5, 4, 2, 8]
               ↑
         Largest element is fixed
```

The next pass fixes the second-largest element, then the third-largest, and so on.

---

## Visual Walkthrough

```text
[5, 3, 8, 4, 2]
 ↑  ↑
 Swap

[3, 5, 8, 4, 2]
    ↑  ↑
  No Swap

[3, 5, 8, 4, 2]
       ↑  ↑
      Swap

[3, 5, 4, 8, 2]
          ↑  ↑
         Swap

[3, 5, 4, 2, 8]
               ✓
```

---

## Number of Passes

For an array of **N** elements,

```text
Maximum Passes = N - 1
```

Example:

```text
5 elements

5 - 1 = 4 passes
```

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best Case (Already Sorted - Optimized) | O(n) |
| Average Case | O(n²) |
| Worst Case | O(n²) |

---

## Space Complexity

```text
O(1)
```

Bubble Sort performs sorting in-place and only needs one temporary variable while swapping.

---

## Algorithm

```text
Repeat (N - 1) times

    Compare every adjacent pair.

    If the left element is greater than the right element,
        Swap them.
```

---

## Key Takeaways

- Compare only adjacent elements.
- Swap only when the left element is greater than the right.
- After every pass, one element reaches its correct position.
- Continue until the array is fully sorted.

---

## Summary

Bubble Sort is a simple comparison-based sorting algorithm that repeatedly compares adjacent elements and swaps them whenever they are in the wrong order. Although it is not the fastest sorting algorithm for large datasets, it is an excellent choice for learning how sorting algorithms work because of its straightforward logic and easy-to-follow process.