Alexander Frederick
Lab 2 MultiBlink

To create the multiple blinking LEDs I used two methods. On the FR6989 and the FR5994, I used a simple count and toggle whereand integer increases by 1 each cycle to toggle the first LED and the second LED is toggled every 5 ticks. After each run through the for while loop, a delay of 100000 is introduced in order to slow the rate.\
For the F5529, FR2311, and the G2553, I used a different system where I had a while loop incrementing a counter, and had each of the two LEDs being toggled when the modulous of a value assigned was equal to 0. This allowed for each count to be incremented individually. The LED was then just changed through a simple XOR of the output register for the specified pin.