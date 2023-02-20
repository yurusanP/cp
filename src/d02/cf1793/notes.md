# [src.cp.cf1793] Codeforces Round #852 (Div. 2)

[toc]

---

## (a) Yet Another Promotion

> Given 2 prices of potatoes, one with a promotion after several buys,
>
> find the min cost to buy a certain amount of potatoes.

Trivial.

Avoid using `double` if possible. It seems that the server has a different precision from the one on my local machine.

## (b) Fedya and Array

> Consider a circular array whose each neighbor is exactly off by 1.
>
> Given the sum of local mins and sum of local maxes, give a possible shortest array.

Note that the local minimums and maximums alternates.

We just consider a special case where the array contain 1 local minimum and 1 local maximum.

## (c) Dora and Search

> Given a permutation, find a subsegment whose both ends are not min or max of it.

Trivial.

## (d) Moscow Gorillas

> Given 2 permutations, count the subsegments at the same position with the same mex.

Given that the inputs are permutations, we can build an index map.

The specific situations are described in the code.
