Jacques Sarraffe

EXECUTBLE IS NAMED: game.x

LIST OF PEOPLE WHOME I HAVE RECEIVED HELP FROM:

Soren Richenberg: 

- helped me with make file. 

- Soren helped me create the the decontstructor for my Screen Class. I was initially confused on what to do,
but he reminded me that you only need to delete the data that is put onto the heap, i.e wherever you use "new" to 
allocate memory.
- Initally discussed the project the first day it was assigned. We went over how to construct the screen, and such,
and said you just use a nested for loop. Once he told me that, I understood exactly what to do with the freePool.

Ali Kooshesh:

- Answered my question on piazza about the makefree() function

- In lab, Professor floated the idea of, printing out your freePool, and follow it everystep of the way,
as a method of debugging your code. I am grateful that you mentioned that, because, I had a problem where
the random munchie would appear on the worm. Using that, printFreePool() function I was able to figure out
where it was going wrong. I ultimately, was setting the munchie to occupied, and then setting it to free,
adding a whole other layer of complexity to the main.cpp. Once I took that logic out, it cut my code in half.
I realized I had alot of similar code, in multiple areas and this ultimately fixed it.

- I asked him if I could you a class for a Cell, instead of a tuple or a pair. He gave me some nice psquedo/ semi partial
solution to the Cell class. I chose to impliment this way, because the last project made me really like using pointers, so this
was the way I ended up implementing it.


Guy Greenleaf:
-I wasted alot of time, trying to code this in CLION, and I couldn't get the debugger for some reason to work with my make file, and it wasn't giving me 
the squiggly lines when I got something wrong. Guy actually made a tutorial video on how to set up VS CODE, with a debugger, and how to directly connect to blue with VS CODE. This made my
life alot easier as I didn't have to worry if it doesn't work on blue because everytime I test it it's running on blue. 

- I started this project the day it got assigned, and spent a whole day getting caught up on curses. For some reason
I thought that it was neccesary. I asked him what the next step was,  he told me that you should  focus just about the "data strucutres"
first, and then the curses stuff. After that I was on track.

HELP FROM EXTERNAL SOURCES:
https://www.educative.io/edpresso/how-to-implement-a-circular-queue-in-cpp

No code was copied and pasted from this link. This link did however provided me with a clear cut explanation with pictures of of how a circular queue functions. 
 It cleared up some of the confusion I had with the % sign, and wrapping, over. Once I glossed over this and understood everything.,
 I wrote the Queue so that it would fit my implemenation for this project. This link was one of the first ones I came across, and was very helpful.

PEOPLE WHOM I HAVE HELPED:

Chris Lapp:
    I told him not to get to hung up on ncurses, and I breifly explained to him what the circular queue does. 
    
LIST OF FEAUTRES PART OF THE PROJECT THAT I HAVE NOT IMPLEMENTED:
    I have implemented all the features part of the project.
