Here's an emulation of the Linux cat program with a small twist. In an attempt
to make things more legible, __537cat only accepts lines which fit within 80
characters__, much like this README. The 80 character boundary might not be
visible online. Open this README with an editor to confirm the boundary.

For example, running `./537cat README` will accept all lines except for this one, because this one is longer than 80 characters.

You can test this using `wc -l README` to count all lines. There should be a
difference of 1 in the two outputs.

# Assertions
[Assertions](https://en.wikipedia.org/wiki/Assert.h "assert.h Wiki page") are a
great way to debug your code. It also forces you think about your logic more
clearly since you are stating your assumptions explicitly in your code.

__Note:__ Assertions are for testing your assumptions while debugging. They are
not for checking bad user input when you release your code to your users. When
checking user input, use descriptive error messages so that the user (even
those not tech savvy) can understand their mistake and fix it.

# No Comments
The `.c` and `.h` files don't have any comments, because I believe that if I
could not explain things well in a programming language like C, I probably
won't do any better with comments in a natural language (English). Plus, the
compiler doesn't check comments, so I might write complete nonsense in the
comments and confuse you. With no comments, you're guaranteed that the compiler
agrees with everything I've said in my code.

Instead of writing comments, I:

* have descriptive identifier names
* write many short functions that do one (and only one) task well

If you cannot understand some part of my code, that means my code that was not
expressive enough. If that's the case, please email me so I can improve my
coding style.

__Note:__ There is one comment in main.c which explains Valgrind memory
warnings. However, it is for instructional purposes, and I wouldn't include it
in production code.

# Output lines?
As we discussed in class, it's tedious to write custom print functions for all
your data structures. So if you want to check contents of your data structure
while debugging, __use GDB to set appropriate breakpoints and explore freely__.
537cat represents the input module with basic condition checking while parsing.
It's likely to be chained with other components for processing and output. So
don't spend time writing print functions for all your modules. GDB is here to
help.

# Clang Static Analyzer
```
cat.c:29:27: warning: Potential leak of memory pointed to by 'line'
        array_list *linesArray = malloc(sizeof(*linesArray));
                                 ^~~~~~
```
Since we're exiting the program right after we're done using the malloc'ed
memory, we can ignore this warning. There are no other CSA errors in this code.

# Valgrind

Valgrind reports no memory errors when 537cat is run on any of the source
files. Test using:
```
valgrind --leak-check=yes --track-origins=yes --read-var-info=yes 537cat main.c
```
