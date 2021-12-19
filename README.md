# CS-210
- ***"Summarize the project and what problem it was solving."***


This project is a clock that displays the current time in a 12 hour and 24 hour format. It allows the user to add hours, minutes, or seconds to each clock.
  
  
- ***"What did you do particularly well?"***


This project had a few issues starting out. It would randomly update every 5 seconds rather than every second. I couldn't figure out what was wrong, until I removed an extra redundant while loop. I think I did a good job at bug fixing these issues because it works almost flawlessly.


- ***"Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?"***


Further bug fixing and perhaps the ability to add a specific number of hours. I would also change how the clock updates and appears.


- ***"Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?"***


The "struct tm* ct = localtime(&total_seconds);" line of code gave me a few headaches. I ended up requesting help from my older brother who works as a developer for government contracts, but he ended up being unavalible for any advice. I ended up researching how localtime() worked, and I changed how it stored the time and additional time values.



- ***"What skills from this project will be particularly transferable to other projects or course work?"***


Further understanding of while loops and various existing functions has helped me in my later projects. Additionally, using StackOverFlow and various other resources for research has helped me realize the wealth of information avalible to figure out where I have made an error.

  
- ***"How did you make this program maintainable, readable, and adaptable?"***


You won't be able to figure it out on your own since, as the creator, you know more than the computer does. A computer cannot tell you where an issue actually occurs, just as it cannot determine whether or not a painting is art. As a result, you'll need another person, preferably a programmer, to check through what you've developed and provide feedback. Peer review is the formal name for the procedure. Anyone may create simple code that allows others to understand what the code is doing at a deeper level through proper commenting, in depth function descriptions and appropriate function naming. This would include inputs, outputs, and algorithms as well as any kind of programming function. Making your code so that other developers may make significant modifications, such as bug fixes or refactoring, to the original code. As a result, anybody may create a class or module that uses the original code as a framework for class extentions.

