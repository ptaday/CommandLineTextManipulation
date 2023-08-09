# Text-Manipulation Command-Line Tool

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Command-Line-Arguments](#command-line-arguments)
- [Part 1: Validate the Command-line Arguments](#part-1-validate-the-command-line-arguments)
- [Part 2: Simple Search and Replacement](#part-2-simple-search-and-replacement)
- [Part 3: Wildcard Search and Replacement](#part-3-wildcard-search-and-replacement)
- [Testing](#testing)
- [License](#license)
- [Contact](#contact)

---

## Description

This command-line tool enables you to search for text in an input file and generate a copy of the input file with the search text replaced by the provided replacement text. It supports various command-line options to customize the search and replacement process.

## Features

- Search for specific text in an input file and replace occurrences with the given replacement text.
- Support for command-line options (-s, -r, -w, -l) to control search and replacement behavior.
- Customizable range of lines to process in the input file.
- Wildcard search and replacement using the -w option.
- Error handling for invalid or missing arguments.

## Prerequisites

- Basic understanding of C programming language.
- Familiarity with command-line interfaces.

## Installation

1. Clone this repository to your local machine.
2. Open the project in your preferred C development environment (e.g., VS Code).
3. Compile and build the project using the provided build commands.

## Usage

To use this text-manipulation command-line tool:

1. Open a terminal window.
2. Navigate to the directory where the executable is located.
3. Run the executable with appropriate command-line arguments to perform text search and replacement.

Refer to the [Command-Line Arguments](#command-line-arguments) section for more details on available options.

## Command-Line Arguments

The command-line tool supports the following options and arguments:

- `-s search_text`: The text to search for in the input file (required).
- `-r replace_text`: The text to replace the search text with in the output file (required).
- `-w`: Enable wildcard searching of words (optional).
- `-l start_line,end_line`: Range of lines in the input file to process (optional).
- `infile`: Pathname of the input file (required).
- `outfile`: Pathname of the output file (required).

## Part 1: Validate the Command-line Arguments

The program checks for various error situations when parsing command-line arguments, including missing arguments, duplicate arguments, and more. The error codes and explanations are provided in the assignment document.

## Part 2: Simple Search and Replacement

Implement functionality to search for instances of search_text in the input file and replace them with replacement_text in the output file. Other content is copied unmodified.

## Part 3: Wildcard Search and Replacement

Enhance the search functionality to support wildcard search and replacement using the -w option. Wildcards can be used as prefixes or suffixes of words.

## Testing 

- The provided unit tests (written using Criterion) help verify the correctness of your implementation.
- Test your code with both computational tests and Valgrind tests for memory errors.
- Use the provided make commands to compile, test, and check test coverage

git add .
git commit -am "your message here"
git push origin

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

For any inquiries or feedback, please contact:
- Pushkar Taday
- Email: pmtaday@gmail.com
- GitHub: ptaday




