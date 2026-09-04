# Bitwise Operators in C++ — Beginner Guide

Bitwise operators work directly with the **bits** of a number.

A bit can only be:

```text
0 or 1
```

The main bitwise operators in C++ are:

```text
&     AND
|     OR
^     XOR
~     NOT
<<    Left Shift
>>    Right Shift
```

---

# 1. What is Binary?

Computers represent numbers using binary.

Binary uses only:

```text
0 and 1
```

For example:

```text
Decimal    Binary
-------    ------
0          0000
1          0001
2          0010
3          0011
4          0100
5          0101
6          0110
7          0111
8          1000
```

Each position represents a power of 2:

```text
  8   4   2   1
  ↓   ↓   ↓   ↓
  2³  2²  2¹  2⁰
```

For example:

```text
5 = 0101
```

because:

```text
0 × 8
1 × 4
0 × 2
1 × 1

= 4 + 1
= 5
```

---

# 2. What Does "Bitwise" Mean?

Bitwise means:

> Work with the individual bits of a number.

For example:

```cpp
5 & 3
```

First, look at their binary representations:

```text
5 = 0101
3 = 0011
```

Then compare the bits:

```text
  0101
& 0011
------
  0001
```

`0001` is `1`.

Therefore:

```cpp
5 & 3 = 1
```

---

# 3. AND (`&`)

AND compares two bits.

The rule is:

> Both bits must be `1` to produce `1`.

Truth table:

```text
A   B   A & B
-----------
0   0     0
0   1     0
1   0     0
1   1     1
```

Easy way to remember:

```text
AND = BOTH must be 1
```

## Example

```cpp
5 & 3
```

Binary:

```text
  0101
& 0011
------
  0001
```

Answer:

```text
1
```

---

# 4. OR (`|`)

OR compares two bits.

The rule is:

> If at least one bit is `1`, the result is `1`.

Truth table:

```text
A   B   A | B
-----------
0   0     0
0   1     1
1   0     1
1   1     1
```

Easy way to remember:

```text
OR = ANY one can be 1
```

## Example

```cpp
5 | 3
```

Binary:

```text
  0101
| 0011
------
  0111
```

`0111` = `7`.

Therefore:

```text
5 | 3 = 7
```

---

# 5. XOR (`^`) ⭐⭐⭐

XOR means:

> Exclusive OR

The most important rule:

```text
SAME      → 0
DIFFERENT → 1
```

Truth table:

```text
A   B   A ^ B
-----------
0   0     0
0   1     1
1   0     1
1   1     0
```

Look carefully:

```text
0 ^ 0 = 0   ← same
0 ^ 1 = 1   ← different
1 ^ 0 = 1   ← different
1 ^ 1 = 0   ← same
```

So:

> XOR gives `1` when the bits are different.

---

# 6. XOR Example

Let's calculate:

```cpp
5 ^ 3
```

Convert to binary:

```text
5 = 0101
3 = 0011
```

Compare each bit:

```text
  0101
^ 0011
------
  0110
```

Bit by bit:

```text
0 ^ 0 = 0
1 ^ 0 = 1
0 ^ 1 = 1
1 ^ 1 = 0
```

Therefore:

```text
0110 = 6
```

So:

```cpp
5 ^ 3 = 6
```

---

# 7. THE Most Important XOR Property

## A number XOR itself = 0

```cpp
5 ^ 5
```

Binary:

```text
  0101
^ 0101
------
  0000
```

Therefore:

```text
5 ^ 5 = 0
```

This works for ANY number:

```text
x ^ x = 0
```

Examples:

```text
1 ^ 1 = 0
2 ^ 2 = 0
10 ^ 10 = 0
100 ^ 100 = 0
```

Why?

Because every bit is the same.

And XOR says:

```text
SAME → 0
```

---

# 8. Another Important XOR Property

## A number XOR 0 = itself

Example:

```cpp
5 ^ 0
```

Binary:

```text
  0101
^ 0000
------
  0101
```

Therefore:

