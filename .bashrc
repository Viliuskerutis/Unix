#
# Define default prompt to <username>@<hostname>:<path><"($|#) ">
# and print '#' for user "root" and '$' for normal users.
#

BASH_ENV=~/.bashrc
typeset +x PS1="\u@\h:\w\\$ "
