# Dictionnary

## Implementation and choices
My choices were made base on the current knowledges of the language minus exisiting functions and confidency on producing a result 
which I think is enough to meet the requirements. Complexity of the code was important to get at least good execution time.
Right now, my solution is able to parse by using space delimitor the input string as follow:
  - Fetch the command "wordcount" to know how to process the remaining of the string. A wrong input will result in no output
  - Open the dictionnary file and populate a new dictionnary "instance" which is a struct pointer representing a dictionnary
  - Read the words delimited by spaces and update the dictionnary when the word exists
  - Display the result using the suggested output <br/><br/><br/>
  
  
As of yet, the dictionnary file format supports the following inputs:
  - Leading blanks (removed)
  - Trailing blanks (removed)
  - empty lines are ignored
  - lines with '#' as first character are ignored <br/><br/><br/>
 
  
*NOT YET SUPPORTED*
  - Spaces in path/filename
  - Spaces in dictionnary words <br/><br/><br/>
  
The current implementation allows for up to 250 characters words.
The current implementation allows for close to infinite dictionnary words. The dictionnary capacity is made 2 times bigger everytime it is full. So memory should be limited by the system it is running on
The current implementation will only display if a word has been at least used once (counter more than 0)
The current implementation allows the user to input a new command without restarting. The dictionnary resources are freed at the end of the current execution once the output has been displayed
The current implementation should work on both x64 and x86 plus should not be windows only (no external library or windows specific used)

## Areas of improvements
The current code compiles with a single warning:  
warning c4090 'function' different 'const' qualifiers => The key for the dictionnary is defined as a const char* because it should not be modified. 
So when freeing the memory, this warning occures.  
  
The current code is poorly commentated except in the readDicFile as several processing happen here. So more comment should be added to get a better clarification on each functions and behaviour.  
  
My choice of implementation might not be the most optimized but it was clearer to me while implementing the input processing. Alternatively some solutions like hashtables should be considered.
The complexity should be more optimized there and the processing would be lighter in a big data scenario.

The "usage" function right now only prints an "ERROR!" message when the input string is wrong. Updating it is only a matter of adding output in the dedicated function.
In the main file in the processWordcountCommand(...) function, the call to the usage block is far too many and should be lighter maintenance-wise. 
To that extend, an error code should be returned to ease the processing and give a better look at the error.
In some case you might even add an error function to give better feedbacks depending of the code value (error structure filled with a code and a message in that case would be better implmentation)  
  
Right now, tests part is limited to the minimum and is only visual. As such, things should surely have been done in a reverse order, in a TDD way.
In order to test, a dictionnary file is provided: "resources/dico.txt"  
For testing you can use the following command:  
wordcount resources/dico.txt *add any word here present or not in the dictionnary*  
  
Another upgrade could be to consider a default folder different from the workinng directory in ease the work when using multiple dictionnaries so adding the "resources" part is not needed
