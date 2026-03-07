include "llvm/Option/OptParser.td"

def help : Flag<["--"], "help">,
  HelpText<"Display available options (--help-hidden for more)">;

def help_hidden : Flag<["--"], "help-hidden">,
  Flags<[HelpHidden]>,
  HelpText<"Display all available options">;

def version : Flag<["--"], "version">,
  HelpText<"Display the version of this program">;
def : Flag<["-"], "v">, Alias<version>, HelpText<"Alias for --version">;



