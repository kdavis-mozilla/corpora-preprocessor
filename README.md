# Corpora Preprocessor
A scripts suite that preprocesses the Wikipedia text corpora from [corpora-generator](https://github.com/kdavis-mozilla/corpora-generator)

# Quick Start

## Prerequisites

- [make](https://www.gnu.org/software/make/)
- [g++](https://gcc.gnu.org/) with C++11 support
- Latest development version of [freeling](http://nlp.lsi.upc.edu/freeling/)
- AWS command line interface [cli](https://aws.amazon.com/cli/)
- [bash](http://www.gnu.org/software/bash/) along with the standard command line utility `mkdir`

## Execution

### What to do...

One simply opens a shell an proceeds as follows:
```bash
MacBook-Pro:Code kdavis$ cd corpora-preprocessor
MacBook-Pro:corpora-preprocessor kdavis$ make all
MacBook-Pro:corpora-preprocessor kdavis$ make preprocessed-text
```

### What happens...

This will run through several steps. It will

* Build en executable `preprocess` in the `bin` directory
* Create a directory `language-models`
* Download the Wikipedia data dumps from S3 created by [corpora-generator](https://github.com/kdavis-mozilla/corpora-generator) into `language-models`
* Create a series of directories,
```bash
language-models/
└── pre-processed
    ├── as
    ├── ca
    ├── cs
    ├── cy
    ├── de
    ├── en
    ...
```appropriate directory
one for each language to be preprocessed `as`, `ca`, `cs`...
* With `preprocess` proprocess the associated data dumps and place them into the appropriate directory.

### What the results are...

The final result is the preprocessed text of each language's Wikipedia dump 
* `pre-processed/as/wiki.txt`
* `pre-processed/ca/wiki.txt`
* `pre-processed/cs/wiki.txt`
* ...

stored in the appropriate directory.
