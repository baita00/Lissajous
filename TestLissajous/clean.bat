@echo off

call :DEL_FILE

del /s *.ncb
del /s *.opt
del /s *.plg
del /s *.aps
del /s *.fd
del /s *.bak
del /s *.*.bak
del /s *.positions
del /s/a Thumbs.db
del /s *.exe
del /s *.pdb
del /s *.~*
del /s *.obj
del /s *.tds

del /s *.run
del /s *.fnr

rd /s/q debug
rd /s/q debugu
rd /s/q release
rd /s/q releaseu

rd /s/q ipch
rd /s/q bin
del *.sdf
del *.user
del *.filters


