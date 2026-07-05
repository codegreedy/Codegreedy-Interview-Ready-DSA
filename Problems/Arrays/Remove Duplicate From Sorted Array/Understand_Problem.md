# 26. Remove Duplicates from Sorted Array

## Understanding the Problem

Imagine you are sitting in an interview.

The interviewer gives you the following array.

```text
1 1 2 2 3 4 4 5
```

Then the interviewer asks,

> **"Remove all duplicate elements without using any extra array."**

Notice something important.

The interviewer is **not** asking you to delete elements from the array.

In Java, C++, and most programming languages, the size of an array cannot be changed after it is created.

So if we cannot actually remove elements, what does the problem really expect?

The answer lies in the problem statement.

It says that the **first part of the array should contain only unique elements**, and the function should return the number of unique elements.

Everything after those unique elements is irrelevant.

This is a very important realization.

Many beginners spend time wondering how to shrink the array, but that is not the goal.

The goal is simply to arrange the unique elements at the beginning of the same array.

---

# Brute Force

Whenever you hear the words **remove duplicates**, the first idea that usually comes to mind is to use another data structure.

For example, we can traverse the array and insert every element into a **HashSet**.

Since a HashSet stores only unique values, all duplicates are automatically removed.

After collecting all unique elements, we copy them back into the original array.

The solution works.

However, let us ask ourselves an interview question.

> **Did the interviewer allow us to use extra space?**

No.

The problem specifically expects us to solve it **in-place**.

Using a HashSet immediately violates that requirement.

Although the logic is correct, this is not the solution the interviewer is looking for.

---

## Time Complexity

```text
O(N)
```

---

## Space Complexity

```text
O(N)
```

The extra HashSet requires additional memory.

---

# Observation

Whenever an interviewer mentions that an array is **sorted**, you should immediately become curious.

Sorted arrays almost always provide an opportunity for optimization.

Let us look at the same example again.

```text
1 1 2 2 3 4 4 5
```

Ask yourself a simple question.

> **Where do duplicate elements appear?**

They always appear **next to each other**.

For example,

```text
1 1
```

appear together.

```text
2 2
```

appear together.

```text
4 4
```

also appear together.

This happens only because the array is sorted.

If the array were not sorted,

```text
1 2 4 1 3 2
```

the duplicates would be scattered everywhere, making the problem much harder.

The interviewer intentionally tells us that the array is sorted because they expect us to use this property.

---

# Thinking Towards Optimization

Now let us forget about duplicates for a moment.

Instead, think only about **unique elements**.

Suppose the array is

```text
1 1 2 2 3 4 4 5
```

Imagine we have already processed the first few elements.

We want the beginning of the array to always look like this.

```text
1 2 3 ...
```

In other words,

everything before a certain position should always contain the correct answer.

Now the question becomes,

> **How do we know where to place the next unique element?**

This is where the Two Pointer technique naturally appears.

---

# Optimization (Two Pointer Approach)

Instead of using another array,

we use two pointers.

The first pointer keeps track of the **last unique element**.

The second pointer keeps exploring the remaining array.

Let us call them

```text
i → Last unique element

j → Current element being checked
```

Initially,

```text
1 1 2 2 3 4 4 5
↑
i

↑
j starts from index 1
```

Why does `i` start at index `0`?

Because the first element is always unique.

There is nothing before it to compare with.

Now let us move `j`.

---

### Step 1

`j` points to

```text
1
```

Compare it with

```text
nums[i]
```

Both values are the same.

That means we found another duplicate.

There is nothing to do.

Simply move `j` forward.

---

### Step 2

Now `j` points to

```text
2
```

Compare

```text
2
```

with

```text
1
```

They are different.

This means we have found a **new unique element**.

Now ask yourself,

> **Where should this unique element go?**

Immediately after the last unique element.

So first move `i` one step forward.

```text
i++
```

Then copy

```text
nums[j]
```

into

```text
nums[i]
```

The array becomes

```text
1 2 2 2 3 4 4 5
```

Notice something interesting.

We did not care that one duplicate was overwritten.

Once we have already processed an element, we never need it again.

---

### Step 3

Continue moving `j`.

Whenever we find another duplicate,

we simply ignore it.

Whenever we find another unique value,

we move `i` forward and place that value there.

Eventually, the array becomes

```text
1 2 3 4 5 ...
```

The remaining values after the unique portion do not matter because the problem never asks us to clean them.

---

# Why Does This Work?

At every moment during the algorithm,

everything from

```text
0
```

to

```text
i
```

contains only unique elements.

This is our invariant.

Whenever we discover another unique value,

we extend this unique portion by one position.

Whenever we discover a duplicate,

we simply ignore it because that value is already present.

By the time `j` reaches the end of the array,

the beginning of the array contains every unique element exactly once.

---

# Dry Run

```text
Initial

1 1 2 2 3 4 4 5

i = 0
j = 1
```

Duplicate

```text
1 == 1
```

Ignore.

---

```text
j = 2

2 != 1
```

Move `i`

```text
i = 1
```

Copy

```text
nums[1] = 2
```

Array

```text
1 2 2 2 3 4 4 5
```

---

Next duplicate

```text
2 == 2
```

Ignore.

---

Next unique

```text
3 != 2
```

Move `i`

Copy `3`

```text
1 2 3 2 3 4 4 5
```

---

Next unique

```text
4 != 3
```

```text
1 2 3 4 ...
```

---

Next duplicate

Ignore.

---

Next unique

```text
5 != 4
```

Final

```text
1 2 3 4 5
```

Return

```text
i + 1
```

because `i` stores the index of the last unique element.

---

# Why Do We Return `i + 1`?

This is one of the most common interview questions.

Remember,

`i` represents the **index** of the last unique element.

Array indices always start from zero.

Suppose

```text
i = 4
```

The unique elements occupy

```text
Index

0
1
2
3
4
```

How many elements are there?

Not four.

There are

```text
5
```

elements.

Therefore,

the total number of unique elements is always

```text
i + 1
```

---

# Complexity Analysis

We traverse the array exactly once.

Therefore,

```text
Time Complexity = O(N)
```

No additional data structure is used.

Everything happens inside the original array.

```text
Space Complexity = O(1)
```

---
# Interview Style Explanation

Youtube Link - 

---

# Interviewer's Perspective

This problem is **not** about removing duplicates. It is about recognizing the hidden clue in the statement: **the array is sorted**. Strong candidates immediately realize that duplicates in a sorted array are always adjacent, eliminating the need for a HashSet. From there, the idea of maintaining a growing "unique section" at the beginning of the array naturally leads to the two-pointer technique.

In an interview, avoid saying, "This is a two-pointer problem." Instead, guide the interviewer through your reasoning: first acknowledge the brute-force approach, explain why extra space is undesirable, point out the significance of the sorted property, and then derive the two-pointer solution. That sequence demonstrates genuine problem-solving ability rather than memorization.


