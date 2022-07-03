# compile for debugging purposes
g++ -g app.cpp

# In command line enter "gdb a.exe"
Now your in debug mode.

# to make a breakpoint type "b main" to break at main function
or "b func_name" to break at a particular function or "b line_no" to break at a specific line number.

# to run in debug mode type "run" or just "r"

# to view the code near your breakpoint type "list" or just "l"

# to see specific line_no your breakpoint is at type "frame" or just "f"

# to execute the next line from the breakpoint type "next" or just "n"

# to view the value of a variable type "print var_name" or just "p var_name"

# to go into function type "step" or just "s"

# to show where you are going and at what point you are at in your program type "backtrace" or just "bt"

# to get information about your breakpoints such as how many you have type "info b"

# to delete a breakpoint type "info b" and the view breakpoint's number and type "delete no_of_breakpoint", Ex: "delete 1"

# to continue to next breakpoint type "continue" or just "c"

# to view frames type "bt", to change frame type "frame frame_no" or just "f frame_no"
From within that frame's context you can print the variables in that frame.

# type "info locals" to view variables in local scope.