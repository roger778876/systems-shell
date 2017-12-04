# systems-shell
by Cesar Mu and Alex Shevchenko

**Features:**
- Executes user commands just like a real terminal
  - Displays green prompt showing current working directory
- Executes multiple commands separated by semicolons (;)
- Ignores extra spacing before, between, and after commands
- Ignores extra newlines without commands
- Prints out correct error messages
- Supports ```cd``` and ```exit```
- Supports multiple redirection
- Supports piping

**Attempted:**
- Multiple piping

**Bugs:**
- There is a small memory leak because of ```strdup()```
- Executing gibberish commands will print ```No such file or directory``` instead of ```gibberish: command not found```
- Code : Organized :: True : False

**Headers:**
```c
struct cmds_array {char **cmds; size_t num_cmds;};
  // used to pass number of commands along with what the commands are
struct cmds_array read_input();
  // prompts and receives user input, sends to separate_cmds
struct cmds_array separate_cmds(char *line);
  // handles parsing the input and delimiting with semicolons
char **separate_args(char *cmd);
  // handles parsing the command and delimiting with spaces
void execute(char **command);
  // receives array and handles execution of the command + arguments
void change_dir(char **command); 
  // handles cd command
void exit_program();
  // handles exit command
```