```text
5 ^ 0 = 5
```

In general:

```text
x ^ 0 = x
```

---

# 9. XOR Can Cancel Duplicate Numbers

This is the REALLY useful part.

Suppose we have:

```text
2 ^ 3 ^ 2
```

The two `2`s can cancel:

```text
2 ^ 3 ^ 2
```

Rearrange:

```text
2 ^ 2 ^ 3
```

Now:

```text
2 ^ 2 = 0
```

So:

```text
0 ^ 3 = 3
```

Therefore:

```text
2 ^ 3 ^ 2 = 3
```

Think of XOR as:

> Duplicate pairs cancel each other out.

---

# 10. Why Can We Rearrange XOR?

XOR has a property where the order doesn't matter.

For example:

```text
2 ^ 3 = 3 ^ 2
```

And:

```text
2 ^ 3 ^ 4
```

can be rearranged as:

```text
2 ^ 4 ^ 3
```

or:

```text
4 ^ 3 ^ 2
```

This is extremely useful because we can move duplicate numbers next to each other.

Example:

```text
4 ^ 1 ^ 2 ^ 1 ^ 2
```

Rearrange:

```text
4 ^ 1 ^ 1 ^ 2 ^ 2
```

Cancel the pairs:

```text
4 ^ 0 ^ 0
```

Then:

```text
4
```

---

# 11. Single Number LeetCode Problem

Suppose:

```text
nums = [4, 1, 2, 1, 2]
```

Every number appears twice except `4`.

We XOR everything:

```text
4 ^ 1 ^ 2 ^ 1 ^ 2
```

Rearrange:

```text
4 ^ 1 ^ 1 ^ 2 ^ 2
```

Cancel the pairs:

```text
4 ^ 0 ^ 0
```

Then:

```text
4 ^ 0 = 4
```

So the answer is:

```text
4
```

That's the entire trick!

---

# 12. The Simple XOR Solution

Instead of using `accumulate`, you can write:

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int result = 0;

        for (int num : nums) {
            result = result ^ num;
        }

        return result;
    }
};
```

Let's understand it:

```cpp
int result = 0;
```

Start with zero.

Then:

```cpp
for (int num : nums)
```

Go through every number.

Then:

```cpp
result = result ^ num;
```

XOR the current number with our result.

---

# 13. Running the XOR Solution

Given:

```text
nums = [4, 1, 2, 1, 2]
```

Start:

```text
result = 0
```

First:

```text
result = 0 ^ 4
       = 4
```

Second:

```text
result = 4 ^ 1
       = 5
```

Third:

```text
result = 5 ^ 2
       = 7
```

Fourth:

```text
result = 7 ^ 1
       = 6
```

Fifth:

```text
result = 6 ^ 2
       = 4
```

Final:

```text
result = 4
```

The duplicate numbers canceled each other.

---

# 14. `accumulate` + `bit_xor`

Your original code was:

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(
            nums.begin(),
            nums.end(),
            0,
            bit_xor<int>()
        );
    }
};
```

This:

```cpp
bit_xor<int>()
```

basically tells `accumulate`:

> Use XOR instead of addition.

It's roughly equivalent to:

```cpp
int result = 0;

for (int num : nums) {
    result = result ^ num;
}

return result;
```

So if you're a beginner, I recommend understanding this version first:

```cpp
int result = 0;

for (int num : nums) {
    result = result ^ num;
}

return result;
```

Then learn `accumulate` later.

---

# 15. NOT (`~`)

NOT flips every bit.

```text
0 → 1
1 → 0
```

Example:

```text
  0101
   ↓↓↓↓
  1010
```

So:

```cpp
~0101
```

becomes:

```text
1010
```

The basic idea:

```text
~ = FLIP EVERY BIT
```

### Important

C++ signed integers make `~` more complicated because of two's-complement representation.

For now, just remember:

```text
~0 → 1
~1 → 0
```

---

# 16. Left Shift (`<<`)

Left shift moves all bits to the left.

