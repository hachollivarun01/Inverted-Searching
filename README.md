# Inverted Search Engine – C

An inverted search engine implemented in C using hash tables and linked lists to index and search words across multiple text files.

## Project Overview

This project creates an inverted index of words present in multiple text files. The indexed data stores each word along with its frequency and the files in which the word occurs.

The project demonstrates practical implementation of data structures, file handling, dynamic memory allocation, string processing, and searching in C.

## Features

- Read and validate multiple text files
- Create an inverted database
- Store words using a hash table
- Maintain file information using linked lists
- Track word frequency across files
- Search for words in the indexed database
- Display the complete database
- Save the database to a file
- Update/restore the database from a saved file
- Handle duplicate and invalid input files

## Data Structures Used

### Hash Table

A hash table is used to organize indexed words into buckets for efficient searching.

### Linked Lists

Linked lists are used to maintain file information and word occurrences associated with each indexed word.

## Project Modules

```text
main.c
database.h
create_database.c
display.c
read.c
search.c
save.c
update.c
