---

# Rotate Array (Interview Thought Process)

## Understanding the Problem

Imagine you are sitting in an interview.

The interviewer writes the following question on the board.

> "Rotate the array to the right by `k` positions."

At first glance, the problem looks very simple. However, instead of thinking about the best algorithm immediately, ask yourself a much simpler question.

> **What exactly happens during one rotation?**

Suppose the array is

```text
1 2 3 4 5
```

After one rotation,

```text
5 1 2 3 4
```

The last element moves to the front, while every other element shifts one position towards the right.

That is all a single rotation does.

Now the interviewer asks you to rotate the array **three times**.

Naturally, your brain says,

> "If I know how to perform one rotation, why not repeat it three times?"

That is a perfectly reasonable starting point.

Experienced interviewers actually expect you to begin with this idea because it shows that you understand the problem before trying to optimize it.

---

# Brute Force

The simplest approach is to perform **one rotation at a time**.

For every rotation,

* Store the last element.
* Shift every element one position towards the right.
* Place the stored element at index `0`.

Let us see this visually.

```text
nums = [1,2,3,4,5]
k = 2
```

### First Rotation

Store the last element.

```text
5
```

Shift every element.

```text
1 2 3 4 5
↓ ↓ ↓ ↓

1 1 2 3 4
```

Place the stored element at the beginning.

```text
5 1 2 3 4
```

### Second Rotation

Again store the last element.

```text
4
```

Shift every element.

```text
5 1 2 3 4
↓ ↓ ↓ ↓

5 5 1 2 3
```

Place the stored element at the beginning.

```text
4 5 1 2 3
```

The answer is correct.

At this point, many candidates stop thinking because the problem has already been solved.

Unfortunately, interviews do not end here.

The interviewer now asks,

> **Can you make it faster?**

---

# Why is the Brute Force Solution Slow?

Before trying to optimize, let us first measure the cost of our current solution.

Suppose the array contains **N** elements.

During one rotation, every element has to be shifted.

That means one rotation takes

```text
O(N)
```

If we repeat the same process **k** times,

the total work becomes

```text
O(N × K)
```

Now imagine the constraints are

```text
N = 100000
K = 100000
```

This means our algorithm performs billions of operations.

Even though the logic is correct, the solution becomes impractical.

So the real interview question is no longer

> **"How do we rotate an array?"**

Instead, it becomes

> **"Can we achieve the same final arrangement without repeatedly moving every element?"**

This is the point where optimization begins.

---

# Observation

Whenever you feel stuck in an interview, stop looking at the process.

Instead, look at the **final answer**.

Consider the following example.

```text
Original

1 2 3 4 5 6 7
```

Rotate by

```text
k = 3
```

The final array becomes

```text
5 6 7 1 2 3 4
```

Instead of asking,

> "How did we reach this answer?"

Ask a different question.

> **Which elements came to the front?**

The answer is immediately visible.

```text
5 6 7
```

These were simply the **last three elements** of the original array.

Now ask another question.

> **What happened to the remaining elements?**

```text
1 2 3 4
```

They simply moved behind them.

Now comes the most important observation.

Did the order inside these two groups change?

Look carefully.

```text
Original

1 2 3 4 | 5 6 7
```

Final

```text
5 6 7 | 1 2 3 4
```

The answer is **No**.

The first group still appears as

```text
1 2 3 4
```

The second group still appears as

```text
5 6 7
```

Nothing inside the groups changed.

Only the positions of the groups changed.

This is the turning point of the problem.

Most candidates spend their time moving every element.

Strong candidates realize that they only need to swap the positions of two groups.

Now the interviewer knows you are thinking instead of memorizing.

---

# Can We Swap These Two Groups Without Extra Space?

If we use another array, the problem becomes easy.

However, interviewers usually expect an **O(1)** space solution.

So now the question becomes,

> **Can we rearrange these two groups inside the same array?**

The answer is yes.

The trick is **reversing**.

At first, reversing feels completely unrelated.

So let us understand why it works instead of memorizing it.

---

# Why Does Reversing Work?

Start with the original array.

```text
1 2 3 4 | 5 6 7
```

Reverse the entire array.

```text
7 6 5 | 4 3 2 1
```

Pause here.

Do not continue immediately.

Look carefully.

Have both groups reached the correct side?

Yes.

The group

```text
5 6 7
```

has moved to the front.

The group

```text
1 2 3 4
```

has moved to the back.

That part is already correct.

So what is still wrong?

Only one thing.

The order inside each group has become reversed.

Instead of

```text
5 6 7
```

we have

```text
7 6 5
```

Instead of

```text
1 2 3 4
```

we have

```text
4 3 2 1
```

Notice something beautiful here.

The groups are already in the correct position.

We only need to fix their internal ordering.

How do we fix a reversed sequence?

Reverse it again.

Reverse the first group.

```text
7 6 5

↓

5 6 7
```

The array becomes

```text
5 6 7 4 3 2 1
```

Now reverse the remaining group.

```text
4 3 2 1

↓

1 2 3 4
```

The final array becomes

```text
5 6 7 1 2 3 4
```

Exactly what we wanted.

The reverse algorithm is no longer a trick.

It becomes a logical consequence of our observation.

---

# One Important Edge Case

Suppose the interviewer gives

```text
nums = [1,2,3,4]
k = 10
```

Should we rotate ten times?

No.

Think about what happens after every complete rotation.

After four rotations,

```text
1 2 3 4
```

The array becomes exactly the same again.

After eight rotations,

it again becomes exactly the same.

Only the remaining rotations actually matter.

That is why we calculate

```java
k = k % n;
```

For this example,

```text
10 % 4 = 2
```

So rotating ten times is exactly the same as rotating only two times.

This simple observation prevents unnecessary work and handles all cases where `k` is larger than the array size.

---

# Final Algorithm

Now the entire algorithm feels natural.

1. Reduce `k` using `k % n`.
2. Reverse the complete array.
3. Reverse the first `k` elements.
4. Reverse the remaining `n - k` elements.

Every step follows directly from the observations we made earlier.

---

# Complexity Analysis

The array is reversed three times.

Each reversal visits every element at most once.

Therefore, the total time complexity is

```text
O(N)
```

Since all operations are performed inside the original array without using any additional data structure, the space complexity is

```text
O(1)
```

---

# Interview Style Explanation

Youtube Link - 
 
---

# Interviewer's Perspective

When interviewers ask **Rotate Array**, they are **not** testing whether you have memorized the reverse algorithm. They are evaluating whether you can begin with a straightforward solution, recognize its limitations, carefully analyze the final arrangement of the elements, discover the key observation that the array consists of two intact groups, and then derive an in-place solution from that observation.

If you explain your thought process in this order during the interview, you demonstrate analytical thinking, problem-solving ability, and optimization skills. Those qualities create a much stronger impression than simply saying, "I know this problem. We reverse the array three times."

---
