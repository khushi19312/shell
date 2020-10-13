# shell


 Introduction
      The project aims at writing a shell program in C. The shell has internal commands and
      external commands.
2. Internal functions implemented
      a. cd - cd~ and cd..
      To change the directory
      ~ gives home directory
      .. gives parent directory
      b. echo - echo -E and echo -n
      Print to shell
      -n prints without line termination
      c. pwd and pwd --help
      Print working directory
      --help gives information on pwd
      d. history - history -c and history -n
      Print or edit history (log)
      -c clear history
      -n clears a particular line
      e. exit - exit n
      Exit the shell
3. External functions implemented
      a. ls - ls -a and ls-1
      Print the files in the current directory
      -a prints files starting with . and ..
      -1 prints ls in a list
      b. cat - cat -n and cat -E
      Print contents of a single file
      -n prints line numbers
      -E terminated each line with $
      c. rm - rm -i and rm -f
      Remove a file or directory
      -i asks for permission before deleting
      -f force deletes
      d. mkdir - mkdir -v and mkdir -p
      Make a new directory
      -v prints a statement that directory is made
      -p checks parent directory
      e. date and date -u
      get/ print the date
      -u prints date in universal time format
