#!/bin/bash
# test mkproj
# FAIL
./mkproj
./mkproj Ass2 abc123 Yes No Ok
./mkproj Ass2
# WORKS
./mkproj Ass2 abc123
# FAIL
./mkproj Ass2 abc123
# WORKS
./mkproj Ass3 def098
./mkproj Ass4 def098

#setup for backup testing
touch ~/Projects/Ass2/docs/file1.txt

# test backup
# FAIL
./backup
./backup -D
./backup ~/Projects/Ass2
./backup ~/Projects/Ass2 ~/Projects/Ass2/backup
# WORKS
./backup ~/Projects/Ass2/docs ~/Projects/Ass2/backup First successfull test
./backup -D ~/Projects/Ass3/docs ~/Projects/Ass3/backup Second test
./backup ~/Projects/Ass2/docs ~/Projects/Ass2/backup Appended log message test
./backup ~/Projects/Ass2/docs ~/Projects/Ass2/backup2 created backup directory

