# C Project Template

A basic C programming project directory structure may contain the following artifacts:

```
.
├── Makefile
├── README.md
├── docs
└── src
    ├── libs
    └── main.c

```

## Makefile
Contains a selection to targets to clean, build, and run the project. 

## README.md
A documentation file, written in markdown, that explains the purpose of the project and how to deploy and run it. 

## docs Directory
Contains project documentation including imagery.

## src Directory
Contains application code. main.c file located here.

## src/libs Directory
Contains headers and source code for project libraries. All projects, with the exception of simple demo programs limited to one main.c file, should be split into a stand-alone library consisting of one header file (libname.h) and one source file (libname.c).