Example:

```cpp
5 << 1
```

Binary:

```text
5 = 0101
```

Shift left:

```text
0101 << 1

= 1010
```

`1010` = `10`.

Therefore:

```text
5 << 1 = 10
```

For positive numbers, you can think:

```text
x << 1 ≈ x × 2
x << 2 ≈ x × 4
x << 3 ≈ x × 8
```

In general:

```text
x << n ≈ x × 2ⁿ
```

There are important caveats involving overflow and signed integers, so don't treat this as an unconditional rule.

---

# 17. Right Shift (`>>`)

Right shift moves bits to the right.

Example:

```cpp
10 >> 1
```

Binary:

```text
10 = 1010
```

Shift right:

```text
1010 >> 1

= 0101
```

`0101` = `5`.

Therefore:

```text
10 >> 1 = 5
```

For positive numbers, think:

```text
x >> 1 ≈ x / 2
x >> 2 ≈ x / 4
x >> 3 ≈ x / 8
```

---

# 18. Quick Cheat Sheet

```text
&   AND
|   OR
^   XOR
~   NOT
<<  LEFT SHIFT
>>  RIGHT SHIFT
```

Remember them like this:

```text
&

BOTH must be 1
```

```text
|

AT LEAST ONE must be 1
```

```text
^

DIFFERENT → 1
SAME      → 0
```

```text
~

FLIP bits
```

```text
<<

MOVE bits LEFT
```

```text
>>

MOVE bits RIGHT
```

---

# 19. Truth Tables

## AND

```text
0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1
```

Think:

```text
BOTH → 1
```

---

## OR

```text
0 | 0 = 0
0 | 1 = 1
1 | 0 = 1
1 | 1 = 1
```

Think:

```text
ANY → 1
```

---

## XOR

```text
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0
```

Think:

```text
DIFFERENT → 1
SAME      → 0
```

---

## NOT

```text
~0 = 1
~1 = 0
```

Think:

```text
FLIP
```

---

# 20. XOR Properties to Memorize

These are VERY useful:

```text
x ^ 0 = x
```

```text
x ^ x = 0
```

```text
x ^ y = y ^ x
```

```text
x ^ y ^ x = y
```

The last one is especially useful.

Example:

```text
7 ^ 12 ^ 7
```

Rearrange:

```text
7 ^ 7 ^ 12
```

Cancel:

```text
0 ^ 12
```

Answer:

```text
12
```

---

# 21. Bitwise vs Logical Operators

Don't confuse these:

```text
&   Bitwise AND
|   Bitwise OR
^   Bitwise XOR
~   Bitwise NOT
```

with:

```text
&&  Logical AND
||  Logical OR
!   Logical NOT
```

### Bitwise

Works with the individual bits:

```cpp
5 & 3
5 | 3
5 ^ 3
~5
```

### Logical

Usually works with conditions/boolean values:

```cpp
x > 0 && y > 0
x > 0 || y > 0
!(x > 0)
```

---

# 22. The Most Important Thing to Remember

If you're just starting bit manipulation, don't try to memorize everything at once.

Start with these:

```text
AND (&)
BOTH 1 → 1
```

```text
OR (|)
ANY 1 → 1
```

```text
XOR (^)
SAME → 0
DIFFERENT → 1
```

```text
NOT (~)
FLIP
```

Then learn:

```text
<< LEFT SHIFT
>> RIGHT SHIFT
```

And for XOR, memorize:

```text
x ^ x = 0
x ^ 0 = x
x ^ y ^ x = y
```

The single most important sentence:

> **XOR gives 1 when the bits are different and 0 when they are the same.**

And the most important coding-problem trick:

> **When you XOR a collection of numbers, duplicate values cancel each other out.**

Example:

```text
4 ^ 1 ^ 2 ^ 1 ^ 2

= 4 ^ (1 ^ 1) ^ (2 ^ 2)

= 4 ^ 0 ^ 0

= 4
```

That's why XOR is perfect for the classic **Single Number** problem.
