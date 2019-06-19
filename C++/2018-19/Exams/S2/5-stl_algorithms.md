# STL Algorithms

## Nonmodifying algorithms

 Nonmodifying algorithms do not change the value of any element, nor do they modify the order in which the elements appear.

 * ``for_each()`` - This is possibly the most important algorithm in this section, as it allows any unary function (i.e. a function of one argument) to be applied to each element in a range/container.
 * ``count()`` - This returns the number of elements in a range or container.
 * ``min_element()`` - Returns the element that has the smallest value, making use of the < relation to perform comparison. It can accept a custom binary function to perform the comparison instead.
 * ``max_element()`` - Returns the element that has the largest value, making use of the > relation to perform comparison. It can accept a custom binary function to perform the comparison instead.
 .Жй
n a range or container that equals a passed value.
