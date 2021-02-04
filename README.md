# shell


 Introduction
 
      The project aims at writing a shell program in C. The shell has internal commands and
      external commands.
2. Internal functions implemented

      a. cd - To change the directory
       ~ gives home directory
       .. gives parent directory
      b. echo - Print to shell
       -n prints without line termination
      c. pwd - Print working directory
       --help gives information on pwd
      d. history - Print or edit history (log)
       -c clear history
       -n clears a particular line
      e. exit - Exit the shell

3. External functions implemented
      a. ls - Print the files in the current directory
       -a prints files starting with . and ..
       -1 prints ls in a list
      b. cat - Print contents of a single file
       -n prints line numbers
      c. rm - Remove a file or directory
       -i asks for permission before deleting
       -f force deletes
      d. mkdir - Make a new directory
       -v prints a statement that directory is made
       -p checks parent directory
      e. date and date -u - get/ print the date
       -u prints date in universal time format
