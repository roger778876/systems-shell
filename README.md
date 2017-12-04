# systems-shell

Out shell implements all of the features that are included in execvp


Headers:

void change_dir(char **command); 

void exit_program();

void execute(char **command);

struct cmds_array separate_cmds(char *line);

char **separate_args(char *cmd);

struct cmds_array read_input();
