# CAbuseSort
CAbuse Sort (caboose sort) is an implementation of quicksort packed into the header of a for loop. This relies on a few *interesting* features of the C Language, but in no way violates the standard.

## Comma Expressions
C executes **Statements** in a top down manner, but it also executes **Expressions** in a left to right order with the value of the expessions being the value of the rightmost expression in the list.
``` C
int f, b, x = (f = foo(), b = bar(), f + b); 
```
The previous code snippet creates 3 variables assigns f the return value of foo(), b the return value of bar and assigns to x their sum. This is a single statement, but contains a list of exressions.
This allows for many computational steps to be taken in a single statement.

## Logical Operators with short circuiting
Short circuiting is a useful feature of the Logical Operators.
``` C
if (x != NULL && x->foo < 0xdeadbeef) {
  ...
}
```
The previous code snippet will evaluate the nullity check and if it fails it will apply the identity that `false && anything` is false to immediately drop out. This is useful because if it went on to evaluate x->foo we would be accessing an invalid pointer.
``` C
if (x != NULL) {
  if (x->foo < 0xdeadbeef) {
    ...
  }
}
```
If it did not short circuit we would have to restructure the code to prevent the execution of the field access when the pointer was NULL.

A similar property holds for logical or where anytime the result of the first operand is true the execution short circuits.

## Ternary Expressions
The C language doesn't have nice if expressions like some languages, but ternaries provide the same functionality with a slightly uglier syntax.
``` C
int x = cond() ? foo() : bar();
```
This assigns x the value of foo() or bar() depending on the result of cond().
It is important to note that this is not a statement, but rather an exression meaninng they can be placed in a comma expression.
``` C
int x = cond1() ? foo1() : foo2(), cond2() ? bar() : baz();
```
We execute foo1 or foo2 based on the result of cond1 and then go on to assign to x the value of bar() or baz() depending on cond2.

## XOR Swapping
xor swapping provides a way to swap two variables "in place."
``` C
int x = 5, y = 12;
x = x ^ y; // x = (x ^ y), y = y
y = y ^ x; // x = (x ^ y), y = y ^ (x ^ y) = x
x = x ^ y; // x = (x ^ y) ^ x = y
```
Using the definition that `(x ^ y) ^ y == x` we can swap the two variables

Again these are all expressions which means this can be placed in a single statement
```C
x ^= y, y ^= x, x ^= y;
```

## Put it all together and you get:
``` C
void qs(int * a, int s) {
    for (int i = 0, w = 0; s > 1 && (i < s-1 || (qs(a,w), qs(a+w+1,s-w-1), 0)); ((a[i] < a[s-1] ? (a[i] != a[w] ? a[w] ^= a[i], a[i] ^= a[w], a[w] ^= a[i], w++ : w++): 1), i++), i == s-1 ? (a[w] != a[s-1] ? a[s-1] ^= a[w], a[w] ^= a[s-1], a[s-1] ^= a[w], 1 : 1) : 1);
}
```
Or *slightly* more readably
``` C
void qs(int * a, int s) {
        for (
       // Initialization:
       int i = 0, w = 0;

       // Comparison
       // Use short circuiting to loop until all elements swapped
       s > 1 &&
       // Check if we need to resurse deeper, and if so make recursive calls
       (i < s-1 || (qs(a,w), qs(a+w+1,s-w-1), 0));

       // Increment
       // Check if we need to swap an element
       ((a[i] < a[s-1] ? // Check if a[i] is less than the pivot
          (a[i] != a[w] ? // Xor swap if the values are different and increment w
              a[w] ^= a[i], a[i] ^= a[w], a[w] ^= a[i], w++ :
              w++):
          1), // We need a value so 1 is as good as any, this is just the branch where we don't swap
        i++), // Increment to the next element
       // If at the end put the pivot in place
       i == s-1 ? 
          (a[w] != a[s-1] ? a[s-1] ^= a[w], a[w] ^= a[s-1], a[s-1] ^= a[w], 1 : 
           1) : 
       1);
}
```
